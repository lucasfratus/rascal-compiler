#include "gerador.hpp"
#include <iostream>

static void emit(const std::string& s) {
    // 4 caracteres do "label" + 1 do ':' para indentação 
    std::cout << "     " << s << std::endl;
}

static void emitLabel(const std::string& s) {
    std::cout << s << ": NADA" << std::endl;
}

GeradorCodigo::GeradorCodigo() : contador_geral(1), nivel_atual(0) {}

std::string GeradorCodigo::newLabel() {
    int n = contador_geral++;
    if (n < 10) return "R0" + std::to_string(n);
    return "R" + std::to_string(n);
}

void GeradorCodigo::gerar(Programa* prog) {
    if (!prog) return;

    if (prog->bloco->subrotinas.empty()) {
        // não tem subrotina → primeiro label é R00
        contador_geral = 0;
    } else {
        // tem subrotina → R00 é do main, subrotinas começam em R01
        contador_geral = 1;
    }
    
    nivel_atual = 0;
    emit("INPP");
    
    tabela.insert(prog->nome, CAT_PROGRAM, TIPO_VAZIO);

    int count_globais = 0;
    for (auto decl : prog->bloco->vars) {
        count_globais += decl->ids.size();
        TipoDado tipo = (decl->tipo == TipoVar::Integer) ? TIPO_INT : TIPO_BOOL;
        for (auto id : decl->ids) {
            tabela.insert(id, CAT_VAR, tipo);
        }
    }

    if (count_globais > 0) {
        emit("AMEM " + std::to_string(count_globais));
    }

    if (!prog->bloco->subrotinas.empty()) {
        emit("DSVS R00");  
    }

    for (auto sub : prog->bloco->subrotinas) {
        visitaDeclSub(sub);
    }

    if (!prog->bloco->subrotinas.empty()) {
        emitLabel("R00");
    }

    for (auto c : prog->bloco->comandos) {
        visitaComando(c);
    }

    if (count_globais > 0) {
        emit("DMEM " + std::to_string(count_globais));
    }

    emit("PARA");
    emit("FIM");
}

void GeradorCodigo::visitaDeclSub(DeclaracaoSub* d) {
    std::string rotulo = newLabel();
    
    TipoDado tRet = (d->tipoSub == TipoSubrotina::Function) 
                    ? ((d->tipoRetorno == TipoVar::Integer) ? TIPO_INT : TIPO_BOOL) 
                    : TIPO_VAZIO;
    Categoria cat = (d->tipoSub == TipoSubrotina::Function) ? CAT_FUNC : CAT_PROC;
    
    std::vector<TipoDado> tiposParams;
    for (auto p : d->parametros) {
        TipoDado t = (p->tipo == TipoVar::Integer) ? TIPO_INT : TIPO_BOOL;
        for (size_t i = 0; i < p->ids.size(); i++) {
            tiposParams.push_back(t);
        }
    }

    tabela.insert(d->nome, cat, tRet, tiposParams);
    Simbolo* s = tabela.lookup(d->nome);
    s->label = rotulo;
    
    int nivel_decl = tabela.getLevel(d->nome); 
    
    emitLabel(rotulo);
    emit("ENPR " + std::to_string(nivel_decl + 1));

    int nivel_antigo = nivel_atual;
    nivel_atual = nivel_decl + 1;

    tabela.enterScope(); 

    int param_offset = -5;
    for (auto p : d->parametros) {
        TipoDado t = (p->tipo == TipoVar::Integer) ? TIPO_INT : TIPO_BOOL;
        for (auto id : p->ids) {
            tabela.insert(id, CAT_PARAM, t, {}, param_offset--);
        }
    }

    if (d->corpo) {
        int count_locais = 0;
        for (auto decl : d->corpo->locais) {
            for (auto id : decl->ids) {
                TipoDado t = (decl->tipo == TipoVar::Integer) ? TIPO_INT : TIPO_BOOL;
                tabela.insert(id, CAT_VAR, t);
                count_locais++;
            }
        }
        
        if (count_locais > 0) {
            emit("AMEM " + std::to_string(count_locais));
        }

        for (auto c : d->corpo->comandos) {
            visitaComando(c);
        }
        
        if (count_locais > 0) {
            emit("DMEM " + std::to_string(count_locais));
        }
        
        int n_params = 0;
        for (auto p : d->parametros) n_params += p->ids.size();
        
        emit("RTPR " + std::to_string(n_params));
    }

    tabela.exitScope();
    nivel_atual = nivel_antigo;
}

void GeradorCodigo::visitaComando(Comando* c) {
    if (!c) return;

    switch (c->tipo_cmd) {
        case TipoComando::CMD_ATRIB:
            visitaAtribuicao((AtribuicaoCmd*)c);
            break;
        case TipoComando::CMD_IF:
            visitaIf((IfCmd*)c);
            break;
        case TipoComando::CMD_WHILE:
            visitaWhile((WhileCmd*)c);
            break;
        case TipoComando::CMD_READ:
            visitaLeitura((LeituraCmd*)c);
            break;
        case TipoComando::CMD_WRITE:
            visitaEscrita((EscritaCmd*)c);
            break;
        case TipoComando::CMD_CHAMADA:
            visitaChamadaProc((ChamadaProcedimentoCmd*)c);
            break;
        case TipoComando::CMD_COMPOSTO:
            visitaComandoComposto((ComandoComposto*)c);
            break;
    }
}

void GeradorCodigo::visitaAtribuicao(AtribuicaoCmd* c) {
    visitaExpressao(c->expr);

    Simbolo* s = tabela.lookup(c->id);
    int k = tabela.getLevel(c->id);
    
    if (s->categoria == CAT_FUNC) {
        int n_params = 0;
        n_params = s->params.size();
        int offset_retorno = -(5 + n_params);
        emit("ARMZ " + std::to_string(k + 1) + "," + std::to_string(offset_retorno));
    } else {
        emit("ARMZ " + std::to_string(k) + "," + std::to_string(s->offset));
    }
}

void GeradorCodigo::visitaIf(IfCmd* c) {
    // IF sem ELSE
    if (c->elseCmd == nullptr) {
        std::string label_fim = newLabel();

        visitaExpressao(c->cond);
        emit("DSVF " + label_fim);  

        visitaComando(c->thenCmd);

        emitLabel(label_fim);
    }
    // IF com ELSE
    else {
        std::string label_fim  = newLabel();
        std::string label_else = newLabel();

        visitaExpressao(c->cond);
        emit("DSVF " + label_else);  
  
        visitaComando(c->thenCmd);
        emit("DSVS " + label_fim);   

        emitLabel(label_else);
        visitaComando(c->elseCmd);

        emitLabel(label_fim);
    }
}

void GeradorCodigo::visitaWhile(WhileCmd* c) {
    std::string label_inicio = newLabel();
    std::string label_fim = newLabel();

    emitLabel(label_inicio);
    visitaExpressao(c->cond);
    emit("DSVF " + label_fim);

    visitaComando(c->corpo);
    emit("DSVS " + label_inicio);

    emitLabel(label_fim);  
}

void GeradorCodigo::visitaLeitura(LeituraCmd* c) {
    for (const auto& id : c->ids) {
        emit("LEIT");
        Simbolo* s = tabela.lookup(id);
        int k = tabela.getLevel(id);
        emit("ARMZ " + std::to_string(k) + "," + std::to_string(s->offset));
    }
}

void GeradorCodigo::visitaEscrita(EscritaCmd* c) {
    for (auto expr : c->exprs) {
        visitaExpressao(expr);
        emit("IMPR");
    }
}

void GeradorCodigo::visitaComandoComposto(ComandoComposto* c) {
    for (auto cmd : c->comandos) {
        visitaComando(cmd);
    }
}

void GeradorCodigo::visitaChamadaProc(ChamadaProcedimentoCmd* c) {
    for (int i = c->args.size() - 1; i >= 0; i--) {
        visitaExpressao(c->args[i]);
    }

    Simbolo* s = tabela.lookup(c->id);
    emit("CHPR " + s->label + "," + std::to_string(nivel_atual));
}

void GeradorCodigo::visitaExpressao(Expressao* e) {
    if (!e) return;

    switch (e->tipo_expr) {
        case TipoExpressao::EXP_INT:
            visitaConst(((IntConstExpr*)e)->valor);
            break;
        case TipoExpressao::EXP_BOOL:
            visitaConst(((BoolConstExpr*)e)->valor == ValorBool::True ? 1 : 0);
            break;
        case TipoExpressao::EXP_VAR:
            visitaVar((VarExpr*)e);
            break;
        case TipoExpressao::EXP_BINARIA:
            visitaBinaria((ExpressaoBinaria*)e);
            break;
        case TipoExpressao::EXP_UNARIA:
            visitaUnaria((ExpressaoUnaria*)e);
            break;
        case TipoExpressao::EXP_CHAMADA:
            visitaChamadaFunc((ChamadaFuncao*)e);
            break;
    }
}

void GeradorCodigo::visitaConst(int val) {
    emit("CRCT " + std::to_string(val));
}

void GeradorCodigo::visitaVar(VarExpr* e) {
    Simbolo* s = tabela.lookup(e->id);
    int k = tabela.getLevel(e->id);
    emit("CRVL " + std::to_string(k) + "," + std::to_string(s->offset));
}

void GeradorCodigo::visitaBinaria(ExpressaoBinaria* e) {
    visitaExpressao(e->esq);
    visitaExpressao(e->dir);

    switch (e->op) {
        case OperadorBinario::Add: 
            emit("SOMA"); 
            break;
        case OperadorBinario::Sub:
            emit("SUBT");
            break;
        case OperadorBinario::Mul: 
            emit("MULT");
            break;
        case OperadorBinario::Div: 
            emit("DIVI");
            break;
        case OperadorBinario::And:
            emit("CONJ");
            break;
        case OperadorBinario::Or:  
            emit("DISJ");
            break;
        case OperadorBinario::Equal:    
            emit("CMIG");
            break;
        case OperadorBinario::NotEqual: 
            emit("CMDG");
            break;
        case OperadorBinario::Less:     
            emit("CMME");
            break;
        case OperadorBinario::LessEq:  
            emit("CMEG");
            break;
        case OperadorBinario::Greater: 
            emit("CMMA");
            break;
        case OperadorBinario::GreaterEq: 
            emit("CMAG");
            break;
    }
}

void GeradorCodigo::visitaUnaria(ExpressaoUnaria* e) {
    visitaExpressao(e->expr);
    if (e->op == OperadorUnario::Negativo) emit("INVR");
    else if (e->op == OperadorUnario::Not) emit("NEGA");
}

void GeradorCodigo::visitaChamadaFunc(ChamadaFuncao* e) {
    emit("AMEM 1");

    for (int i = e->args.size() - 1; i >= 0; i--) {
        visitaExpressao(e->args[i]);
    }

    Simbolo* s = tabela.lookup(e->id);
    emit("CHPR " + s->label + "," + std::to_string(nivel_atual));
}
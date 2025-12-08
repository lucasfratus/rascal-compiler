#include "gerador.hpp"
#include <iostream>

GeradorCodigo::GeradorCodigo() : contador_geral(0) {}

std::string GeradorCodigo::newLabel() {
    int n = ++contador_geral;
    std::string num = std::to_string(n);

    if (n < 10) {
        num = "0" + num;
    }
    
    return "R" + num;
}

void GeradorCodigo::gerar(Programa* prog) {
    if (!prog) return;

    std::cout << "INPP" << std::endl;
    
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
        std::cout << "AMEM " << count_globais << std::endl;
    }

    if (!prog->bloco->subrotinas.empty()) {
        std::cout << "DSVS R00" << std::endl; 
    }

    for (auto sub : prog->bloco->subrotinas) {
        visitaDeclSub(sub);
    }

    if (!prog->bloco->subrotinas.empty()) {
        std::cout << "R00: NADA" << std::endl;
    }

    for (auto c : prog->bloco->comandos) {
        visitaComando(c);
    }

    if (count_globais > 0) {
        std::cout << "DMEM " << count_globais << std::endl;
    }

    std::cout << "PARA" << std::endl; 
    std::cout << "FIM" << std::endl;
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
    
    int nivel = tabela.getLevel(d->nome); 
    
    std::cout << rotulo << ": NADA" << std::endl;
    std::cout << "      ENPR " << (nivel + 1) << std::endl; 

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
            std::cout << "      AMEM " << count_locais << std::endl;
        }

        for (auto c : d->corpo->comandos) {
            visitaComando(c);
        }
        
        if (count_locais > 0) {
            std::cout << "      DMEM " << count_locais << std::endl;
        }
        
        int n_params = 0;
        for (auto p : d->parametros) n_params += p->ids.size();
        
        std::cout << "      RTPR " << n_params << std::endl;
    }

    tabela.exitScope();
}

void GeradorCodigo::visitaComando(Comando* c) {
    if (auto cmd = dynamic_cast<AtribuicaoCmd*>(c)) visitaAtribuicao(cmd);
    else if (auto cmd = dynamic_cast<IfCmd*>(c)) visitaIf(cmd);
    else if (auto cmd = dynamic_cast<WhileCmd*>(c)) visitaWhile(cmd);
    else if (auto cmd = dynamic_cast<LeituraCmd*>(c)) visitaLeitura(cmd);
    else if (auto cmd = dynamic_cast<EscritaCmd*>(c)) visitaEscrita(cmd);
    else if (auto cmd = dynamic_cast<ChamadaProcedimentoCmd*>(c)) visitaChamadaProc(cmd);
    else if (auto cmd = dynamic_cast<ComandoComposto*>(c)) visitaComandoComposto(cmd);
}

void GeradorCodigo::visitaAtribuicao(AtribuicaoCmd* c) {
    visitaExpressao(c->expr);

    Simbolo* s = tabela.lookup(c->id);
    int k = tabela.getLevel(c->id);
    
    if (s->categoria == CAT_FUNC) {
        int n_params = 0;
        n_params = s->params.size();
        std::cout << "ARMZ " << (k + 1) << ", -" << (5 + n_params) << std::endl;
    } else {
        std::cout << "ARMZ " << k << ", " << s->offset << std::endl;
    }
}

void GeradorCodigo::visitaIf(IfCmd* c) {
    std::string label_else = newLabel();
    std::string label_fim = newLabel();

    visitaExpressao(c->cond);
    std::cout << "DSVF " << label_else << std::endl;

    visitaComando(c->thenCmd);
    std::cout << "DSVS " << label_fim << std::endl;

    std::cout << label_else << ": NADA" << std::endl;
    if (c->elseCmd) {
        visitaComando(c->elseCmd);
    }
    
    std::cout << label_fim << ": NADA" << std::endl;
}

void GeradorCodigo::visitaWhile(WhileCmd* c) {
    std::string label_inicio = newLabel();
    std::string label_fim = newLabel();

    std::cout << label_inicio << ": NADA" << std::endl;
    visitaExpressao(c->cond);
    std::cout << "DSVF " << label_fim << std::endl;

    visitaComando(c->corpo);
    std::cout << "DSVS " << label_inicio << std::endl;

    std::cout << label_fim << ": NADA" << std::endl;
}

void GeradorCodigo::visitaLeitura(LeituraCmd* c) {
    for (const auto& id : c->ids) {
        std::cout << "LEIT" << std::endl;
        Simbolo* s = tabela.lookup(id);
        int k = tabela.getLevel(id);
        std::cout << "ARMZ " << k << ", " << s->offset << std::endl;
    }
}

void GeradorCodigo::visitaEscrita(EscritaCmd* c) {
    for (auto expr : c->exprs) {
        visitaExpressao(expr);
        std::cout << "IMPR" << std::endl;
    }
}

void GeradorCodigo::visitaComandoComposto(ComandoComposto* c) {
    for (auto cmd : c->comandos) {
        visitaComando(cmd);
    }
}

void GeradorCodigo::visitaChamadaProc(ChamadaProcedimentoCmd* c) {
    for (auto arg : c->args) {
        visitaExpressao(arg);
    }

    Simbolo* s = tabela.lookup(c->id);
    int k = tabela.getLevel(c->id);
    std::cout << "CHPR " << s->label << ", " << k << std::endl;
}

void GeradorCodigo::visitaExpressao(Expressao* e) {
    if (auto ex = dynamic_cast<IntConstExpr*>(e)) visitaConst(ex->valor);
    else if (auto ex = dynamic_cast<BoolConstExpr*>(e)) visitaConst(ex->valor == ValorBool::True ? 1 : 0);
    else if (auto ex = dynamic_cast<VarExpr*>(e)) visitaVar(ex);
    else if (auto ex = dynamic_cast<ExpressaoBinaria*>(e)) visitaBinaria(ex);
    else if (auto ex = dynamic_cast<ExpressaoUnaria*>(e)) visitaUnaria(ex);
    else if (auto ex = dynamic_cast<ChamadaFuncao*>(e)) visitaChamadaFunc(ex);
}

void GeradorCodigo::visitaConst(int val) {
    std::cout << "CRCT " << val << std::endl;
}

void GeradorCodigo::visitaVar(VarExpr* e) {
    Simbolo* s = tabela.lookup(e->id);
    int k = tabela.getLevel(e->id);
    std::cout << "CRVL " << k << ", " << s->offset << std::endl;
}

void GeradorCodigo::visitaBinaria(ExpressaoBinaria* e) {
    visitaExpressao(e->esq);
    visitaExpressao(e->dir);

    switch (e->op) {
        case OperadorBinario::Add: std::cout << "SOMA" << std::endl; break;
        case OperadorBinario::Sub: std::cout << "SUBT" << std::endl; break;
        case OperadorBinario::Mul: std::cout << "MULT" << std::endl; break;
        case OperadorBinario::Div: std::cout << "DIVI" << std::endl; break;
        case OperadorBinario::And: std::cout << "CONJ" << std::endl; break;
        case OperadorBinario::Or:  std::cout << "DISJ" << std::endl; break;
        case OperadorBinario::Equal:    std::cout << "CMIG" << std::endl; break;
        case OperadorBinario::NotEqual: std::cout << "CMDG" << std::endl; break;
        case OperadorBinario::Less:     std::cout << "CMME" << std::endl; break;
        case OperadorBinario::LessEq:   std::cout << "CMEG" << std::endl; break;
        case OperadorBinario::Greater:  std::cout << "CMMA" << std::endl; break;
        case OperadorBinario::GreaterEq:std::cout << "CMAG" << std::endl; break;
    }
}

void GeradorCodigo::visitaUnaria(ExpressaoUnaria* e) {
    visitaExpressao(e->expr);
    if (e->op == OperadorUnario::Negativo) std::cout << "INVR" << std::endl;
    else if (e->op == OperadorUnario::Not) std::cout << "NEGA" << std::endl;
}

void GeradorCodigo::visitaChamadaFunc(ChamadaFuncao* e) {
    std::cout << "AMEM 1" << std::endl;

    for (auto arg : e->args) {
        visitaExpressao(arg);
    }

    Simbolo* s = tabela.lookup(e->id);
    int k = tabela.getLevel(e->id);
    std::cout << "CHPR " << s->label << ", " << k << std::endl;
}
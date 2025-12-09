#include "semantico.hpp"
#include <iostream>

AnalisadorSemantico::AnalisadorSemantico() 
    : errors(0), funcao_atual_tipo_retorno(TIPO_VAZIO), retorno_encontrado(false) {}

void AnalisadorSemantico::error(const std::string& msg) {
    std::cerr << "ERRO SEMANTICO: " << msg << std::endl;
    errors++;
}

TipoDado AnalisadorSemantico::mapType(TipoVar t) {
    if (t == TipoVar::Integer) return TIPO_INT;
    if (t == TipoVar::Boolean) return TIPO_BOOL;
    return TIPO_DESCONHECIDO;
}

bool AnalisadorSemantico::analyze(Programa* prog) {
    if (!prog) return false;
    
    tabela.insert(prog->nome, CAT_PROGRAM, TIPO_VAZIO);
    visitaBloco(prog->bloco);

    return errors == 0;
}

void AnalisadorSemantico::visitaBloco(Bloco* b) {
    if (!b) return;
    for (auto v : b->vars) visitaDeclVar(v);
    for (auto s : b->subrotinas) visitaDeclSub(s);
    for (auto c : b->comandos) visitaComando(c);
}

void AnalisadorSemantico::visitaDeclVar(DeclaracaoVar* d) {
    TipoDado tipo = mapType(d->tipo);
    for (const auto& nome : d->ids) {
        if (!tabela.insert(nome, CAT_VAR, tipo)) {
            error("Variavel '" + nome + "' ja declarada neste escopo.");
        }
    }
}

void AnalisadorSemantico::visitaDeclSub(DeclaracaoSub* d) {
    TipoDado tipoRetorno = TIPO_VAZIO;
    Categoria cat = CAT_PROC;

    if (d->tipoSub == TipoSubrotina::Function) {
        tipoRetorno = mapType(d->tipoRetorno);
        cat = CAT_FUNC;
    }

    std::vector<TipoDado> tiposParams;
    for (auto p : d->parametros) {
        TipoDado t = mapType(p->tipo);
        for (size_t i = 0; i < p->ids.size(); i++) {
            tiposParams.push_back(t);
        }
    }

    if (!tabela.insert(d->nome, cat, tipoRetorno, tiposParams)) {
        error("Subrotina '" + d->nome + "' ja declarada.");
    }

    tabela.enterScope();

    int param_offset = -5; 

    for (auto p : d->parametros) {
        TipoDado tParam = mapType(p->tipo);
        for (const auto& nomeParam : p->ids) {
            if (!tabela.insert(nomeParam, CAT_PARAM, tParam, {}, param_offset)) {
                error("Parametro '" + nomeParam + "' duplicado.");
            }
            param_offset--; 
        }
    }

    std::string func_antiga = nome_funcao_atual;
    TipoDado tipo_antigo = funcao_atual_tipo_retorno;
    bool retorno_antigo = retorno_encontrado;

    nome_funcao_atual = d->nome;
    funcao_atual_tipo_retorno = tipoRetorno;
    retorno_encontrado = false;

    if (d->corpo) {
        for (auto v : d->corpo->locais) visitaDeclVar(v);
        for (auto c : d->corpo->comandos) visitaComando(c);
    }

    if (cat == CAT_FUNC && !retorno_encontrado) {
        error("Funcao '" + d->nome + "' sem retorno definido.");
    }

    nome_funcao_atual = func_antiga;
    funcao_atual_tipo_retorno = tipo_antigo;
    retorno_encontrado = retorno_antigo;

    tabela.exitScope();
}

void AnalisadorSemantico::visitaComando(Comando* c) {
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

void AnalisadorSemantico::visitaAtribuicao(AtribuicaoCmd* c) {
    Simbolo* sym = tabela.lookup(c->id);
    if (!sym) {
        error("Variavel '" + c->id + "' nao declarada.");
        return;
    }

    TipoDado tipoExpr = visitaExpressao(c->expr);
    
    bool isReturn = (c->id == nome_funcao_atual && funcao_atual_tipo_retorno != TIPO_VAZIO);
    
    if (isReturn) {
        retorno_encontrado = true; 
    }

    if (sym->categoria != CAT_VAR && sym->categoria != CAT_PARAM && !isReturn) {
        error("Atribuicao invalida para '" + c->id + "'.");
    }


    if (tipoExpr != TIPO_DESCONHECIDO && sym->tipo != tipoExpr) {
        error("Tipo incompativel na atribuicao para '" + c->id + "'.");
    }
}

void AnalisadorSemantico::visitaChamadaProc(ChamadaProcedimentoCmd* c) {
    Simbolo* s = tabela.lookup(c->id);
    if (!s) {
        error("Procedimento '" + c->id + "' nao declarado.");
        return;
    }
    if (s->categoria != CAT_PROC) {
        error("'" + c->id + "' nao e um procedimento.");
        return;
    }

    if (c->args.size() != s->params.size()) {
        error("Chamada de procedimento com numero incorreto de argumentos.");
        return;
    }

    
    for (size_t i = 0; i < c->args.size(); i++) {
        TipoDado tArg = visitaExpressao(c->args[i]);
        if (tArg != TIPO_DESCONHECIDO && tArg != s->params[i]) {
            error("Tipo de argumento incompativel na chamada de '" + c->id + "'.");
        }
    }
}



TipoDado AnalisadorSemantico::visitaChamadaFunc(ChamadaFuncao* e) {
    Simbolo* s = tabela.lookup(e->id);
    if (!s) {
        error("Funcao '" + e->id + "' nao declarada.");
        return TIPO_DESCONHECIDO;
    }
    if (s->categoria != CAT_FUNC) {
        error("'" + e->id + "' nao e uma funcao.");
        return TIPO_DESCONHECIDO;
    }

    if (e->args.size() != s->params.size()) {
        error("Chamada de funcao com numero incorreto de argumentos.");
        return s->tipo; 
    }

    for (size_t i = 0; i < e->args.size(); i++) {
        TipoDado tArg = visitaExpressao(e->args[i]);
        if (tArg != TIPO_DESCONHECIDO && tArg != s->params[i]) {
            error("Tipo de argumento incompativel na chamada de '" + e->id + "'.");
        }
    }
    return s->tipo;
}

void AnalisadorSemantico::visitaIf(IfCmd* c) {
    TipoDado tCond = visitaExpressao(c->cond);
    if (tCond != TIPO_BOOL && tCond != TIPO_DESCONHECIDO) { 
        error("A condicao do IF deve ser booleana.");
    }
    visitaComando(c->thenCmd);
    if (c->elseCmd) visitaComando(c->elseCmd);
}

void AnalisadorSemantico::visitaWhile(WhileCmd* c) {
    TipoDado tCond = visitaExpressao(c->cond);
    if (tCond != TIPO_BOOL && tCond != TIPO_DESCONHECIDO) { 
        error("A condicao do WHILE deve ser booleana.");
    }
    visitaComando(c->corpo);
}

void AnalisadorSemantico::visitaLeitura(LeituraCmd* c) {
    for (const auto& id : c->ids) {
        Simbolo* s = tabela.lookup(id);
        if (!s) error("Variavel '" + id + "' nao declarada no READ.");
    }
}

void AnalisadorSemantico::visitaEscrita(EscritaCmd* c) {
    for (auto expr : c->exprs) {
        visitaExpressao(expr);
    }
}

void AnalisadorSemantico::visitaComandoComposto(ComandoComposto* c) {
    for (auto cmd : c->comandos) {
        visitaComando(cmd);
    }
}

TipoDado AnalisadorSemantico::visitaExpressao(Expressao* e) {
    if (!e) return TIPO_DESCONHECIDO;

    switch (e->tipo_expr) {
        case TipoExpressao::EXP_INT:
            return TIPO_INT;
        case TipoExpressao::EXP_BOOL:
            return TIPO_BOOL;
        case TipoExpressao::EXP_VAR:
            return visitaVar((VarExpr*)e);
        case TipoExpressao::EXP_BINARIA:
            return visitaBinaria((ExpressaoBinaria*)e);
        case TipoExpressao::EXP_UNARIA:
            return visitaUnaria((ExpressaoUnaria*)e);
        case TipoExpressao::EXP_CHAMADA:
            return visitaChamadaFunc((ChamadaFuncao*)e);
    }
    return TIPO_DESCONHECIDO;
}

TipoDado AnalisadorSemantico::visitaVar(VarExpr* e) {
    Simbolo* s = tabela.lookup(e->id);
    if (!s) {
        error("Variavel '" + e->id + "' nao declarada."); 
        return TIPO_DESCONHECIDO;
    }
    return s->tipo;
}

TipoDado AnalisadorSemantico::visitaBinaria(ExpressaoBinaria* e) {
    TipoDado t1 = visitaExpressao(e->esq);
    TipoDado t2 = visitaExpressao(e->dir);

    if (t1 == TIPO_DESCONHECIDO || t2 == TIPO_DESCONHECIDO) return TIPO_DESCONHECIDO;

    if (e->op == OperadorBinario::Add || e->op == OperadorBinario::Sub ||
        e->op == OperadorBinario::Mul || e->op == OperadorBinario::Div) {
        if (t1 != TIPO_INT || t2 != TIPO_INT) {
            error("Operacao aritmetica exige operandos inteiros.");
            return TIPO_DESCONHECIDO;
        }
        return TIPO_INT;
    }

    if (e->op == OperadorBinario::Equal || e->op == OperadorBinario::NotEqual ||
        e->op == OperadorBinario::Less || e->op == OperadorBinario::Greater ||
        e->op == OperadorBinario::LessEq || e->op == OperadorBinario::GreaterEq) {
        if (t1 != t2) {
            error("Operacao relacional exige operandos do mesmo tipo.");
            return TIPO_DESCONHECIDO;
        }
        return TIPO_BOOL;
    }

    if (e->op == OperadorBinario::And || e->op == OperadorBinario::Or) {
        if (t1 != TIPO_BOOL || t2 != TIPO_BOOL) {
            error("Operacao logica exige operandos booleanos.");
            return TIPO_DESCONHECIDO;
        }
        return TIPO_BOOL;
    }

    return TIPO_DESCONHECIDO;
}

TipoDado AnalisadorSemantico::visitaUnaria(ExpressaoUnaria* e) {
    TipoDado t = visitaExpressao(e->expr);
    
    if (t == TIPO_DESCONHECIDO) return TIPO_DESCONHECIDO;

    if (e->op == OperadorUnario::Not) {
        if (t != TIPO_BOOL) {
            error("'not' exige booleano.");
            return TIPO_DESCONHECIDO;
        }
        return TIPO_BOOL;
    }
    if (e->op == OperadorUnario::Negativo) {
        if (t != TIPO_INT) {
            error("'-' unario exige inteiro.");
            return TIPO_DESCONHECIDO;
        }
        return TIPO_INT;
    }
    return t;
}
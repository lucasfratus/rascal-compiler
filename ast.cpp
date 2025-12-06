#include "ast.hpp"
#include <iostream>

// funções para facilitar a impressao
static const char* tipoVarToStr(TipoVar t) {
    return (t == TipoVar::Integer) ? "integer" : "boolean";
}

static const char* valorBoolToStr(ValorBool v) {
    return (v == ValorBool::True) ? "true" : "false";
}

static const char* tipoSubrotinaToStr(TipoSubrotina t) {
    return (t == TipoSubrotina::Procedure) ? "procedure" : "function";
}

static const char* opBinToStr(OperadorBinario op) {
    switch (op) {
        case OperadorBinario::Equal:      return "=";
        case OperadorBinario::NotEqual:   return "<>";
        case OperadorBinario::Less:       return "<";
        case OperadorBinario::LessEq:     return "<=";
        case OperadorBinario::Greater:    return ">";
        case OperadorBinario::GreaterEq:  return ">=";
        case OperadorBinario::Add:        return "+";
        case OperadorBinario::Sub:        return "-";
        case OperadorBinario::Or:         return "or";
        case OperadorBinario::Mul:        return "*";
        case OperadorBinario::Div:        return "div";
        case OperadorBinario::And:        return "and";
    }
    return "?";
}

static const char* opUnToStr(OperadorUnario op) {
    switch (op) {
        case OperadorUnario::Negativo: return "-";
        case OperadorUnario::Not:      return "not";
    }
    return "?";
}


// Programa
void Programa::print(int ind) const {
    indent(ind);
    std::cout << "Programa: " << nome << "\n";
    if (bloco) {
        bloco->print(ind + 1);
    }
}

// Bloco

Bloco::~Bloco() {
    for (auto v : vars)       delete v;
    for (auto s : subrotinas) delete s;
    for (auto c : comandos)   delete c;
}


void Bloco::print(int ind) const {
    indent(ind);
    std::cout << "Bloco\n";

    if (!vars.empty()) {
        indent(ind + 1);
        std::cout << "Variaveis:\n";
        for (auto v : vars)
            v->print(ind + 2);
    }

    if (!subrotinas.empty()) {
        indent(ind + 1);
        std::cout << "Subrotinas:\n";
        for (auto s : subrotinas)
            s->print(ind + 2);
    }

    if (!comandos.empty()) {
        indent(ind + 1);
        std::cout << "Comandos:\n";
        for (auto c : comandos)
            c->print(ind + 2);
    }
}

// Declaracoes
void DeclaracaoVar::print(int ind) const {
    indent(ind);
    std::cout << "DeclaracaoVar: ";
    for (size_t i = 0; i < ids.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << ids[i];
    }
    std::cout << " : " << tipoVarToStr(tipo) << "\n";
}


DeclaracaoSub::~DeclaracaoSub() {
    for (auto p : parametros)
        delete p;
    delete corpo;
}


DeclaracaoSub::~DeclaracaoSub() {
    for (auto p : parametros)
        delete p;
    delete corpo;
}

void DeclaracaoSub::print(int ind) const {
    indent(ind);
    std::cout << "Subrotina (" << tipoSubrotinaToStr(tipoSub) << "): " << nome;

    if (tipoSub == TipoSubrotina::Function) {
        std::cout << " : " << tipoVarToStr(tipoRetorno);
    }
    std::cout << "\n";

    if (!parametros.empty()) {
        indent(ind + 1);
        std::cout << "Parametros:\n";
        for (auto p : parametros)
            p->print(ind + 2);
    }

    if (corpo) {
        indent(ind + 1);
        std::cout << "Corpo:\n";
        corpo->print(ind + 2);
    }
}

// Blocos
BlocoSub::~BlocoSub() {
    for (auto v : locais)   delete v;
    for (auto c : comandos) delete c;
}

void BlocoSub::print(int ind) const {
    indent(ind);
    std::cout << "BlocoSub\n";

    if (!locais.empty()) {
        indent(ind + 1);
        std::cout << "Variaveis Locais:\n";
        for (auto v : locais)
            v->print(ind + 2);
    }

    if (!comandos.empty()) {
        indent(ind + 1);
        std::cout << "Comandos:\n";
        for (auto c : comandos)
            c->print(ind + 2);
    }
}

// Comandos

void AtribuicaoCmd::print(int ind) const {
    indent(ind);
    std::cout << "Atribuicao: " << id << " :=\n";
    if (expr)
        expr->print(ind + 1);
}

void AtribuicaoCmd::print(int ind) const {
    indent(ind);
    std::cout << "Atribuicao: " << id << " :=\n";
    if (expr)
        expr->print(ind + 1);
}

ChamadaProcedimentoCmd::~ChamadaProcedimentoCmd() {
    for (auto e : args)
        delete e;
}

void ChamadaProcedimentoCmd::print(int ind) const {
    indent(ind);
    std::cout << "ChamadaProcedimento: " << id << "\n";
    if (!args.empty()) {
        indent(ind + 1);
        std::cout << "Argumentos:\n";
        for (auto e : args)
            e->print(ind + 2);
    }
}

IfCmd::~IfCmd() {
    delete cond;
    delete thenCmd;
    delete elseCmd;
}

void IfCmd::print(int ind) const {
    indent(ind);
    std::cout << "If\n";

    indent(ind + 1);
    std::cout << "Condicao:\n";
    if (cond) cond->print(ind + 2);

    indent(ind + 1);
    std::cout << "Then:\n";
    if (thenCmd) thenCmd->print(ind + 2);

    if (elseCmd) {
        indent(ind + 1);
        std::cout << "Else:\n";
        elseCmd->print(ind + 2);
    }
}

WhileCmd::~WhileCmd() {
    delete cond;
    delete corpo;
}

void WhileCmd::print(int ind) const {
    indent(ind);
    std::cout << "While\n";

    indent(ind + 1);
    std::cout << "Condicao:\n";
    if (cond) cond->print(ind + 2);

    indent(ind + 1);
    std::cout << "Corpo:\n";
    if (corpo) corpo->print(ind + 2);
}


void LeituraCmd::print(int ind) const {
    indent(ind);
    std::cout << "Read: ";
    for (size_t i = 0; i < ids.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << ids[i];
    }
    std::cout << "\n";
}


EscritaCmd::~EscritaCmd() {
    for (auto e : exprs)
        delete e;
}

void EscritaCmd::print(int ind) const {
    indent(ind);
    std::cout << "Write:\n";
    for (auto e : exprs)
        e->print(ind + 1);
}

// Expressoes
void VarExpr::print(int ind) const {
    indent(ind);
    std::cout << "Var: " << id << "\n";
}

void IntConstExpr::print(int ind) const {
    indent(ind);
    std::cout << "Int: " << valor << "\n";
}

void BoolConstExpr::print(int ind) const {
    indent(ind);
    std::cout << "Bool: " << valorBoolToStr(valor) << "\n";
}


void ExpressaoBinaria::print(int ind) const {
    indent(ind);
    std::cout << "ExprBinaria (" << opBinToStr(op) << ")\n";

    if (esq) {
        indent(ind + 1);
        std::cout << "Esq:\n";
        esq->print(ind + 2);
    }

    if (dir) {
        indent(ind + 1);
        std::cout << "Dir:\n";
        dir->print(ind + 2);
    }
}


void ExpressaoUnaria::print(int ind) const {
    indent(ind);
    std::cout << "ExprUnaria (" << opUnToStr(op) << ")\n";
    if (expr) expr->print(ind + 1);
}


ChamadaFuncao::~ChamadaFuncao() {
    for (auto e : args)
        delete e;
}

void ChamadaFuncao::print(int ind) const {
    indent(ind);
    std::cout << "ChamadaFuncao: " << id << "\n";
    if (!args.empty()) {
        indent(ind + 1);
        std::cout << "Argumentos:\n";
        for (auto e : args)
            e->print(ind + 2);
    }
}
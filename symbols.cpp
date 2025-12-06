#include "symbols.hpp"
#include <iostream>

TabelaDeSimbolos::TabelaDeSimbolos() {
    enterScope();
}

TabelaDeSimbolos::~TabelaDeSimbolos() {
    while (!scopes.empty()) {
        exitScope();
    }
}

void TabelaDeSimbolos::enterScope() {
    scopes.push_back(std::map<std::string, Simbolo*>());
    if (scopes.size() > 1) var_offset_local = 0;
}

void TabelaDeSimbolos::exitScope() {
    for (auto const& [key, val] : scopes.back()) {
        delete val;
    }
    scopes.pop_back();
}

bool TabelaDeSimbolos::insert(std::string name, Categoria cat, TipoDado type, std::vector<TipoDado> params) {
    if (scopes.back().count(name)) {
        return false; 
    }

    int offset = 0;
    if (scopes.size() == 1) { 
        offset = var_offset_global++;
    } else {
        offset = var_offset_local++;
    }

    Simbolo* sym = new Simbolo(name, cat, type, offset, params);
    scopes.back()[name] = sym;
    return true;
}

Simbolo* TabelaDeSimbolos::lookup(std::string name) {
    for (int i = scopes.size() - 1; i >= 0; i--) {
        if (scopes[i].count(name)) {
            return scopes[i][name];
        }
    }
    return nullptr;
}

void TabelaDeSimbolos::print() {
    std::cout << "=== Tabela de Simbolos (Escopo Atual) ===" << std::endl;
    for (auto const& [key, val] : scopes.back()) {
        std::cout << "Name: " << val->name << " | Type: " << val->tipo << " | Off: " << val->offset << std::endl;
    }
    std::cout << "=========================================" << std::endl;
}
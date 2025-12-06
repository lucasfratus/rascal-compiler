#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <string>
#include <map>
#include <vector>

enum Categoria { CAT_VAR, CAT_PARAM, CAT_PROC, CAT_FUNC, CAT_PROGRAM };
enum TipoDado { TIPO_INT, TIPO_BOOL, TIPO_VAZIO, TIPO_DESCONHECIDO };

struct Simbolo {
    std::string name;
    Categoria categoria;
    TipoDado tipo;
    int offset; // vai usar pra MEPA DEPOIS

    std::vector<TipoDado> params;

    Simbolo(std::string n, Categoria c, TipoDado t, int o = 0, std::vector<TipoDado> p = {}) 
        : name(n), categoria(c), tipo(t), offset(o), params(p) {}
};

class TabelaDeSimbolos{
private:
    std::vector<std::map<std::string, Simbolo*>> scopes;
    int var_offset_global = 0;
    int var_offset_local = 0;

public:
    TabelaDeSimbolos();
    ~TabelaDeSimbolos();

    void enterScope();
    void exitScope();
    
    bool insert(std::string name, Categoria cat, TipoDado type, std::vector<TipoDado> params = {});
    Simbolo* lookup(std::string name);

    void print();
};

#endif
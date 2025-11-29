#ifndef AST_H
#define AST_H
#include <string>
#include <vector>
#include <iostream>

enum TipoNo {
    NO_PROGRAMA,
    NO_BLOCO,
    NO_VAR_DECL,    
    NO_SUBROTINA, //procedimento/funcao
    NO_PARAM_LIST,
    NO_BEGINEND, // bloco de begin <...> end
    NO_ATRIB,
    NO_IF, // aqui vale pro if <...> then <...> else
    NO_WHILE, // vale p while <...> do
    NO_READ,
    NO_WRITE,
    NO_CHAMADA, // chamada de função/proc
    NO_OP_BINARIA,// vale pros +, -, *, div, and, or, <, >, =
    NO_OP_UNARIA, // not, - 
    NO_ID,
    NO_INT,
    NO_BOOL,
    NO_TIPO
};

struct No {
    TipoNo type;
    std::string valor;
    std::vector<No*> filhos; // usa vetor pq é dinamico, diferente dos arrays do c++

    No(TipoNo t, std::string v = "") : type(t), valor(v) {}

    // destrutor
    ~No() {
        for (auto filho : filhos) delete filho;
    }

    void addFilho(No* filho) {
        if (filho) filhos.push_back(filho);
    }

    // imprime a arvore
    void print(int nivel = 0);
};

#endif
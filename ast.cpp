#include "ast.h"

// converte o enum TipoNo em string pra facilitar ver nos prints
std::string nodeTypeToString(TipoNo type) {
    switch (type) {
        case NO_PROGRAMA: return "PROGRAMA";
        case NO_BLOCO: return "BLOCO";
        case NO_VAR_DECL: return "DECL_VAR";
        case NO_SUBROTINA: return "DECL_SUBROTINA";
        case NO_PARAM_LIST: return "LISTA_PARAM";
        case NO_BEGINEND: return "BEGIN_END";
        case NO_ATRIB: return "ATRIBUICAO";
        case NO_IF: return "IF";
        case NO_WHILE: return "WHILE";
        case NO_READ: return "READ";
        case NO_WRITE: return "WRITE";
        case NO_CHAMADA: return "CHAMADA";
        case NO_OP_BINARIA: return "OP_BIN";
        case NO_OP_UNARIA: return "OP_UN";
        case NO_ID: return "ID";
        case NO_INT: return "NUM";
        case NO_BOOL: return "BOOL";
        case NO_TIPO: return "TIPO";
        default: return "DESCONHECIDO";
    }
}

void No::print(int nivel) {
    // esse foir é p espaçar um pouco a cada nivel da arvore no print
    for (int i = 0; i < nivel; i++) std::cout << "  ";

    std::cout << nodeTypeToString(type);

    if (!valor.empty()) {
        std::cout << " (" << valor << ")";
    }
    std::cout << std::endl;

    for (auto filho : filhos) {
        filho->print(nivel + 1);
    }
}
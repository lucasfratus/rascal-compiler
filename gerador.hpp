#ifndef GERADOR_HPP
#define GERADOR_HPP

#include "ast.hpp"
#include "symbols.hpp"
#include <string>

class GeradorCodigo {
private:
    TabelaDeSimbolos tabela;
    int contador_geral;

    std::string newLabel();

public:
    GeradorCodigo();
    
    void gerar(Programa* prog);

    void visitaBloco(Bloco* b, bool is_subrotina = false, bool is_main = false);
    void visitaDeclSub(DeclaracaoSub* d);
    
    void visitaComando(Comando* c);
    void visitaAtribuicao(AtribuicaoCmd* c);
    void visitaIf(IfCmd* c);
    void visitaWhile(WhileCmd* c);
    void visitaLeitura(LeituraCmd* c);
    void visitaEscrita(EscritaCmd* c);
    void visitaChamadaProc(ChamadaProcedimentoCmd* c);
    void visitaComandoComposto(ComandoComposto* c);

    void visitaExpressao(Expressao* e);
    void visitaBinaria(ExpressaoBinaria* e);
    void visitaUnaria(ExpressaoUnaria* e);
    void visitaVar(VarExpr* e);
    void visitaConst(int val); // junta Int e Bool aqui
    void visitaChamadaFunc(ChamadaFuncao* e);
};

#endif
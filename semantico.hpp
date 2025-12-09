#ifndef SEMANTICS_HPP
#define SEMANTICS_HPP

#include "ast.hpp"
#include "symbols.hpp"
#include <string>
#include <vector>

class AnalisadorSemantico {
private:
    TabelaDeSimbolos tabela;
    int errors;

    std::string nome_funcao_atual; 
    TipoDado funcao_atual_tipo_retorno;

    bool retorno_encontrado;

    void error(const std::string& msg);
    TipoDado mapType(TipoVar t); 
    bool checkTypes(TipoDado t1, TipoDado t2); 

public:
    AnalisadorSemantico();
    ~AnalisadorSemantico() = default;

    bool analyze(Programa* prog);

    void visitaBloco(Bloco* b);
    void visitaDeclVar(DeclaracaoVar* d);
    void visitaDeclSub(DeclaracaoSub* d);
    
    void visitaComando(Comando* c);
    void visitaAtribuicao(AtribuicaoCmd* c);
    void visitaIf(IfCmd* c);
    void visitaWhile(WhileCmd* c);
    void visitaLeitura(LeituraCmd* c);
    void visitaEscrita(EscritaCmd* c);
    void visitaChamadaProc(ChamadaProcedimentoCmd* c);
    void visitaComandoComposto(ComandoComposto* c);

    TipoDado visitaExpressao(Expressao* e);
    TipoDado visitaBinaria(ExpressaoBinaria* e);
    TipoDado visitaUnaria(ExpressaoUnaria* e);
    TipoDado visitaVar(VarExpr* e);
    TipoDado visitaChamadaFunc(ChamadaFuncao* e);
};

#endif
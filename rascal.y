%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include "ast.hpp"
#include "semantico.hpp"
#include "gerador.hpp"
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

int yylex(void);

Programa* raiz = NULL;

%}
%define parse.error verbose

%code requires {
    #include "ast.hpp"
    #include <vector>
}

%union {
    int ival;
    char *sval;

    Programa* ptr_programa;
    Bloco* ptr_bloco;
    BlocoSub* ptr_bloco_sub;
    
    DeclaracaoVar* ptr_decl_var;
    std::vector<DeclaracaoVar*>* vec_decl_var;
    
    DeclaracaoSub* ptr_decl_sub;
    std::vector<DeclaracaoSub*>* vec_decl_sub;
    
    Comando* ptr_comando;
    std::vector<Comando*>* vec_comando;
    
    Expressao* ptr_expr;
    std::vector<Expressao*>* vec_expr;
    std::vector<std::string>* vec_str;
    
    TipoVar tipo_var;
    OperadorBinario op_bin;
}


%token <sval> ID
%token <ival> NUM


%token TK_PROGRAM TK_PROCEDURE TK_FUNCTION TK_VAR TK_BEGIN TK_END 
%token TK_INTEGER TK_BOOLEAN TK_FALSE TK_TRUE TK_WHILE TK_DO 
%token TK_IF TK_THEN TK_ELSE TK_READ TK_WRITE TK_AND TK_OR TK_NOT TK_DIV

%token TK_ABREPAR TK_FECHAPAR TK_PTVG TK_IGUAL TK_DIF TK_MENOR TK_MENOR_IG
%token TK_MAIOR TK_MAIOR_IG TK_ADD TK_SUB TK_MUL TK_ATRIB TK_DOISPT TK_VG TK_PT

%type <ptr_programa> programa
%type <ptr_bloco> bloco 
%type <ptr_bloco_sub> bloco_subrotina

%type <vec_decl_var> possivel_secao_variaveis secao_declaracao_variaveis lista_declaracao_variaveis 
%type <vec_decl_var> lista_declaracao_parametros
%type <vec_decl_var> possivel_parametros_formais parametros_formais

%type <ptr_decl_var> declaracao_tipada
%type <vec_str> lista_identificadores
%type <tipo_var> tipo

%type <vec_decl_sub> possivel_secao_subrotinas secao_declaracao_subrotinas lista_declaracao_subrotinas
%type <ptr_decl_sub> declaracao_subrotina declaracao_procedimento declaracao_funcao

%type <vec_comando> comando_composto lista_comandos
%type <ptr_comando> comando atribuicao condicional repeticao leitura escrita

%type <vec_expr> lista_expressoes lista_expressoes_nao_vazia
%type <ptr_expr> expressao expressao_simples termo fator variavel logico chamada_geral 
%type <op_bin> relacao

%nonassoc TK_THEN
%nonassoc TK_ELSE

%%
programa
    : TK_PROGRAM ID TK_PTVG bloco TK_PT 
    {
        raiz = new Programa($2, $4);
    }
    ;

bloco
    : possivel_secao_variaveis possivel_secao_subrotinas comando_composto
    {
        $$ = new Bloco();
        if ($1) $$->vars = *$1;
        if ($2) $$->subrotinas = *$2;
        if ($3) $$->comandos = *$3;
        
        delete $1; delete $2; delete $3;
    }
    ;

possivel_secao_variaveis
    : /* vazio */ 
    { 
        $$ = new std::vector<DeclaracaoVar*>(); 
    }
    | secao_declaracao_variaveis 
    { 
        $$ = $1; 
    }
    ;

secao_declaracao_variaveis
    : TK_VAR lista_declaracao_variaveis
    {
        $$ = $2;
    }
    ;

declaracao_tipada
    : lista_identificadores TK_DOISPT tipo 
    {
        $$ = new DeclaracaoVar($3, *$1);
        delete $1;
    }
    ;

lista_declaracao_variaveis
    : declaracao_tipada TK_PTVG 
    {
        $$ = new std::vector<DeclaracaoVar*>();
        $$->push_back($1);
    }
    | lista_declaracao_variaveis declaracao_tipada TK_PTVG 
    {
        $$ = $1;
        $$->push_back($2);
    }
    ;

lista_identificadores
    : ID 
    {
        $$ = new std::vector<std::string>();
        $$->push_back($1);
    }
    | lista_identificadores TK_VG ID 
    {
        $$ = $1;
        $$->push_back($3);
    }
    ;

tipo
    : TK_BOOLEAN { $$ = TipoVar::Boolean; }
    | TK_INTEGER { $$ = TipoVar::Integer; }
    ;

possivel_secao_subrotinas
    : /* vazio */ 
    { 
        $$ = new std::vector<DeclaracaoSub*>(); 
    }
    | secao_declaracao_subrotinas 
    { 
        $$ = $1; 
    }
    ;

secao_declaracao_subrotinas
    : lista_declaracao_subrotinas { $$ = $1; }
    ;

lista_declaracao_subrotinas
    : declaracao_subrotina TK_PTVG 
    {
        $$ = new std::vector<DeclaracaoSub*>();
        $$->push_back($1);
    }
    | lista_declaracao_subrotinas declaracao_subrotina TK_PTVG
    {
        $$ = $1;
        $$->push_back($2);
    }
    ;

declaracao_subrotina
    : declaracao_procedimento { $$ = $1; }
    | declaracao_funcao { $$ = $1; }
    ;

declaracao_procedimento
    : TK_PROCEDURE ID possivel_parametros_formais TK_PTVG bloco_subrotina 
    {
        $$ = new DeclaracaoSub($2, *$3, $5); 
        delete $3;
    }
    ;

possivel_parametros_formais
    : /* vazio */ { $$ = new std::vector<DeclaracaoVar*>(); }
    | parametros_formais { $$ = $1; }
    ;

parametros_formais
    : TK_ABREPAR lista_declaracao_parametros TK_FECHAPAR { $$ = $2; }
    ;

/* a estrutura de DeclaracaoVar ta servindo p parametros tbm */
lista_declaracao_parametros
    : declaracao_tipada 
    {
        $$ = new std::vector<DeclaracaoVar*>();
        $$->push_back($1);
    }
    | lista_declaracao_parametros TK_PTVG declaracao_tipada 
    {
        $$ = $1;
        $$->push_back($3);
    }
    ;


declaracao_funcao
    : TK_FUNCTION ID possivel_parametros_formais TK_DOISPT tipo TK_PTVG bloco_subrotina 
    {
        $$ = new DeclaracaoSub($2, *$3, $5, $7);
        delete $3;
    }
    ;

bloco_subrotina
    : possivel_secao_variaveis comando_composto 
    {
        $$ = new BlocoSub();
        if($1) $$->locais = *$1;
        if($2) $$->comandos = *$2;
        delete $1; delete $2;
    }
    ;

comando_composto
    : TK_BEGIN lista_comandos TK_END { $$ = $2; }
    ;

lista_comandos
    : comando 
    {
        $$ = new std::vector<Comando*>();
        $$->push_back($1);
    }
    | lista_comandos TK_PTVG comando 
    {
        $$ = $1;
        $$->push_back($3);
    }
    ;

comando
    : atribuicao { $$ = $1; }
    | chamada_geral {
        ChamadaFuncao* call = (ChamadaFuncao*)$1;
        
        $$ = new ChamadaProcedimentoCmd(call->id);
        ((ChamadaProcedimentoCmd*)$$)->args = call->args;
        call->args.clear();
        delete call; 
    }
    | condicional { $$ = $1; }
    | repeticao { $$ = $1; }
    | leitura { $$ = $1; }
    | escrita { $$ = $1; }
    | comando_composto 
    {
        $$ = new ComandoComposto(*$1); 
        delete $1;
    }
    ;

atribuicao
    : ID TK_ATRIB expressao 
    {
        $$ = new AtribuicaoCmd($1, $3);
    }
    ;


condicional
    : TK_IF expressao TK_THEN comando 
    {
        $$ = new IfCmd($2, $4, NULL);
    }
    | TK_IF expressao TK_THEN comando TK_ELSE comando 
    {
        $$ = new IfCmd($2, $4, $6);
    }
    ;

repeticao 
    : TK_WHILE expressao TK_DO comando 
    {
        $$ = new WhileCmd($2, $4);
    }
    ;

leitura
    : TK_READ TK_ABREPAR lista_identificadores TK_FECHAPAR 
    {
        $$ = new LeituraCmd(*$3);
        delete $3;
    }
    ;

escrita
    : TK_WRITE TK_ABREPAR lista_expressoes_nao_vazia TK_FECHAPAR 
    {
        $$ = new EscritaCmd();
        ((EscritaCmd*)$$)->exprs = *$3;
        delete $3;
    }
    ;

lista_expressoes_nao_vazia
    : expressao 
    {
        $$ = new std::vector<Expressao*>();
        $$->push_back($1);
    }
    | lista_expressoes_nao_vazia TK_VG expressao 
    {
        $$ = $1;
        $$->push_back($3);
    }
    ;

lista_expressoes
    : /* vazio */ { $$ = new std::vector<Expressao*>(); }
    | lista_expressoes_nao_vazia { $$ = $1; }
    ;

expressao
    : expressao_simples { $$ = $1; }
    | expressao_simples relacao expressao_simples 
    {
        $$ = new ExpressaoBinaria($2, $1, $3);
    }
    ;

relacao
    : TK_IGUAL      { $$ = OperadorBinario::Equal; }
    | TK_DIF        { $$ = OperadorBinario::NotEqual; }
    | TK_MENOR      { $$ = OperadorBinario::Less; }
    | TK_MENOR_IG   { $$ = OperadorBinario::LessEq; }
    | TK_MAIOR      { $$ = OperadorBinario::Greater; }
    | TK_MAIOR_IG   { $$ = OperadorBinario::GreaterEq; }
    ;

expressao_simples
    : termo { $$ = $1; }
    | TK_ADD termo { $$ = $2; /* Unario positivo eh ignorado ou tratado */ }
    | TK_SUB termo 
    { 
        $$ = new ExpressaoUnaria(OperadorUnario::Negativo, $2);
    }
    | expressao_simples TK_ADD termo 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::Add, $1, $3);
    }
    | expressao_simples TK_SUB termo 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::Sub, $1, $3);
    }
    | expressao_simples TK_OR termo 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::Or, $1, $3);
    }
    ;

termo
    : fator { $$ = $1; }
    | termo TK_MUL fator 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::Mul, $1, $3);
    }
    | termo TK_DIV fator 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::Div, $1, $3);
    }
    | termo TK_AND fator 
    {
        $$ = new ExpressaoBinaria(OperadorBinario::And, $1, $3);
    }
    ;

fator
    : variavel { $$ = $1; }
    | NUM { $$ = new IntConstExpr($1); }
    | logico { $$ = $1; }
    | chamada_geral { $$ = $1; }
    | TK_NOT fator 
    {
        $$ = new ExpressaoUnaria(OperadorUnario::Not, $2);
    }
    | TK_ABREPAR expressao TK_FECHAPAR { $$ = $2; }
    ;

variavel
    : ID { $$ = new VarExpr($1); }
    ;

logico
    : TK_FALSE { $$ = new BoolConstExpr(ValorBool::False); }
    | TK_TRUE  { $$ = new BoolConstExpr(ValorBool::True); } 
    ;

chamada_geral
    : ID TK_ABREPAR lista_expressoes TK_FECHAPAR 
    {
        ChamadaFuncao* call = new ChamadaFuncao($1);
        call->args = *$3;
        delete $3;
        $$ = call;
    }
    ;

%%

void yyerror(const char *s){
    printf("ERRO SINTÁTICO na linha %d: %s\n", yylineno, s);
}


int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Uso: ./rascal <arquivo_entrada.ras> <arquivo_saida.mepa>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror(argv[1]);
        return 1;
    }

    yyparse();
    
    if (yyin) fclose(yyin);

    if (raiz) {
        std::cout << "\nAST\n\n";
        raiz->print(0);
        std::cout << "\n"; 
        AnalisadorSemantico semantico;
        if (semantico.analyze(raiz)) {
            if (freopen(argv[2], "w", stdout) == NULL) {
                perror(argv[2]);
                delete raiz;
                return 1;
            }

            GeradorCodigo gerador;
            gerador.gerar(raiz);
            
            fclose(stdout);

        } else {
            std::cerr << "Erros semanticos encontrados. Compilacao abortada." << std::endl;
            delete raiz;
            return 1;
        }
        delete raiz;
    }
    return 0;
}
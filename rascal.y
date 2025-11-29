%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

int yylex(void);

No* raiz = NULL;

%}

%code requires {
    #include "ast.h"
}

%union {
    int ival;
    char *sval;
    No* node;
}

%token <sval> ID
%token <ival> NUM


%token TK_PROGRAM TK_PROCEDURE TK_FUNCTION TK_VAR TK_BEGIN TK_END 
%token TK_INTEGER TK_BOOLEAN TK_FALSE TK_TRUE TK_WHILE TK_DO 
%token TK_IF TK_THEN TK_ELSE TK_READ TK_WRITE TK_AND TK_OR TK_NOT TK_DIV

%token TK_ABREPAR TK_FECHAPAR TK_PTVG TK_IGUAL TK_DIF TK_MENOR TK_MENOR_IG
%token TK_MAIOR TK_MAIOR_IG TK_ADD TK_SUB TK_MUL TK_ATRIB TK_DOISPT TK_VG TK_PT

%type <node> programa bloco possivel_secao_variaveis secao_declaracao_variaveis
%type <node> declaracao_tipada lista_declaracao_variaveis lista_identificadores tipo
%type <node> possivel_secao_subrotinas secao_declaracao_subrotinas lista_declaracao_subrotinas
%type <node> declaracao_subrotina declaracao_procedimento declaracao_funcao
%type <node> possivel_parametros_formais parametros_formais lista_declaracao_parametros
%type <node> bloco_subrotina comando_composto lista_comandos comando
%type <node> atribuicao condicional repeticao leitura escrita
%type <node> lista_expressoes lista_expressoes_nao_vazia
%type <node> expressao expressao_simples termo fator variavel logico chamada_geral relacao

%nonassoc TK_THEN
%nonassoc TK_ELSE

%%
programa
    : TK_PROGRAM ID TK_PTVG bloco TK_PT 
    {
        raiz = new No(NO_PROGRAMA, $2);
        raiz->addFilho($4);
    }
    ;

bloco
    : possivel_secao_variaveis possivel_secao_subrotinas comando_composto
    {
        $$ = new No(NO_BLOCO);
        if($1) $$->addFilho($1);
        if($2) $$->addFilho($2);
        $$->addFilho($3);
    }
    ;

possivel_secao_variaveis
    : /* nada */ { $$ = NULL; }
    | secao_declaracao_variaveis { $$ = $1; }
    ;

secao_declaracao_variaveis
    : TK_VAR lista_declaracao_variaveis
    {
        $$ = $2;
    }
    ;

declaracao_tipada
    : lista_identificadores TK_DOISPT tipo {
        $$ = new No(NO_VAR_DECL, "grupo");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    ;

lista_declaracao_variaveis
    : declaracao_tipada TK_PTVG {
        $$ = new No(NO_VAR_DECL); 
        $$->addFilho($1); 
    }
    | lista_declaracao_variaveis declaracao_tipada TK_PTVG {
        $$ = $1;
        $$->addFilho($2);
    }
    ;

lista_identificadores
    :
    ID {
        $$ = new No(NO_ID, "LISTA_IDS");
        $$->addFilho(new No(NO_ID, $1));
    }
    | lista_identificadores TK_VG ID {
        $$ = $1;
        $$->addFilho(new No(NO_ID, $3));
    }
    ;

tipo
    : TK_BOOLEAN { $$ = new No(NO_TIPO, "boolean"); }
    | TK_INTEGER { $$ = new No(NO_TIPO, "integer"); }
    ;

possivel_secao_subrotinas
    :
    /* nada */ { $$ = NULL; }
    | secao_declaracao_subrotinas { $$ = $1; }
    ;

secao_declaracao_subrotinas
    : lista_declaracao_subrotinas { $$ = $1; }
    ;

lista_declaracao_subrotinas
    :
    declaracao_subrotina TK_PTVG {
        $$ = new No(NO_SUBROTINA, "LISTA_SUBROTINAS");
        $$->addFilho($1);
    }
    | lista_declaracao_subrotinas declaracao_subrotina TK_PTVG
    {
        $$ = $1;
        $$->addFilho($2);
    }
    ;

declaracao_subrotina
    :
    declaracao_procedimento { $$ = $1; }
    | declaracao_funcao { $$ = $1; }
    ;

declaracao_procedimento
    : TK_PROCEDURE ID possivel_parametros_formais TK_PTVG bloco_subrotina {
        $$ = new No(NO_SUBROTINA, $2);
        if($3) $$->addFilho($3);
        $$->addFilho($5);
    }
    ;

possivel_parametros_formais
    : /* nada */ { $$ = NULL; }
    | parametros_formais { $$ = $1; }
    ;

parametros_formais
    : TK_ABREPAR lista_declaracao_parametros TK_FECHAPAR { $$ = $2; }
    ;

lista_declaracao_parametros
    : declaracao_tipada { 
        $$ = new No(NO_PARAM_LIST, "PARAMETROS");
        $$->addFilho($1);
    }
    | lista_declaracao_parametros TK_PTVG declaracao_tipada {
        $$ = $1;
        $$->addFilho($3);
    }
    ;


declaracao_funcao
    : TK_FUNCTION ID possivel_parametros_formais TK_DOISPT tipo TK_PTVG bloco_subrotina {
        $$ = new No(NO_SUBROTINA, $2);
        if($3) $$->addFilho($3);
        $$->addFilho($5);
        $$->addFilho($7);
    }
    ;

bloco_subrotina
    : possivel_secao_variaveis comando_composto {
        $$ = new No(NO_BLOCO);
        if($1) $$->addFilho($1);
        $$->addFilho($2);
    }
    ;

comando_composto
    : TK_BEGIN lista_comandos TK_END { $$ = $2; }
    ;

lista_comandos
    : comando {
        $$ = new No(NO_BEGINEND, "BLOCO_COMANDOS");
        $$->addFilho($1);
    }
    | lista_comandos TK_PTVG comando {
        $$ = $1;
        $$->addFilho($3);
    }
    ;

comando
    : atribuicao { $$ = $1; }
    | chamada_geral { $$ = $1; }
    | condicional { $$ = $1; }
    | repeticao { $$ = $1; }
    | leitura { $$ = $1; }
    | escrita { $$ = $1; }
    | comando_composto { $$ = $1; }
    ;

atribuicao
    : ID TK_ATRIB expressao {
        $$ = new No(NO_ATRIB);
        $$->addFilho(new No(NO_ID, $1));
        $$->addFilho($3);
    }
    ;


condicional
    : TK_IF expressao TK_THEN comando {
        $$ = new No(NO_IF);
        $$->addFilho($2);
        $$->addFilho($4);
    }
    | TK_IF expressao TK_THEN comando TK_ELSE comando {
        $$ = new No(NO_IF);
        $$->addFilho($2);
        $$->addFilho($4);
        $$->addFilho($6);
    }
    ;

repeticao 
    : TK_WHILE expressao TK_DO comando {
        $$ = new No(NO_WHILE);
        $$->addFilho($2);
        $$->addFilho($4);
    }
    ;

leitura
    : TK_READ TK_ABREPAR lista_identificadores TK_FECHAPAR {
        $$ = new No(NO_READ);
        $$->addFilho($3);
    }
    ;

escrita
    : TK_WRITE TK_ABREPAR lista_expressoes_nao_vazia TK_FECHAPAR {
        $$ = new No(NO_WRITE);
        $$->addFilho($3);
    }
    ;

lista_expressoes_nao_vazia
    : expressao {
        $$ = new No(NO_PARAM_LIST, "LISTA_EXP");
        $$->addFilho($1);
    }
    | lista_expressoes_nao_vazia TK_VG expressao {
        $$ = $1;
        $$->addFilho($3);
    }
    ;

lista_expressoes
    : /* nada */ { $$ = NULL; }
    | lista_expressoes_nao_vazia { $$ = $1; }
    ;

expressao
    : expressao_simples { $$ = $1; }
    | expressao_simples relacao expressao_simples {
        $$ = $2;
        $$->addFilho($1);
        $$->addFilho($3);
    }
    ;

relacao
    : TK_IGUAL { $$ = new No(NO_OP_BINARIA, "="); }
    | TK_DIF { $$ = new No(NO_OP_BINARIA, "<>"); }
    | TK_MENOR { $$ = new No(NO_OP_BINARIA, "<"); }
    | TK_MENOR_IG { $$ = new No(NO_OP_BINARIA, "<="); }
    | TK_MAIOR { $$ = new No(NO_OP_BINARIA, ">"); }
    | TK_MAIOR_IG { $$ = new No(NO_OP_BINARIA, ">="); }
    ;

expressao_simples
    : termo { $$ = $1; }
    | TK_ADD termo {
        $$ = $2; 
    }
    | TK_SUB termo { 
        $$ = new No(NO_OP_UNARIA, "-");
        $$->addFilho($2);
    }
    | expressao_simples TK_ADD termo {
        $$ = new No(NO_OP_BINARIA, "+");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    | expressao_simples TK_SUB termo {
        $$ = new No(NO_OP_BINARIA, "-");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    | expressao_simples TK_OR termo {
        $$ = new No(NO_OP_BINARIA, "or");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    ;

termo
    : fator { $$ = $1; }
    | termo TK_MUL fator {
        $$ = new No(NO_OP_BINARIA, "*");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    | termo TK_DIV fator {
        $$ = new No(NO_OP_BINARIA, "div");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    | termo TK_AND fator {
        $$ = new No(NO_OP_BINARIA, "and");
        $$->addFilho($1);
        $$->addFilho($3);
    }
    ;

fator
    : variavel { $$ = $1; }
    | NUM { $$ = new No(NO_INT, std::to_string($1)); }
    | logico { $$ = $1; }
    | chamada_geral { $$ = $1; }
    | TK_NOT fator {
        $$ = new No(NO_OP_UNARIA, "not");
        $$->addFilho($2);
    }
    | TK_ABREPAR expressao TK_FECHAPAR { $$ = $2; }
    ;

variavel
    : ID { $$ = new No(NO_ID, $1); }
    ;

logico
    : TK_FALSE { $$ = new No(NO_BOOL, "false"); }
    | TK_TRUE { $$ = new No(NO_BOOL, "true"); } 
    ;

chamada_geral
    : ID TK_ABREPAR lista_expressoes TK_FECHAPAR {
        $$ = new No(NO_CHAMADA, $1);
        if($3) $$->addFilho($3);
    }
    ;


%%

/* Função de tratamento de erro */
void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO na linha %d: %s (próximo de '%s')\n", yylineno, s, yytext);
}

/* Função principal */
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Erro ao abrir arquivo %s\n", argv[1]);
            return 1;
        }
        extern FILE* yyin;
        yyin = file;
    }
    yyparse();

    /* Se a raiz foi gerada sem erros, imprime a arvere */
    if (raiz) {
        std::cout << "--- AST ---" << std::endl;
        raiz->print();
        delete raiz; 
    }

    return 0;
}
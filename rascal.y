%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char *s);

int yylex(void);

%}

%union {
    int ival;
    char *sval;
}

%token <sval> ID
%token <ival> NUM


%token TK_PROGRAM TK_PROCEDURE TK_FUNCTION TK_VAR TK_BEGIN TK_END 
%token TK_INTEGER TK_BOOLEAN TK_FALSE TK_TRUE TK_WHILE TK_DO 
%token TK_IF TK_THEN TK_ELSE TK_READ TK_WRITE TK_AND TK_OR TK_NOT TK_DIV

%token TK_ABREPAR TK_FECHAPAR TK_PTVG TK_IGUAL TK_DIF TK_MENOR TK_MENOR_IG
%token TK_MAIOR TK_MAIOR_IG TK_ADD TK_SUB TK_MUL TK_ATRIB TK_DOISPT TK_VG TK_PT

%nonassoc TK_THEN
%nonassoc TK_ELSE

%%
programa
    : TK_PROGRAM ID TK_PTVG bloco TK_PT 
    {

    }
    ;

bloco
    : possivel_secao_variaveis possivel_secao_subrotinas comando_composto
    {

    }
    ;

possivel_secao_variaveis
    : /* nada */ | secao_declaracao_variaveis
    {

    }
    ;

secao_declaracao_variaveis
    : TK_VAR lista_declaracao_variaveis
    ;

declaracao_tipada
    : lista_identificadores TK_DOISPT tipo
    ;

lista_declaracao_variaveis
    : declaracao_tipada TK_PTVG | lista_declaracao_variaveis declaracao_tipada TK_PTVG
    ;

lista_identificadores
    :
    ID | lista_identificadores TK_VG ID
    ;

tipo
    : TK_BOOLEAN | TK_INTEGER
    ;

possivel_secao_subrotinas
    :
    /* nada */ | secao_declaracao_subrotinas
    ;

secao_declaracao_subrotinas
    : lista_declaracao_subrotinas
    ;

lista_declaracao_subrotinas
    :
    declaracao_subrotina TK_PTVG | lista_declaracao_subrotinas declaracao_subrotina TK_PTVG
    ;

declaracao_subrotina
    :
    declaracao_procedimento | declaracao_funcao
    ;

declaracao_procedimento
    : TK_PROCEDURE ID possivel_parametros_formais TK_PTVG bloco_subrotina
    ;

possivel_parametros_formais
    : /* nada */ | parametros_formais
    ;

parametros_formais
    : TK_ABREPAR lista_declaracao_parametros TK_FECHAPAR
    ;

lista_declaracao_parametros
    : declaracao_tipada | lista_declaracao_parametros TK_PTVG declaracao_tipada
    ;


declaracao_funcao
    : TK_FUNCTION ID possivel_parametros_formais TK_DOISPT tipo TK_PTVG bloco_subrotina
    ;

bloco_subrotina
    : possivel_secao_variaveis comando_composto
    ;

comando_composto
    : TK_BEGIN lista_comandos TK_END
    ;

lista_comandos
    : comando | lista_comandos TK_PTVG comando
    ;

comando
    : atribuicao | chamada_geral | condicional | repeticao | leitura | escrita | comando_composto
    ;

atribuicao
    : ID TK_ATRIB expressao
    ;


condicional
    : TK_IF expressao TK_THEN comando | TK_IF expressao TK_THEN comando TK_ELSE comando
    ;

repeticao 
    : TK_WHILE expressao TK_DO comando 
    ;

leitura
    : TK_READ TK_ABREPAR lista_identificadores TK_FECHAPAR
    ;

escrita
    : TK_WRITE TK_ABREPAR lista_expressoes_nao_vazia TK_FECHAPAR
    ;

lista_expressoes_nao_vazia
    : expressao
    | lista_expressoes_nao_vazia TK_VG expressao
    ;

lista_expressoes
    : /* nada */
    | lista_expressoes_nao_vazia
    ;

expressao
    : expressao_simples | expressao_simples relacao expressao_simples
    ;

relacao
    : TK_IGUAL | TK_DIF | TK_MENOR | TK_MENOR_IG | TK_MAIOR | TK_MAIOR_IG
    ;

expressao_simples
    : termo | TK_ADD termo | TK_SUB termo| expressao_simples TK_ADD termo | 
    expressao_simples TK_SUB termo | expressao_simples TK_OR termo
    ;

termo
    : fator | TK_MUL fator | TK_DIV fator | TK_AND fator   
    ;

fator
    : variavel
    | NUM
    | logico
    | chamada_geral
    | TK_NOT fator
    | TK_ABREPAR expressao TK_FECHAPAR
    ;

variavel
    : ID
    ;

logico
    : TK_FALSE | TK_TRUE 
    ;

chamada_geral
    : ID TK_ABREPAR lista_expressoes TK_FECHAPAR
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
    return 0;
}
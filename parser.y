%{

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

%%
programa
    : TK_PROGRAM TK_ID TK_PTVG bloco TK_PT 
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

lista_declaracao_variaveis
    : declaracao_variaveis T_PTVG | lista_declaracao_variaveis declaracao_variaveis TK_PTVG
    ;

declaracao_variaveis
    :
    lista_identificadores TK_DOISPT tipo
    ;

lista_identificadores
    :
    TK_ID | lista_identificadores TK_VG TK_ID
    ;

tipo
    : TK_BOOLEAN | TK_INTEGER
    ;

possivel_secao_subrotinas
    :
    /* nada */ | secao_declaracao_subrotinas
    ;

lista_declaracao_subrotinas
    :
    declaracao_subrotina TK_PTVG | lista_declaracao_subrotinas declaracao_subrotina TK_PTVG
    ;

declaracao_subrotina
    :
    declaracao_procedimento TK_PTVG | declaracao_funcao TK_PTVG

declaracao_procedimento
    : TK_PROCEDURE TK_ID possivel_parametros_formais TK_PTVG bloco_subrotina
    ;

possivel_parametros_formais
    : /* nada */ | parametros_formais
    ;

parametros_formais
    : TK_ABREPAR lista_declaracao_parametros TK_FECHAPAR
    ;

lista_declaracao_parametros
    : declaracao_parametros | lista_declaracao_parametros TK_PTVG declaracao_parametros
    ;

declaracao_parametros
    : lista_identificadores TK_DOISPT tipo
    ;

declaracao_funcao
    : TK_FUNCTION TK_ID possivel_parametros_formais TK_DOISPT tipo TK_PTVG bloco_subrotina
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
    : atribuicao | chamada_procedimento | condicional | repeticao | leitura | escrita | comando_composto
    ;

atribuicao
    : TK_ID TK_ATRIB expressao
    ;

chamada_procedimento
    : TK_ID TK_ABREPAR lista_expressoes TK_FECHAPAR
    ;

condicional
    : TK_IF expressao TK_THEN comando | TK_IF expressao TK_THEN comando TK_ELSE comando
    ;
%%
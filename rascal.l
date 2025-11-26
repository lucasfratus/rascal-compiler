/* opções do flex */
%option noyywrap yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Inclui os tokens definidos no Bison */
#include "rascal.tab.h" 
%}

ESPACO  [ \t\r\n]+
ID      [a-zA-Z][a-zA-Z0-9_]*
NUM     [0-9]+[0-9]*

%%

"program" { return TK_PROGRAM; }
"procedure" { return TK_PROCEDURE; }
"function" { return TK_FUNCTION; }
"var" { return TK_VAR; }
"begin" { return TK_BEGIN; }
"end" { return TK_END; }
"integer" { return TK_INTEGER; }
"boolean" { return TK_BOOLEAN; }
"false" { return TK_FALSE; }
"true" { return TK_TRUE; }
"while" { return TK_WHILE; }
"do" { return TK_DO; }
"if" { return TK_IF; }
"then" { return TK_THEN; }
"else" { return TK_ELSE; }
"read"  { return TK_READ; }
"write" { return TK_WRITE; }
"and" { return TK_AND; }
"or" { return TK_OR; }
"not" { return TK_NOT; }
"div" { return TK_DIV; }

{NUM}               { yylval.ival = atoi(yytext); return NUM; }
{ID}                { yylval.sval = strdup(yytext); return ID; }

"("                 { return TK_ABREPAR; }
")"                 { return TK_FECHAPAR; }
";"                 { return TK_PTVG; }
":"                 { return TK_DOISPT; }
"."                 { return TK_PT; }
"="                 { return TK_IGUAL; }
"<>"                { return TK_DIF; }
"<"                 { return TK_MENOR; }
"<="                { return TK_MENOR_IG; }
">"                 { return TK_MAIOR; }
">="                { return TK_MAIOR_IG; }
"+"                 { return TK_ADD; }
"-"                 { return TK_SUB; }
"*"                 { return TK_MUL; }
","                 { return TK_VG; }
":="                { return TK_ATRIB; }

{ESPACO}            { /* ignora */ }

.                   { printf("ERRO LÉXICO na linha %d: símbolo ilegal %c\n", yylineno, yytext[0]); }

%%
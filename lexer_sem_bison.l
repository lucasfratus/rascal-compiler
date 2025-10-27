%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap yylineno

ESPACO  [ \t\r\n]+
ID      [a-zA-Z][a-zA-Z0-9_]*
NUM     [0-9]+(\.[0-9]+)?

%%

"program"   { printf("PROGRAM -> %s\n", yytext); }
"procedure" { printf("PROCEDURE -> %s\n", yytext); }
"function"  { printf("FUNCTION -> %s\n", yytext); }
"var"       { printf("VAR -> %s\n", yytext); }
"begin"     { printf("BEGIN -> %s\n", yytext); }
"end"       { printf("END -> %s\n", yytext); }
"integer"   { printf("INTEGER -> %s\n", yytext); }
"boolean"   { printf("BOOLEAN -> %s\n", yytext); }
"false"     { printf("FALSE -> %s\n", yytext); }
"true"      { printf("TRUE -> %s\n", yytext); }
"while"     { printf("WHILE -> %s\n", yytext); }
"do"        { printf("DO -> %s\n", yytext); }
"if"        { printf("IF -> %s\n", yytext); }
"then"      { printf("THEN -> %s\n", yytext); }
"else"      { printf("ELSE -> %s\n", yytext); }
"read"      { printf("READ -> %s\n", yytext); }
"write"     { printf("WRITE -> %s\n", yytext); }
"and"       { printf("AND -> %s\n", yytext); }
"or"        { printf("OR -> %s\n", yytext); }
"not"       { printf("NOT -> %s\n", yytext); }
"div"       { printf("DIV -> %s\n", yytext); }

{NUM}       { printf("NUM -> %s\n", yytext); }
{ID}        { printf("ID -> %s\n", yytext); }
{ESPACO}    { /* ignora */ }

"("         { printf("(\n"); }
")"         { printf(")\n"); }
";"         { printf(";\n"); }
":"         { printf(":\n"); }
"."         { printf(".\n"); }
"="         { printf("=\n"); }
"<>"        { printf("<>\n"); }
"<"         { printf("<\n"); }
"<="        { printf("<=\n"); }
">"         { printf(">\n"); }
">="        { printf(">=\n"); }
"+"         { printf("+\n"); }
"-"         { printf("-\n"); }
"*"         { printf("*\n"); }
","         { printf(",\n"); }
":="        { printf(":=\n"); }

.           { printf("ERRO LÉXICO na linha %d: símbolo ilegal '%c'\n", yylineno, yytext[0]); }

%%

int main(void) {
    yylex();
    return 0;
}

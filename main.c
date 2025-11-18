#include <stdio.h>
//#include "y.tab.h" // só se você tiver tokens definidos em um .y
// mas se estiver testando sozinho, pode comentar isso.

extern int yylex();
extern char *yytext;
extern int yylineno;

int main(void) {
    int token;
    while ((token = yylex())) {
        printf("Token: %d\tTexto: %s\tLinha: %d\n", token, yytext, yylineno);
    }
    return 0;
}
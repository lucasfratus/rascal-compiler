/* opções do flex */
%option noyywrap yylineno

ESPACO  [ \t\r\n]+
ID      [a-zA-Z][a-zA-Z0-9_]*
NUM     [0-9]+[0-9]*

%%

"program" { return PROGRAM; }
"procedure" { return PROCEDURE; }
"function" { return FUNCTION; }
"var" { return VAR; }
"begin" { return BEGIN; }
"end" { return END; }
"integer" { return INTEGER; }
"boolean" { return BOOLEAN; }
"false" { return FALSE; }
"true" { return TRUE; }
"while" { return WHILE; }
"do" { return DO; }
"if" { return IF; }
"then" { return THEN; }
"else" { return ELSE; }
"read"  { return READ; }
"write" { return WRITE; }
"and" { return AND; }
"or" { return OR; }
"not" { return NOT; }
"div" { return DIV; }

{NUM}               { yylval.dval = atof(yytext); return NUM; }
{ID}                { yylval.sval = strdup(yytext); return ID; }

"("                 { return '('; }
")"                 { return ')'; }
";"                 { return ';'; }
":"                 { return ':'; }
"."                 { return '.'; }
"="                 { return '='; }
"<>"                { return "<>"; }
"<"                 { return "<"; }
"<="                { return "<="; }
">"                 { return ">"; }
">="                { return ">="; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
","                 { return ','; }
":="                { return ':='; }

{ESPACO}            { /* ignora */ }

.                   { printf("ERRO LÉXICO na linha %d: símbolo ilegal %c\n", yylineno, yytext[0]); }

%%
lalr.y
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%{
void yyerror(const char *s);
int yylex();
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
 %%
 program:
 expr { printf("%d\n", $1); }
;
expr:
 expr '+' expr { $$ = $1 + $3; }
| expr '-' expr { $$ = $1 - $3; }
| expr '*' expr { $$ = $1 * $3; }
| expr '/' expr { $$ = $1 / $3; }
| '(' expr ')' { $$ = $2; }
| NUMBER { $$ = $1; }
%%
int main(int argc, char *argv[]) {
 yyparse();
 return 0;
}
void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
lalr.l
%{
#include "y.tab.h"
%}

%%

[ \t\n]+         /* ignore whitespace */
[0-9]+           { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]       { return yytext[0]; }

%%

int yywrap() {
    return 1;
}

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
COMMANDS TO EXECUTE THE CODE:
gedit lalr.l
lex lalr.l
gedit lalr.y
yacc -d lalr.y
gcc lex.yy.c y.tab.c -ll -lm
./a.out

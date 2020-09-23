%{
    // First lex assignment
    #include <stdio.h>
    #include <string.h>
    int i = 0;
%}
word   [a-zA-Z0-9]*

%%
{word} { i++; }
"\n" { printf("%d words detected!\n", i); i = 0;}
%%

int yywrap() {
    return 0;
}

int main() {
    yylex();
    return 0;
}

%{
// Remove tabs and spaces
%}

%%
[\n\t]+ { fprintf(yyout, ""); }
. { fprintf(yyout, "%s", yytext); }
%%

int yywrap () {
    return 0;
}

int main() {
    extern FILE *yyin, *yyout;
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    return 0;
}


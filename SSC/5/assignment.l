%{
    // First lex assignment
%}
letter [a-zA-Z]
number [0-9]
id     {letter}({letter}|{number})

%%
{id} { printf("ID detected: %s!", yytext); }
%%

int yywrap() {
    return 0;
}

int main() {
    yylex();
    return 0;
}

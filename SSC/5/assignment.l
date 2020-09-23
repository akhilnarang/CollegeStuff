%{
    // First lex assignment
%}
letter [a-zA-Z]
number [0-9]
id     {letter}({letter}|{number})

%%
{letter} { printf("Letter detected: %s\n", yytext); }
{number} { printf("Digit detected: %s\n", yytext); }
{id} { printf("ID detected: %s!\n", yytext); }
%%

int yywrap() {
    return 0;
}

int main() {
    yylex();
    return 0;
}

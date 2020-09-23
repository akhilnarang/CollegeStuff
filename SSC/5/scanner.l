
%{
#include<stdio.h>
%}

letter [a-zA-Z]
digit [0-9]
startblock [{]
endblock [}]
id ({letter}({letter}|{digit})*)
classname (({letter}|{digit})*)
quote \"
space [' ']
datatype (int|char|float|void)
keyword (class|throws|import|try|catch|finally|static|implements|main)
booleanvalues (true|false)
loops (while|for|do)
conditionalstmts (if|else|switch)
string ({quote}({letter}|{digit})+{quote})
array ({id}(\[))
usrfunction ({keyword}(\())
predefinedclass (Exception|String|Integer|Float|Character|ArithmaticException)
userdefinedclass (class{space}{classname})
predefinedfunction (main|println|Scanner|nextInt|next|nextLine)
package (import{space}{id}(\.{id})*(\.\*)?)
param ({string}|{digit}+|({digit}+\.{digit}+)|{id})
params (({param}(\,{param})*)?)
assignment ({id}\=({string}|{digit}+|({digit}+\.{digit}+)|new{space}(({datatype}(\[([0-9]{1,3})?\])*)|(({classname}|{predefinedclass})\({params}\)))))
operators ((\+\+)|(\-\-)|(\>\=)|(\<\=)|(\=\=)|(\!\=)|(\+\=))
accessspecifiers (public|private|protected)
%%

{accessspecifiers}      { printf("\n%s is access specifier\n", yytext); }
{package}               { printf("\n%s is a package\n", yytext) ;}
{operators}             { printf("\n%s is operator\n", yytext); }
{assignment}            { printf("\n%s is assignment\n", yytext); }
{predefinedclass}       { printf("\n%s is a predefined class\n", yytext); }
{booleanvalues}         { printf("\n%s is a boolean value\n", yytext); }
{conditionalstmts}      { printf("\n%s is a conditional stmt\n", yytext); }
{loops}                 { printf("\n%s is a loop\n", yytext); }
{keyword}               { printf("\n%s is a keyword\n", yytext); }
{predefinedfunction}    { printf("\n%s is predefined function\n", yytext); }
{usrfunction}           { printf("\n%s is a function\n", yytext); }
{array}                 { printf("\n%s is an array\n", yytext); }
{string}                { printf("\n%s is a string\n", yytext); }
{datatype}              { printf("\n%s is a datatype\n", yytext); }
{id}                    { printf("\n%s is an id\n", yytext); }
{startblock}            { printf("\n%s is the start of a block\n", yytext); }
{endblock}              { printf("\n%s is the end of a block\n", yytext); }
%%

int main()		
{
yyin=fopen("Sample.java","r");
yylex();
yywrap();
}

int yywrap()
{
return 1;
}





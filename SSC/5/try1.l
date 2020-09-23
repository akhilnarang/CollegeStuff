
%{
	#include<stdio.h>
%}
letter [a-zA-Z]
digit [0-9]
id ({letter}({letter}|{digit})*)
%%
{digit}+   {printf("digit is :%s",yytext);}
{id}       {printf("identifier is :%s",yytext);}
 .           { }
%%
 main()
{
        yylex();
	yywrap();

}

yywrap()
{
return 1;
}
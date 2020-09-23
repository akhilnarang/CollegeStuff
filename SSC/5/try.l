%{
#include<stdio.h>
int wcnt=0, lcnt=0, char_cnt=0;
%}

charac [^\n\t]
eol \n
word " "

%%

{eol} {lcnt++; wcnt++;}
{word} {wcnt++;}
{charac} {char_cnt++;}
 
%%
main()
{
	yyin=fopen("sample.txt","r");
	yylex();	
	printf("\n\nNumber of lines: %d",lcnt);
	printf("\nNumber of words: %d",wcnt);
	printf("\nNumber of characters: %d",char_cnt);
}
int yywrap()
{
	return 1;
}

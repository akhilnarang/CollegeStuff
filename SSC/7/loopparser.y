%{
#include<stdio.h>
extern int yylex();
extern int yywrap();
extern int yyparse();
%}

%token WHILE IF DO FOR OCB CCB OP CP CMP ASG OPR ID NUM SCOLON COMMA

%%
start: sif | nwhile | dowhile | swhile | nif;

swhile: WHILE OP cmplst CP stmt{printf("Single line while loop\n");};
nwhile: WHILE OP cmplst CP OCB stlst CCB{printf("Multi-line while loop\n");};
dowhile: DO OCB stlst CCB WHILE OP  CP SCOLON {printf("Do while loop\n");};
sif: IF OP cmplst CP stmt {printf("Single line If\n");};
nif: IF OP cmplst CP OCB stlst CCB {printf("Nested If\n");};

cmplst: cmpn COMMA cmplst
	| cmpn;

cmpn: ID CMP ID
	| ID CMP NUM;

stlst: stmt stlst
	| stmt;

stmt: ID ASG ID OPR ID SCOLON
      | ID ASG ID OPR NUM SCOLON
      | ID ASG NUM OPR ID SCOLON
      | ID ASG NUM OPR NUM SCOLON
      | ID ASG ID SCOLON
      | ID ASG NUM SCOLON
      | start {printf("NESTED INSIDE A");};

%%

#include "lex.yy.c"
int yyerror(char *str)
{
	printf("%s",str);
}

int main()
{
	yyparse();
}
/*
OUTPUT
while(a<10)

{

a = a * a;

}
Multi-line while loop

while(i==0) i = i + 1;
Single line while loop

while(i==0)

{

if(a>b)

{

if(a<5)

{

a = a + 1;

}
Nested If
NESTED INSIDE A
}
Nested If
NESTED INSIDE A
}
Multi-line while loop

*/

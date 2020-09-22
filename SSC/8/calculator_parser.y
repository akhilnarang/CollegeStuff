%{
	#include<stdio.h>
%}

%token NUM

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

Expr: E {
		printf("Valid Expression.\n");
		printf("Result = %d\n",$$);						//Displaying Result
		return 0;
	}

E: E'+'E {$$ = $1+$3;}
  |E'-'E {$$ = $1-$3;}
  |E'/'E {$$ = $1/$3;}
  |E'*'E {$$ = $1*$3;}
  |E'%'E {$$ = $1%$3;}
  |'('E')'{$$=$2;}
  |NUM {$$=$1;}
  ;
%%

int main()
{
	yyparse();
	return 0;
}
int yyerror()
{
	printf("Invalid Expression encountered!!\n");
}

/*
OUTPUT
5+7-2+3
Valid Expression.
Result = 13
*/

%{
%}

%%
"while" {return WHILE;}
"if" {return IF;}
"do" {return DO;}
"for" {return FOR;}
"{" {return OCB;}
"}" {return CCB;}
"(" {return OP;}
")" {return CP;}

">" |
">=" |
"<" |
"<=" |
"==" |
"!=" {return CMP;}

"=" {return ASG;}

"+" |
"-" |
"*" |
"/" {return OPR;}


([a-zA-Z])("_"|[a-zA-Z0-9])* {return ID;}
[0-9]+ {return NUM;}
";" {return SCOLON;}
"," {return COMMA;}
" " {}

%%
int yywrap()
{
	return 1;
}
%{
    #include <stdio.h>
%}

ID [a-z][a-zA-Z]?[a-zA-Z]?

%%

"string"|"char"         {printf("< Keyword , %s >\n",yytext);}
{ID}                    {printf("< ID , %s >\n",yytext);}
"+"|"-"|"="|"?"|"<->"   {printf("< Relop , %s >\n",yytext);}
[ \t]                   {}
.                       {printf("<Invalid Token : %s >\n",yytext);}

%%

int yywrap(){}

int main()
{
    yylex();
    return 0;
}
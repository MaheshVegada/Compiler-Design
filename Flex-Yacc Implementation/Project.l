%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%%

string 	{printf("\n--> VALID TOKENS <--\n< Keyword , string>\n");return SDT;}
char 	{printf("\n--> VALID TOKENS <--\n< Keyword , char>\n");return CDT;}
int 	{printf("\n--> VALID TOKENS <--\n< Keyword , int>\n");return IDT;}
"+"     {printf("< Relop , + >\n");return SOP;}
"-"     {printf("< Relop , - >\n");return SOP;}
"<->"	{printf("< Relop , <-> >\n");return SOP;}
\? 		{printf("< Relop , ? >\n");return IOP;}
= 		{printf("< Assop , = >\n");return ASSGN;}
\'		{printf(" < Single Quote , ' >\n");return SINGLE;}
\" 		{printf("< Double Quote , \" >\n");return DOUBLE;}
;       {return SEMICOLON;}
\n 		{return NEWLINE;}

[a-z][a-zA-Z]?[a-zA-Z]?  {printf("< ID , %s >\n",yytext);return VAR;}
[A-Z] 				     {printf(" < CharValue , %s >\n",yytext);return VALCHAR;}
[a-zA-Z0-9]+ 			 {printf("< StringValue , %s >\n",yytext);return VALSTR;}

%%

int yywrap(void)
{
    return 1;
}
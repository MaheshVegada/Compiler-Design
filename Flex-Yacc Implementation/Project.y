%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include "y.tab.h"
    extern int yylex();
    extern int yyparse(void);
    extern int yyerror(char *s);
    int flag=0;
    char s[100]="\n--> 3 ADDRESS CODE <--\n";
%}

%token SEMICOLON NEWLINE SDT CDT IDT SOP IOP ASSGN SINGLE DOUBLE VAR VALSTR VALCHAR

%%
start : expr SEMICOLON NEWLINE {
            printf("\n--> CORRECT SYNTAX <--");
            if(flag==1) printf("\nValid String Declaration\n");
            else if(flag==2) printf("\nValid Char Declaration\n");
            else if(flag==3) printf("\nValid String Operation with Variable\n");
            else if(flag==4) {
                            printf("\nValid String Operation with Value\n");
                            printf("\n--> 3 Address Code <--\nT1 = \"value1\"\n");
                            printf("T2 = \"value2\"\nT3 = T1 operand T2\nvarname = T3\n");
                            strcpy(s,"");
                        }
            else if(flag==5) printf("\nValid String Assignment\n");
            else if(flag==6) printf("\nValid Char Assignment\n");
            else if(flag==6) printf("\nValid Char Assignment\n");
            else if(flag==7) printf("\nValid Position(?) Operation\n");
            flag=0;
            printf("%s\n",s);
            strcpy(s,"\n--> 3 ADDRESS CODE <--\n");
            return 0;
        }

expr : SDT VAR str  
    | CDT VAR char                    
    | IDT VAR int   

str : ASSGN rhsstring {strcat(s,"varname = T");}
    |   {strcat(s,"No 3 Address Code");flag=1;}

char :  ASSGN rhschar {strcat(s,"varname = T");}
    |   {strcat(s,"No 3 Address Code");flag=2;}

int : ASSGN rhsint {strcat(s,"pos = T");}

rhsstring : VAR SOP VAR    {strcat(s,"T = varname operand varname\n");flag=3;}
    | DOUBLE VALSTR DOUBLE rhsstring1   {strcat(s,"T = \"value\"\n");}

rhsstring1 : SOP DOUBLE VALSTR DOUBLE    {flag=4;}
    |        {flag=5;}

rhschar : SINGLE VALCHAR SINGLE     {strcat(s,"T = 'charvalue'\n");flag=6;}

rhsint : VAR IOP VAR    {strcat(s,"T = varname1 ? varname2\n");flag=7;}

%%

int main()
{
    yyparse();
}

int yyerror(char *str)
{
    fprintf(stderr,"--> %s <--\n",str);
    exit(0);
}
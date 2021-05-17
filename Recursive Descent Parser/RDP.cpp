#include <iostream>
#include <stdlib.h>
using namespace std;

int i;
string expr;
void E();
void EM();
void T();
void TM();
void F();


int main()
{
    cout << "\nGRAMMAR:\nE-> TE'\nE'-> +TE'|-TE'|^\nT-> FT'\n";
    cout << "T'-> *FT'|/FT'|^\nF-> id|num|(E)\n\n";
    while(true){
    	cout << "Enter the String: ";
	    cin >> expr;
	    int l = expr.length();
	    expr += "$";
        i = 0;
	    E();
	    if (l == i)
	        cout << "String Accepted\n\n";
	    else
	        cout << "String Rejected\n\n";
	}
}

void E()
{
    T();
    EM();
}

void EM()
{
    if (expr[i] == '+') {
        i++;
        T();
        EM();
    }
    else if (expr[i] == '-') {
        i++;
        T();
        EM();
    }
}

void T()
{
    F();
    TM();
}

void TM()
{
    if (expr[i] == '*') {
        i++;
        F();
        TM();
    }
    else if (expr[i] == '/') {
        i++;
        F();
        TM();
    }
}

void F()
{
    if (isdigit(expr[i]))
        i++;
    
    else if (isalpha(expr[i]))
        i++;

    else if (expr[i] == '(') {
        i++;
        E();
        if (expr[i] != ')') {
            cout << "String Rejected\n\n";
            exit(0);
        }
        i++;
    }
    else {
        cout << "String Rejected\n\n";
        exit(0);
    }
}

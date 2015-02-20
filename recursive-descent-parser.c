//recursive descent parser for
// E->TE'
// E'->+TE'
// T->FT'
// T'->*FT'
// F->(E)/a
// a,(,) are terminals

#include <stdio.h>
void E(); //fn for E
void T(); //fn for T
void F(); //fn for F
void Td(); //fn for T'
void Ed(); //fn for E'
int isAlpha(char c); //fn to check if terminal is alphabet
void error(); //fn to display error message
char ip[12]; //string for input
int ptr = 0; //pointer for string

int main()
{
        printf("Enter expression:");
        scanf("%s",ip);
        E(); //call start symbol fn
        printf("\nValid expression");
        return 0;
}

void E() //E->TE'
{
        T();
        Ed();
}

void Ed() //E'->+TE'
{
        if(ip[ptr] == '+')
        {
                ptr++;
                T();
                Ed();
        }
        else if(isAlpha(ip[ptr])) //if it's an alphabet at the wrong place
                error();
}

void T() //T->FT'
{
        F();
        Td();
}

void Td() //T'->*FT'
{
        if(ip[ptr] == '*')
        {
                ptr++;
                F();
                Td();
        }
        else if(isAlpha(ip[ptr])) //if it's an alphabet at the wrong place
                error();
}

void F() //F->(E)/a
{
        if(ip[ptr] == '(')
        {
                ptr++;
                E();
                if(ip[ptr] == ')')
                        ptr++;
                else
                        error();
        }
        else
        {
                if(isAlpha(ip[ptr])) //terminal
                        ptr++;
                else
                        error();
        }
}
int isAlpha(char c)
{
        return (c>='a' && c<='z');
}

void error()
{
        printf("\nInvalid Expression");
        exit(0);
}

//program to find the first of a given grammar

#include <stdio.h>
#include <string.h>

int isUpper(char); //fn to test if a character is a non-terminal (Capitalized)

char str[10][10]; //array of strings

int main()
{
    int n, i, j;
    char nonterminal; //to store the non-terminal
    printf("Enter the number of productions: "); //number of productions
    scanf("%d", &n);
    printf("Enter the productions in format A->aBc\n"); //productions in specific format
    for (i = 0; i < n; i++) //scan input
        scanf("%s", &str[i]);
    for (i = 0; i < n; i++)
    {
        nonterminal = str[i][0]; //store nonterminal
        if (isUpper(str[i][3])) //str[i][3] is the first character in the production, if it is a nonterminal then do
        {
repeat: //repeat for goto statement
            for (j = 0; j < n; j++)
            {
                if (str[j][0] == str[i][3]) //check if any other production has lhs equal to current nonterminal
                {
                    if (isUpper(str[j][3])) //if that production has first character as nonterminal
                    {
                        i = j;
                        goto repeat; //using goto we repeat till we encounter terminal
                    }
                    else
                        printf("First(%c) = %c\n", nonterminal, str[j][3]); //found a terminal, print
                }
            }
        }
        else
            printf("First(%c) = %c\n", nonterminal, str[i][3]); //first char is itself, terminal. print
    }
    return 0;
}

int isUpper(char ch)
{
    return ( 'A' <= ch & 'Z' >= ch); //returns true if ch is a capital letter
}


/*
O/P:
Enter the number of productions: 3
Enter the productions in format A->aBc
A->aB
B->C
C->d
First(A) = a
First(B) = d
First(C) = d
*/

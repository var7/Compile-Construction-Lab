//program to find the first of a given grammar

#include <stdio.h>
#include <string.h>

int isUpper(char);

char str[10][10];

int main()
{
        int n, i, j;
        char nonterminal;
        printf("Enter the number of productions: ");
        scanf("%d", &n);
        printf("Enter the productions in format A->aBc\n");
        for (i = 0; i < n; i++)
                scanf("%s", &str[i]);
        for (i = 0; i < n; i++)
        {
                nonterminal = str[i][0];
                if(isUpper(str[i][3]))
                {
                        repeat:
                        for(j = 0; j < n; j++)
                        {
                                if(str[j][0] == str[i][3])
                                {
                                        if(isUpper(str[j][3]))
                                        {
                                                i = j;
                                                goto repeat;
                                        }
                                        else
                                                printf("First(%c) = %c\n", nonterminal,str[j][3]);
                                }
                        }
                }
                else
                        printf("First(%c) = %c\n", nonterminal, str[i][3]);
        }
        return 0;
}

int isUpper(char ch)
{
        return ( 'A' <= ch & 'Z' >= ch);
}

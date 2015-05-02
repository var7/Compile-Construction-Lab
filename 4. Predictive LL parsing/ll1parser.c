
#include <stdio.h>

#include <string.h>

#include <stdlib.h>


char prod[10][20], start[2];

char nonterm[10], term[10];

char input[10], stack[50];

int table[10][10];

int te, nte;

int n;

void firsti();
void parse();

int main()

{

    firsti();

    parse();


}



void firsti()

{

    int i, j;
    printf("NOTE:\n");
    printf("The terminals should be entered in single lower case letters,special symbol and\n");
    printf("non-terminals should be entered in single upper case letters.\n");
    printf("extends to symbol is '->' and epsilon symbol is '@' \n");

    printf("\nEnter the no. of terminals:");
    scanf("%d", &te);

    printf("\nEnter the terminals without space in a line:\n");
    scanf("%s", term);
    term[te] = '$';
    //printf("%s",term);

    printf("\nEnter the no. of non terminals:");
    scanf("%d", &nte);

    printf("\nEnter the non terminals without space in a line:\n");
    scanf("%s", nonterm);

    printf("\nEnter the no. of productions:");
    scanf("%d", &n);

    printf("\nEnter the productions");
    i = 0;
    while (i < n)
    {
        printf("%d :", i + 1);
        scanf("%s", prod[i]);
        i++;
    }

    fflush(stdin);
    fflush(stdout);
    start[0] = nonterm[0];
    printf("Start symbol is %c", start[0]);

    printf("\nEnter the input string without $:");
    scanf("%s", input);

    input[strlen(input)] = '$';
    printf("\n\nThe productions are:");
    printf("\nProductionNo. Production");
    for (i = 0; i < n; i++)
        printf("\n %d           %s", i + 1, prod[i]);

    printf("\n\nEnter the parsing table:");
    printf("\nEnter the production number in the required entry as mentioned above.");
    printf("\nEnter the undefined entry or error of table as '0'\n\n");

    for (i = 0; i < nte; i++)
    {
        for (j = 0; j <= te; j++)
        {
            printf("Entry of table[%c,%c]:", nonterm[i], term[j]);
            scanf("%d", &table[i][j]);
        }
    }
}

void parse()
{
    int i, j, prodno;
    int top = -1, current = 0;
    stack[++top] = '$';
    stack[++top] = start[0];
    do
    {
        if ((stack[top] == input[current]) && (input[current] == '$'))
        {
            printf("\nThe given input string is parsed\n");
            //getch();
            exit(0);
        }
        else if (stack[top] == input[current])
        {
            top--;
            current++;
        }
        else if (stack[top] >= 'A' && stack[top] <= 'Z')
        {
            for (i = 0; i < nte; i++)
                if (nonterm[i] == stack[top]) break;
            for (j = 0; j <= te; j++)
                if (term[j] == input[current]) break;
            prodno = table[i][j];
            if (prodno == 0)
            {
                printf("\nThe given input string is not parsed\n");
                //getch();
                exit(0);
            }
            else
            {
                for (i = strlen(prod[prodno - 1]) - 1; i >= 3; i--)
                {
                    if (prod[prodno - 1][i] != '@')
                        stack[top++] = prod[prodno - 1][i];
                }
                top--;
            }
        }
        else
        {
            printf("\nThe given input string is not parsed\n");
            //getch();
            exit(0);
        }
    } while (1);
}

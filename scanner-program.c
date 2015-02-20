#include <stdio.h>

int main()
{
        FILE *fp1, *fp2; //file pointers for input and output file
        char buff[255], ch; 
        int lineno = 1; //variable for line number
        int tokenno = 0; //variable to maintain token number
        char arithop[] = "Arithmetic Operator"; //string to display arithmetic operator
        char assignop[] = "Assignment Operator"; //string to display assignment operator
        char delim[] = "Delimiter"; //string to display delimiter
        char compare[] = "Comparision Operator"; //string to display comparision operator

        fp1 = fopen("test.txt","r"); //open input file in read mode
        fp2 = fopen("result.txt","w"); //open output file in write mode

        fprintf(fp2, "Line no\t\t Token no\t\t Token\t\t\t Lexeme\n"); //print the top line in the output file

        while((ch=fgetc(fp1))!=EOF) //loop till all characters in input file are exhausted
        {
                if(ch == '\n') //if it's a new line, increment line number and continue
                {
                        lineno++; 
                        continue;
                }
                else if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%') //if it's an arithmetic operator, increment token number and printf in output file
                {
                        tokenno++;
                        fprintf(fp2,"%d\t\t %d\t\t %s\t\t %c\n",lineno, tokenno, arithop, ch);
                        continue;
                }
                else if(ch == '=') //if it's equals sign, firsth check if next char is also equals
                {
                        tokenno++; //increment token number
                        if((ch=fgetc(fp1)) == '=') //if next char also equals, then comparision op, else  assignment op
                        {
                                fprintf(fp2,"%d\t\t %d\t\t %s\t\t ==\n",lineno, tokenno, compare);
                        }
                        else
                        {
                                fprintf(fp2,"%d\t\t %d\t\t %s\t\t =\n",lineno, tokenno, assignop);
                                ungetc(ch,fp1);
                        }
                        continue;
                }
                else if(ch == ';') //if it's a delimiter, increment token number and printf in output file
                {
                        tokenno++;
                        fprintf(fp2,"%d\t\t %d\t\t %s\t\t\t %c\n",lineno, tokenno, delim, ch);
                        continue;
                }

        }

        fclose(fp1); //close input file pointer
        fclose(fp2); //close output file pointer

        return 0;
}

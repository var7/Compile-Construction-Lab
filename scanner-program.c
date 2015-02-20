#include <stdio.h>

int main()
{
        FILE *fp1, *fp2;
        char buff[255], ch;
        int lineno = 1;
        int tokenno = 0;
        char arithop[] = "Arithmetic Operator";
        char assignop[] = "Assignment Operator";
        char delim[] = "Delimiter";
        char compare[] = "Comparision Operator";

        fp1 = fopen("test.txt","r");
        fp2 = fopen("result.txt","w");

        fprintf(fp2, "Line no\t\t Token no\t\t Token\t\t\t Lexeme\n");

        while((ch=fgetc(fp1))!=EOF)
        {
                if(ch == '\n')
                {
                        lineno++;
                        continue;
                }
                else if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%')
                {
                        tokenno++;
                        fprintf(fp2,"%d\t\t %d\t\t %s\t\t %c\n",lineno, tokenno, arithop, ch);
                        continue;
                }
                else if(ch == '=')
                {
                        tokenno++;
                        if((ch=fgetc(fp1)) == '=')
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
                else if(ch == ';')
                {
                        tokenno++;
                        fprintf(fp2,"%d\t\t %d\t\t %s\t\t\t %c\n",lineno, tokenno, delim, ch);
                        continue;
                }

        }

        fclose(fp1);
        fclose(fp2);

        return 0;
}

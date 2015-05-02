%{
  //program to convert from upper case to lower case and from lower case to upper case
  #include <stdio.h>
  #include <ctype.h>
  int k;
  void up(char *);
  void low(char *);
%}
letter [a-z]
upper [A-Z]
%%
{letter} {up(yytext);}
{upper} {low(yytext);}
%%
int main()
{
  yylex();
}
void up(char *s)
{
  int i;
  for(i=0;s[i]!='\0';i++)
    printf("%c", toupper(s[i]));
}
void low(char *s)
{
  int i;
  for(i=0;s[i]!='\0';i++)
    printf("%c", tolower(s[i]));
}
int yywrap()
{
  return 1;
}

/*
O/P:
lex upperlower.l
cc lex.yy.c
./a.out
abCDEfgHiJ
ABcdeFGhIj
*/

%{
 // program to check if number is integer or float
%}
Float [0-9]*\.[0-9]+([eE][+]?[0-9]+)?
Int [0-9]+
%%
{Float} printf("this is a floating point number");
{Int} printf("this is an Integer");
%%
int main()
{
  yylex();
}
int yywrap()
{
  return 1;
}

/* 
O/P:
lex intfloat.l
cc lex.yy.c
./a.out
123
this is an Integer
123.789
this is a floating point number
123.789e1011
this is a floating point number
*/

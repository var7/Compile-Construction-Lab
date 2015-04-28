%{
  //Program to check if a number is a hex or octal
%}
Oct [0][0-9]+
Hex [0][x|X][0-9A-Fa-f]+
Bin [0][b][1|0]+
%%
{Hex} printf("this is a hexadecimal number");
{Oct} printf("this is an octal number");
{Bin} printf("this is a binary number");
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
lex octhex.l
cc lex.yy.c
./a.out
o5
this is an octal number
ox23
this is a hexadecimal number
*/

%{
  //Program to check if a number is a hex or octal
%}
Oct [o][0-9]+
Hex [o][x|X][0-9A-Fa-f]+
%%
{Hex} printf("this is a hexadecimal number");
{Oct} printf("this is an octal number");
%%
main()
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

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

%{

#include<stdio.h>

%}

%token DIGIT

%%

S    : E '\n' {printf("%d\n",$1);return 1;}

    ;

E    : E '+' T    { $$ = $1 + $3 ; }

    | T

    ;

T    : T '*' F    { $$ = $1 * $3; }

    | F

    ;

F    : '(' E ')'    { $$=$2; }

    | DIGIT

    ;

%%

int yylex(){

int c;

c=getchar();

if(isdigit(c))

{

    yylval=c-'0';

    return DIGIT;

}

return c;

}

int main()

{

printf("Enter the exp:");

yyparse();

return 0;

}

int yywrap()

{

return 1;

}

yyerror (char const *s)

{

  fprintf (stderr, "%s\n", s);

}


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
%}

%token UPPER DIGIT

%%

statement: UPPER sequence {
    printf("Accepted\n");
    exit(0);
}
| error {
    yyerror("Rejected\n");
    exit(0);
}
;

sequence: sequence UPPER
| sequence DIGIT
| UPPER
| DIGIT
;

%%

int main() {
    printf("Enter a statement: ");
    yyparse();
}

int yylex() {
    char ch;
    while ((ch = getchar()) == ' ');

    if (isupper(ch))
        return UPPER;

    if (isdigit(ch))
        return DIGIT;

    return ch;
}

void yyerror(char *s) {
    printf("");
}

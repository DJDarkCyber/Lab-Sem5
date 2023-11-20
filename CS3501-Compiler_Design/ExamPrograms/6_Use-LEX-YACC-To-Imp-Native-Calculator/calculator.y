%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);

%}

%token NUMBER
%token EOL

%%

program: /* empty */
       | program expression EOL { printf("Result: %d\n", $2); }
       ;

expression: NUMBER
          | expression '+' expression { $$ = $1 + $3; }
          | expression '-' expression { $$ = $1 - $3; }
          | expression '*' expression { $$ = $1 * $3; }
          | expression '/' expression { 
                                        if ($3 == 0) {
                                            yyerror("Error: Division by zero\n");
                                            $$ = 0; // Returning a default value
                                        } else {
                                            $$ = $1 / $3;
                                        }
                                      }
          | '(' expression ')' { $$ = $2; }
          ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s", s);
}

int main() {
    yyparse();
    return 0;
}

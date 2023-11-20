%{
/* program to recognize a C program */
int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* { printf("\n%s is a PREPROCESSOR DIRECTIVE", yytext); }

int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto {
    printf("\n\t%s is a RESERVED WORD\n", yytext);
}

"/*" {
    COMMENT = 1;
    printf("\n\t%s is a COMMENT\n", yytext);
}

"*/" {
    COMMENT = 0;
    printf("\n\t%s is a COMMENT\n", yytext);
}

[_a-zA-Z][_a-zA-Z0-9]* {
    printf("Variable: %s\n", yytext);
}

\( ECHO;

= {
    if (!COMMENT)
        printf("\n\t%s is an ASSIGNMENT OPERATOR", yytext);
}

\<= |
\>= |
\< |
== |
\> {
    if (!COMMENT)
        printf("\n\t%s is a RELATIONAL OPERATOR", yytext);
}

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file;
        file = fopen(argv[1], "r");
        if (!file) {
            printf("could not open %s \n", argv[1]);
            exit(0);
        }
        yyin = file;
    }
    yylex();
    printf("\n\n");
    return 0;
}

int yywrap() {
    return 1;
}

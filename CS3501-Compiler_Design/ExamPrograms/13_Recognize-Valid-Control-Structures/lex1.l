%{
/* program to recognize a C program */
int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* { printf(""); }


while |
for |
do |
if |
break |
continue |
switch |
case |
else |
goto {
    printf("\n\t%s is a CONTROL STATEMENT\n", yytext);
}

"/*" {
    COMMENT = 1;
    printf("\n\t%s is a COMMENT\n", yytext);
}

"*/" {
    COMMENT = 0;
    printf("\n\t%s is a COMMENT\n", yytext);
}



\)(\;)? {
    if (!COMMENT)
        printf("\n\t");
    ECHO;
    printf("\n");
}

\( ECHO;

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

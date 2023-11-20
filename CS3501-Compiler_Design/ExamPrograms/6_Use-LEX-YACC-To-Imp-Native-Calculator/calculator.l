%{
#include "y.tab.h"
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[-+*/()]    { return *yytext; }
\n          { return EOL; }
[ \t]       ; /* Ignore whitespace */

.           { fprintf(stderr, "Error: Invalid character '%s'\n", yytext); }

%%

int yywrap() {
    return 1;
}

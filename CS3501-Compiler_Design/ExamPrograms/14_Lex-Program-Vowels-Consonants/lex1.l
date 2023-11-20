%{
int vowelCount = 0;
int consonantCount = 0;
%}

%%
[aeiouAEIOU]    { vowelCount++; }
[a-zA-Z]        { consonantCount++; }
.               ; // Ignore other characters

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    yy_scan_string(argv[1]);
    yylex();

    printf("Total number of vowels: %d\n", vowelCount);
    printf("Total number of consonants: %d\n", consonantCount);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_SYMBOLS][MAX_SYMBOLS];

void eliminateLeftRecursion(char nonTerminal, int ruleCount) {
    char newNonTerminal = nonTerminal + 1;

    // Create new productions without left recursion
    for (int i = 0; i < ruleCount; i++) {
        if (productions[i][0][0] == nonTerminal) {
            // A -> Aa | b becomes A -> bA'
            printf("%c -> ", nonTerminal);
            for (int j = 1; productions[i][j][0] != '\0'; j++) {
                printf("%c", productions[i][j][0]);
            }
            printf("%c'\n", newNonTerminal);

            // A' -> aA' | ε
            printf("%c' -> ", newNonTerminal);
            for (int j = 1; productions[i][j][0] != '\0'; j++) {
                printf("%c", productions[i][j][0]);
            }
            printf("%c' | ε\n", newNonTerminal);
        } else {
            // Productions without left recursion remain unchanged
            printf("%c -> ", nonTerminal);
            for (int j = 0; productions[i][j][0] != '\0'; j++) {
                printf("%c", productions[i][j][0]);
            }
            printf("\n");
        }
    }
}

int main() {
    int ruleCount;

    printf("Enter the number of rules: ");
    scanf("%d", &ruleCount);

    printf("Enter the non-terminals:\n");
    for (int i = 0; i < ruleCount; i++) {
        scanf(" %c", &nonTerminals[i]);
    }

    printf("Enter the productions:\n");
    for (int i = 0; i < ruleCount; i++) {
        printf("%c -> ", nonTerminals[i]);

        int symbolCount = 0;
        while (1) {
            scanf(" %s", productions[i][symbolCount]);
            if (productions[i][symbolCount][strlen(productions[i][symbolCount]) - 1] == ';') {
                productions[i][symbolCount][strlen(productions[i][symbolCount]) - 1] = '\0';
                break;
            }
            symbolCount++;
        }
    }

    printf("\nGrammar after eliminating left recursion:\n");

    for (int i = 0; i < ruleCount; i++) {
        eliminateLeftRecursion(nonTerminals[i], ruleCount);
    }

    return 0;
}

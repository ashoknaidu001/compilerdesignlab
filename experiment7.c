#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NON_TERMINALS 10
#define MAX_PROD_RULES 10

char nonTerminals[MAX_NON_TERMINALS];
char productions[MAX_NON_TERMINALS][MAX_PROD_RULES][50];
int numProductions[MAX_NON_TERMINALS];

int numNonTerminals = 0;

void eliminateLeftRecursion(int nonTerminalIndex) {
    for (int i = 0; i < nonTerminalIndex; i++) {
        for (int j = 0; j < numProductions[nonTerminalIndex]; j++) {
            char *production = productions[nonTerminalIndex][j];
            if (production[0] == nonTerminals[i]) {
                for (int k = 0; k < numProductions[i]; k++) {
                    char newProduction[50] = "";
                    strcat(newProduction, productions[i][k]);
                    strcat(newProduction, production + 1);
                    strcpy(productions[nonTerminalIndex][numProductions[nonTerminalIndex]], newProduction);
                    numProductions[nonTerminalIndex]++;
                }
            }
        }
    }

    for (int i = 0; i < numProductions[nonTerminalIndex]; i++) {
        if (productions[nonTerminalIndex][i][0] == nonTerminals[nonTerminalIndex]) {
            for (int j = i; j < numProductions[nonTerminalIndex] - 1; j++) {
                strcpy(productions[nonTerminalIndex][j], productions[nonTerminalIndex][j + 1]);
            }
            numProductions[nonTerminalIndex]--;
            i--;
        }
    }
}

int main() {
    printf("Enter the number of non-terminals: ");
    scanf("%d", &numNonTerminals);
    getchar(); // Consume the newline character

    printf("Enter the non-terminals: ");
    for (int i = 0; i < numNonTerminals; i++) {
        scanf("%c", &nonTerminals[i]);
        getchar(); // Consume the newline character
    }

    for (int i = 0; i < numNonTerminals; i++) {
        printf("Enter the number of productions for %c: ", nonTerminals[i]);
        scanf("%d", &numProductions[i]);
        getchar(); // Consume the newline character

        printf("Enter the productions for %c:\n", nonTerminals[i]);
        for (int j = 0; j < numProductions[i]; j++) {
            scanf("%s", productions[i][j]);
            getchar(); // Consume the newline character
        }
    }

    for (int i = 0; i < numNonTerminals; i++) {
        eliminateLeftRecursion(i);
    }

    printf("\nGrammar after left recursion elimination:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("%c -> ", nonTerminals[i]);
        for (int j = 0; j < numProductions[i]; j++) {
            printf("%s", productions[i][j]);
            if (j < numProductions[i] - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10
#define MAX_PROD_RULES 10

char nonTerminals[MAX_NON_TERMINALS];
char terminals[MAX_TERMINALS];
char productions[MAX_NON_TERMINALS][MAX_PROD_RULES][MAX_TERMINALS];

int numNonTerminals = 0;
int numTerminals = 0;
int numProductions[MAX_NON_TERMINALS];

void addToFollow(char *followSet, char terminal) {
    int i;
    for (i = 0; followSet[i] != '\0'; i++) {
        if (followSet[i] == terminal) {
            break;
        }
    }
    if (followSet[i] == '\0') {
        followSet[i] = terminal;
        followSet[i + 1] = '\0';
    }
}

void computeFollow(char nonTerminal, char followSet[MAX_TERMINALS]) {
    for (int i = 0; i < numNonTerminals; i++) {
        for (int j = 0; j < numProductions[i]; j++) {
            for (int k = 0; productions[i][j][k] != '\0'; k++) {
                if (productions[i][j][k] == nonTerminal) {
                    if (productions[i][j][k + 1] == '\0') {
                        if (nonTerminals[i] != nonTerminal) {
                            computeFollow(nonTerminals[i], followSet);
                        }
                    } else {
                        bool epsilonFound = true;
                        for (int l = k + 1; productions[i][j][l] != '\0'; l++) {
                            if (!isupper(productions[i][j][l])) {
                                addToFollow(followSet, productions[i][j][l]);
                                epsilonFound = false;
                                break;
                            } else {
                                char nextNonTerminal = productions[i][j][l];
                                char nextNonTerminalFollow[MAX_TERMINALS];
                                computeFollow(nextNonTerminal, nextNonTerminalFollow);
                                for (int m = 0; nextNonTerminalFollow[m] != '\0'; m++) {
                                    if (nextNonTerminalFollow[m] != 'e') {
                                        addToFollow(followSet, nextNonTerminalFollow[m]);
                                    } else {
                                        epsilonFound = true;
                                    }
                                }
                                if (!epsilonFound) {
                                    break;
                                }
                            }
                        }
                        if (epsilonFound && nonTerminals[i] != nonTerminal) {
                            computeFollow(nonTerminals[i], followSet);
                        }
                    }
                }
            }
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

    printf("Enter the number of terminals: ");
    scanf("%d", &numTerminals);
    getchar(); // Consume the newline character

    printf("Enter the terminals: ");
    for (int i = 0; i < numTerminals; i++) {
        scanf("%c", &terminals[i]);
        getchar(); // Consume the newline character
    }

    for (int i = 0; i < numNonTerminals; i++) {
        printf("Enter the number of productions for %c: ", nonTerminals[i]);
        scanf("%d", &numProductions[i]);
        getchar(); // Consume the newline character

        for (int j = 0; j < numProductions[i]; j++) {
            printf("Enter production %d for %c: ", j + 1, nonTerminals[i]);
            scanf("%s", productions[i][j]);
            getchar(); // Consume the newline character
        }
    }

    printf("\nFollow sets:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FOLLOW(%c) = {", nonTerminals[i]);
        char followSet[MAX_TERMINALS] = "";
        if (i == 0) {
            addToFollow(followSet, '$');
        }
        computeFollow(nonTerminals[i], followSet);
        printf("%s}\n", followSet);
    }

    return 0;
}

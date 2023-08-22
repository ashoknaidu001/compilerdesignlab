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

char firstSets[MAX_NON_TERMINALS][MAX_TERMINALS];
bool visited[MAX_NON_TERMINALS];

void addToFirst(int nonTerminalIndex, char terminal) {
    int i;
    for (i = 0; firstSets[nonTerminalIndex][i] != '\0'; i++) {
        if (firstSets[nonTerminalIndex][i] == terminal) {
            break;
        }
    }
    if (firstSets[nonTerminalIndex][i] == '\0') {
        firstSets[nonTerminalIndex][i] = terminal;
        firstSets[nonTerminalIndex][i + 1] = '\0';
    }
}

void computeFirst(int nonTerminalIndex) {
    visited[nonTerminalIndex] = true;
    for (int i = 0; i < numProductions[nonTerminalIndex]; i++) {
        char firstSymbol = productions[nonTerminalIndex][i][0];
        if (isupper(firstSymbol)) { // Non-terminal
            int firstSymbolIndex = 0;
            while (firstSymbolIndex < numNonTerminals && nonTerminals[firstSymbolIndex] != firstSymbol) {
                firstSymbolIndex++;
            }
            if (!visited[firstSymbolIndex]) {
                computeFirst(firstSymbolIndex);
            }
            for (int j = 0; firstSets[firstSymbolIndex][j] != '\0'; j++) {
                addToFirst(nonTerminalIndex, firstSets[firstSymbolIndex][j]);
            }
        } else if (firstSymbol != 'e') { // Terminal
            addToFirst(nonTerminalIndex, firstSymbol);
        } else if (firstSymbol == 'e') { // Epsilon
            if (productions[nonTerminalIndex][i][1] == '\0') {
                addToFirst(nonTerminalIndex, 'e');
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

    for (int i = 0; i < numNonTerminals; i++) {
        visited[i] = false;
        computeFirst(i);
    }

    printf("\nFirst sets:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FIRST(%c) = {", nonTerminals[i]);
        printf("%s}\n", firstSets[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

// Grammar representation
char nonTerminals[MAX_SYMBOLS];
char productions[MAX_SYMBOLS][MAX_PRODUCTIONS][MAX_SYMBOLS];
int numProductions[MAX_SYMBOLS];

bool isAmbiguous = false;

// Function to check for ambiguity
void checkAmbiguity() {
    // Implement a logic to check for ambiguity based on the grammar rules
    // You might need to implement parsing and tree generation to fully analyze ambiguity

    // Set isAmbiguous to true if ambiguity is detected
}

int main() {
    // Initialize grammar rules
    // ...

    checkAmbiguity();

    if (isAmbiguous) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}

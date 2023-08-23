#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define grammar rules, terminals, and non-terminals
#define NUM_RULES 4
char *grammar[NUM_RULES] = {"E=E+T", "E=T", "T=T*F", "T=F"};
char terminals[] = "+*";
char nonTerminals[] = "ETF";

// Define the parsing table (actions and goto)
#define NUM_STATES 6
#define NUM_SYMBOLS 4
char action[NUM_STATES][NUM_SYMBOLS]; // Action table
int goto_table[NUM_STATES][NUM_SYMBOLS]; // Goto table

// Initialize parsing tables (fill with appropriate values)

// SLR parsing functions
void parse(const char *input) {
    // Initialize stack and other variables

    // Main parsing loop
    while (true) {
        // Determine current state and next input symbol
        
        // Get action from action table
        
        // Perform appropriate action (shift, reduce, accept, or error)
    }
}

int main() {
    char input[100];

    // Input the string to parse
    printf("Enter the input string: ");
    scanf("%s", input);

    parse(input);

    return 0;
}

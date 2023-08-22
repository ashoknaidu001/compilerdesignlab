#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isOperator(char ch) {
    char operators[] = "+-*/%=<>!";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isKeyword(const char *token) {
    char keywords[][10] = {"int", "float", "char", "if", "else", "while", "for"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(const char *token) {
    if (!isalpha(token[0])) {
        return false;
    }
    for (int i = 1; token[i] != '\0'; i++) {
        if (!isalnum(token[i]) && token[i] != '_') {
            return false;
        }
    }
    return true;
}

bool isConstant(const char *token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

void getTokenType(const char *token) {
    if (isKeyword(token)) {
        printf("Keyword: %s\n", token);
    } else if (isIdentifier(token)) {
        printf("Identifier: %s\n", token);
    } else if (isConstant(token)) {
        printf("Constant: %s\n", token);
    } else if (strlen(token) == 1 && isOperator(token[0])) {
        printf("Operator: %s\n", token);
    } else {
        printf("Unrecognized token: %s\n", token);
    }
}

int main() {
    char input[1000];
    printf("Enter lines of code (Ctrl+D to end input):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove comments by replacing the comment part with a space
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '/' && input[i + 1] == '/') {
                input[i] = ' ';
                input[i + 1] = ' ';
                break;
            } else if (input[i] == '/' && input[i + 1] == '*') {
                input[i] = ' ';
                input[i + 1] = ' ';
                int j = i + 2;
                while (!(input[j] == '*' && input[j + 1] == '/')) {
                    if (input[j] == '\0') {
                        break;
                    }
                    input[j] = ' ';
                    j++;
                }
                input[j] = ' ';
                input[j + 1] = ' ';
            }
        }

        // Tokenize the modified input
        const char *delimiters = " \t\n";
        char *token = strtok(input, delimiters);

        while (token != NULL) {
            getTokenType(token);
            token = strtok(NULL, delimiters);
        }
    }

    return 0;
}

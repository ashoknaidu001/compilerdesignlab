#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char expression[100];
int pos = 0;
bool error = false;

void match(char expectedToken) {
    if (expression[pos] == expectedToken) {
        pos++;
    } else {
        printf("Error: Expected '%c' at position %d\n", expectedToken, pos);
        error = true;
    }
}

bool isDigit(char token) {
    return token >= '0' && token <= '9';
}

int parseNumber() {
    int num = 0;
    while (isDigit(expression[pos])) {
        num = num * 10 + (expression[pos] - '0');
        pos++;
    }
    return num;
}

int parseTerm() {
    int value = parseNumber();
    while (expression[pos] == '*' || expression[pos] == '/') {
        char operator = expression[pos];
        pos++;
        int operand = parseNumber();
        if (operator == '*') {
            value *= operand;
        } else if (operator == '/') {
            if (operand != 0) {
                value /= operand;
            } else {
                printf("Error: Division by zero\n");
                error = true;
                return 0;
            }
        }
    }
    return value;
}

int parseExpression() {
    int value = parseTerm();
    while (expression[pos] == '+' || expression[pos] == '-') {
        char operator = expression[pos];
        pos++;
        int operand = parseTerm();
        if (operator == '+') {
            value += operand;
        } else if (operator == '-') {
            value -= operand;
        }
    }
    return value;
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0'; // Remove newline character

    int result = parseExpression();

    if (!error && expression[pos] == '\0') {
        printf("Result: %d\n", result);
    } else {
        printf("Parsing error.\n");
    }

    return 0;
}

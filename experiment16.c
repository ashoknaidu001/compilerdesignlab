#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSIONS 100

typedef struct {
    char expression[50];
    char variable;
} Expression;

Expression expressions[MAX_EXPRESSIONS];
int numExpressions = 0;

void addExpression(const char *expression, char variable) {
    Expression e;
    strcpy(e.expression, expression);
    e.variable = variable;
    expressions[numExpressions++] = e;
}

void eliminateCommonSubexpressions() {
    for (int i = 0; i < numExpressions; i++) {
        for (int j = i + 1; j < numExpressions; j++) {
            if (strcmp(expressions[i].expression, expressions[j].expression) == 0) {
                printf("Common subexpression found:\n");
                printf("Variable: %c\n", expressions[j].variable);
                printf("Expression: %s\n", expressions[j].expression);
                printf("Reuse variable: %c\n", expressions[i].variable);
                printf("\n");

                // Replace the variable in expressions[j] with the reused variable
                expressions[j].variable = expressions[i].variable;
            }
        }
    }
}

int main() {
    addExpression("a + b * c", 'x');
    addExpression("a + b * c", 'y');
    addExpression("x + a * b", 'z');
    addExpression("a * b + c", 'w');

    printf("Original expressions:\n");
    for (int i = 0; i < numExpressions; i++) {
        printf("Variable: %c\n", expressions[i].variable);
        printf("Expression: %s\n", expressions[i].expression);
        printf("\n");
    }

    eliminateCommonSubexpressions();

    printf("Expressions after eliminating common subexpressions:\n");
    for (int i = 0; i < numExpressions; i++) {
        printf("Variable: %c\n", expressions[i].variable);
        printf("Expression: %s\n", expressions[i].expression);
        printf("\n");
    }

    return 0;
}

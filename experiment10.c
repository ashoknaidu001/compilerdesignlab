#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUADRUPLES 100

typedef struct {
    char operator;
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

Quadruple quadruples[MAX_QUADRUPLES];
int numQuadruples = 0;

void generateQuadruple(char operator, const char *arg1, const char *arg2, const char *result) {
    Quadruple q;
    q.operator = operator;
    strcpy(q.arg1, arg1);
    strcpy(q.arg2, arg2);
    strcpy(q.result, result);
    quadruples[numQuadruples++] = q;
}

void printQuadruples() {
    printf("Quadruples:\n");
    printf("%-10s%-10s%-10s%-10s\n", "Operator", "Arg1", "Arg2", "Result");
    for (int i = 0; i < numQuadruples; i++) {
        printf("%-10c%-10s%-10s%-10s\n", quadruples[i].operator, quadruples[i].arg1,
               quadruples[i].arg2, quadruples[i].result);
    }
}

int main() {
    generateQuadruple('=', "5", "", "a");
    generateQuadruple('*', "a", "2", "temp1");
    generateQuadruple('+', "temp1", "3", "b");

    printQuadruples();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPLES 100

typedef struct {
    char operator;
    char arg1[10];
    char arg2[10];
    char result[10];
} Triple;

Triple triples[MAX_TRIPLES];
int numTriples = 0;

void generateTriple(char operator, const char *arg1, const char *arg2, const char *result) {
    Triple t;
    t.operator = operator;
    strcpy(t.arg1, arg1);
    strcpy(t.arg2, arg2);
    strcpy(t.result, result);
    triples[numTriples++] = t;
}

void printTriples() {
    printf("Triples:\n");
    printf("%-10s%-10s%-10s%-10s\n", "Operator", "Arg1", "Arg2", "Result");
    for (int i = 0; i < numTriples; i++) {
        printf("%-10c%-10s%-10s%-10s\n", triples[i].operator, triples[i].arg1,
               triples[i].arg2, triples[i].result);
    }
}

int main() {
    generateTriple('=', "5", "", "a");
    generateTriple('*', "a", "2", "temp1");
    generateTriple('+', "temp1", "3", "b");

    printTriples();

    return 0;
}

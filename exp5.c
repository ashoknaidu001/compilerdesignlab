#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SYMBOLS 100

// Symbol structure
typedef struct {
    char name[30];
    char type[20];
    int value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int numSymbols = 0;

// Function to insert a symbol into the symbol table
void insertSymbol(const char *name, const char *type, int value) {
    if (numSymbols < MAX_SYMBOLS) {
        strcpy(symbolTable[numSymbols].name, name);
        strcpy(symbolTable[numSymbols].type, type);
        symbolTable[numSymbols].value = value;
        numSymbols++;
        printf("Symbol inserted: %s\n", name);
    } else {
        printf("Symbol table is full. Cannot insert symbol: %s\n", name);
    }
}

// Function to search for a symbol in the symbol table
int searchSymbol(const char *name) {
    for (int i = 0; i < numSymbols; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Symbol not found
}

// Function to update the value of a symbol
void updateSymbolValue(const char *name, int newValue) {
    int index = searchSymbol(name);
    if (index != -1) {
        symbolTable[index].value = newValue;
        printf("Symbol value updated: %s\n", name);
    } else {
        printf("Symbol not found: %s\n", name);
    }
}

// Function to delete a symbol from the symbol table
void deleteSymbol(const char *name) {
    int index = searchSymbol(name);
    if (index != -1) {
        for (int i = index; i < numSymbols - 1; i++) {
            symbolTable[i] = symbolTable[i + 1];
        }
        numSymbols--;
        printf("Symbol deleted: %s\n", name);
    } else {
        printf("Symbol not found: %s\n", name);
    }
}

// Function to display the symbol table
void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tType\tValue\n");
    for (int i = 0; i < numSymbols; i++) {
        printf("%s\t%s\t%d\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].value);
    }
}

int main() {
    insertSymbol("x", "int", 10);
    insertSymbol("y", "float", 3.14);
    insertSymbol("z", "char", 'A');

    displaySymbolTable();

    int index = searchSymbol("y");
    if (index != -1) {
        printf("Symbol found: %s\n", symbolTable[index].name);
    } else {
        printf("Symbol not found.\n");
    }

    updateSymbolValue("x", 20);
    deleteSymbol("z");

    displaySymbolTable();

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

bool condition1 = true;
bool condition2 = false;

int main() {
    int x = 10;
    int y = 20;

    if (condition1) {
        y = x + y;
    } else {
        x = x - y;
    }

    if (condition2) {
        x = x * y;
    } else {
        y = y / x;
    }

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}

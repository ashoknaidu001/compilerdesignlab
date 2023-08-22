#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSingleLineComment(const char *line) {
    return strncmp(line, "//", 2) == 0;
}

bool isMultiLineCommentStart(const char *line) {
    return strncmp(line, "/*", 2) == 0;
}

bool isMultiLineCommentEnd(const char *line) {
    return strstr(line, "*/") != NULL;
}

bool isComment(const char *line) {
    return isSingleLineComment(line) || isMultiLineCommentStart(line);
}

int main() {
    char input[100];
    printf("Enter a line of code: ");
    fgets(input, sizeof(input), stdin);

    if (isComment(input)) {
        printf("The input line is a comment.\n");
    } else {
        printf("The input line is not a comment.\n");
    }

    return 0;
}

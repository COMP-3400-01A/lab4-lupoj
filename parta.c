#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    char text[100];

    if (argc > 1) {
        strncpy(text, argv[1], sizeof(text) - 1);
        text[sizeof(text) - 1] = '\0';

    }
    else {
        printf("Enter: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (islower(text[i])) {
            text[i] = toupper(text[i]);
        }
        else if (isspace(text[i])) {
            text[i] = ',';
        }
    }

    printf("%s\n", text);
    return 0;
}

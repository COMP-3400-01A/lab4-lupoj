#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf(text);
    return 0;
}

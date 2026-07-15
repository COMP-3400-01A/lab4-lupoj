#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    char text[100];

    // If there are already arguments, copy it to the text array
    // Else, take user input and copy it to the text array
    if (argc <= 1) {
        printf("ERROR: No arguments\n");
        return 1;
    }

    strncpy(text, argv[1], sizeof(text) - 1);
    text[sizeof(text) - 1] = '\0';

    // Iterate through text array and convert every lower-case letter to upper-case, as well as
    // convert every whitespace to a comma. 
    for (int i = 0; text[i] != '\0'; i++) {
        if (islower(text[i])) {
            text[i] = toupper(text[i]);
        }
        else if (isspace(text[i])) {
            text[i] = ',';
        }
    }

    // Print out text array
    printf("%s\n", text);
    return 0;
}

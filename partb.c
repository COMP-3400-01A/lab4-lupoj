#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {

    // If no arguments provided, exit with status 1
    if (argc == 1) {
        write(2, "ERROR: no arguments provided\n", 20);
        return 1;
    }

    // Check if number of arguments is either odd or even
    // If odd, then there is only one middle argument
    // If even, there are two middle arguments
    if (argc % 2 == 0) {
        // Declare middle to point to the value of the number of arguments divided by 2
        const char* middle = argv[argc/2];

        // Declare eargs to be the command 
        const char* eargs[] = { "echo", middle, NULL};
        int eret = execv("/bin/echo", (char* const*)eargs);

        // If command is invalid, exit with status of 1
        if (eret == -1) {
            perror("exec");
            return 1;
        }
    }
    else {
        // Declare both middle arguments similar to how it is done before
        const char* first_mid = argv[argc/2];
        const char* sec_mid = argv[(argc/2) + 1];

        // Declare eargs to be the command with the two middle arguments
        const char* eargs[] = { "echo", first_mid, sec_mid, NULL};
        int eret = execv("/bin/echo", (char* const*)eargs);

        // If the command is invalid, exit with status of 1
        if (eret == -1) {
            perror("exec");
            return 1;
        }
    }

    return 0;
}

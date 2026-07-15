#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {

    if (argc == 1) {
        write(2, "ERROR: no arguments provided\n", 20);
        return 1;
    }

    if (argc % 2 == 0) {
        const char* middle = argv[argc/2];

        const char* eargs[] = { "echo", middle, NULL};
        int eret = execv("/bin/echo", (char* const*)eargs);

        if (eret == -1) {
            perror("exec");
            return 1;
        }
    }
    else {
        const char* first_mid = argv[argc/2];
        const char* sec_mid = argv[(argc/2) + 1];

        const char* eargs[] = { "echo", first_mid, sec_mid, NULL};
        int eret = execv("/bin/echo", (char* const*)eargs);

        if (eret == -1) {
            perror("exec");
            return 1;
        }
    }


    return 0;
}

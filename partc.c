#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    // TODO: Complete and document
    // If number of arguments is not 3, then insufficent or invalid arguments have 
    // been supplied by the user and exit with status of 1.
    if (argc != 3) {
        write(2, "ERROR: no arguments\n", 20);
        return 1;
    }

    // Initialize pid for the fork
    pid_t pid = fork();

    // If the process ID is less than 0, that indicates that an error has occurred
    // So exit with status of 1
    // If the PID is 0, do child process
    // Otherwise, do the parent process
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        const char* geargs[] = {"grep", "-s", "-q", argv[1], argv[2], NULL};
        execv("/usr/bin/grep", (char* const*)geargs);

        perror("exec failed");
        return 1;
    }
    else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);

            if (exit_code == 0) {
                printf("FOUND: %s\n", argv[1]);
                return 0;
            }
            else if (exit_code == 1) {
                printf("NOT FOUND: %s\n", argv[1]);
                return 0;
            }
            else if (exit_code == 2) {
                printf("ERROR: %s doesn't exist\n", argv[2]);
                return 2;
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../src/lab.h"

void parse_args(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v':
                printf("Shell Version: %d.%d\n", lab_VERSION_MAJOR, lab_VERSION_MINOR);
                exit(0);
            default:
                // Handle other options, if any
                break;
        }
    }
}

int main(int argc, char **argv) {
    parse_args(argc, argv);

    // Read input from the user using GNU Readline
    char *input;
    while ((input = readline("shell> ")) != NULL) {
        // Add the input to the history
        add_history(input);

        // Process the input (for now, just print it)
        printf("You entered: %s\n", input);

        // Free the allocated input
        free(input);
    }

    return 0;
}

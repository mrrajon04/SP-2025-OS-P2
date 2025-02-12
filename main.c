#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    // Other initialization and the main loop of your shell here
    return 0;
}

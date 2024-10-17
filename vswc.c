#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;
    int count_chars = 0;

    // Check for command line argument
    int start_index = 1; // file arguments start here

    for(int i=1; i<argc; i++) {
        if(argv[i][0] == '-') {
            if(strcmp(argv[i], "-c") == 0) count_chars = 1;
            else {
                fprintf(stderr, "Invalid option: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
        }
        else {
            start_index = i;
            break;
        }
    }

    // No file specified : Read from stdin
    if(start_index >= argc) {
        printf("No file specified, reading from standard input...\n");
        file = stdin; // No file provided
    }
    else { // User specified the file to open
        file = fopen(argv[start_index], "r"); // Open file in read mode
        if(!file) {
            perror("Error opening file!!");
            return EXIT_FAILURE;
        }
        printf("Reading from file: %s\n", argv[start_index]);
    }

    // Read the file and display the contents 
    printf("Starting to read...\n");
    while((ch = fgetc(file) != EOF)) {
        count_chars++;
    }
    printf("Finished reading.\n");

    if (count_chars) {
        printf("Characters: %d\n", count_chars);
    }

    // Close the file if it's not stdin
    if(file != stdin) {
        fclose(file);
    }

    return 0;
}
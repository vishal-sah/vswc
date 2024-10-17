#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;

    // Check for command line argument
    if(argc < 2) {
        printf("No file specified, reading from standard input...\n");
        file = stdin; // No file provided
    }
    else { // User specified the file to open
        file = fopen(argv[1], "r"); // Open file in read mode
        if(!file) {
            perror("Error opening file!!");
            return EXIT_FAILURE;
        }
        printf("Reading from file: %s\n", argv[1]);
    }

    // Read the file and display the contents 
    char ch;
    printf("Starting to read...\n");
    while((ch = fgetc(file) != EOF)) {
        putchar(ch);
    }
    printf("Finished reading.\n");

    // Close the file if it's not stdin
    if(file != stdin) {
        fclose(file);
    }

    return 0;
}
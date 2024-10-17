#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;
    int count_chars = 0, count_lines = 0, count_words = 0; // bool 
    int count_char = 0, count_line = 0, count_word = 0; // actual count
    int in_word = 0;

    // Check for command line argument
    int start_index = 1; // file arguments start here

    for(int i=1; i<argc; i++) {
        if(argv[i][0] == '-') { // check for flags
            if(strcmp(argv[i], "-c") == 0) 
                count_chars = 1;
            else if(strcmp(argv[i], "-l") == 0) 
                count_lines = 1;
            else if(strcmp(argv[i], "-w") == 0) 
                count_words = 1;
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
    while(((ch = fgetc(file)) != EOF)) {
        count_char++;
        if(ch == '\n') 
            count_line++;

        if(ch == ' ' || ch == '\n' || ch == '\t') {
            if (in_word) {
                count_word++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    printf("Finished reading.\n");

    // Count the last word if the file does not end with a space or newline
    if(in_word) {
        count_word++;
    }

    if(count_chars) {
        printf("Characters: %d\n", count_char);
    }
    if(count_lines) {
        printf("Lines: %d\n", count_line);
    }
    if(count_words) {
        printf("Words: %d\n", count_word);
    }

    // Close the file if it's not stdin
    if(file != stdin) {
        fclose(file);
    }

    return 0;
}
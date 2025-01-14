# wc Utility

## Overview

This project is a simplified implementation of the Linux `wc` (word count) utility. The `wc` command is commonly used to count the number of lines, words, and characters in files or standard input. 

The goal of this project is to replicate the essential functionalities of `wc`, allowing users to easily obtain word and character counts from specified files or standard input.

## Features

- **Basic Usage:**
  - Count lines, words, and characters in a specified file or from standard input.
  - If no file is specified, the program reads from standard input.

- **Command-Line Flags:**
  - `-l`: Count only the lines.
  - `-w`: Count only the words.
  - `-c`: Count only the characters.

- **Multiple File Support:**
  - Handle multiple file inputs, displaying individual counts and a cumulative total at the end.

- **Error Handling:**
  - Display meaningful error messages for non-existent or unreadable files.

## How to Use

### Compiling (for C implementation)

To compile the program, use the following command:

```bash
gcc -o vswc vswc.c
./vswc [OPTION]... [FILE]...
./vswc test.txt
./vswc -l test.txt
echo "Hello World" | ./vswc
./vswc test.txt
cat test.txt | ./vswc
```

#### Options
1. -c: Count only characters.
2. -l: Count only lines.
3. -w: Count only words.


### Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

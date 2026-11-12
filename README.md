# C Custom Preprocessor

## About

This project is a basic implementation of a C preprocessor using C programming. It takes a C source file as input and generates a processed file with a `.i` extension.

It performs three main operations: comment removal, header file inclusion, and macro substitution.

## Features

- Removes single-line and multi-line comments.
- Handles header file inclusion.
- Stores and replaces defined macros.
- Generates a processed `.i` output file.

## Project Files

- `main.c` – Main program and file handling.
- `header.c` – Handles header file inclusion.
- `comment.c` – Removes comments from the source file.
- `macro.c` – Handles macro definitions and replacement.
- `header.h` – Contains function declarations and header files.
- `Makefile` – Used to compile the program.

## Compilation

Compile the program using:

```bash
make
```

## Execution

Run the executable by providing a C source file:

```bash
./exe inputfile.c
```

Example:

```bash
./exe sample.c
```

The processed output will be generated as:

```text
sample.i
```

## Requirements

- GCC Compiler
- Linux Environment
- Make utility

## Concepts Used

- C Programming
- File Handling
- Pointers
- Dynamic Memory Allocation
- String Manipulation
- Modular Programming

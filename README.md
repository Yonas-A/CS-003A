# CS 003A - FUNDAMENTALS OF COMPUTER SCIENCE II at Pasadena City College

## Description

All the files and projects I made for CS 3A class with Professor Sassan Barkeshli at Pasadena City college in Winter 2020

### Directory structure

The files and folders structure consists of [!includes](./Projects/!includes/) directory as the main library and numbered directories for small projects.

- ### [!includes Directory](./Projects/!includes/)

  This directory contains all the header and source files for fundamental data structure classes, their test files and sample outputs for the test files. In addition it also contains some classes outside of data structure topics that are used throughout the entire course.

- #### [The Numbered directories](./Projects/)

  These directories that start with numbers hold test files and projects derived from the classes in the [!includes](./Projects/!includes/) directory. The `source` directory under this directory hold the test main.cpp files. Some `source` directories also contain a `.pro` file that holds all the dependencies needed for that project.This `.pro` file was automatically created with [`Qt Creator`](https://www.qt.io/product) IDE

  The numbered directories also hold `includes` directory that holds the libraries made specifically for this project. Unlike the files in the `!includes` directory, files under this directory won't be used in any other projects apart from the current project.

  The `output` directory holds the sample outputs for these tests. The `report` directory holds the work report for the main project and underlying structural classes. The `resource` or `build` directories hold the resources used with that project to run the test files such as `.txt` and `.bin` files.

### Language

`c++`

### Additional Libraries Used

[`SFML`](https://www.sfml-dev.org)

### Projects and libraries Made?

- [Rational Numbers](./Projects/06%20Rational/)
- Polynomials

  - [Polynomials with arrays](./Projects/08%20Poly/)
  - [Polynomials without arrays](./Projects/13%20\Poly/)

- [Game of Life with and without SFML](./Projects/14%20Predator%20Prey/)
- [Graphing Calculator with SFML](./Projects/!includes/Graph)

- Linked List

  - [Sorted Linked List](./Projects/!includes/Linked_List_Sorted/)
  - [UnSorted Linked List](./Projects/!includes/Linked_List/)

- List

  - [Unsorted Iterated and non Iterated List](./Projects/!includes/List)
  - [Sorted non Iterated List](./Projects/!includes/Sorted_List)

- [Shunting Yard](./Projects/!includes/Shunting_Yard)
- [Reverse Polish Notation (RPN)](./Projects/!includes/RPN)
- [Tokenization](./Projects/!includes/Token)
- [String Tokenization](./Projects/!includes/Tokenize_String)

- [Randomization](./Projects/!includes/Random)
- [Stack](./Projects/!includes/Queue)
- [Queue](./Projects/!includes/Queue)
- [Vectors](./Projects/!includes/Vector)

## Installation/Setup

Clone or download this project. Then run each numbered directories as separate workspaces.
_NOTE_ On some IDEs it may require to use `.cpp` instead of `.h` when including paths to some libraries that have both a `source` and `header` files

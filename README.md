# advert_of_code_2024

https://adventofcode.com/

## puzzle_3

Makefile, second ARGS, change it to 1 to get the first problem, 2 to get the second 

## puzzle_4

FSM?

## puzzle_5, Jan 2, 2025

buffer -> list of string ("$47|12$") -> list of edges -> list of vertices

General rules:

- From memory control
1. caller define the list that will pass into the callee
2. callee do the memory allocation
3. callee processes the data
4. caller free the memory after return from callee.

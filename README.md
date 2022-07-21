# get_next_line

# Summary
This project is about programming a function that returns a line read from a file descriptor.

Reading a line from a fd is way too tedious

# Function name
get_next_line

# Prototype
char *get_next_line(int fd);

# Turn in files
get_next_line.c, get_next_line_utils.c, get_next_line.h

# Parameters
fd: The file descriptor to read from

# Return value
Read line: correct behavior
NULL: there is nothing else to read, or an error occurred

# External functs.
read, malloc, free

# Description:
Write a function that returns a line read from a file descriptor

42 Sao Paulo

By: Rodrigo Ferreira
Project: get_next_line
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Introduction
The get_next_line project, part of the 42 Cursus, is a fundamental exercise in C programming. Its primary objective is to create a function that reads 📖 a line from a file descriptor,
which could be a file, standard input, or any other stream. The function is designed to read a line from the given file descriptor until a newline character is encountered.
This project provides a practical introduction to working with file descriptors,
handling static variables, managing memory allocation, and understanding how to handle leaks 🚰.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Functionality
The core functionality of the get_next_line function involves reading from a file descriptor in a manner that allows for iterative calls to retrieve subsequent lines. Here's a brief overview of the main features and requirements of the project:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Main Function:
The get_next_line function should read from a specified file descriptor and return a line of text.
It should handle reading from multiple file descriptors simultaneously in the bonus part. 🗃️
Repeated calls to get_next_line should sequentially read lines from the file descriptor.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Buffer Size: 📏
The project allows specifying the buffer size for reading data from the file descriptor.
The buffer size can be modified during compilation using the -D BUFFER_SIZE=n option.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Error Handling: 🚫
The function should handle error conditions gracefully, returning NULL if there's nothing else to read or if an error occurs.
Memory allocated dynamically should be freed properly to prevent memory leaks.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bonus Part:
The bonus part of the project involves implementing get_next_line using only one static variable.
It also requires managing multiple file descriptors simultaneously.
Implementation Details
The project requires careful consideration of file handling, memory management, and error checking.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

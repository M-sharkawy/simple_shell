Simple Shell Team Project (By Martain and Mostafa)

Project Overview:

The project was developed in C and adheres to the Shell Betty linter guidelines.

General Requirements:

 - Compilation: All files must be compiled on Ubuntu 20.04 LTS using gcc with the following flags: -Wall -Werror -Wextra -pedantic -std=gnu89.
 - File Format: Ensure each file ends with a newline.
 - Documentation: A README.md file must be present at the root of the project directory.
 - Code Style: Code must be formatted according to Betty style, verified with betty-style.pl and betty-doc.pl.
 - Memory Management: The shell should be free of memory leaks.
 - Function Limit: Each file should contain no more than five functions.
 - Header Files: All header files should use include guards.

Project Description:

The hsh project involves creating a simple UNIX command language interpreter that can read and execute commands from a file or standard input.

How hsh Works:

 - Prompt and Input: hsh displays a prompt and waits for user input.
 - Process Handling: It spawns a child process to manage the command.
 - Command Execution: The interpreter checks for built-in commands, aliases in the PATH, and local executable  programs. The command, along with its arguments, replaces the child process.
 - Returning to Prompt: After the command execution, the program returns to the parent process and displays the prompt again, ready for a new command.
 - Exit Options: To exit, press Ctrl-D or type exit (with or without a status).
 - Non-Interactive Mode: The shell also supports non-interactive execution.

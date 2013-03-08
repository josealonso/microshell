FUNCTIONALITIES

- A prompt is shown in the standard output.
- The only buit-in commands are the following: pwd, cd, exit.
- Simple commands are read from the standard input and execute them in a loop until a built-in command
exit is issued.
- Redirecting the standard input (<) and the standard output (>) can be used.
- Commands can be executed in the background mode (&).

HINTS FOR IMPLEMENTATION

- To implement the command interpreter, a function must be used, whose parameter is the line input by the user and
the returned value is a table of pointers to strings of characters.
This function is called separaParametros (char *linea, char **parametro) and must be defined in a module called
"parser.c". It's recommended to use the strtok function, which is part of the C Standard Library.
- The library "parser.a", containing the "parser.o" object, must be built.
- As usual, a makefile must also be built, in order to keep up to date the executable version of the "microshell".


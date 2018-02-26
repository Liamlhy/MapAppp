# History-based autocomplete
For this challenge problem, you will write a command auto-complete system. The provided code implements a simple terminal-like input system that reads input one character at a time. You will have to design and implement a data structure that can provide autocomplete results to the user in a reasonable amount of time.

The root of your data structure should be in the `autocomplete_t` struct defined in autocomplete.h. At startup, the main program calls `autocomplete_init`, which is a function you can use to initialize your autocomplete data structure. After each character the user types, the main program calls `autocomplete_get_suggestions` to request suggested text given the input so far. When the user hits enter, the program then calls `autocomplete_add_line` to insert the typed string into the suggestions data structure. You should provide this input as a potential suggestion in the future. At shutdown, the main program calls `autocomplete_shutdown` so you can clean up any memory allocated for your data structure.

Your task is to add any necessary fields to the `autocomplete_t` struct in autocomplete.h, along with any other structs you may need for your data structure. You should then implement the four functions stubbed out in autocomplete.c. You should not change main.c.

## Input Restrictions
You may assume that input text will contain only standard ASCII characters with integer encodings between 0 and 127.

## How to make suggestions
The `autocomplete_get_suggestions` function should return commands in the history that start with the line that has been typed in so far. For example, the partial input "Hel" should produce suggestions "Hello" and "Hello World!", assuming these two lines are in our history. You do not need to save history across runs of the program.

You must implement your suggestion search in a way that can handle a large number of commands in the history. A linear search over a linked list of previous commands will almost certainly be too slow!

## Building, running, and testing the program
To build the program, run `make` and `./autocomplete`. Start typing to see autocomplete suggestions (the default suggestions are not very good). If you hit enter you will get a clear line. If you hit enter with a blank line or press ctrl-C the program will quit.

You will need the ncurses library on your machine to build this project. All MathLAN machines have this library, but I am happy to help you set it up on your own machine if you run Linux or MacOS.

To test the program with a larger history, run the program with additional file name parameters. For example `./autocomplete inputs/short.txt` will load each line of the short.txt file into the autocomplete structure at startup. Once your program works on this short input file, try it with inputs/dictionary.txt to see how it handles a much larger file.

***You should not write the history of inputs to a file. Each new run of the `autocomplete` program should start with a clean history.***

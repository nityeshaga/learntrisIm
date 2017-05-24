Learntris
=======================
#### ABOUT:
This program tries to implement the classic game of Tetris on a terminal. If you are not familar with the game, you can try it [here](http://tetris.com/play-tetris/).

The playing field is made up of a 22 X 10 matrix.

The falling blocks are called tetraminos and as a physical unit in the game. There are 7 types of tetraminos that are named based on their shapes-
the I, the O, the S, the Z, the T, the J and the L tetramino.

The aim of creating this program is not to create a game, C is hardly the language to use for creating a game.
The aim is to create a program that is large enough to warrant the use of dozens of functions split across multiple source files and of a separate test program to help in the development process (called [test-driven development](https://en.wikipedia.org/wiki/Test-driven_development)), a program that is complex enough to provide a stage for using all the best and somewhat difficult features of the C language and apply the ideas of programming one learns, into a large project and see them affect the whole thing.

#### THE FILEPLAN:
The following files have been added by me (author- [Nityesh Agarwal](https://github.com/nityeshaga)) to the [original fork](https://github.com/LearnProgramming/learntris):
* [matrix.c](https://github.com/nityeshaga/learntris/blob/master/matrix.c): contains all the functions that modify or are needed to modify the 2D matrix.  
* [tetramino.c](https://github.com/nityeshaga/learntris/blob/master/tetramino.c): contains all the functions that modify or are needed to modify the tetramino.  
* [learntris.c](https://github.com/nityeshaga/learntris/blob/master/learntris.c): links to the above mentioned files and generic.c, contains the main() function and some other functions that are private to it.  
* [generic.c](https://github.com/nityeshaga/learntris/blob/master/generic.c): contains all functions that are called by more than one file.  
* [matrix.h](https://github.com/nityeshaga/learntris/blob/master/matrix.h), [tetramino.h](https://github.com/nityeshaga/learntris/blob/master/tetramino.h): header files for matrix.c and tetramino.c.  
* [generic.h](https://github.com/nityeshaga/learntris/blob/master/generic.h): header file for generic.c, also contains the struct definition of tetramino and a bunch of other macros.  
* [makefile](https://github.com/nityeshaga/learntris/blob/master/makefile): makefile for compiling learntris.  
* [makefile.debug](https://github.com/nityeshaga/learntris/blob/master/makefile.debug): makefile for compiling for debugging with appropriate symbols.  

*__NOTE__: The lowest tier consists of generic.c. By default, it can access only its own functions and variables.   
The 2nd tier consists of matrix.c and tetramino.c. by default, they can access only the functions and definitions of generic.c and their own.  
The 3rd tier consists of learntris.c. It can access all functions and definitions from generic.c, matrix.c and tetramino.c, along with the ones init contains.*  

All the other files provide a set of automated tests that have guided me through implementing my own version of
[Tetris](https://en.wikipedia.org/wiki/Tetris). These were provided by [LearnProgramming/learntris](https://github.com/LearnProgramming/learntris). Look at the [readme page](https://github.com/LearnProgramming/learntris/blob/master/README.md#the-learntris-challenge) of that repository.

#### HOW TO RUN:
1. Fork this repository
1. Pull the forked copy to your machine
1. Go to the downloaded directory (should be named- learntris)
1. On the terminal type: `make learntris`. This will compile the code.
1. Now type `./learntris`. This will run the game.

#### HOW TO PLAY:

*__NOTE__: All the commands implemented right now* (date- 21.05.17) *were created to pass the tests mentioned in [testplan.org](https://github.com/LearnProgramming/learntris/blob/master/testplan.org) in (https://github.com/LearnProgramming/learntris).*

*__NOTE__: This is a Work In Progress. So these instructions must be looked at, as mere features that have been currently implemented in their most basic form and not as instructions at playing a fully developed game. There are many bugs in the code, so many that almost every command can be broken using some set of input. Which means that you __will__ encounter some when you run the code. So, if you do decide to run the code, please consider [contributing](https://github.com/nityeshaga/learntris/blob/master/README.md#contribute) to its development*

*__NOTE__: As this is a command line game, all commands mentioned here must be proceeded with a newline (implying that you need to press enter after each command) to execute them. You are allowed to enter multiple commands in one line, with or without spaces but none of them will execute until you press enter.*

**COMMAND- 'q': quits the game instantly**  

As mentioned before, the playing field consists of 22 X 10 matrix like this:  
`. . . . . . . . . .` #  0  
`. . . . . . . . . .` #  1  
`. . . . . . . . . .` #  2  
`. . . . . . . . . .` #  3  
`. . . . . . . . . .` #  4  
`. . . . . . . . . .` #  5  
`. . . . . . . . . .` #  6  
`. . . . . . . . . .` #  7  
`. . . . . . . . . .` #  8  
`. . . . . . . . . .` #  9  
`. . . . . . . . . .` # 10  
`. . . . . . . . . .` # 11  
`. . . . . . . . . .` # 12  
`. . . . . . . . . .` # 13  
`. . . . . . . . . .` # 14  
`. . . . . . . . . .` # 15  
`. . . . . . . . . .` # 16  
`. . . . . . . . . .` # 17  
`. . . . . . . . . .` # 18  
`. . . . . . . . . .` # 19  
`. . . . . . . . . .` # 20  
`. . . . . . . . . .` # 21  

The dots imply empty indices.  
**COMMAND- 'p': To view the current state of the matrix, press 'p'** (you won't be shown the number for each line as shown above and in the examples below).

Tetraminos are the basic building blocks of the game. In Learntris, they are implemented using letters of the English alphabet, where the alphabet corresponds to the colour of the respective tetramino.

There are 7 types of tetraminos-

* The I tetramino, colour- cyan:  
`. . . .`  
`c c c c`  
`. . . .`  
`. . . .`  

* The O tetramino, colour- yellow:  
`y y`  
`y y`  

* The Z tetramino, colour- red:  
`r r .`  
`. r r`  
`. . .`  

* The S tetramino, colour- green:  
`. g g`  
`g g .`  
`. . .`  

* The J tetramino, colour- blue:  
`b . .`  
`b b b`  
`. . .`  

* The L tetramino, colour- orange:  
`. . o`  
`o o o`  
`. . .`  

* The T tetramino, colour- magenta:  
`. m .`  
`m m m`  
`. . .`  

**COMMAND- 'I', 'O', 'Z', 'S', 'J', 'L', 'T': pressing any of these selects the corresponding tetramino, spawns it on the matrix and makes it active**  
**COMMAND- 'P': prints the matrix along with the active tetramino**  
*__NOTE__: selecting a tetramino does not fix it to the matrix, therefore, it does not define its current state, which means that the command- 'p' will not show it on the matrix*

Now, that the tetramino is active, you can move it around in the matrix.  
**COMMAND- '>': moves the active tetramino one cell to the right, press '>'**  
**COMMAND- '<': moves the active tetarmino one cell to the left, press '<'**  
**COMMAND- 'v': moves the active tetramino one cell down, press 'v'**  
*__NOTE__: The tetramino is active after any of these movement commands, which implies that it is not fixed to the matrix*  

**COMMAND- 'V': hard drops the active tetramino (moves it down in the current column as much as possible) and fixes it at the position**  
After this command, the tetramino gets fixed to the matrix and goes in a state of permanent inactivity.  

The tetraminos can be rotated, any number of times, both clockwise and anti-clockwise.  
**COMMAND- ')': rotates the active tetramino clockwise by 90 degrees**  
**COMMAND- '(': rotates the active tetramino anti-clockwise by 90 degrees**  

Here's an example illustrating the above commands:  

> T ( >>>> > Pq  
`. . . . . . . . . M` #  0  
`. . . . . . . . M M` #  1  
`. . . . . . . . . M` #  2  
`. . . . . . . . . .` #  3  
`. . . . . . . . . .` #  4  
`. . . . . . . . . .` #  5  
`. . . . . . . . . .` #  6  
`. . . . . . . . . .` #  7  
`. . . . . . . . . .` #  8  
`. . . . . . . . . .` #  9  
`. . . . . . . . . .` # 10  
`. . . . . . . . . .` # 11  
`. . . . . . . . . .` # 12  
`. . . . . . . . . .` # 13  
`. . . . . . . . . .` # 14  
`. . . . . . . . . .` # 15  
`. . . . . . . . . .` # 16  
`. . . . . . . . . .` # 17  
`. . . . . . . . . .` # 18  
`. . . . . . . . . .` # 19  
`. . . . . . . . . .` # 20  
`. . . . . . . . . .` # 21  

Here's another example:  

> TV ZV pq
`. . . . . . . . . .` #  0  
`. . . . . . . . . .` #  1  
`. . . . . . . . . .` #  2  
`. . . . . . . . . .` #  3  
`. . . . . . . . . .` #  4  
`. . . . . . . . . .` #  5  
`. . . . . . . . . .` #  6  
`. . . . . . . . . .` #  7  
`. . . . . . . . . .` #  8  
`. . . . . . . . . .` #  9  
`. . . . . . . . . .` # 10  
`. . . . . . . . . .` # 11  
`. . . . . . . . . .` # 12  
`. . . . . . . . . .` # 13  
`. . . . . . . . . .` # 14  
`. . . . . . . . . .` # 15  
`. . . . . . . . . .` # 16  
`. . . . . . . . . .` # 17  
`. . . r r . . . . .` # 18  
`. . . . r r . . . .` # 19  
`. . . . m . . . . .` # 20  
`. . . m m m . . . .` # 21  

Scoring:  
Whenever you are able to completely fill a row, you are eligible to add 100 points to your existing score.  
**COMMAND- 's': checks if a completely filled row is present in the matrix. If yes, then it deletes the first appearance of such a row, shifts all rows above it one cell down and increases the score by 100 points**  
So, if you have 2 or more such rows, you need to enter the 's' command that many number of times.  
**COMMAND- '?n': queries the number of rows deleted and prints it**  
**COMMAND- '?s': queries the score and prints it**  
**COMMAND- ';': prints a newline on the output screen.** Useful when using 'p' or 'P' command multiple times in the same input line.

Miscellaneous commands:  
**COMMAND- '!': works as the pause/resume button**  
**COMMAND- '@': prints the title screen and effectively pauses the game until the resume button is pressed**  
**COMMAND- 'p': works after the '@' command is given and shows the menu**  
**COMMAND- 'g': to set the matrix to a given state by specifying each of the 22x10 characters in sequence**

#### CONTRIBUTE:

Although C is not the language to create games, it does a fantastic job at creating a terminal application for Linux. In its essence, this is what this program is. So, there are numerous areas for improvement in it. Here are a few ways you could help:  

* Read through the code and do a little code review.  
  * Comment on the readability of the code. Was it easy to read the code? Could you follow it?  
  * Comment on the division of tasks among functions or the control flow in the program.  
* Run the program on your machine and check for the robustness of the code. See if it behaves rationally for all kinds of input.  
* It would be really awesome if you decided to contribute some code.  
  * Try improving the documentation.  
  * Try fixing a bug you have found.  
  * Or, thought of a new feature to add to the game? Tell everyone about it by opening an issue. Better yet, write the code to add it!
* Or, help in any other way I might have missed.

All contributions are greatly appreciated. Please contact me for any queries or more information about the code or the project.  
Thank you!!  

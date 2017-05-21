Learntris
=======================
#### ABOUT THE GAME:
This program tries to implement the classic game of Tetris on a terminal. If you are not familar with the game, you can try it [here](http://tetris.com/play-tetris/).

The playing field is made up of a matrix (22 X 10).

The falling blocks are called tetraminos and as a physical unit in the game. There are 7 types of tetraminos that are named based on their shapes-
the I, the O, the S, the Z, the T, the J and the L tetramino.

#### THE FILEPLAN:
The following files have been added by me (author- [Nityesh Agarwal](https://github.com/nityeshaga)) to the [original fork](https://github.com/LearnProgramming/learntris):
* [matrix.c](https://github.com/nityeshaga/learntris/blob/master/matrix.c): contains all the functions that modify the 2D matrix.
* [tetramino.c](https://github.com/nityeshaga/learntris/blob/master/tetramino.c): contains all the functions that modify the tetramino.
* [learntris.c](https://github.com/nityeshaga/learntris/blob/master/learntris.c): links to the above mentioned files, contains the main() function and the functions that do not fall in the above mentioned categories. 
* [generic.c](https://github.com/nityeshaga/learntris/blob/master/generic.c): contains all functions that are need by more than one file.
* [matrix.h](https://github.com/nityeshaga/learntris/blob/master/matrix.h), [tetramino.h](https://github.com/nityeshaga/learntris/blob/master/tetramino.h): header files for matrix.c and tetramino.c.
* [generic.h](https://github.com/nityeshaga/learntris/blob/master/generic.h): header file for generic.c, also contains the struct definition of tetramino.
* [makefile](https://github.com/nityeshaga/learntris/blob/master/makefile): makefile for compiling learntris.
* [makefile.debug](https://github.com/nityeshaga/learntris/blob/master/makefile.debug): makefile for compiling for debugging with appropriate symbols.

All the other files provide a set of automated tests that will guide you through implementing your own version of
[Tetris](https://en.wikipedia.org/wiki/Tetris). These were provided by [LearnProgramming/learntris](https://github.com/LearnProgramming/learntris). [This will direct you to the readme page of that repo](https://github.com/LearnProgramming/learntris/blob/master/README.md#the-learntris-challenge).

#### HOW TO RUN:
1. Fork this repository
1. Pull the forked copy to your machine
1. Go to the downloaded directory (should be named- learntris)
1. On the terminal type: `make learntris`. This will compile the code.
1. Now type `./learntris`. This will run the game.

#### HOW TO PLAY:

*__NOTE__: All the commands implemented right now* (date- 21.05.17) *were created to pass the tests mentioned in [testplan.org](https://github.com/LearnProgramming/learntris/blob/master/testplan.org) in (https://github.com/LearnProgramming/learntris).*

*__NOTE__: This is a Work In Progress. So these instructions must be looked at as the features that have been currently implemented, in their most basic form, not instructions at playing a full fledged game. There are many bugs in the code, so many that almost every command can be broken using some set of input. Which means that you __will__ encounter some when you the code. So, if you do decide to run the code, please consider [contributing] to its development*

*__NOTE__: As this is a command line game, all commands mentioned here must be proceeded with a newline (implying that you need to press enter after each command) to execute them. You are allowed to enter multiple commands in one line but none of them will execute until you press enter.*

**COMMAND- 'q': quits the game instantly**  

As mentioned before, the playing field consists of 22 X 10 matrix like this:
. . . . . . . . . . #  0  
. . . . . . . . . . #  1  
. . . . . . . . . . #  2  
. . . . . . . . . . #  3  
. . . . . . . . . . #  4  
. . . . . . . . . . #  5  
. . . . . . . . . . #  6  
. . . . . . . . . . #  7  
. . . . . . . . . . #  8  
. . . . . . . . . . #  9  
. . . . . . . . . . # 10  
. . . . . . . . . . # 11  
. . . . . . . . . . # 12  
. . . . . . . . . . # 13  
. . . . . . . . . . # 14  
. . . . . . . . . . # 15  
. . . . . . . . . . # 16  
. . . . . . . . . . # 17  
. . . . . . . . . . # 18  
. . . . . . . . . . # 19  
. . . . . . . . . . # 20  
. . . . . . . . . . # 21  

The dots imply empty indices.  
**COMMAND- 'p': To view the current state of the matrix, press 'p'** (you won't be shown the number for each line as shown above).

Tetraminos are the basic building blocks of the game. In Learntris, they are implemented using letters of the English alphabet, where the alphabet corresponds to the colour of the respective tetramino.

There are 7 types of tetraminos-

* The I tetramino, colour- cyan:  
. . . .  
c c c c  
. . . .  
. . . .  

* The O tetramino, colour- yellow:
y y  
y y  

* The Z tetramino, colour- red:
r r .
. r r
. . .

* The S tetramino, colour- green:
. g g
g g .
. . .

* The J tetramino, colour- blue:
b . .
b b b
. . .

* The L tetramino, colour- orange:
. . o
o o o
. . .

* The T tetramino, colour- magneta:
. m .
m m m
. . .

**COMMAND- 'I', 'O', 'Z', 'S', 'J', 'L', 'T': pressing any of these selects the corresponding tetramino, places it on the matrix and makes it active**  
**COMMAND- 'P': prints the matrix along with the active tetramino**  
*__NOTE__: selecting a tetramino does not fix it to the matrix, therefore, it does not define it current state, which means that the command- 'p' will not show it on the matrix*

Now, that the tetramino is active, you can move it around in the matrix.  
**COMMAND- '>': moves the active tetramino one cell to the right, press '>'**  
**COMMAND- '<': moves the active tetarmino one cell to the left, press '<'**  
**COMMAND- 'v': moves the active tetramino one cell down, press 'v'**  
*__NOTE__: The tetramino is active after any of these movement commands, meaning that it is not fixed to the matrix*  

**COMMAND- 'V': hard drops the active tetramino** (moves it down in the current column as much as possible) **and fixes it at the position**  
After this command, the tetramino gets fixed to the matrix and goes in a permanent state of inactivity.  

The tetraminos can be rotated, any number of times, both clockwise and anti-clockwise.
**COMMAND- ')': rotates the active tetramino clockwise by 90 degrees**  
**COMMAND- '(': rotates the active tetramino anti-clockwise by 90 degrees**  

Here's an example illustrating the above commands:  

> T ( >>>> > Pq  
. . . . . . . . . M #  0  
. . . . . . . . M M #  1  
. . . . . . . . . M #  2  
. . . . . . . . . . #  3  
. . . . . . . . . . #  4  
. . . . . . . . . . #  5  
. . . . . . . . . . #  6  
. . . . . . . . . . #  7  
. . . . . . . . . . #  8  
. . . . . . . . . . #  9  
. . . . . . . . . . # 10  
. . . . . . . . . . # 11  
. . . . . . . . . . # 12  
. . . . . . . . . . # 13  
. . . . . . . . . . # 14  
. . . . . . . . . . # 15  
. . . . . . . . . . # 16  
. . . . . . . . . . # 17  
. . . . . . . . . . # 18  
. . . . . . . . . . # 19  
. . . . . . . . . . # 20  
. . . . . . . . . . # 21  

Here's another example:  

> TV ZV pq
. . . . . . . . . . #  0  
. . . . . . . . . . #  1  
. . . . . . . . . . #  2  
. . . . . . . . . . #  3  
. . . . . . . . . . #  4  
. . . . . . . . . . #  5  
. . . . . . . . . . #  6  
. . . . . . . . . . #  7  
. . . . . . . . . . #  8  
. . . . . . . . . . #  9  
. . . . . . . . . . # 10  
. . . . . . . . . . # 11  
. . . . . . . . . . # 12  
. . . . . . . . . . # 13  
. . . . . . . . . . # 14  
. . . . . . . . . . # 15  
. . . . . . . . . . # 16  
. . . . . . . . . . # 17   
. . . r r . . . . . # 18  
. . . . r r . . . . # 19  
. . . . m . . . . . # 20  
. . . m m m . . . . # 21  

Scoring:  
Whenever you are able to completely fill a row, you are eligible to add 100 points to your existing score.  
**COMMAND- 's': checks if a completely filled row is present in the matrix. If yes, then deletes the first appearance of such a row, shifts all rows above it one cell down and increases the score by 100 points**  
So, if you have 2 or more such rows, you need to enter the 's' command that many number of times.  
**COMMAND- '?n': queries the number of rows deleted and prints it**  
**COMMAND- '?s': queries the score and prints it**  

Miscellaneous commands:  
**COMMAND- '!': works as the pause/resume button**  
**COMMAND- '@': prints the title screen and effectively pauses the game until the resume button is pressed**  
**COMMAND- 'p': works after the '@' command is given and shows the menu**  

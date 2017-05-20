/*matrix.h HEADER FILE CONTAINS THE FUNCTION DECLARATIONS FOR matrix.c*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int empty_matrix(void);
int set_given_matrix(void);
int clear_row_matrix(int);
int nudge_right(tetramino);
int nudge_left(tetramino);
int move_down(tetramino);
int check_compatible(tetramino, int, int);

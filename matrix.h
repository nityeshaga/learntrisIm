/*matrix.h HEADER FILE CONTAINS THE FUNCTION DECLARATIONS FOR matrix.c*/

#include<stdio.h>
#include<ctype.h>

int empty_matrix(void);
int set_given_matrix(void);
int check_empty_row(int);
int clear_row_matrix(int);
int nudge_right(int, int);
int nudge_left(int, int);
int move_down(int, int);
int check_empty(int, int, int, int);

#define TOP 1
#define BOTTOM -1
#define RIGHT 2
#define LEFT -2
#define ALL 0


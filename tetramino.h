/*tetramino.h HEADER FILE CONTAINS THE FUNCTION DECLARATIONS FOR tetramino.c*/

#include<stdio.h>
#include<stdlib.h>

int select_tetramino(char type);
int display_tetramino(void);
int rotate(char);
int nempty_rows(int);
int nempty_columns(int);
void calc_emptiness(void);

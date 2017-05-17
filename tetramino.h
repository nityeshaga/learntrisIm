/*tetramino.h HEADER FILE CONTAINS THE FUNCTION DECLARATIONS FOR tetramino.c*/

#include<stdio.h>
#include<stdlib.h>

int select_tetramino(char type);
int display_tetramino(void);
int rotate(char);
int nempty_rows(int);
int nempty_columns(int);

typedef struct tetramino
{
	char **array;
	int dimension;
} tetramino;

#define TOP 1
#define BOTTOM -1
#define RIGHT 2
#define LEFT -2
#define ALL 0


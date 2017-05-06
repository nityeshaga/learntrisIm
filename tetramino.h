/*tetramino.h HEADER FILE CONTAINS THE FUNCTION DECLARATIONS FOR tetramino.c*/

#include<stdio.h>
#include<stdlib.h>

int select_tetramino(char type);
int display_tetramino(void);
int rotate_cw(void);

typedef struct tetramino
{
	char **array;
	int dimension;
} tetramino;



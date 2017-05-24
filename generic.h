#include<stdio.h>
#include<stdlib.h>

#define TOP 0
#define BOTTOM 1
#define RIGHT 2
#define LEFT 3
#define ALL -1
#define ROW 10
#define COLUMN 11

typedef struct tetramino
{
	char **array;	/*2D matrix that stores the tetramino shape*/
	int dimension;	/*length of side of square matrix that stores the tetramino*/
	char *n_empty;	/*no. of empty rows/columns from the TOP, BOTTOM, RIGHT OR LEFT of the tetramino matrix*/
	int fix;		/*flags if the tetramino has been fixed to the matrix*/
} tetramino;

int check_empty(int, char *, int);
int check_empty_column(int new_home, char **array, int, int);
int array_init(char ***array, int nrows, int ncolumns);
int is_compatible(char matrix[22][10], tetramino selected, int ar, int ac);

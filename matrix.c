/*THIS FILE CONTAINS ALL THE VARIABLES AND FUNCTION DEFINITIONS REQUIRED TO IMPLEMENT AND OPERATE ON THE MATRIX*/

#include"matrix.h"

/*the data structure chosen for the matrix must allow for frequent data insertions and deletions at any desired position
 *it should also allow us to rewrite the whole matrix
 *a 2D array seems to be the appropriate choice for the data structure*/
char matrix[22][10];

int active_row= -1;
int active_column= -1;

/*empty_matrix(): assigns '.' to the Matrix elements*/
int empty_matrix(void)
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			matrix[i][j]= '.';
	}
	return 0;
}

/*set_given_matrix(): sets the Matrix to 'given'*/
int set_given_matrix(void)
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j) {
			char c= getchar();
			if(c==' ' || c=='\n'){
				--j;
				continue;
			}
			else
				matrix[i][j]= c;
		}
	}
	return 0;
}

/*check_empty_row(): checks if the specified 'row' is empty; returns 1 if empty and 0 if non-empty*/
int check_empty_row(int row)
{
	int status= 1;
	int i;
	for(i= 0; i< 10; ++i) {
		if(matrix[row][i]!='.') {
			status= 0;
			break;
		}
	}
	return status;
}

/*clear_row_matrix(): clears a specified row*/
int clear_row_matrix(int row)
{
	int i;
	for(i= 0; i< 10; ++i)
		matrix[row][i]= '.';
	return 0;
}

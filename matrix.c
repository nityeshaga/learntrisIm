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
int check_empty_row(int row) //see the function check_empty()
							 //and use that instead
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

/*nudge_right(): nudges the active tetramino to the right if possible*/
int nudge_right(int nempty_col, int dimension)
{
	int new_home= active_column + (dimension-nempty_col);
	if(new_home < 10) 
		if(check_empty(new_home, LEFT, dimension, 0))
			++active_column;
	else 
		return -1;
	return 0;
}

/*nudge_left(): nudges the active tetramino to the left if possible*/
int nudge_left(int nempty_col, int dimension)
{
	int new_home= active_column + nempty_col;// - 1;	//it must be
												//active_column + nempty_col -1
	if(new_home> 0) 
		if(check_empty(new_home, LEFT, dimension, 0))
			--active_column;
	else 
		return -1;
	return 0;
}

/*move_down(): moves the active tetramino down if possible*/
int move_down(int nempty_row, int dimension)
{
	int new_home= active_row+ (dimension-nempty_row);
	if(new_home < 22)
		if(check_empty(new_home, BOTTOM, dimension, nempty_row))
			++active_row;
	else
		return -1;
	return 0;
}

/*check_empty(): checks if the specified portion of a specified row/column in the matrix is empty*/
int check_empty(int index, int direction, int dimension, int fix) //change the function definition
														 //the function should simply accept an index, 
														 //a flag identifying it as a row or column and the dimension
														 //UPDATE: NOTE THAT THIS IS EXACTLY WHAT THE FUNCTION IS DOING
														 //JUST NEED TO USE BETTER NAMES
{
	switch(direction) {
		case BOTTOM:
			{
				int i;
				for(i= active_column+ fix; i< active_column + dimension - 1; ++i)
					if(matrix[index][i]!='.')
						return 0;
				return 1;
			}
			break;

		case LEFT:
			{
				int i;
				for(i= active_row; i< active_row + dimension-1; ++i)
					if(matrix[i][index]!='.')
						return 0;
				return 1;
			}
			break;

		default:
			return 0;
	}
}

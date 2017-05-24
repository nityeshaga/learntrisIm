/*THIS FILE CONTAINS ALL THE VARIABLES AND FUNCTION DEFINITIONS REQUIRED TO MODIFY THE MATRIX*/

#include"generic.h"
#include"matrix.h"

/*the data structure chosen for the matrix must allow for frequent data insertions and deletions at any desired position
 *it should also allow us to rewrite the whole matrix
 *a 2D array seems to be the appropriate choice for the data structure*/
char matrix[22][10];

int active_row= -1;
int active_column= -1;

/*empty_matrix(): empties the matrix by assigning '.' to the matrix elements*/
int empty_matrix(void)
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			matrix[i][j]= '.';
	}
	return 0;
}

/*set_given_matrix(): sets the Matrix to given*/
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

/*clear_row_matrix(): clears a specified 'row'*/
int clear_row_matrix(int row)
{
	int i;
	for(i= 0; i< 10; ++i)
		matrix[row][i]= '.';
	return 0;
}

/*nudge_right(): nudges the 'selected' tetramino to the right if possible*/
int nudge_right(tetramino selected)
{
	int new_home= active_column + 1;
	if(new_home < 10- ((selected.dimension-1)- selected.n_empty[RIGHT])) {
		if(is_compatible(matrix, selected, active_row, new_home))
			active_column= new_home;
		else
			return -1;
	}
	else
		return -1;
	return 0;
}

/*nudge_left(): nudges the active tetramino to the left if possible*/
int nudge_left(tetramino selected)
{
	int new_home= active_column - 1; 
	if(new_home+selected.n_empty[LEFT]>=0) {
		if(is_compatible(matrix, selected, active_row, new_home))
			active_column= new_home;
		else
			return -1;
	}
	else 
		return -1;
	return 0;
}

/*move_down(): moves the active tetramino down if possible*/
int move_down(tetramino selected)
{
	int new_home= active_row+1;
	int range= selected.dimension- selected.n_empty[BOTTOM];
	if(new_home < 22- (range- 1)) {
		if(is_compatible(matrix, selected, new_home, active_column))
			active_row= new_home;
	}
	else
		return -1;
	return 0;
}

/*shift_down(): shifts all the rows above the 'subject' row, down*/
void shift_down(int subject)
{
	int i;
	for(i= subject-1; i>=0; --i) {
		if(check_empty_row(&matrix[i][0], 10)) {
			break;
		}
		else {
			int j;
			for(j= 0; j< 10; ++j)
				matrix[i+1][j]= matrix[i][j];
		}
	}
	clear_row_matrix(i+1);
}

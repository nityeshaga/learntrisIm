/*THIS FILE CONTAINS ALL THE FUNCTION AND OTHER DEFINITIONS REQUIRED BY MORE THAN ONE FILE*/

#include"generic.h"

/*check_empty_row(): checks if the row of a square matrix of side length 'dimension', starting with the element at address 'start' is empty for the next 'dimension' no. of elements*/
int check_empty_row(char *start, int dimension)
{
	int flag= 0;	/*flags if a non-empty character is found*/
	int i;
	for(i= 0; i< dimension; ++i) {
		if(*(start+i)!= '.') {
			flag= 1;
			break;
		}
	}
	return !flag;
}

/*check_empty_column(): checks if the column specified by 'new_home' in the 'array' is empty, starting with 'active_row', for next 'dimension' no. of elements*/
int check_empty_column(int new_home, char array[4][4], int active_row, int dimension)
{
	int flag= 0;
	int i;
	for(i= 0; i< dimension; ++i) {
		if(check_empty_row(&array[active_row+i][new_home], 1)==0) {
			flag= 1;
			break;
		}
	}
	if(flag==0)
		return 1;
	else
		return 0;
}

/*check_compatible(): returns 1 if the 'selected' tetramino can be placed with it 1st element at ['ar', 'ac']*/
int is_compatible(char matrix[22][10], tetramino selected, int ar, int ac)
{
	int flag= 1;	/*flags if the tetramino is compatible*/
	int i, j;
	for(i= ar; i< ar+selected.dimension; ++i) {
		for(j= ac; j< ac+selected.dimension; ++j) {
			if(matrix[i][j]!='.' && selected.array[i-ar][j-ac]!='.') {
				flag= 0;
				break;
			}
		}
	}

	return flag;
}

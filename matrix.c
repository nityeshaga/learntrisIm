/*THIS FILE CONTAINS ALL THE VARIABLES AND FUNCTION DEFINITIONS REQUIRED TO IMPLEMENT AND OPERATE ON THE MATRIX*/

#include"matrix.h"

char matrix[22][10];

/*print_matrix(): prints the current state of the matrix*/
int print_matrix()
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			printf("%c ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}

/*set_to_dot(): assigns '.' to the Matrix elements*/
int set_to_dot()
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			matrix[i][j]= '.';
	}
	return 0;
}

/*set_to_given(): sets the Matrix to 'given'*/
int set_to_given()
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

/*check_empty(): checks if the specified 'row' is empty; returns 1 if empty and 0 if non-empty*/
int check_empty(int row)
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

/*clear_row(): clears a specified row*/
int clear_row(int row)
{
	int i;
	for(i= 0; i< 10; ++i)
		matrix[row][i]= '.';
	return 0;
}


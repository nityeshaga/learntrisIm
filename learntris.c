/*THIS FILE CONTAINS THE main() FUNCTION WHICH MAKES ALL THE NECESSARY ABSTRACT FUNCTION CALLS*/

#include<stdio.h>

#include"tetramino.h"

int print_matrix(char matrix[22][10]);
int set_to_dot(char matrix[22][10]);
int set_to_given(char matrix[22][10]);
int check_empty(char matrix[22][10], int row);
int clear_row(char matrix[22][10], int row);

char getnext();

char matrix[22][10];
int s= 0; /*register to store score*/
int n= 0; /*register to store no of cleared lines*/

int main(void)
{
	if(set_to_dot(matrix)) {
		printf("Error in initializing\n");
		return 1;
	}
	char input;
	do {
	
		input= getnext();
		switch(input) {

			/* select the appropriate tetramino*/
			case 'I':
			case 'O':
			case 'Z':
			case 'S':
			case 'J':
			case 'L':
			case 'T':
				select_tetramino(input);
				break;

			/*display the active tetramino*/
			case 't':
				display_tetramino();
				break;

			/*rotate the active tetramino*/
			case ')':
				rotate_cw();
				break;

			/*put a newline on the output*/
			case ';':
				putchar('\n');
				break;

			/* p: prints current Matrix state*/
			case 'p':
				if(print_matrix(matrix)) {
					printf("Error in printing\n");
					return 1;
				}
				break;

			/* g: sets Matrix to 'given'*/
			case 'g':
				if(set_to_given(matrix)) {
					printf("Error in setting matrix to given input");
					return 1;
				}
				break;

			/* c: clears the Matrix*/
			case 'c':
				if(set_to_dot(matrix)) {
					printf("Error setting matrix to dot");
					return 1;
				}
				break;

			/* ?: query*/
			case '?':
				input= getnext();

				/*note- a different switch case is needed as the symbols of query commands overlap with the regular ones*/
				switch(input) {
					/* ?s: query score*/
					case 's':
						printf("%d\n", s);
						break;
					
					/* ?n: query number of cleared lines*/
					case 'n':
						printf("%d\n", n);
						break;
					break;
				}

				break;

			/* s: one 'step' of the simulation*/
			case 's': 
				{
					int i;
					for(i= 0; i< 22; ++i) {
						if(!check_empty(matrix, i)) {
							if(clear_row(matrix, i)) {
								printf("Unable to clear\n");
								return 1;
							}
							else {
								s+=100;
								n+=1;
							}
							break;
						}
					}
				}
				break;

			/* q: quits*/
			case 'q':
				break;

			default:
				;//printf("%c. /*Not implemented*/", input);/*test 2 failed: //it takes '.' as a value of input*/
		}
	}
	while(input!='q');
	return 0;
}

/*print_matrix(): prints the current state of the matrix*/
int print_matrix(char matrix[22][10])
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
int set_to_dot(char matrix[22][10])
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			matrix[i][j]= '.';
	}
	return 0;
}

/*set_to_given(): sets the Matrix to 'given'*/
int set_to_given(char matrix[22][10])
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
int check_empty(char matrix[22][10], int row)
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
int clear_row(char matrix[22][10], int row)
{
	int i;
	for(i= 0; i< 10; ++i)
		matrix[row][i]= '.';
	return 0;
}

/*getnext(): returns the next non-space character in the buffer*/
char getnext()
{
	char c= ' ';
	while(c==' ' || c=='\n' || c=='\t')
		c= getchar();
	return c;
}

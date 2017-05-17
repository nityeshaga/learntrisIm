#include<stdio.h>

#include"matrix.h"
#include"tetramino.h"

extern int active_row;
extern int active_column;
extern tetramino selected;
extern char matrix[22][10];

void tetramino_on_matrix(void);
char getnext(void);
int print_matrix(char input);
int collide(void);
void calliberate(void);


int s= 0; /*register to store score*/
int n= 0; /*register to store no of cleared lines*/

int main(void)
{
	if(empty_matrix()) {
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
				tetramino_on_matrix();
				select_tetramino(input);
				active_row= 0;
				active_column= selected.dimension==2? 4: 3; 
				//calliberate();
				break;

			/*display the active tetramino*/
			case 't':
				display_tetramino();
				break;

			/*rotate the active tetramino clockwise*/
			case ')':
				rotate(input);
				//calliberate();
				break;

			/*rotate the active tetramino anti-clockwise*/
			case '(':
				rotate(input);
				//calliberate();
				break;
			/*put a newline on the output*/
			case ';':
				putchar('\n');
				break;

			/* p: prints current Matrix state*/
			case 'p':
				if(print_matrix(input)) {
					printf("Error in printing\n");
					return 1;
				}
				break;

			/* g: sets Matrix to 'given'*/
			case 'g':
				if(set_given_matrix()) {
					printf("Error in setting matrix to given input");
					return 1;
				}
				break;

			/* c: clears the Matrix*/
			case 'c':
				if(empty_matrix()) {
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
						if(!check_empty_row(i)) {
							if(clear_row_matrix(i)) {
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

			/* P: prints the matrix along with the active tetramino*/
			case 'P':
				print_matrix(input);
				break;

			/* >: nudges the active tetramino one cell to the right*/
			case '>':
				nudge_right(nempty_columns(RIGHT), selected.dimension); 
				break;

			/* <: nudges the active tetramino one cell to the left*/
			case '<':
				nudge_left(nempty_columns(LEFT), selected.dimension);
				break;

			/* v: moves the active tetramino on cell downward*/
			case 'v':
				move_down(nempty_rows(BOTTOM), selected.dimension);
				break;
		
			/* V: hard drop*/
			case 'V':
				active_row= collide();
				tetramino_on_matrix();
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

/*getnext(): returns the next non-space character in the buffer*/
char getnext()
{
	char c= ' ';
	while(c==' ' || c=='\n' || c=='\t')
		c= getchar();
	return c;
}

/*tetramino_on_matrix(): fixes the tetramino permanently the on the matrix*/
void tetramino_on_matrix(void)
{
	int i, j;
	for(i= 0; i<22; ++i) {
		for(j= 0; j<10; ++j) {
			if(i>=active_row && j>=active_column && i<active_row+selected.dimension && j<active_column+selected.dimension && matrix[i][j]=='.')
				matrix[i][j]= selected.array[i-active_row][j-active_column];
		}
	}
}

/*print_matrix(): prints either the current state of the matrix(P) or the past one(p)*/
int print_matrix(char input)
{
	switch(input) {
	case 'p':
		{
			int i, j;
			for(i= 0; i< 22; ++i) {
				for(j= 0; j< 10; ++j)
					printf("%c ", matrix[i][j]);
				printf("\n");
			}
			return 0;
		}
		break;

	case 'P':
		{
			int i, j;
			for(i= 0; i<22; ++i) {
				for(j= 0; j<10; ++j) {
					if((i>=active_row && i<active_row+selected.dimension) && (j>=active_column && j<active_column+selected.dimension)) {
						if(matrix[i][j]=='.')
							printf("%c ", toupper(selected.array[i-active_row][j-active_column]));
						else
							printf("%c ", matrix[i][j]);
					}
					else
						printf("%c ", matrix[i][j]);
				}
				printf("\n");
			}
			return 0;
		}
		break;
	}
}

/*collide(): returns the row index where the tetramino needs to begin in order to have the collision with maximum fitting;*/
int collide(void)
{
	int ar= active_row;
	int ac= active_column;

	/*find the last row in matrix that has empty space for the tetramino*/
	int last_e_row= -1;
	int i, j;
	int flag= 0;	/*flags if non-'.' character is found*/
	for(i= ar+1; i< 22; ++i) {
		if(!check_empty(i, BOTTOM, selected.dimension, 0))
			break;
	}
	last_e_row= i-1;
	last_e_row-= (selected.dimension-1);
	ar= last_e_row;

	/*fix according to empty rows in the tetramino*/
	int ne_row_tetramino= nempty_rows(BOTTOM);
	ar+= ne_row_tetramino;

	/*check if the end of selected tetramino fits in the row after the last one*/
	int fix= 1;
	for(i= 0; i< selected.dimension; ++i) {
		if(selected.array [(selected.dimension-1)- ne_row_tetramino][i]!='.') {
			if(matrix [ar+ selected.dimension][ac+ i]!='.') {
				fix= 0;
				break;
			}
		}
	}
	ar+=fix;
	return ar;
}

/*calliberate(): calliberates the active row and column to correct position according to the orientation of tetramino*/
/*
void calliberate(void)
{
	int flag= 0;*/	/*flags if the row/column is non-empty*/
	/*
	int i;
	int add_r= 0, add_c= 0;
*/

	/*calliberate active row*/
	/*for(i= 0; i<=selected.dimension; ++i) {
		if(i==selected.dimension && flag==0) {
			++add_r;
			i= -1;
		}
		else if(i<selected.dimension && selected.array[add_r][i]!='.')
			flag= 1;
	}
	active_row+=add_r;
*/

	/*calliberate active column*/
	/*
	for(i= 0; i<=selected.dimension; ++i) {
		if(i==selected.dimension && flag==0) {
			++add_c;
			i= 0;
		}
		else if(i<selected.dimension && selected.array[i][add_c]!='.')
			flag= 1;
	}
	active_column+=add_c;
}
*/

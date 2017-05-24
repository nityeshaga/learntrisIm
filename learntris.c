#include<stdio.h>

#include"generic.h"
#include"matrix.h"
#include"tetramino.h"

#define MAXREAD 100

//#define TESTING	/*uncomment this line when running testris.py*/

extern int active_row;
extern int active_column;
extern tetramino selected;
extern char matrix[22][10];

void tetramino_on_matrix(void);
char getnext(void);
int print_matrix(char input);
int collide(void);
void print_menu(void);

int s= 0; /*register to store score*/
int n= 0; /*register to store no of cleared lines*/
int game_over= 0;	/*flags if the game is over*/

int main(void)
{

	if(empty_matrix()) {
		printf("Error in initializing\n");
		return 1;
	}
	char input;

	#ifndef TESTING
	printf("Learntris (c) 1992 Tetraminex, Inc.\n"
			"Press 'p' for help\n");
	do {
		input= getnext();

		switch(input) {

			/* 'p': print menu*/
			case 'p':
				printf( "1. Press start button ('!') to begin.\n"
						"2. Press 'q' to quit\n");
				break;

			/* 'q': quit game*/
			case 'q':
				printf("Quitting.\n");
				return 0;
				break;

			case '!':
				;
				break;

			default:
				printf("Invalid input\n");
		}
	}
	while(input!='!');
	#endif

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

				/*fix the existing tetramino to the matrix if not fixed already*/
				if(selected.dimension!=0 && !selected.fix) {
					if(active_row==22- (selected.dimension- selected.n_empty[BOTTOM]))
						tetramino_on_matrix();
					else {
						active_row= collide();
						tetramino_on_matrix();
					}
				}

				select_tetramino(input);
				active_row= 0;
				active_column= selected.dimension==2? 4: 3; 
				break;

			/*display the active tetramino*/
			case 't':
				display_tetramino();
				break;

			/*rotate the active tetramino clockwise*/
			case ')':
			/*rotate the active tetramino anti-clockwise*/
			case '(':
				{
					tetramino test;
					test= rotate(input);

					if(test.dimension==0)
						printf("Select a tetramino first\n");

					/*update 'selected' only if the new configuration is compatible*/
					if(is_compatible(matrix, test, active_row, active_column)) {
						free(selected.n_empty);
						selected= test;
					}
					/*no rotation happens otherwise*/
					else {
						free(test.n_empty);
					}

				}
				break;

			/*put a newline on the output*/
			case ';':
				putchar('\n');
				break;

			/* p: prints current matrix state*/
			case 'p':
				if(print_matrix(input)) {
					printf("Error in printing\n");
					return 1;
				}
				break;

			/* g: sets matrix to 'given'*/
			case 'g':
				if(set_given_matrix()) {
					printf("Error in setting matrix to given input");
					return 1;
				}
				break;

			/* c: clears the matrix*/
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
					int flag;	/*flags if a full row is found*/
					/*find the first completely full row in matrix if present*/
					int i, j;
					for(i= 0; i< 22; ++i) {
						flag= 1;
						for(j= 0; j< 10; ++j) {
							if(matrix[i][j]=='.') {
								flag= 0;
								break;
							}
						}
						if(flag)
							break;
					}

					if(flag) {
						if(clear_row_matrix(i)) {
							printf("Unable to clear\n");
							return 1;
						}
						else {
							s+=100;
							n+=1;
							#ifndef TESTING
							print_matrix('p');
							shift_down(i);
							#endif
						}
						break;
					}
				}
				break;

			/* P: prints the matrix along with the active tetramino*/
			case 'P':
				print_matrix(input);
				break;

			/* >: nudges the active tetramino one cell to the right*/
			case '>':
				nudge_right(selected);
				break;

			/* <: nudges the active tetramino one cell to the left*/
			case '<':
				nudge_left(selected);
				break;

			/* v: moves the active tetramino on cell downward*/
			case 'v':
				move_down(selected);
				break;
		
			/* V: hard drop*/
			case 'V':
				active_row= collide();
				tetramino_on_matrix();
				break;

			/* q: quits*/
			case 'q':
				break;

			/* '@': print start screen*/
			case '@':
				printf("Learntris (c) 1992 Tetraminex, Inc.\n");
				do {
				input= getnext();

					switch(input) {

						/* 'p': print menu*/
						case 'p':
							printf("Press start button to begin.\n");
							break;

						default:
							;
					}
				}
				while(input!='!');
				break;

			/* '!': pause*/
			case '!':
				printf("Paused\n");
				do {
				input= getnext();

					switch(input) {

						/* 'p': print menu*/
						case 'p':
							printf("Press start button to continue.\n");
							break;

						default:
							;
					}
				}
				while(input!='!');
				break;

			default:
				;
		}

		#ifndef TESTING
		/*check game over*/
		if(game_over) {
			printf("Game Over\n");
			break;
		}
		#endif
	}
	while(input!='q');
		
	if(game_over) {
		printf("Game Over\n");
	}

	return 0;
}

/*getnext(): returns the next non-space character in the buffer*/
char getnext(void)
{
	char c= ' ';
	while(c==' ' || c=='\n')
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
	selected.fix= 1;

	/*check game over*/
	if(active_row==0) {
		game_over= 1;
	}
}

/*print_matrix(): prints either the current state of the matrix(p) or the expected one(P)*/
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
	int flag= 0;	/*flags if non-empty row is found*/
	int i, j;
	for(i= ar+1; i< 22; ++i) {
		for(j= ac+selected.n_empty[LEFT]; j< ac+ selected.dimension- selected.n_empty[RIGHT]; ++j) {
			if(matrix[i][j]!='.') {
				flag= 1;
				break;
			}
		}
		if(flag)
			break;
	}
	last_e_row= i-1;
	ar= last_e_row;

	/*fix according to the rows in the tetramino*/
	ar-= (selected.dimension-1);
	ar+= selected.n_empty[BOTTOM];

	/*check if the end of selected tetramino fits in the next possible row (which is obviously non-empty)*/
	int fix= 1;
	for(i= selected.n_empty[LEFT]; i< selected.dimension- selected.n_empty[RIGHT]; ++i) {
		if((ar+ selected.dimension- selected.n_empty[BOTTOM])>21) {	/*if 'ar' is the last possible row in the matrix*/
			fix= 0;
			break;
		}
		else if(matrix [ar+ selected.dimension- selected.n_empty[BOTTOM]][ac+ i]!='.' && selected.array[selected.dimension-selected.n_empty[BOTTOM]-1][i]!='.') {
			fix= 0;
			break;
		}
	}
	ar+=fix;
	return ar;
}

/*print_menu(): prints the menu*/
void print_menu(void) {
	printf("Press start button to begin\n");
}

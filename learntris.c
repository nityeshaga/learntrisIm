/*THIS FILE CONTAINS THE main() FUNCTION WHICH MAKES ALL THE NECESSARY ABSTRACT FUNCTION CALLS*/

#include<stdio.h>

#include"tetramino.h"
#include"matrix.h"

char getnext();

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
				if(print_matrix()) {
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

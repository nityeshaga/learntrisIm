#include<stdio.h>
int print_state(char state[22][10]);
int set_to_dot(char state[22][10]);
int set_to_given(char state[22][10]);

int main(void)
{
	char state[22][10];
	if(set_to_dot(state)) {
		printf("Error in initializing\n");
		return 1;
	}
	char input;
	scanf("%c", &input);
	switch(input) {

		/* q: quits*/
		case 'q':
			break;

		/* p: prints Matrix*/
		case 'p':
			if(print_state(state)) {
				printf("Error in printing\n");
				return 1;
			}
			break;

		/* g: sets Matrix to 'given'*/
		case 'g':
			if(set_to_given(state)) {
				printf("Error in setting matrix to given input");
				return 1;
			}
			else {
				if(print_state(state)) {
					printf("Error printing the Matrix");
					return 1;
				}
			}
			break;

		/* c: clear the Matrix*/
		case 'c':
			if(set_to_dot(state)) {
				printf("Error setting matrix to dot");
				return 1;
			}
			else {
				if(print_state(state)) {
					printf("Error printing\n");
					return 1;
				}
			}
			break;
		default:
			printf("/*Not implemented*/");
	}
	return 0;
}

/*print_state(): prints the current state of the matrix*/
int print_state(char state[22][10])
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			printf("%c ", state[i][j]);
		printf("\n");
	}
	return 0;
}

/*set_to_dot(): assigns '.' to the Matrix elements*/
int set_to_dot(char state[22][10])
{
	int i, j;
	for(i= 0; i< 22; ++i) {
		for(j= 0; j< 10; ++j)
			state[i][j]= '.';
	}
	return 0;
}

/*set_to_given(): sets the Matrix to 'given'*/
int set_to_given(char state[22][10])
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
				state[i][j]= c;
		}
	}
	return 0;
}

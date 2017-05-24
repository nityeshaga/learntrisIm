/*tetramino.c FILE CONTAINS ALL THE VARIABLES AND FUNCTION DEFINITIONS REQUIRED TO MODIFY THE TETRAMINOS*/

#include"generic.h"
#include"tetramino.h"

tetramino selected= {NULL, 0, NULL, 0};

/*select_tetramino(): assigns the appropriate properties of 'type' tetramino to the selected tetramino variable*/
int select_tetramino(char type)
{
	if(selected.array!=NULL) {
		free(selected.array[0]);
		free(selected.array);
	}

	selected.fix= 0;
	selected.dimension= 4;
	selected.n_empty= (char *)malloc(sizeof(char) * 4);
	array_init(&selected.array, selected.dimension, selected.dimension);

	switch(type) {
		case 'I':
			{
				selected.dimension= 4;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==1) {
							selected.array[i][j]= 'c';
							continue;
						}
							selected.array[i][j]= '.';
					}
			}
			break;

		case 'O':
			{
				selected.dimension= 2;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i<2 && j<2)
							selected.array[i][j]= 'y';
						else
							selected.array[i][j]= '.';
					}
			}
			break;

		case 'Z':
			{
				selected.dimension= 3;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==0) {
							if(j==0 || j==1) {
								selected.array[i][j]= 'r';
								continue;
							}
						}
						else if(i==1)
							if(j==1 || j==2) {
								selected.array[i][j]= 'r';
								continue;
							}
						selected.array[i][j]= '.';
					}
			}
			break;

		case 'S':
			{
				selected.dimension= 3;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==0) {
							if(j==1 || j==2) {
								selected.array[i][j]= 'g';
								continue;
							}
						}
						else if(i==1)
							if(j==0 || j==1) {
								selected.array[i][j]= 'g';
								continue;
							}
						selected.array[i][j]= '.';
					}
			}
			break;
			
		case 'J':
			{
				selected.dimension= 3;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==0) {
							if(j==0) {
								selected.array[i][j]= 'b';
								continue;
							}
						}
						else if(i==1 && j<3) {
							selected.array[i][j]= 'b';
							continue;
						}
						selected.array[i][j]= '.';
					}
			}
			break;

		case 'L':
			{
				selected.dimension= 3;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==0) {
							if(j==2) {
								selected.array[i][j]= 'o';
								continue;
							}
						}
						else if(i==1 && j<3) {
							selected.array[i][j]= 'o';
							continue;
						}
						selected.array[i][j]= '.';
					}
			}
			break;

		case 'T':
			{
				selected.dimension= 3;
				int i, j;
				for(i= 0; i< selected.dimension; ++i)
					for(j= 0; j< selected.dimension; ++j) {
						if(i==0) {
							if(j==1) {
								selected.array[i][j]= 'm';
								continue;
							}
						}
						else if(i==1 && j<3) {
							selected.array[i][j]= 'm';
							continue;
						}
						selected.array[i][j]= '.';
					}
			}
			break;

		default:
			return 1;
	}
	calc_emptiness(selected);
	return 0;
}

/*display_tetramino(): displays the selected tetramino*/
int display_tetramino(void)
{
	int i, j;

	if(selected.dimension==0) /*ERROR: tetramino not selected*/
		return 1;

	for(i= 0; i< selected.dimension; ++i) {
		for(j= 0; j< selected.dimension; ++j)
			printf("%c ", selected.array[i][j]);
		printf("\n");
	}
	return 0;
}

/*rotate(): rotates the tetramino clockwise or anticlockwise as directed by 'type' by 90 degrees*/
tetramino rotate(char type)
{
	if(selected.dimension==0)
		return selected;

	/*create a tetramino variable-temp*/
	tetramino temp= {NULL, 0, NULL};
	temp.dimension= selected.dimension;
	array_init(&temp.array, temp.dimension, temp.dimension);
	temp.n_empty= (char *)malloc(sizeof(char) * 4);

	int i, j, k;
	/*initialize temp.array to store '.'*/
	for(i= 0; i< selected.dimension; ++i)
		for(j= 0; j< selected.dimension; ++j)
			temp.array[i][j]= '.';

	/*store the rotated version on temp variable*/
	/*clockwise rotation*/
	if(type==')') {
		for(i= temp.dimension-1, k= 0; i>= 0; --i, ++k)
			for(j= 0; j<temp.dimension; ++j)
				temp.array[j][i]= selected.array[k][j];
	}
	/*anti-clockwise rotation*/
	else if(type=='(') {
		for(i= 0; i< temp.dimension; ++i)
			for(j= temp.dimension-1, k= 0; j>=0; --j, ++k)
				temp.array[j][i]= selected.array[i][k];
	}

	calc_emptiness(temp);

	return temp;
}

/*calc_emptiness(): evaluates the no. of empty rows and columns in the 'selected's 2D array and makes appropriate changes*/
void calc_emptiness(tetramino selected)
{
	int i;
	for(i= 0; i< 4; ++i)
		selected.n_empty[i]= 0;

	/*from the LEFT*/
	i= 0;
	while(i< selected.dimension && check_empty_column(i, selected.array, 0, selected.dimension)) {
		++i;
		++selected.n_empty[LEFT];
	}

	/*from the RIGHT*/
	i= selected.dimension-1;
	while(i>=0 && check_empty_column(i, selected.array, 0, selected.dimension)) {
		--i;
		++selected.n_empty[RIGHT];
	}

	/*from the TOP*/
	i= 0;
	while(i< selected.dimension && check_empty_row(&selected.array[i][0], selected.dimension)) {
		++i;
		++selected.n_empty[TOP];
	}
	
	/*from the BOTTOM*/
	i= selected.dimension-1;
	while(i>=0 && check_empty_row(&selected.array[i][0], selected.dimension)) {
		--i;
		++selected.n_empty[BOTTOM];
	}
}

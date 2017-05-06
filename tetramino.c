/*tetramino.c FILE CONTAINS ALL THE VARIABLES AND FUNCTION DEFINITIONS REQUIRED FOR IMPLEMENTING AND OPERATING ON THE TETRAMINOS*/

#include"tetramino.h"

//static tetramino_init(tetramino var);

tetramino selected= {NULL, 0};

/*select_tetramino(): assigns the appropriate properties of 'type' tetramino to the 'selected' tetramino variable*/
int select_tetramino(char type)
{
	selected.dimension= 4;
	selected.array= (char **)malloc(sizeof(char *) * selected.dimension);
	selected.array[0]= (char *)malloc(sizeof(char) * selected.dimension * selected.dimension);
	int i; 
	for(i= 0; i< selected.dimension; i++)
		selected.array[i]= (*selected.array + selected.dimension * i);

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

/*rotate_cw(): rotates the tetramino clockwise by 90 degrees*/
int rotate_cw(void)
{
	if(selected.dimension==0)
		return 1;

	/*create a tetramino variable-temp*/
	tetramino temp= {NULL, 0};
	temp.dimension= selected.dimension;
	temp.array= (char **)malloc(sizeof(char *) * temp.dimension);
	temp.array[0]= (char *)malloc(sizeof(char) * temp.dimension * temp.dimension);
	int i, j, k; 
	for(i= 0; i< temp.dimension; i++)
		temp.array[i]= (temp.array[0] + temp.dimension * i);

	/*initialize temp.array to store '.'*/
	for(i= 0; i< selected.dimension; ++i)
		for(j= 0; j< selected.dimension; ++j)
			temp.array[i][j]= '.';

	/*store the rotated version on temp variable*/
	for(i= temp.dimension-1, k= 0; i>= 0; --i, ++k)
		for(j= 0; j<temp.dimension; ++j)
			temp.array[j][i]= selected.array[k][j];

	/*change the address stored on selected.array*/
	selected.array= temp.array;
	return 0;
}

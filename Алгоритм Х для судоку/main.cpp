#include "DancingLinks.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void printHelp()
{
	printf("Error syntax\n\
Usage: DancingLinks.exe <X> <Path>\n\
\n\
\t<X> - Number of cells vertically and horizontally\n\
\t<Path> - Path to input file with target sudoku\n\
\n\
All parameters are required to enter\n");
}

int readInputFile(int matrix[9][9], const char *path, int numb_cells)
{
	FILE* fp = fopen(path, "r");

	for(int i = 0; i< numb_cells; i++)
		for (int j = 0; j < numb_cells; j++)
		{
			fscanf(fp, "%d ", &matrix[i][j]);
		}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printHelp();
		exit(-1);
	}
	int numb_cells = argv - '0';
	int N = P * P;
	int Matrix[P*P][P*P] = { '\0' }, i = 0, j = 0;

	readInputFile(Matrix, argv[2], N /*numb_cells*/);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}

	i = 0; j = 0;
	printf("\n"); printf("\n");

	i = algo_start(Matrix);

	if (i == EXIT_SUCCESS)
	{
		for (i = 0; i < P * P; i++)
		{
			for (j = 0; j < P * P; j++)
			{
				printf("%d ", Matrix[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("No solution\n");
	}
	return i;
}

#include "alg_x.h"
#include <stdlib.h>
#include <time.h> 


int main()
{
	int N = P * P;
	int Matrix[P*P][P*P] = { '\0' }, i = 0, j = 0;

	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				Matrix[i][j] = 0;
			}
		}
		i = 0; j = 0;

	}
	srand(time(NULL));
	i = rand() % 30;
	printf("%d\n", i);
	for (j = 0; j < i; j++)
	{
		int x = rand() % N;
		int y = rand() % N;
		Matrix[x][y] = rand() % N;
		printf("%d %d %d\n", x, y, Matrix[x][y]);
	}
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

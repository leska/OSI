#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 2000
#define y 100

int main()
{
//	int **matrix= (int **)malloc(y*sizeof(int *));
	//for( int i=0; i<y; i++)
		//matrix[i]=(int *)malloc(x*sizeof(int));
	int matrix [x][y];
	int i,j,k;
	int rep=5000,tmp;
	clock_t s1,s2,finish;

	s1=clock();

	for(k=0;k<rep;k++)
		for(i=0;i<x;i++)
			for(j=0;j<y;j++)
				tmp+=matrix[i][j];

	s2 = clock();

	for(k=0; k<rep;k++)
		for(j=0; j<y; j++)
			for(i=0; i<x; i++)
				tmp+=matrix[i][j];

	finish = clock();

//	for( int i=0; i<y; i++)
//		free(matrix[i]);
//	free (matrix);

	printf("by rows: %d\nby columns: %d\n", (int)(s2-s1), (int)(finish-s2));
	return 0;
}
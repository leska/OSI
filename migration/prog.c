#include<stdio.h>
#include<time.h>

int main()
{
        int size=1000;
	int matr[1000][1000];	
	int k,i,j;
	for(k=0;k<size;k++)
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				matr[i][j]=0;
		return 0;
}

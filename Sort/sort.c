#include <stdio.h>
#include <stdlib.h>
#define MAXNUMBERS 100000

int arr[MAXNUMBERS], count;
int err=0;
int main(int argc, char** argv) {
	int i,j,t, readed, writed;
	count = 0;
	
	if (argc < 3)
		{
		err=1;goto sw;
		}
	for(i = 1; i < argc-1; i++){	
		FILE * f = fopen(argv[i], "r");
		if (!f)
			{
			err=2;goto sw;
			}
		while (!feof(f)){
			readed = fscanf(f, "%d", &arr[count++]);
			if (readed == 0){
				fclose(f);
				err=3;goto sw;
			}
			else if (readed == EOF)
				count--;
			if (count >= MAXNUMBERS){
				fclose(f);
				err=4; goto sw;
			}
		}
		fclose(f);
	}	

	for(i = 0; i < count; i++)
		for(j = 0; j < i; j++){
			if (arr[i] < arr[j]){
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	FILE * fout = fopen(argv[argc-1], "w");
	if (!fout)
		{
		err=5;goto sw;
		}
	
	for(i = 0; i < count; i++){
		writed = fprintf(fout, "%d\n", arr[i]);
		if (writed < 0){
			fclose(fout);
			err=6; goto sw;
		}
	}
	fclose(fout);

sw:
switch(err)
{
case 0:
	printf("All ok");break;
case 1:
	printf("malo faylow");break;
case 2:
	printf("Bad");break;
case 3:
	printf("v fayle kaka");break;
case 4:
	printf("U menya ne hvataet pamati");break;
case 5:
	printf("WTF");break;
case 6:
	printf("ne shmogla zapisat");break;
}
	return err;

}
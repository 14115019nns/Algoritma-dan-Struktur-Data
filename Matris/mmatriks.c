#include "matriks.h"
#include <stdio.h>
int main(){
	int NB,NK;
	MATRIKS M;
	ElType X;
	
	printf("Masukan banyaknya baris : ");
	scanf("%d",&NB);
	printf("Masukan banyaknya kolom : ");
	scanf("%d",&NK);
	
	MakeMATRIKS(NB,NK,&M);
	BacaMATRIKS(&M,NB,NK);
	TulisMATRIKS(M);
	return 0;
}

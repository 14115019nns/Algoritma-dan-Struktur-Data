#include "soal1.h"
#include <stdio.h>

int main(){
	int N,i=0;
	ListArray L;
	DataType X;
	MakeEmpty(&L);
	
	printf("Masukan banyak array : ");
	scanf("%d",&N);
	
	for(int i=1; i<=N; i++){
		printf("Masukan bilangan ke-%d : ",i);
		scanf("%d",&X);
		Insert(&L,X);
	}
	printf("Bilangan maksimum adalah : %d", Max(L));
	return 0;
}

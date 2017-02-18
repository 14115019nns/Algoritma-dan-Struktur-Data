#include <stdio.h>
#include "garis.h"
#include "point.h"


int main(){
	GARIS L1,L2;
	POINT P1,P2;
	float deltaX,deltaY;
	MakeGARIS(P1,P2,&L1);
	MakeGARIS(P1,P2,&L2);
	printf("Masukan garis pertama (X1,Y1)&(X2,Y2) : \n");
	BacaGARIS(&L1);
	printf("Masukan garis pertama (X1,Y1)&(X2,Y2) : \n");
	BacaGARIS(&L2);
	printf("Garis pertama : ");
	TulisGARIS(L1);
	printf("\nGaris pertama : ");
	TulisGARIS(L2);
	printf("\nPanjang garis pertama : \n");
	printf("%.2f",PanjangGARIS(L1));
	printf("\nPanjang garis pertama : \n");
	printf("%.2f",PanjangGARIS(L2));
	printf("\nGradien garis pertama : \n");
	printf("%.2f",Gradien(L1));
	printf("\nGradien garis kedua : \n");
	printf("%.2f",Gradien(L2));
	printf("\nMasukan delta X : ");
	scanf("%f",&deltaX);
	printf("\nMasukan delta Y : ");
	scanf("%f",&deltaY);
	printf("Garis pertama setelah digeser : ");GeserGARIS(&L1,deltaX,deltaY);
	printf("\nGaris pertama setelah digeser : ");GeserGARIS(&L2,deltaX,deltaY);
	return 0;
}

#include "point.h"
#include <stdio.h>
/*Nama : Nanda Nur Septama*/
/* File: mpoint.c */
/* Tanggal: 28 Agustus 2016 */
int main(){
	
	POINT P1,P2;
	float X,Y;
	
	printf("Masukan Absis(P1) & Ordinat(P1)\n");
	BacaPOINT(&P1);
	printf("Masukan Absis(P2) & Ordinat(P2)\n");
	BacaPOINT(&P2);
	printf("Ini Absis(P1) & Ordinat(P1)\n");
	TulisPOINT(P1);
	printf("Ini Absis(P1) & Ordinat(P1)\n");
	TulisPOINT(P2);
	printf("Kuadran Absis(P1) & Ordinat(P1)\n");
	printf("%d\n",Kuadran(P1));
	printf("Kuadran Absis(P1) & Ordinat(P1)\n");
	printf("%d\n",Kuadran(P2));
	
	return 0;
}

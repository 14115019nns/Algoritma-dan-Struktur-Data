#include "soal1.h"
#include <stdio.h>

void MakeEmpty(ListArray *L){
	Neff(*L)=0;
}
//Membuat  inisiialisasi awal yang menandakan array masih kosong
//cirinya Neff(T) = 0;

int IsEmpty(ListArray L){
	return (Neff(L)==0);
}
//Mengecek array masih dalam keadaan kosong atau tidak

int IsFull(ListArray L){
	return (Neff(L)==MaxElm);
}
//Mengecek array sudah dalam keadaan full atau tidak

void Insert(ListArray *L, DataType dataInput){
	int i = Neff(*L);
	if(IsFull(*L)==MaxElm){
		printf("Array sudah penuh\n");
	}
	else {
		Data(*L,i) = dataInput;
		Neff(*L)++;
	}
}
//Untuk memasukan nilai kedalam array

int Max(ListArray L){
	int i=0;
	int Max = Data(L,i);
	while(i<=Neff(L)){
	
		if(Max < Data(L,i+1)){
			Max= Data(L,i+1);
		}
		else{}
		i++;
	}
}
//Mencari bilangan maksimum pada array

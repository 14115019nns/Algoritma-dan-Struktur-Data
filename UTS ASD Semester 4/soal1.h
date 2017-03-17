#ifndef SOAL1_H
#define SOAL1_H

#define MaxElm 50

typedef int DataType;
typedef struct{
	DataType dataArray[MaxElm];
	DataType Neff;
} ListArray;

#define Data(T,i) (T).dataArray[(i)]
#define Neff(T) (T).Neff

void MakeEmpty(ListArray *L);
//Membuat  inisiialisasi awal yang menandakan array masih kosong
//cirinya Neff(T) = 0;

int IsEmpty(ListArray L);
//Mengecek array masih dalam keadaan kosong atau tidak

int IsFull(ListArray L);
//Mengecek array sudah dalam keadaan full atau tidak

void Insert(ListArray *L, DataType dataInput);
//Untuk memasukan nilai kedalam array

int Max(ListArray L);
//Mencari bilangan maksimum pada array

#endif

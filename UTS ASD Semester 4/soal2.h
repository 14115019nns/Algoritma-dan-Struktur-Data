#ifndef SOAL2_H
#define SOAL2_H

//mendefinisikan jumlah data yang dapat tersimpan
#define MaxData 50


#define Matematika 0
#define Fisika 1
#define Kimia 2
#define PTI 3

typedef char String[150];
typedef struct{
	String nama;
	String nim;
	int nilai[4];
} StrukturMahasiswa;

typedef StrukturMahasiswa DataMahasiswa[MaxData];

#endif

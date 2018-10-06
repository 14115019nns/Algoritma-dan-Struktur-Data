#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address next;
} ElmtList;

typedef struct {
	address first;
} List;


//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

bool isListEmpty (List L){
	/* Mengirim true jika list kosong */
	return First(L)==Nil;
}

void createList (List *L){
	/*	I.S. sembarang
		F.S. Terbentuk list kosong 
	*/
	First(*L)=Nil;

}
address getLast(List L){

	address next = First(L);
	while(Next(next)!=Nil){
		next = Next(next);
	}
	return next;
}

address alokasi (infotype X){
	/*	Mengirimkan address hasil alokasi sebuah elemen
		Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
		Info(P) = X, Next(P) = Nil
		Jika alokasi gagal, mengirimkan Nil
	*/
	address P = address(malloc(sizeof(ElmtList)));
	if(P==NULL)
		return Nil;

	Info(P) = X;
	Next(P) = Nil;
	return P;
	
}

void dealokasi (address *P){
	/*	I.S. P terdefinisi
		F.S. P dikembalikan ke sistem
		Melakukan dealokasi/pengembalian address P
	*/
	free(*P);
}

void insertFirst (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		nilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}

void insertAfter (List *L, address P, address Prec){
	/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
		P sudah dialokasi
		F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
	*/
	Next(P)= Next(Prec);
	Next(Prec) = P;
}


void insertLast (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(isListEmpty(*L))
		insertFirst(L,X);

	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}


/*
* Fungsi Overloading => merupakan fungsi yang memiliki nama sama
* namum memiliki parameter dan iplementasi yang berbeda.
* contoh : 
* insertFirst(List *L,address P) dan insertFirst (List *L, infotype X)
* Beberda di parameter kedua, fungsi tersebut akan otomatis memilih fungsi yang akan
* di jalankan , sesuai dengan parameter pembedanya( kedua ).
*/
void insertFirst(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		P hasil Alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	Next(P)=First(*L);
	First(*L) = P;
}

void insertLast(List *L,address P){
	/*	I.S. L mungkin kosong
		F.S. P ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai P hasil alokasi X.
		Jika alokasi gagal: I.S.= F.S.
	*/
	if(isListEmpty(*L))
		First(*L) = P;
	else{
		address last = getLast(*L);
		insertAfter(L,P,last);
	}
}

void deleteFirst (List *L, infotype *X){
	/*	I.S. List L tidak kosong
		F.S. Elemen pertama list dihapus : nilai info disimpan pada X
		dan alamat elemen pertama di-dealokasi
	*/
	*X = Info(First(*L));
	address P = Next(First(*L));
	dealokasi(&First(*L));
	First(*L) = P;
}

void deleteAfter (List *L, address *Pdel, address Prec){
	/*	I.S. List tidak kosong. Prec adalah anggota list L.
		F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus
	*/
	*Pdel = Next(Prec);
	if(*Pdel!=Nil) {
		Next(*Pdel) = Nil;
	}
	dealokasi(&(*Pdel));
}

void deleteLast(List *L, infotype *X){
	/*	I.S. list tidak kosong
		F.S. Elemen terakhir list dihapus : nilai info disimpan pada X
		dan alamat elemen terakhir di-dealokasi
	*/
	address P = First(*L);
	if(Next(P)==Nil){			// For list with one element
		*X = Info(First(*L));
		dealokasi(&First(*L));
		First(*L) = Nil;
	}else{						// For list with more than one elements (min 2 elmts)
		while(Next(Next(P))!=Nil){
			P = Next(P);
		}// P is an element before last element
		*X = Info(Next(P));
		dealokasi(&Next(P));
		Next(P) = Nil;
	}
}
void printInfo(List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<< "[";
	if(!isListEmpty(L)){
		address P = First(L);
		while(Next(P)!=Nil){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout << "]" << endl;
}
/* gunakan fungsi pada master.cpp tambahkan fungsi dibawah dan int main */

void Hapus (List *L){
/* hapus nilai pertama list (deletefirst) jika element list (n%2==0) 
 dan menghapus nilai terakhir list(deletelast) jika element list (n%3==0) */
	address P = First(*L);
	infotype X;
	while(Next(P)!=Nil){
		if(Info(P)%2==0){
			deleteFirst(L,&X);
		}
		else if(Info(P)%3==0){
			deleteLast(L,&X);
		}
		P=Next(P);
	}
	if(Info(P)%2==0){
		deleteFirst(L,&X);
	}
	else if(Info(P)%3==0){
		deleteLast(L,&X);
	}
}

infotype max (List L){
	/*	Mengirimkan nilai Info(P) yang maksimum */
	int max = -Infinity;
	address P = First(L);
	while(P!=Nil){
		if(max<Info(P))
			max = Info(P);
		P=Next(P);
	}
	return max;
}

void reverseList (List *L){
	/*	I.S. L terdefinisi, boleh kosong
		F.S. Elemen list L dibalik :
		Elemen terakhir menjadi elemen pertama, dan seterusnya.
		Membalik elemen list, tanpa melakukan alokasi/dealokasi.
	*/
	address next,curr,prev;
	curr = First(*L);
	next = Nil;
	prev = Nil;
	while(curr!=Nil){
		next = Next(curr);
		Next(curr) = prev;
		prev = curr;
		curr = next;
	}
	First(*L) = prev;
}

infotype min (List L){
	/*	Mengirimkan nilai Info(P) yang minimum */
	int min = Infinity;
	address P = First(L);
	while(P!=Nil){
		if(min>Info(P))
			min = Info(P);
		P=Next(P);
	}
	return min;
}

int main(){
	List L;
	createList(&L);

	//Soal D
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;	
		insertLast(&L,x);
	}
	Hapus(&L);
	printInfo(L);
}

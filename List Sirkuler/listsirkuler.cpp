#include <iostream>
#include <stdlib.h>
using namespace std;


/* Definisi Type Data */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

#define Nil NULL

bool IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P;
	P = (address) malloc(sizeof(ElmtList));
	if(P==NULL){
		return Nil;
	}else{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}
address search(List L, infotype X){
	if(X==Info(First(L))){
		address temp = First(L);
		return temp;
	}
	else{
		address P = Next(First(L));
		address temp = Nil;
		while(Next(P)!=First(L)){
			if(X==Info(P)){
				temp = P;
				break;
			}
			P = Next(P);
		}
		return temp;
	}
}
address getLast(List L){

	address P = Next(First(L));
	while(Next(P)!=First(L)){
		P = Next(P);
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = alokasi(X);
	address Q = First(*L);
	if(P!=NULL){
		if(First(*L)==Nil){
			First(*L) = P;
			Next(P) = P;
		}
		else{
			address last = getLast(*L);
			Next(P) = First(*L);
			First(*L) = P;
			Next(last) = First(*L);
		}
	}
}
void InsertFirst (List *L, address P)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address Q = First(*L);
	if(P!=NULL){
		if(First(*L)==Nil){
			First(*L) = P;
			Next(P) = P;
		}
		else{
			address last = getLast(*L);
			Next(P) = First(*L);
			First(*L) = P;
			Next(last) = First(*L);
		}
	}
}
void InsVLast(List *L, infotype X){
	address P = alokasi(X);
	if(P!=NULL){
		if(IsEmpty(*L)){
			InsVFirst(&(*L),X);
		}
		else{
			address last = getLast(*L);
			Next(last) = P;
			Next(P) = First(*L);
		}
	}
}
void InsertLast(List *L, address P){
	if(P!=NULL){
		if(IsEmpty(*L)){
			InsertFirst(&(*L),P);
		}
		else{
			address last = getLast(*L);
			Next(last) = P;
			Next(P) = First(*L);
		}
	}
}
void InsVAfter (List * L, address here, address newnode){
	if(newnode!=NULL){
		Next(newnode) = Next(here);
		Next(here) = newnode;
	}
} 
void DelVFirst(List *L, infotype *X){
	address P = First(*L);
	address Q = First(*L);
	*X = Info(P);
	if(Next(P)==P){
		First(*L)=Nil;
		Dealokasi(Q);
	}
	else{
		address last = getLast(*L);
		First(*L) = Next(P);
		Next(last) = First(*L);
		Dealokasi(Q);
	}
}
void DeleteFirst(List *L, address *P){
	*P = First(*L);
	address Q = First(*L);
	if(Next(*P)==*P){
		First(*L)=Nil;
		Dealokasi(Q);
	}
	else{
		address last = getLast(*L);
		First(*L) = Next(*P);
		Next(last) = First(*L);
		Dealokasi(Q);
	}
}
void DelVLast(List *L, infotype *X){
	address P = First(*L);
	address Q = First(*L);
	if(Next(P)==P){
		First(*L)=Nil;
	}
	else{
		while(Next(Next(Q))!=First(*L)){
			Q=Next(Q);
		}
		P = Next(Q);
		Next(Q) = First(*L);
	}	
	*X = Info(P);
	Dealokasi(P);
}
void DeleteLast(List *L, address *P){
	*P=First(*L);
	address Q = First(*L);
	if(Next(*P)==*P){
		First(*L)=Nil;
	}
	else{
		while(Next(Next(Q))!=First(*L)){
			Q=Next(Q);
		}
		*P = Next(Q);
		Next(Q) = First(*L);
	}	
	Dealokasi(*P);
}
void printInfo(List L){
	cout << "[";
	address Q = First(L);
	if(Q!=Nil){
		while(Next(Q)!=First(L)){
			cout << Info(Q) << ", ";
			Q = Next(Q);
		}
		cout << Info(Q);
	}
	cout << "]" << endl;
}
int nbElmt(List L){
	address last = getLast(L);
	address P = First(L);
	int i=0;
	while(P!=last){
		i++;
		P = Next(P);
	}
	return i+1;
}

int main(){
	List L;
	CreateEmpty(&L);
	int n,x;
	address del;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x;
		address P = alokasi(x);
		InsertLast(&L,P);
	}
	printInfo(L);
	cout << endl;
	DeleteLast(&L,&del);
	printInfo(L);
	return 0;
}

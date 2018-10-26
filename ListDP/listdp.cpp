#include <iostream>
#include <stdlib.h>
#include "boolean.h"
using namespace std;


/* Definisi Type Data */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
	address prev;
} ElmtList;
typedef struct {
	address First;
	address Last;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)


#define Nil NULL

boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L)==Nil&&Last(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Last(*L) = Nil;
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
		Next(P) = Prev(P) = Nil;
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
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address here = First(L);
	while(Next(here)!=Nil){
		if(Info(here)==X)
			return here;
	}
	return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = alokasi(X);
	if(P!=NULL){
		if(IsEmpty(*L)){
			First(*L) = Last(*L) = P;
		}
		else{
			Next(P) = First(*L);
			Prev(First(*L)) = P;
			First(*L) = P;
		}
	}
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = alokasi(X);
	if(P!=NULL){
		if(IsEmpty(*L)){
			InsVFirst(&(*L),X);
		}
		else{
			Next(Last(*L)) = P;
			Prev(P) = Last(*L);
			Last(*L) = P; 
		}
	}
}
void InsVAfter(List *L, address here, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list setelah elemen here.*/
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	address P = alokasi(X);
	if(P!=NULL){
		Prev(Next(here)) = P;
		Next(P) = Next(here);
		Next(here)=P;
		Prev(P)=here;
	}

}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	address next = Next(First(*L));
	Dealokasi(First(*L));
	First(*L) = next;
	if(next==Nil){
		Last(*L) = Nil;
	}
	else{
		Prev(next) = Nil;
	}
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	*X = Info(Last(*L));
	address prev = Prev(Last(*L));
	Dealokasi(Last(*L));
	Last(*L) = prev;
	if(prev==Nil){
		First(*L)=Nil;
	}else{
		Next(prev) = Nil;
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if(P!=NULL){
		if(IsEmpty(*L)){
			First(*L) = Last(*L) = P;
		}
		else{
			Next(P) = First(*L);
			Prev(First(*L)) = P;
			First(*L) = P;
		}
	}	
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(P!=NULL){
		if(IsEmpty(*L)){
			InsertFirst(&(*L),P);
		}
		else{
			Next(Last(*L)) = P;
			Prev(P) = Last(*L);
			Last(*L) = P; 
		}
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if(P!=NULL){
		if(Next(Prec)==Nil){
			InsertLast(&(*L),P);
		}
		else{
			Prev(Next(Prec)) = P;
			Next(P) = Next(Prec);
			Next(Prec)=P;
			Prev(P)=Prec;
		}
	}	
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	if(P!=NULL){
		Next(Prev(Succ)) = P;
		Prev(P) = Prev(Succ);
		Prev(Succ) = P;
		Next(P)=Succ;
	}		
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	if(*P==Last(*L)){
		First(*L)=Last(*L) = Nil;
	}
	else{
		First(*L) = Next(First(*L));
		Prev(First(*L))=Nil;
	}

}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	if(*P==First(*L)){
		First(*L)=Last(*L) = Nil;
	}else{
		Last(*L) = Prev(Last(*L));
		Next(Last(*L)) = Nil;
	}
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P = Search(*L,X);
	if(P!=NULL){
		if(P==First(*L)){
			DelFirst(&(*L),&P);
		} else if(P==Last(*L)){
			DelLast(&(*L),&P);
		}else{
			Prev(Next(P)) = Prev(P);
			Next(Prev(P)) = Next(P);
			Dealokasi(P);
		}
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	address P = Next(Prec);
	if(Next(Next(Prec))!=Nil){
		*Pdel = P;
		Prev(Next(P)) = Prec;
		Next(Prec) = Next(*Pdel);
	}
	else{
		DelLast(&(*L),&(*Pdel));
	}
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	address prev = Prev(Succ);
	if(Prev(Prev(Succ))!=Nil){
		*Pdel=prev;
		Next(Prev(prev)) = Succ;
		Prev(Succ)=Prev(*Pdel);
	}
	else{
		DelFirst(&(*L),&(*Pdel));
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = First(L);
	cout << "[";
	if(!IsEmpty(L)){
		while(Next(P)!=Nil){
			cout << Info(P) << ", ";
			P = Next(P);
		}
		cout << Info(P);
	}cout << "]";
}
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = Last(L);
	cout << "[";
	if(!IsEmpty(L)){
		while(Prev(P)!=Nil){
			cout << Info(P) << ", ";
			P = Prev(P);
		}
		cout << Info(P);
	}
	cout << "]";
}
int NbX(infotype X, List L){
	int count=0;
	address here = First(L);
	while(here!=Nil){
		if(Info(here)==X){
			count++;
		}
		here = Next(here);
	}
	return count;
}
int Jarak(List L, infotype X, infotype Y){
	int length=0;
	boolean firstX=false,firstY=false,counting=false;
	address here = First(L);
	while(here!=Nil){
		if(counting==false){
			if(Info(here)==X){
				firstX=true;counting=true;
			} else if(Info(here)==Y){
				firstY=true;counting=true;
			}
		}
		else if(counting==true){
			if(Info(here)==X){
				firstX=true;
			} else if(Info(here)==Y){
				firstY=true;
			}
			length++;
		}
		here=Next(here);
	}
	return length;
}
int main(){

	List L;
	int n,x,i=0;
	CreateEmpty(&L);
	printf("Masukan n : ");
	cin >> n;
	for(i=0; i<n; i++){
		cin >> x;
		InsVFirst(&L,x);
	}
	PrintForward(L);
	cout << endl;
	cout << "Jumlah bilangan X=3 adalah : " << NbX(3,L) << endl;
	cout <<  "Jarak antara X=1 dan Y=5 adalah : " << Jarak(L,2,1)-1 << endl;
	return 0;
}

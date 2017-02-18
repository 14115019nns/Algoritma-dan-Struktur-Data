#include "array.h"
#include <stdio.h>
void MakeEmpty (TabInt * T){
	Neff(*T) =0 ;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	return (i>=IdxMin&&i<=NMax);
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
	return (i>=IdxMin&&i<Neff(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	return (Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
	return (Neff(T)==NMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
	IdxType i,tmp=1;
	ElType X;
	scanf("%d",&i);
	
	if (IsIdxValid(*T,i)){
	while(tmp<=i){
		scanf("%d",&X);
		Elmt(*T,tmp)=X;
		tmp++;
		Neff(*T)++;
		}
	}
	else {}
}
/* I.S. sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= NMax */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= NMax; Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsi (TabInt T){
	IdxType i=1;
	if (IsEmpty(T)){
		printf("Tabel Kosong\n");
	}
	else {
		while (i<=Neff(T)){
			printf("[%d]%d\n",i,Elmt(T,i));
			i++;
		}
	}
	
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T){
	IdxType i=1;
	if (IsEmpty(T)){
		printf("[]\n");
	}
	else{
		printf("[");
		while(i<=Neff(T)){
			printf("%d",Elmt(T,i));
			if ((i+1)!=Neff(T)){
				printf(",");
			}
			else {}
			i++;
		}
	printf("]");
	}
	
	
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while(i<=Neff(T1)){
		Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while (i<=Neff(T2)){
		Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while (i<=Neff(T2)){
		Elmt(T3,i) = Elmt(T1,i) * Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c){
	IdxType i=1;
	while(i<=Neff(Tin)){
		Elmt(Tin,i) *= c;
		i++;
	}
	return Tin;
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
	boolean same=true;
	if(Neff(T1)==Neff(T2)){
		same = true;
	}
	else if(IsEmpty(T1)&&IsEmpty(T2)){
		same = true;
	}
	else{same=false;}
	return same;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2){
	boolean less=true;
	IdxType i=1;
	if(IsEmpty(T1)&&IsEmpty(T2)){
		less = false;
	}
	else if(IsEQ(T1,T2)){
		while(i<=Neff(T1)){
			if(Elmt(T1,i)<Elmt(T2,i)){
				less = true;
			}
			else{
				return false;
			}
			i++;
		}
	}
	return less;
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
 
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
	IdxType j,i=1;
	if(Neff(T)==0){
		return IdxUndef;
	}
	else{
		while(i<=Neff(T)){
			if(X==Elmt(T,i)){
				return j=i;
			}
			else{
				j=IdxUndef;
			}
			i++;
		}
		return j;
	}
	
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X){
	boolean found=false;
	IdxType i=1,j;
	if(IsEmpty((T))){
		return IdxUndef;
	}
	else{
		while((i<=Neff(T))||(found==true)){
			if(X==Elmt(T,i)){
				found = true;
			}
			else{
				found = false;
			}
			i++;
		}
		return i;	
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X){
	boolean found=false;
	IdxType i=1;
	if(IsEmpty(T)){
		return found;
	}
	else{
		while((i<=Neff(T))&&(found==true)){
			if(X==Elmt(T,i)){
				found=true;
			}
			else{
				found=false;
			}
			i++;
		}
		return found;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X){
	boolean found=false;
	IdxType i=0;
	if(IsEmpty(T)){
		return found;
	}
	else {
		while((i<=Neff(T))&&(found==true)){
			if(X==Elmt(T,i)){
				found=true;
			}
			else{
				found=false;
			}
			i++;
		}
		return found;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	IdxType i=1;
	ElType Max=Elmt(T,i);
	while(i<=Neff(T)){
		if(Max<Elmt(T,i)){
			Max=Elmt(T,i);
		}
		else{}
		i++;
	}
	return Max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T){
	IdxType i=1;
	ElType Min=Elmt(T,i);
	while(i<=Neff(T)){
		if(Min>Elmt(T,i)){
			Min=Elmt(T,i);
		}
		else{}
		i++;
	}
	return Min;
} 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
	IdxType i=1,tmp=0;
	ElType Max=Elmt(T,i);
	while (i<=Neff(T)){
		if(Max<Elmt(T,i)){
			tmp = i;
		}
		else{}
		i++;
	}
	return tmp;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T){
	IdxType i=1,tmp=0;
	ElType Min=Elmt(T,i);
	while (i<=Neff(T)){
		if(Min>Elmt(T,i)){
			tmp = i;
		}
		else{}
		i++;
	}
	return tmp;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
	IdxType i=1;
	ElType X;
	MakeEmpty(&(*Tout));
	if(IsEmpty(Tin)){
		Neff(*Tout)=0;
	}
	else{
		while(i<=Neff(Tin)){
			X = Elmt(Tin,i);
			Elmt(*Tout,i) = X;
			i++;
		}
	}
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T){
	TabInt T1;
	ElType X;
	IdxType j=1,i=1;
	MakeEmpty(&T1);
	while(i<=Neff(T)){
		X = Elmt(T,i);
		Elmt(T1,i) = X;
		Neff(T1)++;
		i++;
	}
	MakeEmpty(&T);
#include "array.h"
#include <stdio.h>
void MakeEmpty (TabInt * T){
	Neff(*T) =0 ;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	return (i>=IdxMin&&i<=NMax);
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
	return (i>=IdxMin&&i<Neff(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	return (Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
	return (Neff(T)==NMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
	IdxType i,tmp=1;
	ElType X;
	scanf("%d",&i);
	
	if (IsIdxValid(*T,i)){
	while(tmp<=i){
		scanf("%d",&X);
		Elmt(*T,tmp)=X;
		tmp++;
		Neff(*T)++;
		}
	}
	else {}
}
/* I.S. sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= NMax */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= NMax; Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsi (TabInt T){
	IdxType i=1;
	if (IsEmpty(T)){
		printf("Tabel Kosong\n");
	}
	else {
		while (i<=Neff(T)){
			printf("[%d]%d\n",i,Elmt(T,i));
			i++;
		}
	}
	
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
void TulisIsiTab (TabInt T){
	IdxType i=1;
	if (IsEmpty(T)){
		printf("[]\n");
	}
	else{
		printf("[");
		while(i<=Neff(T)){
			printf("%d",Elmt(T,i));
			if ((i+1)!=Neff(T)){
				printf(",");
			}
			else {}
			i++;
		}
	printf("]");
	}
	
	
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while(i<=Neff(T1)){
		Elmt(T3,i) = Elmt(T1,i) + Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while (i<=Neff(T2)){
		Elmt(T3,i) = Elmt(T1,i) - Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
TabInt KaliTab (TabInt T1, TabInt T2){
	TabInt T3;
	IdxType i=1;
	MakeEmpty(&T3);
	while (i<=Neff(T2)){
		Elmt(T3,i) = Elmt(T1,i) * Elmt(T2,i);
		Neff(T3)++;
		i++;
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
TabInt KaliKons (TabInt Tin, ElType c){
	IdxType i=1;
	while(i<=Neff(Tin)){
		Elmt(Tin,i) *= c;
		i++;
	}
	return Tin;
}
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
	boolean same=true;
	if(Neff(T1)==Neff(T2)){
		same = true;
	}
	else if(IsEmpty(T1)&&IsEmpty(T2)){
		same = true;
	}
	else{same=false;}
	return same;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
boolean IsLess (TabInt T1, TabInt T2){
	boolean less=true;
	IdxType i=1;
	if(IsEmpty(T1)&&IsEmpty(T2)){
		less = false;
	}
	else if(IsEQ(T1,T2)){
		while(i<=Neff(T1)){
			if(Elmt(T1,i)<Elmt(T2,i)){
				less = true;
			}
			else{
				return false;
			}
			i++;
		}
	}
	return less;
}
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
 
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
	IdxType j,i=1;
	if(Neff(T)==0){
		return IdxUndef;
	}
	else{
		while(i<=Neff(T)){
			if(X==Elmt(T,i)){
				return j=i;
			}
			else{
				j=IdxUndef;
			}
			i++;
		}
		return j;
	}
	
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
IdxType Search2 (TabInt T, ElType X){
	boolean found=false;
	IdxType i=1,j;
	if(IsEmpty((T))){
		return IdxUndef;
	}
	else{
		while((i<=Neff(T))||(found==true)){
			if(X==Elmt(T,i)){
				found = true;
			}
			else{
				found = false;
			}
			i++;
		}
		return i;	
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
boolean SearchB (TabInt T, ElType X){
	boolean found=false;
	IdxType i=1;
	if(IsEmpty(T)){
		return found;
	}
	else{
		while((i<=Neff(T))&&(found==true)){
			if(X==Elmt(T,i)){
				found=true;
			}
			else{
				found=false;
			}
			i++;
		}
		return found;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
boolean SearchSentinel (TabInt T, ElType X){
	boolean found=false;
	IdxType i=0;
	if(IsEmpty(T)){
		return found;
	}
	else {
		while((i<=Neff(T))&&(found==true)){
			if(X==Elmt(T,i)){
				found=true;
			}
			else{
				found=false;
			}
			i++;
		}
		return found;
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	IdxType i=1;
	ElType Max=Elmt(T,i);
	while(i<=Neff(T)){
		if(Max<Elmt(T,i)){
			Max=Elmt(T,i);
		}
		else{}
		i++;
	}
	return Max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
ElType ValMin (TabInt T){
	IdxType i=1;
	ElType Min=Elmt(T,i);
	while(i<=Neff(T)){
		if(Min>Elmt(T,i)){
			Min=Elmt(T,i);
		}
		else{}
		i++;
	}
	return Min;
} 
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T){
	IdxType i=1,tmp=0;
	ElType Max=Elmt(T,i);
	while (i<=Neff(T)){
		if(Max<Elmt(T,i)){
			tmp = i;
		}
		else{}
		i++;
	}
	return tmp;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T){
	IdxType i=1,tmp=0;
	ElType Min=Elmt(T,i);
	while (i<=Neff(T)){
		if(Min>Elmt(T,i)){
			tmp = i;
		}
		else{}
		i++;
	}
	return tmp;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout){
	IdxType i=1;
	ElType X;
	MakeEmpty(&(*Tout));
	if(IsEmpty(Tin)){
		Neff(*Tout)=0;
	}
	else{
		while(i<=Neff(Tin)){
			X = Elmt(Tin,i);
			Elmt(*Tout,i) = X;
			i++;
		}
	}
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
TabInt InverseTab (TabInt T){
	TabInt T1;
	ElType X;
	IdxType j=1,i=1;
	MakeEmpty(&T1);
	while(i<=Neff(T)){
		X = Elmt(T,i);
		Elmt(T1,i) = X;
		Neff(T1)++;
		i++;
	}
	MakeEmpty(&T);
	while(i>=j){
		Elmt(T,i) = Elmt(T1,i);
		i--;
		Neff(T)++;
	}
	return T;
}
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
boolean IsSimetris (TabInt T){
	boolean same=false;
	IdxType i=1,j;
	j=Neff(T);
	if((Neff(T)%2)==1){
		while(i<=((Neff(T)/2)+1)){
		if(Elmt(T,i)==Elmt(T,j)){
			same = true;
		}
		else {
			return false;
		}
		i++;
		j--;
	}
	return same;
	}
	else if ((Neff(T)%2)==0){
		while(i<=(Neff(T)/2)){
		if(Elmt(T,i)==Elmt(T,j)){
			same = true;
		}
		else {
			return false;
		}
		i++;
		j--;
	}
	return same;
	}
	
}

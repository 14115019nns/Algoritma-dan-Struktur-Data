/* Gunakan Fungsi pada master.cpp tambahkan fungsi dibawah ini dan int main 
dibawah ini */
/* Pakai Fungsi-Fungsi yang ada di Master 
dan tambahkan int main dibawah */

#include <iostream>
#include <stdlib.h> 
using namespace std;
 
typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
    infotype info;
    address next;
} ElmtList;
 
typedef struct {
    address first;
}List ;
 //SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

bool IsEmpty(List L) {
    return ((L).first == NULL);
}
 
void createList(List *L) {
    First(*L) = NULL;
}
 
void Deallocation(address hapus) {
    free(hapus);
}
address getLast(List L){

	address next = First(L);
	while(Next(next)!=Nil){
		next = Next(next);
	}
	return next;
}
 
address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
 
    Info(NewElmt) = x;
    Next(NewElmt) = NULL;
 
    return NewElmt;
}
 
void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
 
    if (NewElmt != NULL) {
        Next(NewElmt) = First(*L);
        First(*L) = NewElmt;
    }
}
 
void InsertAfter(address *PredElmt, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
 
    if (NewElmt != NULL) {
        Next(NewElmt) = Next(*PredElmt);
        Next(*PredElmt) = NewElmt;
    }
}
 
void InsertLast(List *L, infotype x) {
    if (IsEmpty(*L)) {
        InsertFirst(&(*L), x);
    } else {
        address temp;
        temp = First(*L);
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }
        InsertAfter(&temp, x);
    }
}
 
void DeleteFirst(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp;
        temp = First(*L);
        *hapus = Info(temp);
        First(*L) = Next(First(*L));
        Next(temp) = NULL;
        Deallocation(temp);
    }
}
 
void DeleteAfter(address pred, infotype *hapus) {
    if (pred->next != NULL) {
        address temp;
        temp = Next(pred);
        *hapus = Info(temp);
        Next(pred) = Next(temp);
        Next(temp)= NULL;
        Deallocation(temp);
    }
}
 
void DeleteLast(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp, predTemp;
        predTemp = NULL;
        temp = First(*L);
        while (temp->next != NULL) {
            predTemp = temp;
            temp =Next(temp);
        }
 
        if (temp == (*L).first) {
            DeleteFirst(&(*L), &(*hapus));
        } else {
            DeleteAfter(predTemp, &(*hapus));
        }
    }
}

void reverseList (List *L){
	/*	I.S. L terdefinisi, boleh kosong
		F.S. Elemen list L dibalik :
		Elemen terakhir menjadi elemen pertama, dan seterusnya.
		Membalik elemen list, tanpa melakukan alokasi/dealokasi.
	*/
	address next,curr,prev;
	curr = First(*L);
	prev = NULL;
	next = Next(curr);
	
	while (curr!= NULL){ 
		next = Next(curr);
		Next(curr) = prev ;
		prev=curr;
		curr=next;
	}First(*L)=prev;
}

void printInfo (List L){
	
	cout<<"[";
	if(!IsEmpty(L)){
		address temp =First(L);
		while(Next(temp)!=NULL){
			cout<<Info(temp) <<", ";
			temp = Next(temp);
		}
		cout<<Info(temp);
	}
	cout<<"]"<<endl;
}
bool checkPrima(infotype i){
	/*	I.S.i merupakan isi dari node L
		F.S. cek apakah i prima, 
        jika iya return true
	*/
	if(i>3){
		if(i%2!=0&&i%3!=0){
			return true;
		}
		else{
			return false;
		}
	}
	else if(i<=1){
		return false;
	}
	else if(i==2||i==3){
		return true;
	}
}
void copyPrima(List L, List *L2){
	/*	I.S. L terdefinisi, boleh kosong.
        L2 terdifinisi dan kosong.
		F.S. copy isi dari L ke L2 yang merupakan
        bilangan
	*/
    address temp;
    address P = First(L);
    while(P!=Nil){
    	if(checkPrima(Info(P))==true){
    		InsertLast(L2,Info(P));
    	}
		P=Next(P);
    }
}
bool cekGanjil(infotype x){
	if(x%2==1){
		return true;
	}
	return false;
}
void concat(List L, List L2, List *L3){
	address P = First(L);
	infotype x;
	while(P!=Nil){
		x = Info(P);
		InsertLast(L3,x);
		P = Next(P);
	}
	P = First(*L3);
	while(P!=Nil){
		if(Next(P)==Nil){
			Next(P) = First(L2);
			return;
		}
		P = Next(P);
	}
	
}
int solveProblem(List L){
	int jumlah=0;
	address P = First(L);
	while(P!=Nil){
    	if(cekGanjil(Info(P))==true){
    		jumlah = jumlah + Info(P);
    	}
		P=Next(P);
    }
    return jumlah;
}
int main(){
	List L,L2,L3;
	createList(&L);
	createList(&L2);
	/*	I.S. L dan L2 terdefinisi
		F.S. isi List L, berhenti input ketika
        L di inputkan -1.
	*/
	int x=0;
	cin >> x;
	while(x!=-1){
		InsertLast(&L,x);
		cin >> x;
	}
	printInfo(L);
	copyPrima(L,&L2);
	printInfo(L2);
	
}

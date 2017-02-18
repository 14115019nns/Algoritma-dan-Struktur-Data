#include "matriks.h"
#include <stdio.h>
/* ********** Definisi ADT MATRIKS dengan indek

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
	if(IsIdxValid(NB,NK)){
		 NBrsEff(*M) = NB;
		  NKolEff(*M) = NK;
	}
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */


/* *** Pengecekan Indeks Matriks *** */
boolean IsIdxValid (int i, int j){
	return ((i>=BrsMin&&i<=BrsMax)&&(j>=KolMin&&j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	return ((i>=BrsMin&&i<=NBrsEff(M)&&j>=KolMin&&j<=NKolEff(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	
	 NBrsEff(*MHsl) =  NBrsEff(MIn);
	  NKolEff(*MHsl) =  NKolEff(MIn);
	  for(int i=BrsMin; i<=NBrsEff(MIn); i++){
	  	for(int j=KolMin; j<=NKolEff(MIn); j++){
	  		Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		  }
	  }
	
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	int i,j;
	ElType tmp;
	if(IsIdxValid(NB,NK)){
		MakeMATRIKS(NB,NK,&(*M));
		for(i=BrsMin; i<=NBrsEff(*M); i++){
			for(j=KolMin; j<=NKolEff(*M); j++){
				printf("Masukan data pada baris ke-%d dan kolom ke-%d : ",i,j);
				scanf("%d",&tmp);
				Elmt(*M,i,j) = tmp;
			}
		}
	}
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
	int i,j;
	for(i=BrsMin; i<=NBrsEff(M); i++){
		for(j=KolMin; j<=NKolEff(M); j++){
			if(j==NKolEff(M)){
				printf("%d\n",Elmt(M,i,j));
			}
			else{
				printf("%d ",Elmt(M,i,j));
			}
		}
	}
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom, 
           masing-masing baris diakhiri enter */
/* Contoh: menulis matriks 3x3 (masing-masing baris diakhiri enter)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	int i,j,NB,NK;
	NB = NBrsEff(M1);
	NK = NKolEff(M1);
	MATRIKS M3;
	ElType tmp;
	MakeMATRIKS(NB,NK,&M3)
	if(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2)){
		for(i=BrsMin; i<=NBrsEff(M1); i++){
			for(i=KolMin; i<=NKolEff(M1); j++){
				tmp = Elmt(M1,i,j) + Elmt(M2,i,j);
				Elmt(M3,i,j)=tmp;
				tmp=0;	
			}
		}
		return M3;
	}
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	int i,j,NB,NK;
	NB = NBrsEff(M1);
	NK = NKolEff(M1);
	MATRIKS M3;
	ElType tmp;
	MakeMATRIKS(NB,NK,&M3)
	if(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2)){
		for(i=BrsMin; i<=NBrsEff(M1); i++){
			for(i=KolMin; i<=NKolEff(M1); j++){
				tmp = Elmt(M1,i,j) - Elmt(M2,i,j);
				Elmt(M3,i,j)=tmp;
				tmp=0;	
			}
		}
		return M3;
	}
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	int i,j;
	MATRIKS M3;
	if 
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
	int i,j;
	MATRIKS Mout;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);
	for(i=BrsMin;i<=NBrsEff(M);i++){
		for(j=KolMin;j<=NKolEff(M);j++){
			Elmt(Mout,i,j) = Elmt(M,i,j) * X;
		}
	}
	return Mout;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
	int i,j;
	MATRIKS Mout;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);
	for(i=BrsMin;i<=NBrsEff(M);i++){
		for(j=KolMin;j<=NKolEff(M);j++){
			Elmt(Mout,i,j) = Elmt(M,i,j) * X;
		}
	}
	TulisMATRIKS(Mout);
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	boolean sama=true;
	if(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2)){
		for(int i=BrsMin; i<=NBrsEff(M1); i++){
			for(j=KolMin;j<=NKolEff(M1);j++){
				if(Elmt(M1,i,j)==Elmt(M2,i,j)){
					sama = true;
				}
				else{
					sama=false;
					return sama;
				}
			
			}
		}
	}
	else{
		sama = false;
		return sama;
	}
	return sama;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1[i][j] = M2[i][j] */
boolean NEQ (MATRIKS M1, MATRIKS M2){
	return !EQ(M1,M2);
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	return(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NbElmt (MATRIKS M){
	return(NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
	boolean simetri=true;
	if(IsBujurSangkar(M)){
		for(int i=BrsMin; i<=NBrsEff(M); i++){
			for(j=KolMin;j<=NKolEff(M);j++){
				if(Elmt(M,i,j)==Elmt(M,j,i)){
					simetris = true;
				}
				else{
					return false;
				}
			}
		}
			
	}
	else{
		return false;
	}
	return simetris;
}

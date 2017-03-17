#include "soal2.h"
#include <stdio.h>
float total(int X[], int j){
	
	int total=0;
	float rata=0;
	int i;
	for( i=0; i<j; i++){
		
		total+=X[i];
	}
	rata = total/i;
	
	return rata;
	
}
int main(){
	int N;
	
	DataMahasiswa a;
	
	printf("Masukan banyak mahasiswa : ");
	scanf("%d",&N);
	int j=0;
	float tot[N];
	for (int i=0; i<N; i++){
		printf("Masukan data mahasiswa ke-%d\n",i+1);
		printf("Nama : ");
		scanf("%s",a[i].nama);
		printf("Nim : ");
		scanf("%s",a[i].nim);
		printf("Masukan nilai \n");
		for( j=0; j<=3; j++){
			if(j==0){
				printf("Masukan nilai matematika : ");
				scanf("%d",&a[i].nilai[j]);
			}
			else if(j==1){
				printf("Masukan nilai fisika : ");
				scanf("%d",&a[i].nilai[j]);
			}
			else if(j==2){
				printf("Masukan nilai kimia : ");
				scanf("%d",&a[i].nilai[j]);
			}
			else if(j==3){
				printf("Masukan nilai Pti : ");
				scanf("%d",&a[i].nilai[j]);
			}
			
		}
		tot[i] = total(a[i].nilai,j);
			j=0;
	}
	for(int i=0; i<N; i++){
		printf("%d.",i+1);
		printf(" %s",a[i].nama);
		printf(" (%s)",a[i].nim);
		printf(" = %.2f",tot[i]);
		printf("\n");
	}
	


return 0;

}

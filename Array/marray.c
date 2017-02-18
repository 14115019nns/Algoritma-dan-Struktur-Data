#include "array.h"
#include <stdio.h>
int main(){
	
	TabInt T;
	ElType X;
	IdxType i=1;
	
	MakeEmpty(&T);
	BacaIsi(&T);
	TulisIsiTab(T);
	
	
	return 0;
}

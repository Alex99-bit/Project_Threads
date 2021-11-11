#include <iostream>
#include <pthread.h>
#include <windows.h>
using namespace std;

#include "Primos.h"
#define sys system

// Funcion principal, despliega el menu
int main(){
	Primos obj;
	short int op=true;
	
	do{
		sys("cls");
		cout<<"\n\t**Numeros primos mejorados**"<<endl;
		obj.ingr_num();
		obj.buscar_primo();
		obj.cont_primos();
		
		
		cout<<"\n\tRepetir proceso? 1-Si 0-No\n\t>> ";
		cin>>op;
		
		while(op<0 || op>1){
			cout<<"\n\tError, opcion invalida\n\t>> ";
			cin>>op;
		}
	}while(op);
	return 0;
}

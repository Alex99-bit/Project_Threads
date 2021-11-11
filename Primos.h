
// Prototipo de la funcion para los procesos de los hilos
void *process(void *arg);
void *busca(void *arg);

// Estructura para almacenar el contador y el numero limite
typedef struct{
	int num,cont;
	int cont2,buscador;
}Tipos;

// Clase para contar los numeros primos
class Primos{
	private:
		Tipos numers;
	public:
		void ingr_num();
		void cont_primos();
		void buscar_primo();
};

void Primos::buscar_primo(){
	cout<<"\n\tIngresa el numero que quieres comparar: ";
	cin>>numers.buscador;
}

// Metodo que se implementa para pedir y almacenar un numero en la estructura
void Primos::ingr_num(){ 
	cout<<"\n\tIngresa un numero entero: ";
	cin>>numers.num;
}

// Se crea el hilo dentro del metodo
void Primos::cont_primos(){
	pthread_t hilo_cont;
	pthread_t hilo_busc;
	
	pthread_create(&hilo_cont,NULL,process,&numers);
	pthread_create(&hilo_busc,NULL,busca,&numers);
	
	pthread_join(hilo_cont,NULL);
	pthread_join(hilo_busc,NULL);
}

//Ejecuta el hilo de busqueda
void *busca(void *arg){
	Tipos var = *((Tipos*)arg);
	
	var.cont=0;
	for(long int i=1;i<=var.buscador;i++){
		
		if(var.buscador%i==0){
			var.cont++;
			cout<<"\n\tNumero "<<i<<" divide a "<<var.buscador<<endl;
		}
	}
	
	if(var.cont<=2){
		cout<<"\n\tEl numero "<<var.buscador<<" es primo"<<endl;
	}else{
		cout<<"\n\tEl numero "<<var.buscador<<" no es primo"<<endl;
	}
}

// Ejecuta el proceso de muestreo de los numeros primos
void *process(void *arg){
	Tipos var = *((Tipos*)arg);
	
	// Indice entra en sub ciclo para compararce con los numeros que hay hasta la posicion del indice
	for(long int i=1;i<=var.num;i++){
		var.cont=0;
		for(long int j=1;j<=i;j++){
			if(i%j==0){
				var.cont++;
			}
		}
		if(var.cont<=2){
			cout<<"\n\t"<<i;
			var.cont2++;
		}
	}
	
	cout<<"\n\tHay un total de "<<var.cont2<<" numeros primos"<<endl;
}


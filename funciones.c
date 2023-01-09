//Autores.- Martinez Buenrostro Jorge Rafael 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
//#include <math.h>
#include "funciones.h"
 
arreglo crearArreglo(int n){
	arreglo a;

	a = (arreglo)malloc(sizeof(Arreglo));

	a->arr = (int*)malloc(sizeof(int)*n);
	a->tam = n;
	return a;
}

int numeroRandom(int minimo,int maximo){
	srand((unsigned)time(NULL)*clock()*getpid());
	return rand() % (maximo + 1 - minimo) + minimo;
}

void llenarArreglo(arreglo a){
	int i,j,r;

	for(i = 0;i < a->tam;i++){
//		a->arr[i] = numeroRandom(1,a->tam*(i+1));
		a->arr[i] = numeroRandom(0,9);		
	}
}

void liberarArreglo(arreglo a){
	free(a->arr);
	free(a);
}

/*
Se ordena el arreglo 'a' usando el metodo de la burbuja
*/

void ordenarArreglo(arreglo a){
 	int i,j,temp,n;

 	n = a->tam;

   	for (i = 0; i < n-1; i++){       
       	for (j = 0; j < n-i-1; j++){
          	if (a->arr[j] > a->arr[j+1]){
              temp = a->arr[j];
              a->arr[j] = a->arr[j+1];
              a->arr[j+1] = temp;
			}
		}
	}	 
}

void mostrarArreglo(arreglo a){
	int i;

	for(i = 0;i < a->tam;i++){
		printf("|%d|",a->arr[i]);
	}
	printf("\n");
}

void unirArreglo(arreglo a,arreglo b,arreglo c){
	int i,j,k;
	/*
	i es el indice que recorre el arreglo a 
	j es el indice que recorre el arreglo b
	*/
	k = 0; //indice que recorre el arreglo c
	/*
	este ciclo se acaba cuando alguno de los indices i o j 
	alcanza el tamaño de su arreglo 
	*/
    for(i = 0, j = 0;i < a->tam && j < b->tam;){
    	if(a->arr[i] < b->arr[j]){
    		c->arr[k++] = a->arr[i++];
    	}else{
    		c->arr[k++] = b->arr[j++];
    	}   	
   	}
    /*
	este ciclo inicia cuando el arreglo b es mas pequeño 
	que el arreglo a
    */
    while (i < a->tam){
    	c->arr[k++] = a->arr[i++];
    } 
    /*
	este ciclo inicia cuando el arreglo a es mas pequeño 
	que el arreglo b 
    */
    while (j < b->tam){
        c->arr[k++] = b->arr[j++];
    }
}

double cronometro(arreglo a){
	double t;

	clock_t inicio = clock();

	/*
	funcion a cronometrar
	*/

	clock_t final = clock();
	t = (double)(final - inicio) / CLOCKS_PER_SEC;

	return t;
}

void mergeSort(arreglo a,int bajo,int alto){
	int mitad;
		
	if(bajo < alto){
		mitad = (bajo + alto) / 2;
		/*
		recursion por la izquierda
		*/
		mergeSort(a,bajo,mitad);
		/*
		recursion por la derecha
		*/
		mergeSort(a,mitad + 1,alto);
		/*
		mezcal de los dos sub-arreglos ordenados
		*/
		merge(a,bajo,mitad,mitad + 1,alto);	
	}
}
 
void merge(arreglo a,int bajo_1,int alto_1,int bajo_2,int alto_2){
	arreglo temp;
	int i,j,k;

	temp = crearArreglo(a->tam);	
	
	i = bajo_1;
	j = bajo_2;	
	k = 0;

	/*
	este ciclo acaba cuando ya no hay elementos en los arreglos
	*/
	
	while(i <= alto_1 && j <= alto_2){	
		if(a->arr[i] < a->arr[j]){
			temp->arr[k++] = a->arr[i++];
		}
		else{
			temp->arr[k++] = a->arr[j++];
		}
	}

	/*
	copia los elementos restantes del primer arreglo
	*/
	
	while(i <= alto_1){	
		temp->arr[k++] = a->arr[i++];
	}	

	/*
	copia los elementos restantes del segundo arreglo
	*/
	while(j <= alto_2){	
		temp->arr[k++] = a->arr[j++];
	}

	/*
	copia los elementos del arreglo temporal al arreglo a
	*/
	for(i = bajo_1,j = 0;i <= alto_2;i++,j++){
		a->arr[i] = temp->arr[j];
	}
}

cadena crearCadena(){
	cadena a;

	a = (cadena)malloc(sizeof(Cadena));

	a->wn = (char*)malloc(sizeof(char));
	return a;
}

void pedirCadena(cadena a){
	scanf("%[^\n]s",a->wn);
	getchar();
}

void subCadena(cadena c,cadena s){
	int nC,nS;

	nC = strlen(c->wn);
	nS = strlen(s->wn);

	int indiceS,indiceC,temp;
	indiceS = 0;
	indiceC = 0;
	temp = 0;

	int esta;
	esta = 0;

	if(nS > nC){
		printf("\nLa subcadena es mas grande que la cadena principal\n");
	}
	if(nS <= nC){

		while(indiceC < nC){
			indiceS = 0;
			while(c->wn[indiceC] == s->wn[indiceS]){
				indiceS++;
				indiceC++;
			}

			if(indiceS == nS )
				esta++;

			indiceC++;
		}

		printf("\n\nLa subCadena '%s' se encuentra %i veces dentro de la cadena principal '%s'\n",s->wn,esta,c->wn );
	}
}

nodo crearLista(){
	nodo lista;
	lista = NULL;
	return lista;
}

nodo crearNodo(){
	nodo nvo;

	nvo = (nodo)malloc(sizeof(Nodo));

	nvo->elemento = crearArchivo();
	return nvo;
}

archivo crearArchivo(){
	archivo a;

	a = (archivo)malloc(sizeof(Archivo));

	a->valor = 0;
	a->mbytes = 0;
	a->tasa = 0.0;
	return a;
}

nodo abrirArchivo(nodo lista){
	archivo a;
	cadena partida,leida;
    FILE * f;
    int elemento,i;

    f = fopen ("datos.csv", "r"); 

    if (f == NULL){
	    printf("Error opening file");
	}else{
	   	leida = crearCadena();

	 	while(!feof(f)){
	 		i = 0;
		    a = crearArchivo();
		    partida = crearCadena();
		    //fgets(donde se guardara,
		    //numero maximo de caracteres que leera incluyendo null,
		    //apuntador del archivo)
			fgets(leida->wn, 99, f);

		    partida->wn = strtok(leida->wn,",");
			elemento = atoi(partida->wn);
			a->valor = elemento;

		  	while(partida->wn != NULL){
		  		partida->wn = strtok(NULL,",");

		    	if(partida->wn != NULL){
		       		a->mbytes = atoi(partida->wn);
		   	   	}           
		    }
		    a->tasa = (float)a->mbytes / (float)elemento;
		    lista = insertar(lista,a);
		   	i++;
	    }
    }

   	fclose(f); 
   	fflush(stdin);
   	return lista;
}

nodo insertar(nodo lista,archivo a){
	nodo actual, ultimo, nvo;
	actual = lista;

	if(lista == NULL){
		nvo = crearNodo();
		nvo->elemento = a;
		nvo->nxt = NULL;
		lista = nvo;
		return lista;
	}

	while(actual != NULL){
		ultimo = actual;
		actual = actual->nxt;
	}

	nvo = crearNodo();
	nvo->elemento = a;
	nvo->nxt = ultimo->nxt;
	ultimo->nxt = nvo;
	return lista;
}

void mostrarLista(nodo lista){
	nodo actual;
	actual = lista;

	while(actual != NULL){
		printf("|%d,%d|\n",actual->elemento->valor,actual->elemento->mbytes);
		actual = actual->nxt;
	}
}

nodo ordenarPorValor(nodo lista){
	nodo actual, siguiente;
	archivo a;
	
	actual = lista;

	while(actual->nxt != NULL){
		siguiente = actual->nxt;

		while(siguiente != NULL){
			if(actual->elemento->valor > siguiente->elemento->valor){
				a = siguiente->elemento;
				siguiente->elemento = actual->elemento;
				actual->elemento = a;
			}
			siguiente = siguiente->nxt;
		}
		actual = actual->nxt;
		siguiente = actual->nxt;
	}
	return lista;
}

nodo ordenarPorMb(nodo lista){
	nodo actual, siguiente;
	archivo a;
	
	actual = lista;

	while(actual->nxt != NULL){
		siguiente = actual->nxt;

		while(siguiente != NULL){
			if(actual->elemento->mbytes > siguiente->elemento->mbytes){
				a = siguiente->elemento;
				siguiente->elemento = actual->elemento;
				actual->elemento = a;
			}
			siguiente = siguiente->nxt;
		}
		actual = actual->nxt;
		siguiente = actual->nxt;
	}
	return lista;
}

nodo ordenarPorTasa(nodo lista){
	nodo actual, siguiente;
	archivo a;

	actual = lista;

	while(actual->nxt != NULL){
		siguiente = actual->nxt;

		while(siguiente != NULL){
			if(actual->elemento->tasa > siguiente->elemento->tasa){
				a = siguiente->elemento;
				siguiente->elemento = actual->elemento;
				actual->elemento = a;
			}
			siguiente = siguiente->nxt;
		}
		actual = actual->nxt;
		siguiente = actual->nxt;
	}
	return lista;
}

nodo obtenerDatos(nodo lista, int tam){
	nodo actual,aux;
	int suma;

	suma = 0;
	actual = lista;
	aux = crearLista();

	while(actual != NULL && suma <= tam){
		if( (suma += actual->elemento->mbytes) > tam ){
			return aux;
		}else{
			aux = insertar(aux,actual->elemento);
			actual = actual->nxt;
		}
	}
	return aux;
}

int valorTotal(nodo lista){
	nodo actual;
	int total;

	total = 0;
	actual = lista;

	while(actual != NULL){
		total += actual->elemento->valor;
		actual = actual->nxt;
	}
	return total;
}

int mbytesTotales(nodo lista){
	nodo actual;
	int total;

	total = 0;
	actual = lista;

	while(actual != NULL){
		total += actual->elemento->mbytes;
		actual = actual->nxt;
	}
	return total;
}

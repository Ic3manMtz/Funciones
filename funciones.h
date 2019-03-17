//Autores.- Martinez Buenrostro Jorge Rafael 

#include <stdio.h>

#ifndef _arreglo_
#define _arreglo_

typedef struct Arreglo{
	int * arr;
	int tam;
}Arreglo;

typedef struct Cadena{
	char * wn;
}Cadena;

typedef struct Archivo{
	int valor;
	int mbytes;
	float tasa;
}Archivo;

typedef struct Nodo{
	struct Archivo * elemento;
	struct Nodo * nxt;
}Nodo;

typedef Arreglo * arreglo;
typedef Cadena * cadena;
typedef Archivo * archivo;
typedef Nodo * nodo;

arreglo crearArreglo(int n);
int numeroRandom(int minimo,int maximo);
void llenarArreglo(arreglo a);
void liberarArreglo(arreglo a);
void ordenarArreglo(arreglo a);
void mostrarArreglo(arreglo a);

void unirArreglo(arreglo a,arreglo b,arreglo c);

double cronometro(arreglo a);

void mergeSort(arreglo a,int bajo,int alto);
void merge(arreglo a,int bajo_1,int alto_1,int bajo_2,int alto_2);

cadena crearCadena();
void pedirCadena(cadena a);
void subCadena(cadena a,cadena b);

nodo crearLista();
nodo crearNodo();
archivo crearArchivo();
nodo abrirArchivo(nodo lista);
nodo insertar(nodo lista, archivo a);
void mostrarLista(nodo lista);
nodo ordenarPorValor(nodo lista);
nodo ordenarPorMb(nodo lista);
nodo ordenarPorTasa(nodo lista);
nodo obtenerDatos(nodo lista, int tam);
int valorTotal(nodo lista);
int mbytesTotales(nodo lista);

#endif
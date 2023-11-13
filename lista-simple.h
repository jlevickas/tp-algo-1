#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "libro.h"

#ifndef __LISTA
#define __LISTA

typedef Libro T;

typedef struct nodo {
	T dato;
	struct nodo * sig;
} Nodo;

typedef struct {
	Nodo * com;
	Nodo * actual;
	int cantidad;
} Lista;

void crearLista(Lista * l){
	Nodo * cab = (Nodo *)malloc(sizeof(Nodo));
	Nodo * cen = (Nodo *) malloc (sizeof(Nodo));
	l->com = cab;
	l->actual = cab;
	cab->sig = cen;
	cen->sig = NULL;
	l->cantidad = 0;
}

void posicionar(Lista *l, int x){
	primero(l);
	for (int i = 0; i < x; ++i){
		siguiente(l);
	}
}

void primero(Lista * l){
	 l->actual = l->com->sig;
}

boolean esListaVacia(Lista l){
	return l.cantidad == 0;
}

void siguiente (Lista * l){
	l->actual = l->actual->sig;
}

boolean esUltimo(Lista l){
	return l.actual->sig == NULL;
}

T getDato(Lista l){
	return l.actual->dato;
}

void anterior (Lista * l){
	Nodo * p = l->com;
	while (p->sig != l->actual)
	{
		p = p->sig;
	}
	l->actual = p;
}

void insertarDespues(Lista * l, T x){
	Nodo * aux = (Nodo*)malloc(sizeof(Nodo));
	aux->dato = x;
	aux->sig = l->actual->sig;
	l->actual->sig = aux;
	l->actual = aux;
	(l->cantidad)++;
}

void insertarAntes(Lista * l, T x){
	Nodo * aux = (Nodo*)malloc(sizeof(Nodo));
	aux->dato = x;
	aux->sig = l->actual;
	anterior(l);
	l->actual->sig = aux;
	l->actual = aux;
	(l->cantidad)++;
}

void eliminar(Lista * l){
	Nodo * aux = l->actual;
	anterior(l);
	l->actual->sig = aux->sig;
	free(aux);
	(l->cantidad)--;
}

/* void buscar(Lista * l, T x){
	// NO FUNCIONA CON TDA ALUMNO XQ NO SE PUEDE COMPARAR.
	// PODRÍA FUNCIONAR SI SE COMPARA POR MATRICULA
	primero(l);
	while (l->actual->dato != x){
		siguiente(l);
	}
} */

void copiar(Lista * l1, Lista * l2){
	primero(l1);
	while (!esUltimo(*l1)){
		insertarDespues(l2, getDato(*l1));
		siguiente(l1);
	}
}

Nodo * getActual(Lista l){
	return l.actual;
}

void setActual(Lista * l, Nodo * n){
	l->actual = n;
}

#endif
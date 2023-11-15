#include "util.h"

#ifndef __LIBRO
#define __LIBRO

typedef struct {
    char titulo[100];
    char autores[300];
    int cant_paginas;
    int ISBN;
    int anio_edicion;
    char editorial[100];
    char genero[100];
} Libro;

void crearLibro(Libro *l){
    strcpy(l->titulo,"");
    l->cant_paginas = 0;
    l->ISBN = 0;
    l->anio_edicion = 0;
    strcpy(l->autores,"");
    strcpy(l->editorial,"");
    strcpy(l->genero,"");
}

void set_titulo(Libro *l, char * titulo){
    strcpy(l->titulo, titulo);
}

char * get_titulo(Libro l){
    char * aux = (char*) malloc(100*sizeof(char));
	strcpy(aux, l.titulo);
	return aux;
}

void set_ISBN(Libro *l,int ISBN){
    l->ISBN = ISBN;
}

int get_ISBN(Libro l){
    return l.ISBN;
}

void set_autores(Libro *l, char *a){
    strcpy(l->autores, a);
}

char * get_autores(Libro l){
    char * aux = (char*) malloc(300*sizeof(char));
	strcpy(aux, l.autores);
	return aux;
}
    
void set_cant_pag(Libro *l, int cant_paginas){
    l->cant_paginas = cant_paginas;
}

int get_cant_pag(Libro l){
    return l.cant_paginas;
}

void set_anio_edicion(Libro *l, int anio_edicion){
    l->anio_edicion = anio_edicion;
}

int get_anio_edicion(Libro l){
    return l.anio_edicion;
}

void set_editorial(Libro *l, char * editorial){
    strcpy(l->editorial,"");
}

char * get_editorial(Libro l){
    char * aux = (char*) malloc(100*sizeof(char));
	strcpy(aux, l.editorial);
	return aux;
}

void set_genero(Libro *l,char * genero){
    strcpy(l->genero,"");
}

char * get_genero(Libro l){
    char * aux = (char*) malloc(100*sizeof(char));
	strcpy(aux, l.genero);
	return aux;
}

boolean comparaLibro(Libro l1, Libro l2){
    return l1.ISBN == l2.ISBN;
}

char * toString(Libro l){
	char * linea = (char*)malloc(sizeof(char)*500);
	sprintf(linea,"Titulo: %s\nAutores: %s\nCantidad de paginas: %d\nISBN: %d\nAnio de edicion: %d\nEditorial: %s\nGenero: %s\n",l.titulo,l.autores,l.cant_paginas,l.ISBN,l.anio_edicion,l.editorial,l.genero); 
    return linea;
}

void leerLibro(Libro *l){
    char titulo[100];
    leerCadena(titulo, 100, "Ingrese el titulo: ");
    strcpy(l->titulo, titulo);

    char autor[300];
    printf("Ingrese la cantidad de autores (1-3): ");

    int cant_autores;
    scanf(" %d", &cant_autores);
    getchar();

    int i;
    for(i=0; i<cant_autores; i++){
        char autor[100];
        leerCadena(autor, 100, "Ingrese un autor: ");
        strcat(l->autores, autor);
        if (i < cant_autores - 1) {
            strcat(l->autores, ", ");
        }
    }

    printf("Ingrese la cantidad de paginas: ");
    scanf(" %d", &l->cant_paginas);
    getchar();    
    
    printf("Ingrese el ISBN: ");
    scanf(" %d", &l->ISBN);
    getchar();

    printf("Ingrese el anio de edicion: ");
    scanf(" %d", &l->anio_edicion);
    getchar();

    char editorial[100];
    leerCadena(editorial, 100, "Ingrese la editorial: ");
    strcpy(l->editorial, editorial);
     
    char genero[100];
    leerCadena(genero, 100, "Ingrese el genero: ");
    strcpy(l->genero, genero);

}



#endif
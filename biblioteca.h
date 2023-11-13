#include "libro.h"
#include "lista-simple.h"

typedef Lista Biblioteca;
void crearBiblioteca (Biblioteca * b){
	crearLista(b);
}

void altaLibro (Biblioteca * b, Libro l){
    if(!existeLibro(*b, l))
        insertarDespues(b, l);
}

void bajaLibro (Biblioteca * b, Libro l){
    if(existeLibro(*b, l)){
        eliminar(b);
    }
}

void modificarLibro(Biblioteca * b, Libro l){
    if(existeLibro(*b, l)){
        eliminar(b);
        leerLibro(&l);
        insertarDespues(b, l);
    }
}

boolean existeLibro(Biblioteca b, Libro l){
    boolean existe = 0;
    primero(&b);
    while(!esUltimo(b) && !existe){
        existe = comparaLibro(l, getDato(b));
        siguiente(&b);
    }
}


void listarAutores(Biblioteca b){
    primero(&b);
    while(!esUltimo(b)){
        printf("%s\n", get_autores(getDato(b)));
        siguiente(&b);
    }
}

void listarTitulos(Biblioteca b){
    primero(&b);
    while(!esUltimo(b)){
        printf("%s\n", get_titulo(getDato(b)));
        siguiente(&b);
    }
}

#include "libro.h"
#include "lista-simple.h"

typedef Lista Biblioteca;
void crearBiblioteca (Biblioteca * b){
	crearLista(b);
}

void altaLibro (Biblioteca * b){
    Libro l;
    crearLibro(&l);
    leerLibro(&l);
    if(!existeLibro(*b, l))
        insertarDespues(b, l);
}

void bajaLibro (Biblioteca * b, Libro l){
    if(existeLibro(*b, l)){
        setActual(b, l);
        eliminar(b);
    }
}

void modificarLibro (Biblioteca * b, Libro l){
    
}

boolean existeLibro(Biblioteca b, Libro l){
    boolean existe = 0;
    Libro aux;
    crearLibro(&aux);
    while(!esUltimo(b) && !existe){
        leerLibro(&aux);
        existe = comparaLibro(l, aux);
    }
    return existe;
}


void listarAutores(Biblioteca b){
    Libro l;
    crearLibro(&l);
    while(!esUltimo(b)){
        leerLibro(&l);
        printf("%s\n", get_autores(l));
    }
}

void listarLibros(Biblioteca b){
    Libro l;
    crearLibro(&l);
    while(!esUltimo(b)){
        leerLibro(&l);
        printf("%s\n", get_titulo(l));
    }
}

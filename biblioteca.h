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

char * buscarLibro(Biblioteca b, char* libroDeseado) {
    primero(&b);
    while (!esUltimo(b)){
        Libro libroActual = getDato(b);
        char* tituloActual = get_titulo(libroActual);

        if (strcmp(tituloActual, libroDeseado) == 0) {
            return (toString(libroActual));
        }
        else{
        siguiente(&b);
        }
    }
}

//primero
void listarAutores(Biblioteca b){
    primero(&b);
    while(!esUltimo(b)){
        printf("%s\n", get_autores(getDato(b)));
        siguiente(&b);
    }
}

//segundo
void listarTitulos(Biblioteca b){
    primero(&b);
    while(!esUltimo(b)){
        printf("%s\n", get_titulo(getDato(b)));
        siguiente(&b);
    }
}

//tercero
void listarGenero(Biblioteca b, char* generoDeseado) {
    primero(&b);
    while (!esUltimo(b)){
        Libro libroActual = getDato(b);
        char* generoActual = get_genero(libroActual);

        if (strcmp(generoActual, generoDeseado) == 0) {
            printf("Libro : %s\n", toString(libroActual));
            printf("\n");
        }

        siguiente(&b);
    }
}

//cuarto
void listarAutor(Biblioteca b, char* autorDeseado) {
    primero(&b);
    while (!esUltimo(b)){
        Libro libroActual = getDato(b);
        char* autorActual = get_autores(libroActual);

        if (strcmp(autorActual, autorDeseado) == 0) {
            printf("Libro : %s\n", toString(libroActual));
            printf("\n");
        }

        siguiente(&b);
    }
}

//quinto
void listarEditorial(Biblioteca b, char* editorialDeseada) {
    primero(&b);
    while (!esUltimo(b)){
        Libro libroActual = getDato(b);
        char* editorialActual = get_editorial(libroActual);

        if (strcmp(editorialActual, editorialDeseada) == 0) {
            printf("Libro : %s\n", toString(libroActual));
            printf("\n");
        }

        siguiente(&b);
    }
}

void listarEditorialPorEdicion(Biblioteca b, char* editorialDeseada, int anio1, int anio2) {
    primero(&b);
    while (!esUltimo(b)){
        Libro libroActual = getDato(b);
        char* editorialActual = get_editorial(libroActual);

        if (strcmp(editorialActual, editorialDeseada) == 0) {
            if(get_anio_edicion(libroActual)<=anio2 && get_anio_edicion(libroActual)>=anio1){
                printf("Libro : %s\n", toString(libroActual));
                printf("\n");
            }
        }
        siguiente(&b);
    }
}

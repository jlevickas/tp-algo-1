#include "libro.h"
#include "lista-simple.h"

typedef Lista Biblioteca;
void crearBiblioteca (Biblioteca * b){
	crearLista(b);
}

boolean existeLibro(Biblioteca b, Libro l){
    boolean existe = false;
    primero(&b);
    while(!esUltimo(b) && !existe){
        existe = comparaLibro(l, getDato(b));
        siguiente(&b);
    }
    return existe;
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

void seleccionarLibro(Biblioteca *b, Libro *l){
    int ISBN;
    printf("Ingrese el ISBN del libro que desea buscar: ");
    scanf("%d", &ISBN);
    primero(b);
    boolean existe = false;
    while(!esUltimo(*b) && !existe){
        if(get_ISBN(getDato(*b)) == ISBN){
            *l = getDato(*b);
            existe = true;
        }
        siguiente(b);
    }
}

void buscarLibro(Biblioteca * b, char* libroDeseado) {
    primero(b);
    while (!esUltimo(*b)){
        Libro libroActual = getDato(*b);
        char * tituloActual = get_titulo(libroActual);

        if (strcmp(tituloActual, libroDeseado) == 0) {
            printf("%s\n",toString(libroActual));
            return;
        }
        else{
        siguiente(b);
        }
    }
}

//primero
void listarAutores(Biblioteca * b){
    primero(b);
    while (!esUltimo(*b)){
        Libro libro = getDato(*b);
        char * autores = get_autores(libro);
        char delimitador[3] = ", ";

        char * autor = strtok(autores, delimitador);

        while (autor != NULL){
            printf("%s\n", autor);
            autor = strtok(NULL, delimitador);
        }
        siguiente(b);
    }
}

//segundo
void listarTitulos(Biblioteca *b){
    printf("Listado de titulos:\n");
    primero(b);
    while(!esUltimo(*b)){
        printf("%s\n", get_titulo(getDato(*b)));
        siguiente(b);
    }
}

//tercero
void listarGenero(Biblioteca * b, char* generoDeseado) {
    primero(b);
    while (!esUltimo(*b)){
        Libro libroActual = getDato(*b);
        char* generoActual = get_genero(libroActual);

        if (strcmp(generoActual, generoDeseado) == 0) {
            printf("Libro: %s\n", toString(libroActual));
            printf("\n");
        }

        siguiente(b);
    }
}

//cuarto
void listarAutor(Biblioteca * b, char* autorDeseado) {
    primero(b);
    while (!esUltimo(*b)){
        Libro libro = getDato(*b);
        char * autores = get_autores(libro);
        char delimitador[3] = ", ";

        char * autor = strtok(autores, delimitador);

        while (autor != NULL){
            if (strcmp(autor, autorDeseado) == 0){
                printf("Libro: %s\n", toString(libro));
                printf("\n");
            }
            autor = strtok(NULL, delimitador);
        }
        siguiente(b);
    }
}

//quinto
void listarEditorial(Biblioteca * b, char* editorialDeseada) {
    primero(b);
    while (!esUltimo(*b)){
        Libro libroActual = getDato(*b);
        char* editorialActual = get_editorial(libroActual);

        if (strcmp(editorialActual, editorialDeseada) == 0) {
            printf("Libro: %s\n", toString(libroActual));
            printf("\n");
        }

        siguiente(b);
    }
}

//sexto
void listarEditorialPorEdicion(Biblioteca * b, char* editorialDeseada, int anio1, int anio2) {
    primero(b);
    while (!esUltimo(*b)){
        Libro libroActual = getDato(*b);
        char* editorialActual = get_editorial(libroActual);

        if (strcmp(editorialActual, editorialDeseada) == 0) {
            if(get_anio_edicion(libroActual)<=anio2 && get_anio_edicion(libroActual)>=anio1){
                printf("Libro: %s\n", toString(libroActual));
                printf("\n");
            }
        }
        siguiente(b);
    }
}

//septimo
void listarAutoresEditorial(Biblioteca * b, char *editorialDeseada) {
    primero(b);
    
    while (!esUltimo(*b)) {
        Libro libroActual = getDato(*b);
        
        if (strcmp(get_editorial(libroActual), editorialDeseada) == 0) {
            printf("Autor: %s\n", get_autores(libroActual));
        }

        siguiente(b);
    }
}

//octavo
void listarPorAnioEdicion(Biblioteca * b, int anioDeseado) {
    primero(b);

    while (!esUltimo(*b)) {
        Libro libroActual = getDato(*b);

        if (get_anio_edicion(libroActual) == anioDeseado)
           printf("Libro: %s\n", toString(libroActual));
           break;
        }

        siguiente(b);
    }

//noveno
void listarAutoresPorLetra(Biblioteca *b, char letra) {
    primero(b);

    while (!esUltimo(*b)) {
        Libro libro = getDato(*b);
        char *autores = get_autores(libro);
        char *autor = strtok(autores, ", ");

        while (autor != NULL) {
            if (autor[0] == letra) {
                printf("%s\n", autor);  
            }
            autor = strtok(NULL, ", ");
        }

        siguiente(b);
    }
}

//decimo
void listarPorPalabraEnTitulo(Biblioteca *b, char *palabradeseada) {
    primero(b);

    while (!esUltimo(*b)) {
        Libro libroActual = getDato(*b);

        char titulo[100];
        strcpy(titulo, get_titulo(libroActual));
        char *token = strtok(titulo, " ");

        while (token != NULL) {
            
            if (strstr(token, palabradeseada)  != NULL) {
               printf("Libro: \n%s\n", toString(libroActual));
               break;  
            }

            token = strtok(NULL, " ");
        }
        siguiente(b);
    }
}

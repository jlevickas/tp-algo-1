#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "lista-simple.h"
#include "libro.h"
#include "biblioteca.h"

char menuPrincipal(){
    printf("---------------------------------------------\n");
	printf("A: Dar de Alta un Libro\nB: Dar de Baja un Libro\nC: Consultar por un libro por su titulo\nM: Modificar un Libro\nL: Ingresar al menu de Listados\nS: Salir del programa");
	printf("\nIngrese opcion: ");
	fflush(stdin);
	return getchar();
}

char menuListados(){
    printf("---------------------------------------------\n");
    printf("0: Listar todos los autores existentes\n1: Listar todos los libros existentes\n2: Listar todos los libros de un genero\n3: Listar todos los libros de un autor\n4: Listar todos los libros de una editorial\n5: Listar todos los libros de una editorial en un rango de anios\n6: Listar todos los autores de una editorial\n7: Listar todos los libros editados en determinado anio\n8: Listar todos los autores cuyo apellido empieza con determinada letra\n9: Listar todos los libros cuyos titulos contengan una palabra\nV: Volver al menu principal");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    return getchar();
}

void main(){
    Biblioteca b;
    crearBiblioteca(&b);
    Libro l;
    crearLibro(&l);
    char opcion;
    do {
        opcion = menuPrincipal();
        switch(opcion){
            case 'a':
            case 'A':
                leerLibro(&l);
                altaLibro(&b, l);
                break;
            case 'b':
            case 'B':
                seleccionarLibro(b, &l);
                bajaLibro(&b, l);
                break;
            case 'c':
            case 'C':
                char titulo[100];
                leerCadena(titulo, "Ingrese el titulo del libro a buscar: ");
                buscarLibro(b, titulo);
                break;
            case 'm':
            case 'M':
                seleccionarLibro(b, &l);
                modificarLibro(&b, l);
                break;
            case 'l':
            case 'L':
                char opcionListados;
                char editorial[100];
                char genero[100];
                char autor[100];
                int anio1, anio2;
                do {
                    opcionListados = menuListados(&b);
                    switch(opcionListados){
                        case '0':
                            listarAutores(b);
                            break;
                        case '1':
                            listarTitulos(b);
                            break;
                        case '2':
                            leerCadena(genero, "Ingrese el genero: ");
                            listarGenero(b, genero);
                            break;
                        case '3':
                            leerCadena(autor, "Ingrese el autor: ");
                            listarAutor(b, autor);
                            break;
                        case '4':
                            leerCadena(editorial, "Ingrese la editorial: ");
                            listarEditorial(b, editorial);
                            break;
                        case '5':
                            leerCadena(editorial, "Ingrese la editorial: ");
                            printf("Ingrese el anio inicial: ");
                            scanf("%d", &anio1);
                            printf("Ingrese el anio final: ");
                            scanf("%d", &anio2);
                            listarEditorialPorEdicion(b, editorial, anio1, anio2);
                            break;
/*                         case '6':
                            listarAutoresEditorial(&b);
                            break;
                        case '7':
                            listarLibrosAnio(&b);
                            break;
                        case '8':
                            listarAutoresLetra(&b);
                            break;
                        case '9':
                            listarLibrosPalabra(&b);
                            break; */
                    }
                } while (opcionListados != 'v' && opcionListados != 'V');
        }        
    } while (opcion != 's' && opcion != 'S');
}

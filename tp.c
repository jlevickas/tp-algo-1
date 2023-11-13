#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "lista-simple.h"
#include "libro.h"

int main(){
    Libro l;
    crearLibro(&l);
    leerLibro(&l);
    printf("Titulo: %s\n",get_titulo(l));
    printf("Autores: %s\n",get_autores(l));
    printf("Cant. paginas: %d\n",get_cant_pag(l));
    printf("ISBN: %d\n",get_ISBN(l));
    printf("Anio de edicion: %d\n",get_anio_edicion(l));
    printf("Editorial: %s\n",get_editorial(l));
    printf("Genero: %s\n",get_genero(l));
    return 0;
}
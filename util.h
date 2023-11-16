#ifndef __UTIL
#define __UTIL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define false 0
#define true !false
typedef int boolean;


char * leerCadena(char * c, int size, char * msg){
    printf(msg);
    fflush(stdin);
    fgets(c, size, stdin);
    c[strlen(c)-1] = '\0';
    return c;
}

char leerChar(char *c, char *msg) {
    printf("%s", msg);
    scanf(" %c", c);
    getchar();

    return *c;
}

#endif
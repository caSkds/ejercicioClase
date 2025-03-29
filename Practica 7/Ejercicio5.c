#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

void main(){
    int deleted;
    struct lista elements;
    crearLista(&elements);
    insertar(&elements,5);
    insertar(&elements,6);
    insertar(&elements,7);
    insertar(&elements,8);
    insertar(&elements,9);
    insertar(&elements,10);
    verLista(&elements);
    printf("Seleccione el índice a eliminar");
    do{
        printf("Por favor elegir un índice del 0 al 5\n");
        scanf("%d",&deleted);
    }
    while(deleted<0||deleted>6);

    borrarIndice(&elements,deleted);
    verLista(&elements);
    borrarIndice(&elements,1);
}
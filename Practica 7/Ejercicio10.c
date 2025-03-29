#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

int indexInsert(struct lista*);

void main(){
    struct lista miLista;
    struct lista aux1;
    struct lista aux2;
    struct lista aux3;
    int divisions = 0;
    crearLista(&miLista);
    crearLista(&aux1);
    crearLista(&aux2);
    crearLista(&aux3);
    for(int i = 0; i<7; i++){
        divisions = insertar(&miLista, i);
    }
    do{
        printf("Favor de seleccionar el número de listas en las cuales dividir el arreglo \n");
        scanf("%d",&divisions);
    }while(divisions<1 &&divisions >3);
    printf("Lista original:\n");
    verLista(&miLista);
    if(divisions ==1){
        for(int i =0; i<7; i++){
            insertarIndice(&aux1,i,indexInsert(&aux1));
        }
    }
    else if(divisions ==2){
        for(int i =0; i<7; i++){
            if(i%2){
                insertarIndice(&aux1,i,indexInsert(&aux1));

            }
            else{
                insertarIndice(&aux2,i,indexInsert(&aux2));
            }
        }
    }
    else if(divisions ==3){
        for(int i =0; i<7; i++){
            if(i%3 == 0){
                insertarIndice(&aux1,i,indexInsert(&aux1));

            }
            else if(i%3==1){
                insertarIndice(&aux2,i,indexInsert(&aux2));
            }
            else{insertarIndice(&aux3,i,indexInsert(&aux3));}
        }
    }
    printf("Lista 1: \n");
    verLista(&aux1);
    printf("Lista 2: \n");
    verLista(&aux2);
    printf("Lista 3: \n");
    verLista(&aux3);
}


int indexInsert(struct lista* list){
    if (size(list) ==-1){
        return 0;
    }
    else{return size(list);}
}
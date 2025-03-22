
#include <stdio.h>
#include <stdlib.h>
#include "DynamicQueue.h"



void main(){
    struct cola *Queue = calloc(1,sizeof(struct cola));
    struct cola *auxQueue = calloc(1,sizeof(struct cola));
    int elementos[6];

    crearCola(Queue);
    crearCola(auxQueue);

    int max = 0 ;
    int aux = 0;
    for(int i = 0; i < 12; i++){
        int dato;
        printf("Ingrese el dato %i:",i+1);
        scanf("%i",&dato);
        encolar(Queue,dato);
    }
    printf("Primeros elementos de la cola: ");
    for(int i = 0; i < 12; i++){
        if (front(Queue) > max){
            max = front(Queue);
        }
        if (i<6){
            printf("%i ",front(Queue));
        }
        encolar(auxQueue,front(Queue));
        desencolar(Queue);

    }

    printf("\nElementos invertidos de la cola: ");
    for(int i = 0; i <6; i++){
        elementos[i] = front(auxQueue);
        desencolar(auxQueue); 
    }
    for(int i = 5; i > -1; i--){
        encolar(auxQueue,elementos[i]);
    }
    for(int i = 0; i < 12; i++){
        if (i>6){
            printf("%i ",front(auxQueue));
        }
        
        desencolar(auxQueue);
        
    }
    printf("\nEl elemento mas grande de la cola es: %d\n", max);
    free(Queue);
    free(auxQueue);
}
    
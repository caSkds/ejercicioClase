#include "DynamicQueue.h"
#include <stdio.h>
#include <stdlib.h>



void main(){
    struct cola *Queue = calloc(1,sizeof(struct cola));
    crearCola(Queue);


    
    int currElement=0;
    int max = 0;
    int queueElements[12] ={0};
    int iterator =0;
    
    for(int i = 0; i<12;i++){
        printf("Ingrese un número \n");
        scanf("%d",&currElement);
        encolar(Queue, currElement);
    }
    
    struct nodo *verNodo = Queue->frente;
    while (verNodo != NULL) {
        queueElements[iterator] = verNodo->dato;
        iterator++;
        verNodo = verNodo->siguiente;
    }
    max = queueElements[0];
    for(int i =0; i<12; i++){
        if(queueElements[i]>max){
            max = queueElements[i];
        }
        
    }
    printf("El elemento más grande de la cola es: %d\n", max);
    printf("Los primeros 6 elementos de la cola son:\n");
    for(int i=0;i<6; i++){
        printf("%d ", queueElements[i]);
        
    }
    printf("\n");
    printf("Dichos elementos invertidos son:\n");
    for(int i=5;i>-1; i--){
        printf("%d ", queueElements[i]);
        
    }
    free(Queue);

}
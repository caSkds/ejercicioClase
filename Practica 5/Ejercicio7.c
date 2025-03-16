#include <stdio.h>
#include <stdlib.h>
#include "StaticQueue.h"

void crearCola(struct cola *colaNueva){
    colaNueva->head=0;
    colaNueva->tail=-1;
    colaNueva->size=0;
    printf("Cola creada\n");
}
int encolar(struct cola *colaEncolar,int nuevoDato){
    if(colaEncolar->size==10){
        printf("Cola llena\n");
        return -1;
    }else{
        colaEncolar->tail++;
        colaEncolar->size++;
        colaEncolar->elementos[colaEncolar->tail]=nuevoDato;
        printf("Elemento agregado \n");
        return 0;
    }
}
int desencolar(struct cola *colaDesencolar){
    if(colaDesencolar->size==0){
        printf("Cola vacia\n");
        return -1;
    }else{
        printf("Elemento eliminado%d\n",colaDesencolar->elementos[colaDesencolar->head]);
        colaDesencolar->head++;
        colaDesencolar->size--;
        return 0;
    }
}

int front (struct cola *frontQueue){
    if (frontQueue -> size ==0){
        printf("Cola vacía");
        return -1;
    }
    else{
        return frontQueue ->elementos[frontQueue ->head];

    }

}
int empty (struct cola *emptyQueue){
    if (emptyQueue ->size == 0){
        printf("La cola está vacía\n");
        return 0;
    }
    else{
        printf("La cola no está vacía\n");
        return 1;
    }

}
int full (struct cola *fullQueue){
    if (fullQueue ->size != 10){
        printf("La cola no está llena\n");
        return 0;
    }
    else{
        printf("La cola está llena\n");
        return 1;
    }
    return 0;
}
int sizeC (struct cola* queueDim){
    printf("La cola tiene %d elementos\n", queueDim->size);
    return queueDim->size;
}

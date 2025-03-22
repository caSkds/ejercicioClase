#include<stdio.h>
#include <stdlib.h>
#include"StaticQueue.h"
void verCola(struct cola *);

int main()
{
    struct cola miCola,pares,impares;
    crearCola(&miCola);
    crearCola(&pares);
    crearCola(&impares);
    int valores[15];
    for(int i=1;i<16;i++)
    {
        if(i%2==0)
        {
            encolar(&pares,i);
        }
        else
        {
            encolar(&impares,i);
        }
    encolar(&miCola,i);
    }
    printf("Cola original:\n");
    verCola(&miCola);
    printf("Pares:\n");
    verCola(&pares);
    printf("Impares:\n");
    verCola(&impares);
}

void crearCola(struct cola *colaNueva){
    colaNueva->head=0;
    colaNueva->tail=-1;
    colaNueva->size=0;
    printf("Cola creada\n");
}
int encolar(struct cola *colaEncolar,int nuevoDato){
    if(colaEncolar->size==15){
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
        return 1;
    }
    else{
        printf("La cola no está vacía\n");
        return 0;
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
}
int sizeC (struct cola* queueDim){
    printf("La cola tiene %d elementos\n", queueDim->size);
    return queueDim->size;
}
void verCola(struct cola *verCola) {
    if (verCola->size == 0) {
        printf("Cola vacía\n");
        return;
    }
    
    printf("Elementos en la cola:\n");
    for (int i = 0; i < verCola->size; i++) {
        printf("%d ", verCola->elementos[verCola->head + i]);
    }
    printf("\n");
}
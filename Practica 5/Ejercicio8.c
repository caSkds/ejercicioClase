
#include <stdio.h>
#include <stdlib.h>
#include "StaticQueue.h"

int main() {
    struct cola cola1, cola2;
    int dato, i, j;

    crearCola(&cola1);
    crearCola(&cola2);

    printf("Ingrese los elementos de la primera cola:\n");
    for (i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &dato);
        encolar(&cola1, dato);
    }

    printf("Ingrese los elementos de la segunda cola:\n");
    for (i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &dato);
        encolar(&cola2, dato);
    }

    printf("Elementos repetidos entre las dos colas:\n");
    int encontrado = 0;
    for (i = 0; i < 5; i++) {
        int elemento1 = front(&cola1);
        desencolar(&cola1);
        encolar(&cola1, elemento1);
        
        for (j = 0; j < 5; j++) {
            int elemento2 = front(&cola2);
            desencolar(&cola2);
            encolar(&cola2, elemento2);
            
            if (elemento1 == elemento2) {
                printf("%d ", elemento1);
                encontrado = 1;
                break;
            }
        }
    }
    
    if (!encontrado) {
        printf("No hay elementos repetidos");
    }
    printf("\n");

    return 0;
}

void crearCola(struct cola *colaNueva) {
    colaNueva->head = 0;
    colaNueva->tail = -1;
    colaNueva->size = 0;
    printf("Cola creada\n");
}

int encolar(struct cola *colaEncolar, int nuevoDato) {
    if (colaEncolar->size == 10) {
        printf("Cola llena\n");
        return -1;
    } else {
        colaEncolar->tail++;
        colaEncolar->size++;
        colaEncolar->elementos[colaEncolar->tail] = nuevoDato;
        printf("Elemento agregado \n");
        return 0;
    }
}

int desencolar(struct cola *colaDesencolar) {
    if (colaDesencolar->size == 0) {
        printf("Cola vacia\n");
        return -1;
    } else {
        printf("Elemento eliminado%d\n", colaDesencolar->elementos[colaDesencolar->head]);
        colaDesencolar->head++;
        colaDesencolar->size--;
        return 0;
    }
}

int front(struct cola *frontQueue) {
    if (frontQueue->size == 0) {
        printf("Cola vacía");
        return -1;
    } else {
        return frontQueue->elementos[frontQueue->head];
    }
}

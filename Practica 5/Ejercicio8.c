/*8) Dadas dos colas estáticas por el usuario de longitud 5, con elementos
de tipo entero, verificar cuáles elementos son repetidos entre ambas
colas.*/

#include <stdio.h>
#include <stdlib.h>
#include "StaticQueue.h"


// Función para crear una cola
void crearCola(struct cola *colaNueva) {
    colaNueva->head = 0;
    colaNueva->tail = -1;
    colaNueva->size = 0;
}

// Función para encolar un elemento en la cola
int encolar(struct cola *colaEncolar, int nuevoDato) {
    if (colaEncolar->size == 5) {
        return -1; // La cola está llena
    } else {
        colaEncolar->tail = (colaEncolar->tail + 1) % 5;
        colaEncolar->elementos[colaEncolar->tail] = nuevoDato;
        colaEncolar->size++;
        return 0; 
    }
}

//  verifica elementos repetidos entre dos colas
void Repetidos(struct cola *cola1, struct cola *cola2) {
    int i, j;
    int elementosCola1[5], elementosCola2[5];

    // Copio los elementos de las colas 
    for (i = 0; i < 5; i++) {
        elementosCola1[i] = cola1->elementos[(cola1->head + i) % 5];
        elementosCola2[i] = cola2->elementos[(cola2->head + i) % 5];
    }

    printf("Elementos repetidos entre las dos colas:\n");
    int encontrado = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (elementosCola1[i] == elementosCola2[j]) {
                printf("%d ", elementosCola1[i]);
                encontrado = 1;
                break; 
            }
        }
    }
    if (encontrado==0) {
        printf("No hay elementos repetidos ");
    }
    printf("\n");
}
        scanf("%d", &dato);
        encolar(&cola2, dato);
    }

    Repetidos(&cola1, &cola2);

    return 0;
}

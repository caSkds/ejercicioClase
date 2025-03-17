/*8) Dadas dos colas estáticas por el usuario de longitud 5, con elementos
de tipo entero, verificar cuáles elementos son repetidos entre ambas
colas.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  


struct cola {
    int elementos[MAX];
    int head;
    int tail;
    int size;
};

void crearCola(struct cola *colaNueva) {
    colaNueva->head = 0;
    colaNueva->tail = -1;
    colaNueva->size = 0;
    printf("Cola creada\n");
}

int encolar(struct cola *colaEncolar, int nuevoDato) {
    if (colaEncolar->size == MAX) {
        printf("Cola llena\n");
        return -1;
    } else {
        colaEncolar->tail = (colaEncolar->tail + 1) % MAX;
        colaEncolar->elementos[colaEncolar->tail] = nuevoDato;
        colaEncolar->size++;
        printf("Elemento agregado: %d\n", nuevoDato);
        return 0;
    }
}

int desencolar(struct cola *colaDesencolar) {
    if (colaDesencolar->size == 0) {
        printf("Cola vacía\n");
        return -1;
    } else {
        int elemento = colaDesencolar->elementos[colaDesencolar->head];
        printf("Elemento eliminado: %d\n", elemento);
        colaDesencolar->head = (colaDesencolar->head + 1) % MAX;
        colaDesencolar->size--;
        return elemento;
    }
}

int front(struct cola *frontQueue) {
    if (frontQueue->size == 0) {
        printf("Cola vacía\n");
        return -1;
    } else {
        return frontQueue->elementos[frontQueue->head];
    }
}

int empty(struct cola *emptyQueue) {
    return (emptyQueue->size == 0) ? 1 : 0;
}

int full(struct cola *fullQueue) {
    return (fullQueue->size == MAX) ? 1 : 0;
}

// Función para obtener el tamaño de la cola
int sizeC(struct cola *queueDim) {
    return queueDim->size;
}

void verificarRepetidos(struct cola *cola1, struct cola *cola2) {
    int i, j;
    int elementosCola1[MAX], elementosCola2[MAX];

    // Copio los elementos de cola1 
    for (i = 0; i < MAX; i++) {
        elementosCola1[i] = front(cola1);
        desencolar(cola1);
    }
    
    // Copio los elementos de cola2 
    for (i = 0; i < MAX; i++) {
        elementosCola2[i] = front(cola2);
        desencolar(cola2);
    }

    printf("Elementos repetidos entre las dos colas:\n");
    int encontrado = 0;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (elementosCola1[i] == elementosCola2[j]) {
                printf("%d ", elementosCola1[i]);
                encontrado = 1;
                break;  // Evita imprimir duplicados si ya se encontró en una iteración previa
            }
        }
    }
    if (!encontrado) {
        printf("No hay elementos repetidos");
    }
    printf("\n");

    // Volver a encolar los elementos en sus respectivas colas :p
    for (i = 0; i < MAX; i++) {
        encolar(cola1, elementosCola1[i]);
    }
    for (i = 0; i < MAX; i++) {
        encolar(cola2, elementosCola2[i]);
    }
}

int main() {
    struct cola cola1, cola2;
    int dato, i;

    crearCola(&cola1);
    crearCola(&cola2);

    printf("Ingrese los elementos de la primera cola:\n");
    for (i = 0; i < MAX; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &dato);
        encolar(&cola1, dato);
    }

    printf("Ingrese los elementos de la segunda cola:\n");
    for (i = 0; i < MAX; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &dato);
        encolar(&cola2, dato);
    }

    verificarRepetidos(&cola1, &cola2);

    return 0;
}

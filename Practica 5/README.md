# Práctica 5

## Ejercicio 1: Operaciones básicas de pilas estáticas
Todas las funciones en este ejercicio han sido declaradas como prototipos de funciones en el archivo `StaticStack.h`, al igual que la estructura de pila estática, la cual, puede ser observada a continuación.

```c
struct pila{
    int elementos[10];
    int tope;
};
```
### Top/Peek
Para esto, es importante recordar que la variable `tope`nos indica el índice del último elemento agregado a la pila. Por lo tanto, si se desea acceder al último elemento se debe de acceder al elemento de índice `tope`. Dicho elemento es regresado al usuario.

En caso de que la pila se encuentre vacía (verificado con un condicional que revisa si `tope==-1`) se imprime al usuario que la pila está vacía, y se regresa un -1 para indicar que hubo un error.

```c
//Prototipo en StaticStack.h
int peek(struct pila *pilaPeek);

//Definición de la función
int peek(struct pila *pilaPeek){
    if(pilaPeek->tope==-1){
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("El tope es: %d\n",pilaPeek->elementos[pilaPeek->tope]);
        
        return pilaPeek->elementos[pilaPeek->tope];
    }
}
```
### Empty
La función `empty` revisa si no hay un solo elemento en la pila. Para esto es importante recordar que la pila es inicializada con `tope=-1`(revisar función `crearPila`en `StaticStack.h`) y sin datos. Por ende, el valor de `tope`será igual a -1 cuando esté vacía. Esto se verifica en un condicional. De estar vacía se regresa un 1, 0 si no lo está además de un mensaje correspondiente a cada caso impreso en la terminal.

> Si se ha escogido 1 y 0, es porque al trabajar con booleanos, el 1 representa verdadero y 0 falso. Este comportamiento se repetirá en más funciones del ejercicio 1 y 7.


```c
//Prototipo/firma de la función
int empty(struct pila *pilaEmpty);

// Definición de la función
int full(struct pila *pilaFull){
    if (pilaFull->tope == 9){
        printf("Pila llena\n");
        return 1;
    }
    else{
        printf("Pila no llena \n");
        return 0;
    }
}

```
### Full
La función `full` revisa nuevamente la variable tope. Si la variable vale 9, indica que el índice 9 (el último posible en `elementos`, array de la estructura `pila`) ha sido ocupado; por lo tanto solo basta con verificar si `tope==9`. En caso de valer 9, se informa al usuario imprimiendo un mensaje en la terminal y regresando un 1. De lo contrario, (y acompañado de un mensaje en la terminal) se regresa 0.

```c
//Prototipo/firma de la función
int full(struct pila *pilaFull);

//Definición de la función
int full(struct pila *pilaFull){
    if (pilaFull->tope == 9){
        printf("Pila llena\n");
        return 1;
    }
    else{
        printf("Pila no llena \n");
        return 0;
    }
}
```
### Size
La función `size`revisa la variable `tope`. Dado que tope regresa el índice del último elemento, solo basta con agregarle 1 para que nos devuelva el tamaño de nuestra pila. Para esto se crea una variable llamada `stackSize`que es igual a `tope+1`, la cual se regresa al usuario y se imprime en la terminal.

```c
//Prototipo/Firma de la función
int size(struct pila *pilaSize);

//Definición de la función
int size(struct pila *pilaSize){
    int stackSize = pilaSize->tope +1;
    printf("Tamaño de la pila: %d\n", stackSize);
        return stackSize;
    
}

```
## Ejercicio 2: Multipliar 10 valores de una pila estática por un valor proporcionado por el usuario
Todas las funciones en este ejercicio han sido declaradas como prototipos de funciones en el archivo `StaticStack.h`, al igual que la estructura de pila estática.
Las funciones usadas en este ejercicio fueron:
```c
void crearPila(struct pila *pilaNueva){
    pilaNueva->tope=-1;
    printf("Pila creada\n");
}

int pop(struct pila *pilaPop){
    if(pilaPop->tope==-1){
        printf("Pila vacia\n");
        return -1;
    }else{
        printf("Elemento eliminado %d\n",pilaPop->elementos[pilaPop->tope]);
        pilaPop->tope--;
        return 0;
    }
}

int push(struct pila *pilaPush,int nuevoDato){
    if(pilaPush->tope==10){
        printf("Pila llena\n");
        return -1;
    }else{
        pilaPush->tope++;
        pilaPush->elementos[pilaPush->tope]=nuevoDato;
    }
}
```
### Explicación de la main:
```c
struct pila pilaFI;
    int elemento,val;
    crearPila(&pilaFI);
```
- Se declara una pila de tipo struct pila llamada `pilaFI`.
- Se declaran dos variables enteras:
1. `elemento` Se usará para que el usuario ingrese por teclado los valores que desea que contenga `pilaFi`.
2. `val` Se usará para guardar el valor por el cual el usuario desea multiplicar los `elementos` de `pilaFI`.
## Ejercicio 7: Operaciones básicas de colas estáticas
Todas las funciones en este ejercicio han sido declaradas como prototipos de funciones en el archivo `StaticQueue.h`, al igual que la estructura de cola estática, la cual, puede ser observada a continuación.
```c
struct cola{
    int elementos[10];
    int head;
    int tail;
    int size;
};
```
### Front
Dado que la cola sigue el principio FIFO, el elemento al frente de la cola se considera que es el primero en ser agregado. Su índice dentro de `elementos`es seguido por la variable `head`. 

Primero se revisa si la cola está vacía. De estarlo se le informa la usuario y se regresa un -1. De tener elementos, se regresa el elemento `elementos[head]`.

```c
//Prototipo de la función:
int front (struct cola *);
// Definición de la función:
int front (struct cola *frontQueue){
    if (frontQueue -> size ==0){
        printf("Cola vacía");
        return -1;
    }
    else{
        return frontQueue ->elementos[frontQueue ->head];

    }

}
```

### Empty
Para revisar si la cola está vacía, solo se revisa la variable `size`, la cual corresponde al número de elementos en la cola. De estar vacía (`size==0`) se regrea al usuario un 1, además de un mensaje indicando que la cola está vacía. De tener al menos un elemento se informa al usuario y se regresa un 0.

```c
//Prototipo/firma de la función
int empty (struct cola *);
// Definición de la función
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

```
### Full
Para revisar si la cola está vacía, solo se revisa la variable `size`, la cual corresponde al número de elementos en la cola. De estar llena (`size==10`, pues el array de la estructura cola está definido para 10 elementos) se regrea al usuario un 1, además de un mensaje indicando que la cola está vacía. De tener al menos un elemento se informa al usuario y se regresa un 0.

```c
//Prototipo/firma de la función
int full (struct cola *);
//Definición de la función
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

```
### SizeC
Para esto solo se devuelve la variable `size`, la cual es igual al número de elementos en la cola.


```c
//Prototipo/firma de la función
int sizeC (struct cola *);
//Definición de la función
int sizeC (struct cola* queueDim){
    printf("La cola tiene %d elementos\n", queueDim->size);
    return queueDim->size;
}
```

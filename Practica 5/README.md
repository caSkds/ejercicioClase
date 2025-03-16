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
## Ejercicio 7: Operaciones básicas de colas estáticas
### Front
### Empty
### Full
### SizeC
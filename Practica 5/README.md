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
## Ejercicio 2: Multiplicar 10 valores de una pila estática por un valor proporcionado por el usuario
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
- Se declara una pila de tipo struct pila llamada `pilaFI` y se llama a la función `crearPila`.
- Se declaran dos variables enteras:
1. `elemento` Se usará para que el usuario ingrese por teclado los valores que desea que contenga `pilaFI`.
2. `val` Se usará para guardar el valor por el cual el usuario desea multiplicar los `elementos` de `pilaFI`.
```c
printf("Ingrese los 10 elementos de la pila:\n");
    for(int i=0;i<10;i++)
    {
        printf("Ingrese el elemento %i de la pila:",i+1);
        scanf("%i",&elemento);
        push(&pilaFI,elemento);
    }
    printf("Ingrese el valor por el que se van a multiplicar los valores de la pila:");
    scanf("%i",&val);
```
- Se pide al usuario ingresar los 10 elementos para `pilaFI`.
- Se entra a un ciclo `for` que se repite 10 veces para que el usuario ingrese los 10 elementos de la pila.
- Se hace uso de la función `push` para ingresar cada `elemento` ingresado por el usuario a `pilaFI`.
- Saliendo del ciclo `for` se pide al usuario ingresar el valor por el cual se van a multiplicar los valores de `pilaFI`. Siendo guardado este valor por `val`.
```c
printf("\nPila sin multiplicar:\n");
    for(int i=0;i<10;i++)
    {
        printf("%i\t",pilaFI.elementos[i]);
    }
```
- Se imprime la pila sin modificar haciendo uso de un ciclo `for` donde se imprimirán los `elementos` de `pilaFI` ingresados por el usuario anteriormente.
```c
for(int i=0;i<10;i++)
    {
        pilaFI.elementos[i]=pilaFI.elementos[i]*val;
    }
```
Ahora, mediante el uso de otro ciclo `for` se multiplica cada elemento de `pilaFI` por el valor `val` ingresado por el usuario.
```c
printf("\nPila multiplicada:\n");
    for(int i=0;i<10;i++)
    {
        printf("%i\t",pilaFI.elementos[i]);
    }
    return 0;
```
Se muestra la pila multiplicada usando un ciclo `for`, en el cual se verá `pilaFI`. 
Terminando con el programa.
## Ejercicio 5: Ordenar una pila dinámica
Todas las funciones en este ejercicio han sido declaradas como prototipos de funciones en el archivo `DynamicStack.h`, al igual que la estructura de pila dinámica.
Las funciones usadas en este ejercicio fueron:
```c
void crearPila(struct pila *nuevaPila) {
    nuevaPila->tope = NULL;
    printf("PILA CREADA\n");
}

int push(struct pila *pilaPush, int nuevoDato) {
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if (nuevoNodo == NULL) {
        printf("NO SE ASIGNÓ MEMORIA PARA EL NODO\n");
        return -1;
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = pilaPush->tope;
    pilaPush->tope = nuevoNodo;
    return 0;
}

int pop(struct pila *pilaPop) {
    if (pilaPop->tope == NULL) {
        printf("PILA VACÍA\n");
        return -1;
    }
    struct nodo *nodoAux = pilaPop->tope;
    pilaPop->tope = nodoAux->siguiente;
    free(nodoAux);
    return 0;
}

void verPila(struct pila *verPila) {
    printf("Datos de la pila:\n");
    struct nodo *verNodo = verPila->tope;
    while (verNodo != NULL) {
        printf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }
}

```
### Explicación de la main:
```c
struct pila pila1;
int dato;
```
Se declara a `pila1` de tipo `struct pila` y también se declara la variable entera `dato`; la cual guardará los datos que vaya a ingresar el usuario por teclado a `pila1`.
```c
crearPila(&pila1);
    printf("Ingrese 15 elementos para la pila dinamica:\n");
    for(int i=0;i<15;i++)
    {
        printf("Ingrese el nuevo dato:\n");
        scanf("%i",&dato);
        push(&pila1,dato);
    }
    verPila(&pila1);
```
- Se crea la pila con ayuda de la función `crearPila`; pasándole la dirección de memoria de `pila1`.
- Se pide al usuario 15 elementos para la pila dinámica creada.
- Mediante un ciclo `for` se va pidiendo al usuario cada dato.
1. Guarda el dato ingresado por el usuario en la variable `dato`.
2. Mediante la función `push`, se va guardando en `pila1` cada dato ingresado por el usuario.
- Al finalizar el ciclo for, se enseña la pila con los datos ingresados por el usuario.
```c
    struct nodo *nodoAux1;
    struct nodo *nodoAux2;
    int aux;
```
- Se crean las 2 variables de tipo `struct nodo` de tipo apuntador `nodoAux1` y `nodoAux2` respectivamente.
- Se crea también una variable entera llamada `aux` la cual nos va a ayudar a hacer este ordenamiento.
```c
for(int i=0;i<14;i++)
    {
        nodoAux1=pila1.tope;
        nodoAux2=nodoAux1->siguiente;
        for(int j=0;j<14-i;j++)
        {
            if(nodoAux1->dato>nodoAux2->dato)
            {
                aux=nodoAux1->dato;
                nodoAux1->dato=nodoAux2->dato;
                nodoAux2->dato=aux;
            }
            nodoAux1=nodoAux1->siguiente;
            nodoAux2=nodoAux2->siguiente;
        }
    }
```
### Primer for:
- El primer for inicializa a `nodoAux1` a la dirección del `tope` de `pila1` y se recorre 14 veces, permitiendo comparar hasta el ultimo elemento de la pila dinámica `pila1`.
- Ahora, `nodoAux2` apunta al nodo `siguiente` de `nodoAux1`; esto para que esté un lugar después y permitir comparar a `nodoAux1` con `nodoAux2`.
***Se inicializan en cada iteración del `for` externo para que a la hora de terminar el `for` interno, se evite el sobreescribir la misma información una y otra vez, evitando así problemas con la compilación***.
### Segundo for:
- Este segundo for también se recorre 14 veces, pero cada vez que se incrementa el contador del `for` externo, se va restando a este `for` interno para evitar comparaciones innecesarias, permitiendo la optimización y la rapidez de la comparación.
- Dentro de este `for`; se pregunta si el `dato` apuntado por el `nodoAux1` es mayor al `dato` apuntado por el `nodoAux2`; esto con la finalidad de que de ser cierto; entre a este `if` y haga lo siguiente:
  1. La variable `aux` guarda el `dato` al que apunta `nodoAux1`.
  2. Ahora, el `dato` apuntado por `nodoAux1` se vuelve el `dato` apuntado por `nodoAux2`.
  3. Ahora, el `dato` apuntado por `nodoAux2` se convierte al `aux`; con esto; lo que hacemos es recorrer cada vez que se cumpla el `if`; se vaya recorriendo un dato mayor hasta el final de `pila1`;
- Saliendo del `if`; ahora lo que se hace es que cada nodo avance una posición con:
```c
nodoAux1=nodoAux1->siguiente;
nodoAux2=nodoAux2->siguiente;
```
Esto permite ordenar poco a poco los elementos de la pila en orden ascendente.
```c
printf("Pila ordenada:\n");
verPila(&pila1);
while(pila1.tope!=NULL)
{
    pop(&pila1);
}
return 0;
```
Aquí simplemente imprimimos con ayuda de la funcion `verPila` la pila ya ordenada; se libera toda la memoria de la pila principal con el ciclo `while`, se va libernado cada nodo de `pila1` con la funcion `pop`; y así termina el programa.
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

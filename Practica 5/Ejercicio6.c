/******************************************************************************
Dada una palabra por el usuario verificar si es palíndromo empleando
pilas dinámicas.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"DynamicStack.h"

int i,j=0,aux;
int main()
{
    struct pila Pila;
    crearPila(&Pila);
    
    char palabra[30],*p;

    printf("Ingrese la palabra a revisar\n");
    scanf("%s",palabra);
    //Aunque la estrucutra posee datos de tipo entero, si almaceno un caracter 
    //este se almacenara como ASCII, el cual me permite hacer comparaciones.
    
    aux = strlen(palabra);
    for (i=0;i<aux;i++)
    {
        push(&Pila,palabra[i]);
    }
    verPila(&Pila);
    for (i=0;i<aux;i++)
    {
    if(peek(&Pila)!=palabra[i])
    {
        j+=1;
    }
    pop(&Pila);
    }
    if (j==0)
    {
        printf("Su palabra es un palindromo\n");
        return 0;
    }
    else
    {
        printf("Su palabra NO es un palindromo\n");
        return 0;
    }


    return 0;
}

void crearPila(struct pila *pilaNueva){
	pilaNueva->tope=NULL;
	printf("Pila creada\n");
}

int push(struct pila *pilaPush,int nuevoDato){
	struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
	if(nuevoNodo==NULL){
    	printf("No se pudo asignar la memoria\n");
    	return -1;
	}
	nuevoNodo->dato=nuevoDato;
	if(pilaPush->tope==NULL){
    	nuevoNodo->siguiente=NULL;
	}else{
    	nuevoNodo->siguiente=pilaPush->tope;
   	 
	}
	pilaPush->tope=nuevoNodo;
	return 0;
}

int pop(struct pila *pilaPop){ 
	if(pilaPop->tope==NULL){
    	printf("Pila vacia \n");
    	return -1;
	}
	struct nodo *nodoEliminar=pilaPop->tope;
	pilaPop->tope=nodoEliminar->siguiente;
	free(nodoEliminar);
	return 0;
}

void verPila(struct pila *verPila){
	printf("Datos en la pila\n");
	struct nodo *verNodo=verPila->tope;
	while(verNodo!=NULL){
    	printf("%d",verNodo->dato);
    	printf("\n");
    	verNodo=verNodo->siguiente;
	}
    
}

int peek(struct pila *pilaPeek) {
    if (pilaPeek->tope == NULL) {
        printf("Pila vacía\n");
        return -1;
    } else {
        printf("El tope es: %d\n", pilaPeek->tope->dato);
        return pilaPeek->tope->dato;
    }
}

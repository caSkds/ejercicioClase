#include <stdio.h>
#include <stdlib.h>
#include "ListaDobleCircular.h"


void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    nuevaLista->size=0;
}

int insertar(struct lista *insertarLista, int nuevoDato, int errorMsg){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        if(errorMsg ==1){
            printf("No se pudo asignar memoria\n");
        }
        return -1;
    }
    nuevoNodo->dato=nuevoDato;
    if(insertarLista->head==NULL){
        insertarLista->head=nuevoNodo;
        insertarLista->head->siguiente=insertarLista->head;
        insertarLista->head->anterior=insertarLista->head;
    }else{
        nuevoNodo->anterior=insertarLista->head->anterior;
        insertarLista->head->anterior->siguiente=nuevoNodo;
        insertarLista->head->anterior=nuevoNodo;
        nuevoNodo->siguiente=insertarLista->head;
        insertarLista->head=nuevoNodo;
    }
    insertarLista->size++;
    return 0;
}
int buscar(struct lista *buscarLista, int buscarDato, int errorMsg){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        if(errorMsg ==1){
            printf("No se pudo asignar memoria\n");
        }
        return -1;
    }
    int iterations =0;
    buscarNodo = buscarLista->head;
    buscarNodo-> dato = buscarDato;
    do{
        if(buscarNodo->dato==buscarDato){
        return buscarNodo->dato;
        iterations++;
    }}
    while(iterations<buscarLista->size);
    
    if(errorMsg ==1){
            printf("Elemento no encontrado\n");
        }
    return -1;
}


struct nodo * buscarNodo(struct lista *buscarLista, int buscarDato, int errorMsg){
    struct nodo *buscarNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(buscarNodo==NULL || buscarLista->head==NULL){
        if(errorMsg ==1){
            printf("Lista vacía\n");
        }
        return NULL;
    }
    int iterations =0;
    buscarNodo = buscarLista->head;
    buscarNodo-> dato = buscarDato;
    do{
        if(buscarNodo->dato==buscarDato){
        return buscarNodo;
        iterations++;
    }}
    while(iterations<buscarLista->size);
    if(errorMsg ==1){
        printf("Nodo no enontrado\n");
    }
    return NULL;
}

int sizeLista(struct lista *sizeLista){
    return sizeLista->size;
}

int vaciarLista(struct lista *vaciarLista){
    if (vaciarLista->head == NULL) {
        printf("La lista esta vacia \n");
        return -1;
    }

    struct nodo *actual = vaciarLista->head;
    struct nodo *temp;

    do {
        temp = actual->siguiente;
        free(actual);
        actual = temp;
    } while (actual != vaciarLista->head);

    vaciarLista->head = NULL;
    vaciarLista->size = 0;

    return 0;
}

/*Inserta cualquier elemento en un índice dado  */
int insertarCualquierPosicion(struct lista* inserted, int indice, int datum, int errorMsg){
    struct nodo *aux = (struct nodo*)malloc(sizeof(struct nodo));
    if (aux ==NULL){
        if(errorMsg == 1){
            printf("No se pudo asignar espacio a memoria\n");
        }
        return -1;
    }
    aux ->dato = datum;
    
    if(inserted->head ==NULL){
        inserted->head = aux;
        inserted->head ->anterior = inserted->head;
        inserted->head ->siguiente = inserted->head;
        inserted->size++;
        return 0;
    }
    struct nodo *iterator = inserted->head;
    if (indice<0){
        for(int i = 0;i< (indice*-1);i++){
            iterator = iterator->anterior;
        }
    }
    else{
        for(int i =0; i<(sizeLista(inserted)-indice-1);i++){
            iterator = iterator->siguiente;
        }
    }
    iterator ->siguiente ->anterior =aux;
    aux ->siguiente = iterator ->siguiente;
    aux->anterior = iterator;
    iterator ->siguiente = aux;
    inserted->size++;
    return 0;

}


void verLista(struct lista *viewer){
    struct nodo *view  = viewer->head;
    if(viewer->head ==NULL){
        printf("Lista vacia\n");
    }
    else{
    printf("Elementos de la lista:\n");
    
    do{
        printf("%d\n", view->dato);
        view = view->siguiente;

    }
    while(view!=viewer->head);
    }
    
}

void verListaPosiciones(struct lista *listaVer){
    if(listaVer->head==NULL){
        printf("La lista esta vacia\n");
    }else{
        struct nodo *verNodo = listaVer->head;
        int indice=listaVer->size;
        printf("Datos en la lista \n");
        do{
            printf("posicion:%d dato:%d\n",indice,verNodo->dato);
            verNodo=verNodo->siguiente;
            indice --;
        }while(verNodo!=listaVer->head);
    }
    printf("\n");
}



int borrar(struct lista *borrarLista,int datoBorrar){
    if(borrarLista->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    struct nodo *nodoEliminar=borrarLista->head;
    do{
        if(nodoEliminar->dato==datoBorrar){
            if(nodoEliminar == borrarLista->head){
                if(nodoEliminar->siguiente == nodoEliminar){
                    borrarLista->head=NULL;
                }else{
                    struct nodo *nodoTem = borrarLista->head;
                    while(nodoTem->siguiente!=borrarLista->head){
                        nodoTem=nodoTem->siguiente;
                    }
                    borrarLista->head=nodoEliminar->siguiente;
                    nodoTem->siguiente=borrarLista->head;
                    nodoEliminar->siguiente->anterior=nodoTem;
                }
            }else{
                nodoEliminar->anterior->siguiente=nodoEliminar->siguiente;
                nodoEliminar->siguiente->anterior=nodoEliminar->anterior;
            }
            free(nodoEliminar);
            borrarLista->size--;
            return 0;
        }
        nodoEliminar=nodoEliminar->siguiente;
    }while(nodoEliminar!=borrarLista->head);
    return 0;
}

int borrarIndice(struct lista *listaBorrar, int indiceBorrar) {
    if (listaBorrar->head == NULL) {
        printf("Lista vacia\n");
        return -1;
    }
    int tamano = listaBorrar->size;
    if (indiceBorrar < 0) { //ajustar indice a positivo
        indiceBorrar = tamano + indiceBorrar;  // desde final
    }
    indiceBorrar = (indiceBorrar % tamano + tamano) % tamano; //ajustar para que indice sea "valido"
    struct nodo *actual = listaBorrar->head;
    int contador = 0;
    while (contador < indiceBorrar) {
        actual = actual->siguiente;
        contador++;
    }
    struct nodo *nodoEliminar = actual;
    if (nodoEliminar == listaBorrar->head) {    // Si el nodo a borrar es el head
        listaBorrar->head = nodoEliminar->siguiente;
    }
    nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
    nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
    if (nodoEliminar->siguiente == nodoEliminar) {   // Si solo habia un nodo
        listaBorrar->head = NULL;
    }
    free(nodoEliminar);
    listaBorrar->size--; 
    return 0;
}

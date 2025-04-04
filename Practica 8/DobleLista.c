//Lista Doble 
//Lista Doble 
#include "listaDoble.h"


void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    nuevaLista->size=-1;
    printf("Lista creada\n");
}
/*
int insertar(struct lista *insertarLista,int nuevoDato){
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        printf("No se asigno memoria\n");
        return -1;
    }
    //Si si se creo el nodo 
    nuevoNodo->dato=nuevoDato;
    //Vamos a verificar si es el primer elemento
    if(insertarLista->head == NULL){
        //Si es el primer elemento
        nuevoNodo->siguiente=insertarLista->head;
        nuevoNodo->anterior=NULL;
        insertarLista->head = nuevoNodo;
    }else{
        nuevoNodo->siguiente=insertarLista->head;
        nuevoNodo->anterior=NULL;
        insertarLista->head->anterior=nuevoNodo;
        insertarLista->head=nuevoNodo;
    }
    insertarLista->size++;
    return 0;
}
*/
int insertar(struct lista *insertarLista,int nuevoDato){
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        printf("No se asigno memoria\n");
        return -1;
    }
    //Si si se creo el nodo 
    nuevoNodo->dato=nuevoDato;
    //Vamos a verificar si es el primer elemento
    nuevoNodo->siguiente=insertarLista->head;
    if(insertarLista->head != NULL){
        insertarLista->head->anterior=nuevoNodo;
    }
    insertarLista->head = nuevoNodo;
    nuevoNodo->anterior=NULL;
    insertarLista->size++;
    return 0;
}

int buscar(struct lista *buscarLista,int datoBuscar){
    if(buscarLista->head==NULL){
        printf("La lista esta vacia\n");
        return -1;
    }
    struct nodo *nodoAux=buscarLista->head;
    while(nodoAux!=NULL){
        if(nodoAux->dato==datoBuscar){
            printf("Dato Encontrado\n");
            return nodoAux->dato;
        }
        nodoAux=nodoAux->siguiente;
    }
    printf("Dato no encontrado\n");
    return -1;
}

int borrar(struct lista *listaBorrar,int datoBorrar){
    if(listaBorrar->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    
    struct nodo *nodoEliminar = listaBorrar->head;
    //vamos a realizar la busqueda del elemento
    while(nodoEliminar!=NULL && nodoEliminar->dato!=datoBorrar){
        nodoEliminar=nodoEliminar->siguiente;
    }
    //si es nulo
    if(nodoEliminar==NULL){
        printf("Dato no encontrado\n");
        return -1;
    }
    
    //si si se encuentra el dato
    if(nodoEliminar->siguiente==NULL && nodoEliminar->anterior==NULL){
        //si es el unico nodo en la lista
        listaBorrar->head=NULL;
    }else if(nodoEliminar->siguiente==NULL){
        nodoEliminar->anterior->siguiente=NULL;
    }else if(nodoEliminar==listaBorrar->head){
        listaBorrar->head=nodoEliminar->siguiente;
        listaBorrar->head->anterior=NULL;
    }else{
        nodoEliminar->anterior->siguiente=nodoEliminar->siguiente;
        nodoEliminar->siguiente->anterior=nodoEliminar->anterior;
    }
    listaBorrar->size--;
    free(nodoEliminar);
    return 0;
}

void verLista(struct lista *listaVer){
    if(listaVer->head==NULL){
        printf("La lista esta vacia\n");
    }else{
        struct nodo *verNodo = listaVer->head;
        printf("Datos en la lista \n");
        while(verNodo!=NULL){
            printf("%d\n",verNodo->dato);
            verNodo=verNodo->siguiente;
        }
    }
    printf("\n");
}

void verListaPosiciones(struct lista *listaVer){
    if(listaVer->head==NULL){
        printf("La lista esta vacia\n");
    }else{
        struct nodo *verNodo = listaVer->head;
        int indice=listaVer->size;
        printf("Datos en la lista \n");
        while(verNodo!=NULL){
            printf("posicion:%d dato:%d\n",indice,verNodo->dato);
            verNodo=verNodo->siguiente;
            indice --;
        }
    }
    printf("\n");
}

struct nodo * buscarNodo(struct lista *buscarLista,int datoBuscar){
    if(buscarLista->head==NULL){
        printf("La lista esta vacia\n");
        return NULL;
    }
    struct nodo *nodoAux=buscarLista->head;
    while(nodoAux!=NULL){
        if(nodoAux->dato==datoBuscar){
            printf("Dato Encontrado\n");
            return nodoAux;
        }
        nodoAux=nodoAux->siguiente;
    }
    printf("Dato no encontrado\n");
    return NULL;
}

int borrarIndice(struct lista *listaBorrar,int indiceBorrar){
    if(listaBorrar->head==NULL){
        printf("Lista vacia\n");
        return -1;
    }
    
    if(indiceBorrar > listaBorrar->size || indiceBorrar < 0 ){
        printf("Indice no valido\n");
        return -1;
    }
    
    struct nodo *nodoEliminar = listaBorrar->head;
    int indiceAux=listaBorrar->size;
    //vamos a realizar la busqueda del elemento
           //1             //1
    while(indiceAux!=indiceBorrar){
        nodoEliminar=nodoEliminar->siguiente;
        indiceAux--;
    }
    //si es nulo
    if(nodoEliminar==NULL){
        printf("Dato no encontrado\n");
        return -1;
    }
    
    //si si se encuentra el dato
    if(nodoEliminar->siguiente==NULL && nodoEliminar->anterior==NULL){
        //si es el unico nodo en la lista
        listaBorrar->head=NULL;
    }else if(nodoEliminar->siguiente==NULL){
        nodoEliminar->anterior->siguiente=NULL;
    }else if(nodoEliminar==listaBorrar->head){
        listaBorrar->head=nodoEliminar->siguiente;
        listaBorrar->head->anterior=NULL;
    }else{
        nodoEliminar->anterior->siguiente=nodoEliminar->siguiente;
        nodoEliminar->siguiente->anterior=nodoEliminar->anterior;
    }
    listaBorrar->size--;
    free(nodoEliminar);
    return 0;
}

int sizeLista(struct lista *listaSize){
    return listaSize->size;
}  


int insertarCualquierInidice(struct lista* listaInsertar, int dato){

}
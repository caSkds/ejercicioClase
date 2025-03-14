#include <stdio.h>
#include <stdlib.h>

void ingresar();
void suma();
void punto();
void modificar();

int i,j,r,contador,x;

struct vectores
{
    int *vec;
}v[2];

int main()
{
    int op;
    do{
    printf("\n\nMenu vectores\n");
    printf("1) Ingresar vectores\n");
    printf("2) Suma de vectores\n");
    printf("3) Producto punto Vectores\n");
    printf("4) Modificar algun vector\n");
    printf("5) Salir\n");
    scanf("%d",&op);
    switch(op)
    {
            case 1:
                ingresar();
                break;
            case 2:
                suma();
                break;
            case 3:
                punto();
               break;
            case 4:
               modificar();
               break;
            case 5:
               printf  ("Saliendo...");
               break;
            default:
                printf("Opcion invalida\n");
            
        
    }
    }while(op != 5);
    free(v[0].vec);
    free(v[1].vec);
    return 0;
}

void ingresar()
{
    contador=1;
    printf("Ingrese la dimension de sus vectores:\t");
    scanf("%d",&x);
    v[0].vec=(int *)malloc(x * sizeof(int));
    v[1].vec=(int *)malloc(x * sizeof(int));
    if(v[0].vec!=NULL)
    {
        for(j=0;j<2;j++)
        {
            printf("\nVector %d\n",j+1);
            for(i=0;i<x;i++)
            {
                printf("valor %d:\t",i+1);
                scanf("%d",&v[j].vec[i]);
            }
        }
    }
    else
    {
        printf("Error, no se creo el vector\n");
    }
}

void suma()
{
    if(contador!=0)
    {
        printf("\nVector resultante:\n");
        for(i=0;i<x;i++)
        {
            printf("valor %d:\t%d\n",i+1,v[0].vec[i]+v[1].vec[i]);
        }
    }
    else
    {
        printf("Ingrese primero los vectores\n");
    }
}

void punto()
{
    int sumatoria=0;
    
    if(contador!=0)
    {
        printf("\nProducto punto:\t");
        for(i=0;i<x;i++)
        {
            sumatoria+=v[0].vec[i]*v[1].vec[i];
        }
        printf("%d\n",sumatoria);
    }
    else
    {
        printf("Ingrese primero los vectores\n");
    }
}

void modificar()
{
    int mod,val;
    printf("Que vector desea modificar?");
    for(j=0;j<2;j++)
        {
            printf("\n\nVector %d\n",j+1);
            for(i=0;i<x;i++)
            {
                printf("valor %d:\t%d\n",i+1,v[j].vec[i]);
            }
        }
    scanf("%d",&mod);
    printf("Que valor desea modificar?:\t");
    scanf("%d",&val);
    printf("Ingrese el nuevo valor:\t");
    scanf("%d",&v[mod-1].vec[val-1]);
    printf("Valor modificado correctamente\n");
    for(j=0;j<2;j++)
        {
            printf("\n\nVector %d\n",j+1);
            for(i=0;i<x;i++)
            {
                printf("valor %d:\t%d\n",i+1,v[j].vec[i]);
            }
        }
    
}

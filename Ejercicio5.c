#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();

void main(){
    int opcion = menu();
    char command[50];
    while (opcion!=5){
        switch(opcion){
            case 1:
                strcpy(command,"gcc Ejercicio1.c && ./a.out");
                system(command);

                break;
            case 2:
            strcpy(command,"gcc Ejercicio2_eda1_practica4.c && ./a.out");
            system(command);
                
                break;
            case 3:
            strcpy(command,"gcc Ejercicio3.c && ./a.out");
            system(command);
                
                break;
            case 4:
            strcpy(command,"gcc Ejercicio4.c && ./a.out");
            system(command);
              
                break;
            case 5:
                break;
            default:
                printf("Escriba una opción válida \n");
        }
        opcion =menu();
    

}
}

int menu(){

        int option;
        printf("\nElija una opción:\n");
        printf("Ejercicio 1: \n");
        printf("Ejercicio 2: \n");
        printf("Ejercicio 3: \n");
        printf("Ejercicio 4: \n");
        printf("5)Salir\n");
        scanf("%d",&option);
        return option;
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct amznUser{
    char name[20];
    char surname[20];
    char surname2[20];
    int age;
    int usrID;

}*user;
int nUsers = 0;

user addUser(int modUser);
void viewUser(char name[20], char surname[20], char surname2[20], int age, int usrid);
int modUser();
int menu();

void main()
{
    user *userList;
    user *reserve;
    userList = (user*)malloc(1*sizeof(user));
    int i = 0;
    int id;
    int opcion = menu();
    while (opcion!=5){
        switch(opcion){
            case 1:
                userList = realloc(userList,(nUsers+1) * sizeof(user));
                userList[nUsers] = addUser(-1);
                nUsers++;



                break;
            case 2:
                if (nUsers!=0){
                i=0;
                do{viewUser(userList[i]->name,userList[i]->surname,userList[i]->surname2,userList[i]->age,userList[i]->usrID);
                i++;
                }
                while(i<nUsers);
                i=0;
                }else{
                    printf("no hay usuarios registrados\n");
                }
                
                
                break;
            case 3:
                
                if (nUsers!=0){
                i=0;
                do{viewUser(userList[i]->name,userList[i]->surname,userList[i]->surname2,userList[i]->age,userList[i]->usrID);
                    i++;
                }
                while(i<nUsers);
                i=0;
                printf("Seleccione el ID a modificar:\n");
                id = modUser();
                userList[id-1] = addUser(id);
                }
                else{
                    printf("no hay usuarios registrados\n");
                }
                break;
            case 4:
                if (nUsers != 0 ){
                    printf("Seleccione el ID a eliminar:");
                    i=0;
                    do{viewUser(userList[i]->name,userList[i]->surname,userList[i]->surname2,userList[i]->age,userList[i]->usrID);
                        i++;
                    }
                    while(i<nUsers);
                    i=0;
                    id = modUser();
                    if (nUsers == 1){
                        nUsers = 0;
                        //printf("nUsers%d\n", nUsers);
                    }
                    else {
                        
                        if (id!=nUsers){

                            for( int i =id; i<nUsers; i++){
                                reserve = userList[i-1];

                                userList[i-1] = userList[i];

                                userList[i] = reserve;  

                            }
                        }
                        nUsers--;
                        if (nUsers!=0){
                            for(int i =0;i<nUsers; i++){
                                userList[i]->usrID = i+1;
                            }
                        }
                    


                    }
                }else{
                    printf("no hay usuarios registrados\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Escriba una opción válida \n");
        }
        opcion =menu();
    }  
    free(userList);
}


int menu(){
    int option;
    printf("\nElija una opción:\n");
    printf("1)Agregar usuarios\n");
    printf("2)Ver usuarios\n");
    printf("3)Modificar usuario\n");
    printf("4)Borrar usuario\n");
    printf("5)Salir\n");
    scanf("%d",&option);
    return option;
}


user addUser(int modUser){
    char newName[20];
    char newSurname[20];
    char newSurname2[20];
    int newAge;
    int newUsrID;
    printf("Ingrese el nombre: ");
    scanf("%s",&newName);
    printf("Ingrese el apellido paterno: ");
    scanf("%s",&newSurname);
    printf("Ingrese el apellido materno: ");
    scanf("%s",&newSurname2);
    printf("Ingrese la edad ");
    scanf("%d",&newAge);
    if (modUser==-1){
        newUsrID=nUsers+1;
    }
    else{
        newUsrID = modUser;
    }
    user newUser = malloc(sizeof(struct amznUser));
    strcpy(newUser->name, newName);
    strcpy(newUser->surname, newSurname);
    strcpy(newUser->surname2, newSurname2);
    newUser->age = newAge;
    newUser->usrID = newUsrID;
   // {newName,newSurname,newSurname2,newAge,newUsrID};

    return newUser;
}

void viewUser(char name[20], char surname[20], char surname2[20], int age, int usrid){


    if(nUsers==0){
        printf("\nNo hay nuevos usuarios :C");
    }
    else{

            printf("\nNombre de contacto: %s\n", name);
            printf("Apellido paterno de contacto: %s\n", surname);
            printf("Apellido materno de contacto: %s\n",surname2);
            printf("Edad de contacto: %d\n", age);
            printf("ID de contacto: %d\n",usrid);
        
    }
}



int modUser(){
    int id;
    if (nUsers ==0){
        printf("No hay usuarios registrados \n");
    }
    else{
        do{
            scanf("%d", &id);
            if (id <0 || id>nUsers){
                printf("Favor de introducir un ID válido\n");
            }
        }while(id <0 || id>nUsers);

    }   
    return id;
}
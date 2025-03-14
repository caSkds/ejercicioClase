/*2) La Facultad de Ingenier�a necesita un programa para sacar el promedio
de 3 ex�menes parciales de N alumnos de la materia de Estructura de
datos y Algoritmos I.
Aparecer� primero el siguiente men�:
1)Ingresar el n�mero de alumnos
2)salir
Ingresar el n�mero de alumnos:
Se ingresar�n a cuantos alumnos se le pedir�n sus calificaciones.
Despu�s de haber ingresado cuantos alumnos, se implementar� el
siguiente submen�:
Men� Calificaciones
a) Ingresar Calificaciones
b) Calcular promedio
c) Alumnos Exentos
d) Modificar Calificaciones
e) Salir
Ingresar calificaciones:
Se ingresar�n las calificaciones de cada alumno, recordar que las
calificaciones solo pueden ser de 0-10, si se ingresa otro valor diferente a
este, se mandar� el mensaje: �Calificaci�n no v�lida�.
Calcular promedio:
Calculara el promedio de los alumnos. Si no hay calificaciones(no se ha
ingresado a la opci�n a) mostrar� el mensaje �Ingrese primero a la opci�n
a C:�
Alumnos Exentos:
Mostrar� a los alumnos exentos de la materia, recordar que la materia se
exenta con 6.Si no hay calificaciones(no se ha ingresado a la opci�n a)
mostrar� el mensaje �Ingrese primero a la opci�n a C:�
Modificar Calificaciones:
Se escoger� a un alumno que desee modificar alguno de sus ex�menes, se
mostrar� el antes y despu�s de la modificaci�n. Si no hay calificaciones(no
se ha ingresado a la opci�n a) mostrar� el mensaje �Ingrese primero a la
opci�n a C:�*/
#include <stdio.h>
#include <stdlib.h>

struct calificaciones
{
    float calificacionexamen1;
    float calificacionexamen2;
    float calificacionexamen3;
    float promedio;
};

void ingresarCalificaciones(struct calificaciones *,int);
void calcularPromedio(struct calificaciones *,int);
void alumnosExentos(struct calificaciones *,int);
void modificarCalificacion(struct calificaciones *,int);
int main()
{
    struct calificaciones *alumnos;
    int numAlumnos,ban=0;
    int opcionEx;
    char opcionInt;
    do
    {
        printf("\tMenu calificaciones\n");
        printf("1)Ingresar el numero de alumnos\n");
        printf("2)Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%i",&opcionEx);
        switch(opcionEx)
        {
        case 1:
            printf("Ingrese el numero de alumnos a evaluar:\n");
            scanf("%i",&numAlumnos);
            alumnos=malloc(numAlumnos*sizeof(struct calificaciones));
            do
            {
            printf("\n\n\tMenu calificaciones\n\n");
            printf("a)Ingresar calificaciones\n");
            printf("b)Calcular promedio\n");
            printf("c)Alumnos exentos\n");
            printf("d)Modificar calificaciones\n");
            printf("e)Salir\n");
            printf("Ingrese una opcion:\n");
            scanf(" %c",&opcionInt);
            switch(opcionInt)
            {
            case 'a':
                ingresarCalificaciones(alumnos,numAlumnos);
                ban=1;
                break;
            case 'b':
                if(ban==1)
                {
                    calcularPromedio(alumnos,numAlumnos);
                }
                else
                {
                    printf("Ingrese primero a la opción a C:");
                }
                break;
            case 'c':
                if(ban==1)
                {
                    alumnosExentos(alumnos,numAlumnos);
                }
                else
                {
                    printf("Ingrese primero a la opción a C:");
                }
                break;
            case 'd':
                if(ban==1)
                {
                    modificarCalificacion(alumnos,numAlumnos);
                }
                else
                {
                    printf("Ingrese primero a la opción a C:");
                }
                break;
            case 'e':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
            }
            }while(opcionInt!='e');
            break;
        case 2:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida\n");
        }

    }while(opcionEx!=2);
    free(alumnos);
    return 0;
}

void ingresarCalificaciones(struct calificaciones *alumnos,int maximo)
{
    for(int i=0; i<maximo; i++)
    {
        printf("Ingrese la calificacion del examen 1 del alumno %i:",i+1);
        do
        {
        scanf("%f",&alumnos[i].calificacionexamen1);
        if(alumnos[i].calificacionexamen1>=0&&alumnos[i].calificacionexamen1<=10)
        {
            printf("Calificacion agregada satisfactoriamente\n");
        }
        else
        {
            printf("Calificacion no valida, ingrese otra en el rango de 0 a 10:\n");
        }
        }while(alumnos[i].calificacionexamen1<0||alumnos[i].calificacionexamen1>10);
        printf("Ingrese la calificacion del examen 2 del alumno %i:",i+1);
        do
        {
        scanf("%f",&alumnos[i].calificacionexamen2);
        if(alumnos[i].calificacionexamen2>=0&&alumnos[i].calificacionexamen2<=10)
        {
            printf("Calificacion agregada satisfactoriamente\n");
        }
        else
        {
            printf("Calificacion no valida, ingrese otra en el rango de 0 a 10:\n");
        }
        }while(alumnos[i].calificacionexamen2<0||alumnos[i].calificacionexamen2>10);
        printf("Ingrese la calificacion del examen 3 del alumno %i:",i+1);
        do
        {
        scanf("%f",&alumnos[i].calificacionexamen3);
        if(alumnos[i].calificacionexamen3>=0&&alumnos[i].calificacionexamen3<=10)
        {
            printf("Calificacion agregada satisfactoriamente\n");
        }
        else
        {
            printf("Calificacion no valida, ingrese otra en el rango de 0 a 10:\n");
        }
        }while(alumnos[i].calificacionexamen3<0||alumnos[i].calificacionexamen3>10);
    }
    for(int i=0;i<maximo;i++)
    {
        alumnos[i].promedio=(alumnos[i].calificacionexamen1+alumnos[i].calificacionexamen2+alumnos[i].calificacionexamen3)/3;
    }
}

void calcularPromedio(struct calificaciones *alumnos,int maximo)
{
    for(int i=0;i<maximo;i++)
    {
        printf("El promedio del alumno %i es: %.2f\n",i+1,alumnos[i].promedio);
    }
}

void alumnosExentos(struct calificaciones *alumnos,int maximo)
{
    for(int i=0;i<maximo;i++)
    {
        if(alumnos[i].promedio>=6)
        {
            printf("El alumno %i esta excento\n",i+1);
        }
    }
}

void modificarCalificacion(struct calificaciones*alumnos,int maximo)
{
    int seleccionado;
    int seleccionado2;
    float valAntes;
    do
    {
        printf("Ingrese al alumno que desea cambiar su calificacion:, considere que hay %i alumnos\n",maximo);
        scanf("%i",&seleccionado);
        if(seleccionado>0&&seleccionado<=maximo)
        {
            printf("Ingrese que calificacion desea cambiar del alumno seleccionado (1,2 o 3):\n");
            printf("Considere que el alumno seleccionado tiene:\n");
            printf("Examen 1:%.2f\n",alumnos[seleccionado-1].calificacionexamen1);
            printf("Examen 2:%.2f\n",alumnos[seleccionado-1].calificacionexamen2);
            printf("Examen 3:%.2f\n",alumnos[seleccionado-1].calificacionexamen3);
            scanf("%i",&seleccionado2);
            do
            {
                if(seleccionado2==1)
                {
                    do
                    {
                        printf("Ingrese la nueva calificacion del examen 1:\n");
                        valAntes=alumnos[seleccionado-1].calificacionexamen1;
                        scanf("%f",&alumnos[seleccionado-1].calificacionexamen1);
                        if(alumnos[seleccionado-1].calificacionexamen1>=0&&alumnos[seleccionado-1].calificacionexamen1<=10)
                        {
                            printf("Calificacion agregada satisfactoriamente\n");
                            printf("Calificacion anterior: %.2f\n",valAntes);
                            printf("Calificacion nueva agregada: %.2f\n",alumnos[seleccionado-1].calificacionexamen1);
                        }
                        else
                        {
                            printf("Calificacion no valida\n");
                        }
                    }while(alumnos[seleccionado-1].calificacionexamen1<0||alumnos[seleccionado-1].calificacionexamen1>10);
                }
                else
                {
                    if(seleccionado2==2)
                    {
                        do
                        {
                        printf("Ingrese la nueva calificacion del examen 2:\n");
                        valAntes=alumnos[seleccionado-1].calificacionexamen2;
                        scanf("%f",&alumnos[seleccionado-1].calificacionexamen2);
                        if(alumnos[seleccionado-1].calificacionexamen2>=0&&alumnos[seleccionado-1].calificacionexamen2<=10)
                        {
                            printf("Calificacion agregada satisfactoriamente\n");
                            printf("Calificacion anterior: %.2f\n",valAntes);
                            printf("Calificacion nueva agregada: %.2f\n",alumnos[seleccionado-1].calificacionexamen2);
                        }
                        else
                        {
                            printf("Calificacion no valida\n");
                        }
                        }while(alumnos[seleccionado-1].calificacionexamen2<0||alumnos[seleccionado-1].calificacionexamen2>10);
                    }
                    else
                    {
                        if(seleccionado2==3)
                        {
                            do
                            {
                            printf("Ingrese la nueva calificacion del examen 3:\n");
                            valAntes=alumnos[seleccionado-1].calificacionexamen3;
                            scanf("%f",&alumnos[seleccionado-1].calificacionexamen3);
                            if(alumnos[seleccionado-1].calificacionexamen3>=0&&alumnos[seleccionado-1].calificacionexamen3<=10)
                            {
                            printf("Calificacion agregada satisfactoriamente\n");
                            printf("Calificacion anterior: %.2f\n",valAntes);
                            printf("Calificacion nueva agregada: %.2f\n",alumnos[seleccionado-1].calificacionexamen3);
                            }
                            else
                            {
                            printf("Calificacion no valida\n");
                            }
                            }while(alumnos[seleccionado-1].calificacionexamen3<0||alumnos[seleccionado-1].calificacionexamen3>10);
                        }
                        else
                        {
                            printf("Opcion fuera de rango\n");
                        }
                    }
                }
            }while(seleccionado2<1||seleccionado2>3);
        }
        else
        {
            printf("Opcion fuera de rango, considere que hay %i alumnos",maximo);
        }
    }while(seleccionado<=0||seleccionado>maximo);

    for(int i=0;i<maximo;i++)
    {
        alumnos[i].promedio=(alumnos[i].calificacionexamen1+alumnos[i].calificacionexamen2+alumnos[i].calificacionexamen3)/3;
    }
}

#include <stdio.h>
#include <stdlib.h>

int** sumarMatrices(int** matriz1, int** matriz2, int filas, int columnas);
int** restarMatrices(int** matriz1, int** matriz2, int filas, int columnas);
int** transponerMatriz(int** matriz, int filas, int columnas);
int** multiplicarMatrices(int** matriz1, int** matriz2, int filas1, int columnas1, int columnas2);
void liberarMemoria(int** matriz, int filas);

int main() {
    int filas1, columnas1, filas2, columnas2;
    int opcion;
    int aux = 0; //para poder salir de los diferentes switch 

    printf("Ingrese las FILAS de la PRIMER matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese las COLUMNAS de la PRIMER matriz: ");
    scanf("%d", &columnas1);
    
    int** matriz1 = (int*)malloc(filas1 * sizeof(int)); //aparto memoria para la primera mattriz
    for (int i = 0; i < filas1; i++) {
        matriz1[i] = (int*)malloc(columnas1 * sizeof(int));
    }

    printf("Ingrese los datos de la primera matriz:\n");
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas1; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Ingrese las FILAS de la SEGUNDA matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese las COLUMNAS de la SEGUNDA matriz: ");
    scanf("%d", &columnas2);
    
    int** matriz2 = (int*)malloc(filas2 * sizeof(int));//aparto memoria para la segndfa matriz
    for (int i = 0; i < filas2; i++) {
        matriz2[i] = (int*)malloc(columnas2 * sizeof(int));
    }
    
    printf("Ingrese los datos de la segunda matriz:\n");
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    do {
        // Caso en el que ambas matrrices son cuadradas y de igual dimensión
        if ((filas1 == columnas1) && (filas2 == columnas2) && (filas1 == filas2)) {
            printf("Menu Matrices %d x %d:  \n", filas1, filas1);
            printf(" 1) Suma de Matrices \n 2) Resta de Matrices \n 3) Transpuesta de Matrices \n 4) Salir \n");
            printf("Seleccione una opcion: \n");
            scanf("%d", &opcion);

            switch(opcion) {
                case 1: {
                    int** suma = sumarMatrices(matriz1, matriz2, filas1, columnas1);
                    printf("Suma de las matrices: \n");
                    for (int i = 0; i < filas1; i++) {
                        for (int j = 0; j < columnas1; j++) {
                            printf("( %d ) \t", suma[i][j]);
                        }
                        printf("\n");
                    }
                    liberarMemoria(suma, filas1);
                    break;
                }
                case 2: {
                    int** resta = restarMatrices(matriz1, matriz2, filas1, columnas1);
                    printf("Resta de las matrices: \n");
                    for (int i = 0; i < filas1; i++) {
                        for (int j = 0; j < columnas1; j++) {
                            printf("( %d )\t", resta[i][j]);
                        }
                        printf("\n");
                    }
                    liberarMemoria(resta, filas1);
                    break;
                }
                case 3: {
                    int** trans1 = transponerMatriz(matriz1, filas1, columnas1);
                    int** trans2 = transponerMatriz(matriz2, filas2, columnas2);
                    printf("Transpuesta de la primera matriz: \n");
                    for (int i = 0; i < columnas1; i++) {
                        for (int j = 0; j < filas1; j++) {
                            printf("( %d )\t", trans1[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Transpuesta de la segunda matriz: \n");
                    for (int i = 0; i < columnas2; i++) {
                        for (int j = 0; j < filas2; j++) {
                            printf("( %d )\t", trans2[i][j]);
                        }
                        printf("\n");
                    }
                    liberarMemoria(trans1, columnas1);
                    liberarMemoria(trans2, columnas2);
                    break;
                }
                case 4:
                    printf("Saliendo del sistema... VUELVA PRONTO ;D \n");
                    aux=1;
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
            }
        }
        // Caso en el que las matrices tienen sus  dimensiones diferentes pero se puede realizar la multiplicación
        else if (columnas1 == filas2) {
            printf(" Tus matrices no pueden ser realizadas en todas las operaciones :(\n Menu Matrices %d x %d:\n", filas1, columnas2);
            printf("1) Multiplicacion de Matrices\n2) Salir\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);

            switch(opcion) {
                case 1: {
                    int** producto = multiplicarMatrices(matriz1, matriz2, filas1, columnas1, columnas2);
                    printf("Multiplicacion de las matrices: \n");
                    for (int i = 0; i < filas1; i++) {
                        for (int j = 0; j < columnas2; j++) {
                            printf("( %d )\t", producto[i][j]);
                        }
                        printf("\n");
                    }
                    liberarMemoria(producto, filas1);
                    break;
                }
                case 2:
                      printf("Saliendo del sistema... VUELVA PRONTO ;D \n");
                      aux=1;
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
            }
        }
        // Caso en que las matrices tienen dimensiones diferentes y NO se puede multiplicar pero se pueden trnasponer :D
        else {
            printf(" Tus matrices no pueden ser realizadas en todas las operaciones :(\n Menu Matrices %d x %d:\n", filas2, columnas1);
            printf("1) Transpuesta de Matrices\n2) Salir\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);

            switch(opcion) {
                case 1: {
                    int** trans1 = transponerMatriz(matriz1, filas1, columnas1);
                    int** trans2 = transponerMatriz(matriz2, filas2, columnas2);
                    printf("Transpuesta de la primera matriz: \n");
                    for (int i = 0; i < columnas1; i++) {
                        for (int j = 0; j < filas1; j++) {
                            printf("( %d )\t", trans1[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Transpuesta de la segunda matriz: \n");
                    for (int i = 0; i < columnas2; i++) {
                        for (int j = 0; j < filas2; j++) {
                            printf("( %d )\t", trans2[i][j]);
                        }
                        printf("\n");
                    }
                    liberarMemoria(trans1, columnas1);
                    liberarMemoria(trans2, columnas2);
                    break;
                }
                case 2:
                    printf("Saliendo del sistema... VUELVA PRONTO ;D \n");
                    aux=1;
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
            }
        }
    } while (!aux);
    
    
    liberarMemoria(matriz1, filas1);//libero las matricres originales
    liberarMemoria(matriz2, filas2);
    
    return 0;
}

int** sumarMatrices(int** matriz1, int** matriz2, int filas, int columnas) {
    int** resultado = (int*)malloc(filas * sizeof(int));
    for (int i = 0; i < filas; i++) {
        resultado[i] = (int*)malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return resultado;
}

int** restarMatrices(int** matriz1, int** matriz2, int filas, int columnas) {
    int** resultado = (int*)malloc(filas * sizeof(int));
    for (int i = 0; i < filas; i++) {
        resultado[i] = (int*)malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    return resultado;
}

int** transponerMatriz(int** matriz, int filas, int columnas) {
    int** transpuesta = (int*)malloc(columnas * sizeof(int));
    for (int i = 0; i < columnas; i++) {
        transpuesta[i] = (int*)malloc(filas * sizeof(int));
        for (int j = 0; j < filas; j++) {
            transpuesta[i][j] = matriz[j][i];
        }
    }
    return transpuesta;
}

int** multiplicarMatrices(int** matriz1, int** matriz2, int filas1, int columnas1, int columnas2) {
    int** resultado = (int*)malloc(filas1 * sizeof(int));
    for (int i = 0; i < filas1; i++) {
        resultado[i] = (int*)malloc(columnas2 * sizeof(int));
        for (int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas1; k++) {
                resultado[i][j] = resultado [i][j] + matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return resultado;
}

void liberarMemoria(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
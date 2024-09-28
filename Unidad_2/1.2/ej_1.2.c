/*
Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector.
*/
#include <stdio.h>
#define FILAS 5
#define COLUMNAS 4

void Mostrar(int[][COLUMNAS], int, int);
void Carga(int[][COLUMNAS], int, int);
void SumaFilas(int[][COLUMNAS], int, int);
void SumaColumnas(int[][COLUMNAS], int, int);

int main(){
    int mainMatriz[FILAS][COLUMNAS];

    Carga(mainMatriz, FILAS, COLUMNAS);

    Mostrar(mainMatriz, FILAS, COLUMNAS);   
    printf("\n");
    SumaFilas(mainMatriz, FILAS, COLUMNAS);
    printf("\n");
    SumaColumnas(mainMatriz, FILAS, COLUMNAS);

    return 0;
}

void Carga(int mainMatriz[][COLUMNAS], int filas, int columnas){
    int i, j;

   for(i = 0 ; i < filas ; i++){
        for(j = 0 ; j < columnas ; j++){
            printf("Ingrese el dato en la posicion (filas: %d, columna: %d): ", i+1, j+1);
            scanf("%d", &mainMatriz[i][j]);
        }
    }
}

void SumaFilas(int mainMatriz[][COLUMNAS], int filas, int columnas){
    int result = 0, i, j;

    for(i = 0 ; i < filas ; i++){
        result = 0;
        for(j = 0 ; j < columnas ; j++){
            result+=mainMatriz[i][j];
        }
        printf("La suma de la fila %d es: %d\n", i+1, result);
    }
}

void SumaColumnas(int mainMatriz[][COLUMNAS], int filas, int columnas){
    int result = 0, i, j;

    for(i = 0 ; i < columnas ; i++){
        result = 0;
        for(j = 0 ; j < filas ; j++){
            result+=mainMatriz[j][i];
        }
        printf("La suma de la columnas %d es: %d\n", i+1, result);
    }
}

void Mostrar(int mainMatriz[][COLUMNAS], int filas, int columnas){
    int i, j;

     for(i = 0 ; i < filas ; i++){
        printf("Fila %d\t", i+1);
        for(j = 0 ; j < columnas ; j++){
            printf("%d\t", mainMatriz[i][j]);
        }
        printf("\n");
    }
}
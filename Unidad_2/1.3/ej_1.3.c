/*
Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor
almacenado en la matriz indicando cuantas veces se repite y en que posiciones.
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define FILA 5
#define COLUMNA 8


void CargaRandom(int [][COLUMNA], int, int);
void MostrarMatriz(int [][COLUMNA], int, int);
int Maximo(int [][COLUMNA], int, int);
void MostrarMaximo(int [][COLUMNA], int, int);

int main(){
    int matriz[FILA][COLUMNA] = {0}, d;

    CargaRandom(matriz, FILA, COLUMNA);

    MostrarMatriz(matriz, FILA, COLUMNA);

    return 0;
}

void CargaRandom(int main[][COLUMNA], int f, int c){
    int r = 0, i , j = 0;
    srand(time(NULL));

    for(i = 0 ; i < f ; i++){
        for(j = 0 ; j < c ; j++){
            r = rand() % 100;
            main[i][j] = r;
        }
    }
}

void MostrarMatriz(int matriz[][COLUMNA], int f, int c){
    int i , j;

    for(i = 0 ; i < f ; i++){
        for(j = 0 ; j < c ; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int Maximo(int matriz[][COLUMNA], int f, int c){
    int i, j, aux = matriz[0][0];

    for(i = 0 ; i < f ; i++){
        for(j = 1; i < c ; j++){
            if(matriz[i][j])
                aux = matriz[i][j];
        }
    }

    return aux;
}
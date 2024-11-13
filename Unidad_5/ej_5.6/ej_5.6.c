/* Cargar un vector de enteros con números aleatorios de 3 cifras máximo.
Realizar una función que retorne un puntero al mayor valor del vector
Mostrar el máximo valor mediante el puntero y la posición en la cual se encuentra */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VECTOR 4

void CargaAleatoria(int[], int);
int* BuscarMayor(int[], int);

int main(){
    int v[VECTOR] = {0};
    int *pos;

    CargaAleatoria(v, VECTOR);

    pos = BuscarMayor(v, VECTOR);

    printf("El mayor valor es: %d\n", *pos);
    printf("La posicion es: %d\n", &pos);
}

void CargaAleatoria(int v[], int l){
    int i;
    srand(time(NULL));

    for(i = 0; i < l; i++){
        v[i] = rand() % 111;
    }
}

int* BuscarMayor(int v[], int l){
    int i, mayor = 0;
    int *pos;

    printf("\n");
    for(i = 0; i < l; i++){
        if(v[i] > mayor){
            mayor = v[i];
            pos = &v[i];
        }
    }


    return pos;
}
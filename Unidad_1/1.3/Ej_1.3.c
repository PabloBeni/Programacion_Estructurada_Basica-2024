/*En un curso de la maestría en informática los estudiantes deben exponer en forma grupal sus investigaciones
de un tema dado. El curso está formado por 5 grupos. Se pide realizar un programa para sortear el orden de
exposición de dichos grupos. Cada vez que se ejecute el programa deberá mostrar un orden de exposición
distinto para cada uno de los 5 grupos. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 5

void CargarVector(int[], int);
void OrdenarVector(int[], int[], int);

int main(){
    int v[LENGTH], v2[LENGTH] = {1,2,3,4,5}, i;

    CargarVector(v, LENGTH);
    OrdenarVector(v, v2, LENGTH);

    printf("El orden es el siguiente: ");
    for(i = 0; i < LENGTH; i++){
        printf("\n%d", v2[i]);
    }

    return 0;
}

void CargarVector(int v[], int l){
    int i;
    srand(time(NULL));

    for(i = 0; i < l; i++){
        v[i] = rand() % 100;
    }
}

void OrdenarVector(int v[], int v2[], int l){
    int i, j, aux;

    for(i = 0; i < l-1; i++){
        for(j = 0; j < l-1; j++){
            if(v[j] < v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                aux = v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = aux;
            }
        }
    }
}
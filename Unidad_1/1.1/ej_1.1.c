/*
1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

void CargaRandom(int[], int, int);
void Mostrar(int[], int);
int MenorValor(int[], int);
int MayorValor(int[], int);
int CantidadRepeticion(int[], int, int);
int BuscarPosicion(int[], int, int);

int main(){
    int v[LENGTH], num_menor, num_mayor, cant_menor, pos_mayor;

    CargaRandom(v, LENGTH, 1001);
    num_menor = MenorValor(v, LENGTH);
    num_mayor = MayorValor(v, LENGTH);
    cant_menor = CantidadRepeticion(v, LENGTH, num_menor);
    pos_mayor = BuscarPosicion(v, LENGTH, num_mayor);

    Mostrar(v, LENGTH); 
    printf("\nEl menor valor es: %d y se repite: %d", num_menor, cant_menor);
    printf("\nEl mayor valor es: %d y su posicion es; %d", num_mayor, pos_mayor + 1);

    return 0;
}

void CargaRandom(int v[], int l, int cifras){
    int i;
    srand(time(NULL));

    for(i = 0; i < l; i++){
        v[i] = rand() % cifras;
    }
}

void Mostrar(int v[], int l){
    int i;

    for(i = 0; i < l; i++){
        printf("%d ", v[i]);
    }
}

int MenorValor(int v[], int l){
    int i;
    int aux = v[0];

    for(i = 1;i < l;i++){
        if(v[i] < aux){
            aux = v[i];
        }
    }

    return aux;
}

int MayorValor(int v[], int l){
    int i, aux = v[0];

    for(i = 1; i < l; i++){
        if(v[i] > aux){
            aux = v[i];
        }
    }

    return aux;
}

int CantidadRepeticion(int v[], int l, int b){
    int i, cant = 0;

    for(i = 0; i < l; i++){
        if(b == v[i]) cant++;
    }

    return cant;
}

int BuscarPosicion(int v[], int l, int b){
    int i = 0, pos = -1;

    while(pos==-1 && i<l){
        if(v[i]==b){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}
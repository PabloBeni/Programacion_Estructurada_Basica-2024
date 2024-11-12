/*Hacer un programa que cargue un vector de 10 enteros y lo muestre usando una función para cargar y otra
mostrar sin utilizar subíndices.*/
#include <stdio.h>
#define Z 10;

void Carga(int[]);
void Mostrar(int[]);

int main(){
    int v[10];

    //Muy parecido al metodo tradicional
    Carga(v);
    Mostrar(v);

    return 0;
}

void Carga(int v[]){
    int i;

    for(i = 0; i < 10 ; i++){
        printf("Ingrese valor: ");
        scanf("%d", v+i);
    }
}

void Mostrar(int v[]){
    int i;

    for(i = 0; i < 10 ; i++){
        printf("\n%d", *(v+i));
    }
}
/*Al programa anterior agregarle una función que reciba la dirección de inicio del vector y un número a buscar
y retorne un puntero al dato encontrado o NULL sino lo encuentra. En el main agregar un proceso de
búsqueda que se repita hasta ingresar un número negativo o cero a buscar. Si se lo encontró se debe
indicar en que posición del vector estaba (calcular dicha posición utilizando la dirección retornada) */
#include <stdio.h>
#define Z 10;

void Carga(int[]);
void Mostrar(int[]);
int* Buscar(int*, int);

int main(){
    int v[10], *dato;

    Carga(v);
    
    dato = Buscar(&v[0], 7);

    printf("%d", *dato);

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

int* Buscar(int *v, int b){
    int *dato = NULL, i = 0;

    while(dato == NULL && i < 10){
        if(*v+i == b){
            dato = *v+i;
        }else{
            i++;
        }
    }

    return dato;
}


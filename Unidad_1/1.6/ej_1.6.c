/*
Dado un conjunto de 10 números enteros ordenados de menor a mayor, ingresar por teclado 3 números más
no ordenados. Insertarlos donde correspondan. Mostrar en pantalla la serie inicial y la final. 
*/
#include <stdio.h>
#define NUMEROSEXTRA 3
#define NUMEROS 10

void Ordenamiento(int[], int);
void CargaNumeros(int[], int, int);
void Mostrar(int[], int[], int, int);
int Busqueda(int[], int, int);

int main(){
    int numerosOrdenados[NUMEROS] = {1, 3, 5, 6, 8, 11, 15, 18, 19, 23};
    int numeroOrdenadosCopia[NUMEROS + NUMEROSEXTRA] = {1, 3, 5, 6, 8, 11, 15, 18, 19, 23};

    CargaNumeros(numeroOrdenadosCopia, NUMEROS, NUMEROSEXTRA);
    Ordenamiento(numeroOrdenadosCopia, NUMEROS+NUMEROSEXTRA);

    Mostrar(numerosOrdenados, numeroOrdenadosCopia, NUMEROS, NUMEROSEXTRA);

    return 0;
}

void CargaNumeros(int numerosOrdenadosCopia[], int c, int e){
    int i, dato, pos = -1, flag = 0;

    for (i = 0; i < e; i++)
    {
        flag=0;
        do{
            if(!flag){
                printf("Ingrese un dato a agregar: ");
                scanf("%d", &dato);
            }else{
                printf("Dato repetido, ingrese otro numero: ");
                scanf("%d", &dato);
            }
            pos = Busqueda(numerosOrdenadosCopia, dato, c+e);
            flag=1;
        }while(pos != -1);

        numerosOrdenadosCopia[c + i] = dato;
    }
}

void Ordenamiento(int numerosOrdenados[], int c){
    int i, j, aux;

    for(i=0;i<c-1;i++){
        for(j=0;j<c-1-i;j++){
            if(numerosOrdenados[j]>=numerosOrdenados[j+1]){
                aux=numerosOrdenados[j];
                numerosOrdenados[j]=numerosOrdenados[j+1];
                numerosOrdenados[j+1]=aux;
            }
        }
    }
}

void Mostrar(int numeroOrdenados[], int numeroOrdenadosCopia[], int c, int v){
    int i;

    printf("\nPrimer Array\n");
    for(i=0;i<c;i++){
        printf("%d ", numeroOrdenados[i]);
    }
    printf("\nSegundo Array\n");
    for(i=0;i<c+v;i++){
        printf("%d ", numeroOrdenadosCopia[i]);
    }
}

int Busqueda(int v[], int aBuscar, int c){
    int pos = -1, i = 0;

    while(pos == -1 && i <= c){
        if(v[i] == aBuscar)
            pos = i;
        else
            i++;
    }
	
	return pos;
}
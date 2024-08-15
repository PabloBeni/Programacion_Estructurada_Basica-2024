#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_PRODUCTOS 10

void IngresarCodigo(int[], int);
int Busqueda(int[], int, int);
int Mayor(int[], int);
int Menor(int[], int);
void Mostrar(int[], int[], int);
void IngresarPedidos(int[], int[], int);

int main()
{
    int codigos[CANTIDAD_PRODUCTOS], pedidos[CANTIDAD_PRODUCTOS] = {0};

    IngresarCodigo(codigos, CANTIDAD_PRODUCTOS);
    IngresarPedidos(codigos, pedidos, CANTIDAD_PRODUCTOS);
    Mostrar(codigos, pedidos, CANTIDAD_PRODUCTOS);
}

void IngresarCodigo(int c[], int m){
    /*
    i: Iterador
    aux: Variable auxiliar, almacena el codigo de producto de manera temporal. 
    pos: Posición del codigo repetido dentro del vector Codigo.
    */
    int i, aux, pos;

    for(i = 0; i < m; i++){
        //*Verificacion del Codigo de Producto
        do{
            printf("Ingrese codigo de producto: ");
            scanf("%d", &aux);

            pos = Busqueda(c, aux, i);

            if(pos != -1){
                printf("Numero repetido, ingrese de nuevo\n");
            }else if(!(aux > 999 && aux < 10000)){
                printf("Numero fuera de rango.\n");
            }
        }while(pos != -1 && !(aux > 999 && aux < 10000));
        //*Una vez verificado, se le asigna al vector[i] el valor de aux. 
        c[i] = aux;
    }
}

int Busqueda(int v[], int valor, int cantidad){
    /*
    i: Iterador, inicializado en 0 porque se utiliza el 0.
    pos: Si no se encuentra el valor buscado se devolvera -1. 
    */
    int i = 0, pos = -1;

    while(pos == -1 && i < cantidad){
        if(v[i] == valor){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}

void IngresarPedidos(int c[], int p[], int cantidad){
    int pos, i = 0, codigo, producto;

    printf("Se ingresan los datos de los pedidos.\n");

    //*Verificamos que el codigo de producto existe y cumpla el intervalo
    do{
        printf("Ingrese codigo de producto: ");
        scanf("%d", &codigo);
        pos = Busqueda(c, codigo, cantidad);
    }while(!(codigo > 999 && codigo < 10000) && pos == -1);

    //*Carga Parcial, al ingresar 0 se interrumpe la carga de datos. 
    while(codigo != 0){
        do{
            printf("Ingrese cantidad de productos: ");
            scanf("%d", &producto);
        }while(!(producto > 0)); //*Mayor a 0 porque no puede haber entregas negativas.

        //*Le sumamos la cantidad de pedido en el vector de pedido a la posicion relacionada con el vector de codigo. 
        p[pos] += producto;

        i++;

        if(i < cantidad){
            do{
                printf("Ingrese codigo de producto: ");
                scanf("%d", &codigo);
                pos = Busqueda(c, codigo, cantidad);
            }while(!(codigo > 999 && codigo < 10000) && pos != -1);
        }
    }
}

int Mayor(int c[], int cantidad){
    int aux, i;
    aux = c[0];

    for(i = 1; i < cantidad; i++){
        if(aux > c[i]){
            aux = c[i];
        }
    }

    return aux;
}

int Menor(int c[], int cantidad){
    int aux, i;
    aux = c[0];

    for(i = 1; i < cantidad; i++){
        if(aux < c[i]){
            aux = c[i];
        }
    }

    return aux;
}

void Mostrar(int c[], int p[], int cantidad){
    int i, mayor, menor;

    mayor = Mayor(p, cantidad);
    menor = Menor(p, cantidad);

    printf("Listado de producto y pedidos: ");
    for(i = 0; i < cantidad; i++){
        printf("Producto n: %d, \tCant. pedidos: %d", c[i], p[i]);
    }

    for(i = 0; i < cantidad; i++){
        if(p[i] == mayor){
            printf("Codigo: %d, ventas: %d", c[i], p[i]);
        }
    }
    for(i = 0; i < cantidad; i++){
        if(p[i] == menor){
            printf("Codigo: %d, ventas: %d", c[i], p[i]);
        }
    }
}
/*Dada la siguiente estructura:
typedef struct
{
int codigo;
char descripcion[31];
float precio;
}sProductos
a. Crear una variable del tipo sProductos
b. Ingresar por teclado los campos
c. Crear un puntero a dicha estructura
d. Mostrar los datos ingresados mediante el puntero utilizando las dos nomenclaturas posibles */
#include <stdio.h>

typedef struct{
    int codigo; 
    char descripcion[31];
    float precio;
}sProductos;

sProductos CargarDatos();

int main(){
    sProductos producto; 
    sProductos *pProducto; 

    producto = CargarDatos();
    pProducto = &producto;

    printf("Datos sin puntero: \n");
    printf("%d\n", producto.codigo);
    printf("%s\n", producto.descripcion);
    printf("%.2f\n", producto.precio);

    printf("Datos con puntero: \n");
    printf("%d\n", (*pProducto).codigo);
    printf("%s\n", (*pProducto).descripcion);
    printf("%.2f\n", (*pProducto).precio);

    return 0;
}

sProductos CargarDatos(){
    sProductos producto;

    printf("Ingrese codigo de producto: ");
    scanf("%d", &producto.codigo);

    fflush(stdin);
    printf("Ingrese descripción del producto: ");
    fgets(producto.descripcion, 32, stdin);

    printf("Ingrese precio del producto: ");
    scanf("%f", &producto.precio);

    return producto;
}


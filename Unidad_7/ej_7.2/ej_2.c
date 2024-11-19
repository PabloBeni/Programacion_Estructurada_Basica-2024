/*Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a. Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c. Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
con stock menor al punto de pedido. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[15];
    int codigo;
    int cantidad;
}VENTAS;

typedef struct{
    int codigo;
    char descripcion[20];
    float precio;
    int stock;
    int punto_pedido;
    int cantidad_pedido;
}PRODUCTO;

FILE *OpenFile(char[], char[]);
void ProcesarInformacion();
int CargaProductos(PRODUCTO[], int);
int BusquedaProductoxID(int, PRODUCTO[], int);

int main(){

    ProcesarInformacion();
    return 0;
}

FILE *OpenFile(char name[30], char type[3]){
    FILE *file;

    file = fopen(name, type);
    if(file == NULL){
        printf("No se pude abrir el archivo.");
        system("Pause");
        exit(1);
    }

    return file;
}

void ProcesarInformacion(){
    FILE *fVentas;
    VENTAS venta; 

    //* Definimos variables 
    char antSucursal[15];
    PRODUCTO productos[200];
    int cant_productos = CargaProductos(productos, 200);
    float importe_total, recaudacion_total = 0;
    //* 

    //*Abrir archivos
    fVentas = OpenFile("ventas.dat", "rb");
    //*

    //*Corte Control
    fread(&venta, sizeof(VENTAS), 1, fVentas);
    while(!feof(fVentas)){
        strcpy(antSucursal, venta.nombre);
        printf("\n-----------SUCURSAl %s-----------", antSucursal);
        importe_total = 0;
        while(!feof(fVentas) && strcmp(antSucursal, venta.nombre) == 0){   
            /*a. Mostrar el importe total vendido en cada sucursal.
            b. Mostrar la recaudación total de la empresa en el mes.
            c. Determinar la sucursal que vendió mayor cantidad de productos.
            d. Actualizar el archivo de productos con el nuevo stock.
            e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse*/
            //!Asumimos que el producto existe
            importe_total += productos[BusquedaProductoxID(venta.codigo, productos, cant_productos)].precio;
            
            fread(&venta, sizeof(VENTAS), 1, fVentas);
        }       
        printf("\nImporte vendido: %.2f\n", importe_total);
    }

    fclose(fVentas);
}

int CargaProductos(PRODUCTO c[], int cant){
    FILE *fProductos;
    PRODUCTO producto;
    int i = 0;
    fProductos = OpenFile("productos.dat", "rb");

    fread(&producto, sizeof(PRODUCTO), 1, fProductos);
    while(!feof(fProductos) && i < cant){
        c[i] = producto;
        i++; 
        fread(&producto, sizeof(PRODUCTO), 1, fProductos);
    }
    fclose(fProductos);

    return i;
}

int BusquedaProductoxID(int codigo, PRODUCTO producto[], int cant){
    int i = 0, pos = -1;

    i = 0;
    while(i < cant && pos == -1){
        if(producto[i].codigo == codigo){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}
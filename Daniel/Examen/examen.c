#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int stock;
} STOCK;

typedef struct{
    int id;
    int stock;
    char description[30];
} PRODUCTO;

STOCK BuscarProducto(int, char[]);
FILE *OpenFile(char[], char[]);
void ProcesarDatos();
void Actualizar();

int main(){
    ProcesarDatos();
    Actualizar();
    return 0;
}



FILE *OpenFile(char name[30], char type[3]){
    FILE *file; 
    file = fopen(name, type);
    if(file == NULL){
        printf("No se pudo abrir el archivo");
        system("Pause");
        exit(1);
    }

    return file;
}

STOCK BuscarProducto(int id, char nombre[30]){
    FILE *file;
    file = OpenFile(nombre, "rb");
    STOCK stock;
    int encontrado = 1;

    fread(&stock, sizeof(STOCK), 1, file);
    while(!feof(file) && encontrado){
        if(stock.id == id){
            encontrado = 0;
        }else{
            fread(&stock, sizeof(STOCK), 1, file);
        }
    } 

    fclose(file);

    if(encontrado){
        stock.id = -1;
    }

    return stock;
}

void ProcesarDatos(){
    FILE *fileProductos;
    fileProductos = OpenFile("productos.dat", "r+b");
    PRODUCTO producto;
    STOCK stock1, stock2, stock3, stock4;
    int cantidad_stock;

    fread(&producto, sizeof(PRODUCTO), 1, fileProductos);
    while(!feof(fileProductos)){
        stock1 = BuscarProducto(producto.id, "stock1.dat");
        stock2 = BuscarProducto(producto.id, "stock2.dat");
        stock3 = BuscarProducto(producto.id, "stock3.dat");
        stock4 = BuscarProducto(producto.id, "stock4.dat");
        cantidad_stock = 0;

        if(stock1.id != -1) cantidad_stock += stock1.stock;
        if(stock2.id != -1) cantidad_stock += stock2.stock;
        if(stock3.id != -1) cantidad_stock += stock3.stock;
        if(stock4.id != -1) cantidad_stock += stock4.stock;

        fseek(fileProductos, sizeof(PRODUCTO)*- 1, SEEK_CUR);
        producto.stock = cantidad_stock;
        fwrite(&producto, sizeof(PRODUCTO), 1, fileProductos);
        fflush(fileProductos);
        // fseek(fileProductos, 0, SEEK_CUR);

        fread(&producto, sizeof(PRODUCTO), 1, fileProductos);
    }

    fclose(fileProductos);
}

void Actualizar(){
    FILE *fileProductos, *fileProductos_new, *deleted;
    PRODUCTO producto;
    fileProductos = OpenFile("productos.dat", "rb");
    fileProductos_new = OpenFile("productos_n.csv", "wt");
    deleted = OpenFile("deleted.csv", "wt");
    fprintf(fileProductos_new, "ID\t|\tSTOCK\t|\tDESC\n");
    fprintf(deleted, "Productos borrados\n");

    fread(&producto, sizeof(PRODUCTO), 1, fileProductos);
    while(!feof(fileProductos)){
        if(producto.stock != 0){
            // fwrite(&producto, sizeof(PRODUCTO), 1, fileProductos_new);
            fprintf(fileProductos_new, "%d\t|\t%d\t|\t%s\n", producto.id, producto.stock, producto.description);
        }else{
            fprintf(deleted, "ID: %d\n", producto.id);
        }

        fread(&producto, sizeof(PRODUCTO), 1, fileProductos);
    }

    fclose(fileProductos);
    fclose(fileProductos_new);
    fclose(deleted);

    remove("productos.dat");
    rename("productos_n.csv", "productos.csv");
}
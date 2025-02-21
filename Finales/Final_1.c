#include <stdio.h>
#define MAX_PRODUCTO 40

typedef struct{
    int numero_producto;
    char nombre_producto[30];
    char rubro;
    int punto_repo;
    int stock;
}PRODUCTO;

int CargaProducto(PRODUCTO[]);
int BusquedaProducto(PRODUCTO[], int, int);
void ActualizarStock(PRODUCTO[], int);
void MostrarProductos(PRODUCTO[], int);

int main(){
    PRODUCTO productos[40];
    int l;

    l = CargaProducto(productos);
    ActualizarStock(productos, l);

    MostrarProductos(productos, l);

    return 0;
}

int CargaProducto(PRODUCTO productos[MAX_PRODUCTO]){
    PRODUCTO pr; 
    int i = 0;

    do{
        printf("Ingrese numero de producto: ");
        scanf("%d", &pr.numero_producto);
    }while(!(pr.numero_producto > -1));
    
    while(pr.numero_producto != 0 && i < 41){
        fflush(stdin);
        printf("Ingrese nombre producto: ");
        gets(pr.nombre_producto);

        printf("Ingrese el codigo de rublo:");
        scanf("%c", &pr.rubro);

        printf("Ingrese punto minimo de reposicion: ");
        scanf("%d", &pr.punto_repo);

        printf("Ingrese stock disponible: ");
        scanf("%d", &pr.stock);

        productos[i] = pr; 

        i++;

        do{
            printf("Ingrese numero de producto: ");
            scanf("%d", &pr.numero_producto);
        }while(!(pr.numero_producto > -1));
    }

    return i;
}

void ActualizarStock(PRODUCTO productos[MAX_PRODUCTO], int l){
    int cod, i, cantidad, index, flag = 0;

    printf("\n");
    printf("Ingrese el numero de producto a actualizar: ");
    scanf("%d", &cod);

    do{
        if(!flag){
            index = BusquedaProducto(productos, cod, l);
            flag = 1;
        }else{
            printf("Producto no encontrado \n");
            printf("Ingrese el numero de producto a actualizar: ");
            scanf("%d", &cod);
            index = BusquedaProducto(productos, cod, l);
        }
    }while(index == -1);

    for(i = 0; i < 7; i++){
        printf("Ingrese ventas del dia %d: ", i+1);
        scanf("%d", &cantidad);
        productos[index].stock += cantidad;
    }
}

int BusquedaProducto(PRODUCTO producto[MAX_PRODUCTO], int id, int l){
    int i=0, pos=-1;

    while(pos==-1 && i<l){ 
        if(producto[i].numero_producto == id){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void MostrarProductos(PRODUCTO productos[MAX_PRODUCTO], int l){
    int i;

    for(i = 0; i < l; i++){
        printf("%d  |    %s     |   %d  |   %c \n", productos[i].numero_producto, productos[i].nombre_producto, productos[i].stock, productos[i].rubro);
    }
}
/*Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego del ingreso se debe
ordenar de forma ascendente la colección con dichos códigos para permitir realizar búsquedas binarias.
Luego se ingresan las ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código
de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una
venta de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
        CANT UNIDADES       CÓDIGO
            XXX              XXX
            XXX              XXX
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades). */
#include <stdio.h>
#include <math.h>
#define NROPRODUCTOS 5
#define NROVENDEDORES 5

void OrdenarMayorAMenor(int[], int[],int);
void CargaProductos(int[], int);
void CargaVentas(int[], int[], int[], int);
void Informe(int[], int[], int[], int, int);
int Busqueda(int[], int, int);

int main(){
    int codigoProducto[NROPRODUCTOS] = {0};
    int cantidadProductosV[NROPRODUCTOS] = {0};
    int cantidadMenosV[NROPRODUCTOS] = {0};

    CargaProductos(codigoProducto, NROPRODUCTOS);   
    CargaVentas(codigoProducto, cantidadProductosV, cantidadMenosV, NROPRODUCTOS);

    OrdenarMayorAMenor(cantidadProductosV, codigoProducto, NROPRODUCTOS);

    Informe(codigoProducto, cantidadProductosV, cantidadMenosV, NROPRODUCTOS, NROVENDEDORES);
    
    return 0;
}

void CargaProductos(int codigoProducto[], int c){
    int codigo, flag = 0, i;

    for(i = 0 ; i < c ; i++){
        flag = 0;
        do{
            if(!flag){ 
                printf("Ingrese codigo de producto: ");
                scanf("%d", &codigo);   
            }else{
                printf("Dato ingresado mal, vuelve ingresado: ");
                scanf("%d", &codigo);   
            }
            flag = 1;
        }while(!(codigo < 1000));
        codigoProducto[i] = codigo;
    }
}

void OrdenarMayorAMenor(int cantidadProductosV[], int codigoProducto[], int c){
    int i, j, aux;
	
	for(i=0;i<c-1;i++){
		for(j=0;j<c-1-i;j++){
			if(cantidadProductosV[j]<cantidadProductosV[j+1]){
				aux = cantidadProductosV[j];
				cantidadProductosV[j] = cantidadProductosV[j+1];
				cantidadProductosV[j+1] = aux;

                aux = codigoProducto[j];
				codigoProducto[j]=codigoProducto[j+1];
				codigoProducto[j+1]=aux;
			}
		}
	}
}

void CargaVentas(int codigoProducto[], int cantidadProductosV[], int cantidadMenosV[], int c){
    int codigoVendedor, codigoProducto, cantidadVendida, posProducto = -1; 

    do{
        printf("Ingrese codigo de vendedor: ");
        scanf("%d", &codigoVendedor);
    }while(!(codigoVendedor > 1000 && codigoVendedor < 1006) && codigoVendedor != 0);

    while(codigoVendedor != 0){
        do{
            printf("Ingrese codigo de producto: ");
            scanf("%d", &codigoProducto);
            
            posProducto = Busqueda(codigoProducto, codigoProducto, c);
        }while(!(codigoProducto > 0 && codigoProducto < 1000) || posProducto == -1);

        do{
            printf("Ingrese cantidad del producto: ");
            scanf("%d", &cantidadVendida);
        }while(!(cantidadVendida > -1));

        cantidadMenosV[(codigoVendedor - 1000) - 1]++;
        cantidadProductosV[posProducto] += cantidadVendida;

        do{
            printf("Ingrese codigo de vendedor: ");
            scanf("%d", &codigoVendedor);
        }while(!(codigoVendedor > 1000 && codigoVendedor < 1006) && codigoVendedor != 0);

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

void Informe(int codigoProducto[], int cantidadProductosV[], int cantidadMenosV[],int c, int v){
    int i;

    printf("CANT\nUNIDADES\t CODIGO \n");
    for(i = 0; i < c; i++){
        printf("%d \t\t %d \n", cantidadProductosV[i], codigoProducto[i]);
    }
    printf("\n");
    printf("Cantidad de productos vendidor por vendedor\n");
    for(i = 0; i < v; i++){
        printf("Vendedor: %d \t\t , vendio: %d \n", (i+1000) + 1, cantidadMenosV[i]);
    }
}
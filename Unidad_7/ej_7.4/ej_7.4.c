/*La empresa de colectivos línea 166 desea saber cuánto debe cobrar en un mes determinado según los viajes
realizados y registrados en el sistema mediante la tarjeta SUBE para ello dispone de un archivo de viajes
los viajes del mes que está ordenado por número de Interno (colectivo) que contiene la siguiente
información:
    • Número de Interno (entero)
    • Número tarjeta SUBE (entero)
    • Código de Tarifa (texto de 10 caracteres máximo)
    • Día (entero)
    • Hora (entero)
Se dispone de un segundo archivo llamado tarifas.dat que contiene información de las tarifas por cada mes con
la siguiente estructura:
    • Mes (entero)
    • Código de Tarifa (texto de 10 caracteres máximo)
    • Precio (float)
Se sabe que como máximo se manejan 8 tarifas distintas en cada mes.
Se solicita:
    a. Ingresar por teclado el mes a procesar y recuperar las tarifas correspondientes
    b. Mostrar el importe total a cobrar por la empresa
    c. Generar un archivo que contenga la cantidad de viajes y la recaudación de cada interno en el mes.
    d. Informar el interno que realizó menos cantidad de viajes
    e. Por cada interno mostrar cuantos viajes se realizaron por cada tipo de tarifa ordenado por cantidad de
    viajes en forma descendente.
Funciones obligatorias:
    • CargaTarifas: que levanta a un vector en memoria las tarifas del mes ingresado por teclado.
    • OrdenarViajes: para ordenar los viajes según lo pedido en el punto e.
    • MostrarViajes: para mostrar en forma de listado los viajes ordenados del punto e. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nro_interno;
    int nro_sube;
    char codigo_tarifa[11];
    int dia;
    int hora;
}VIAJE;

typedef struct{
    int mes;
    char codigo_tarifa[10];
    float precio;
}TARIFA;


FILE *OpenFile(char[], char[]);
int CargaTarifas(TARIFA[], int);
void OrdenarViajes();
void MostrarViajes();
int IngresarMes();
float ImporteTotal(TARIFA[], int);
void ProcesarDatos(TARIFA[], int);
int BusquedaID(char[], TARIFA[], int);

int main(){
    TARIFA tarifas[8];
    int cant = CargaTarifas(tarifas, 8);

    ProcesarDatos(tarifas, cant);
}

FILE *OpenFile(char name[20], char type[3]){
    FILE *file;
    if((file = fopen(name, type)) == NULL){
        printf("No se a podido abrir el archivo.");
        system("Pause");
        exit(1);
    }

    return file;
};

int CargaTarifas(TARIFA tarifas[], int cant){
    int i = 0;
    FILE *fileTarifas;
    TARIFA tarifa;
    int mes = IngresarMes();    

    fileTarifas = OpenFile("tarifas.dat", "rb");  

    fread(&tarifa, sizeof(TARIFA), 1, fileTarifas);
    while(!feof(fileTarifas) && i < cant){
        if(mes == tarifa.mes){
            tarifas[i] = tarifa;
            i++;
        }
        fread(&tarifa, sizeof(TARIFA), 1, fileTarifas);
    }   

    fclose(fileTarifas);

    return i;


}

int IngresarMes(){
    int mes, flag = 1;

    do{
        if(flag){
            printf("Ingrese mes(1 - 12): ");
            scanf("%d", &mes);
        }else{
            printf("Numero ingresado no aceptado\n");
            printf("Ingrese el dato otra vez(1 - 12): ");
            scanf("%d", &mes);
        }
        flag = 0;
    }while(!(mes > 0 && mes < 13));

    return mes;
}

float ImporteTotal(TARIFA tarifas[], int cant){
    int i, acum = 0;

    for(i = 0; i < cant; i++){
        acum += tarifas[i].precio;
    } 

    return acum;
}

void ProcesarDatos(TARIFA tarifa[], int cant){
    /*a. Ingresar por teclado el mes a procesar y recuperar las tarifas correspondientes
    b. Mostrar el importe total a cobrar por la empresa
    c. Generar un archivo que contenga la cantidad de viajes y la recaudación de cada interno en el mes.
    d. Informar el interno que realizó menos cantidad de viajes
    e. Por cada interno mostrar cuantos viajes se realizaron por cada tipo de tarifa ordenado por cantidad de
    viajes en forma descendente.*/
    FILE *fileInterno, *fileViajes;
    fileInterno = OpenFile("internos.csv", "wt");
    fileViajes = OpenFile("viajes.dat", "rb");
    VIAJE viaje;
    int cantidad_viajes, nro_internoAnt;
    float recaudacion_total;
    fprintf(fileInterno, "**************MES NRO: %d**************\n", tarifa[0].mes);
    fprintf(fileInterno, "INTERNO\t|\t\tCANT.VIAJES\t\t|\t\tRECAUDACION\n");

    fread(&viaje, sizeof(VIAJE), 1, fileViajes);
    while(!feof(fileViajes)){
        cantidad_viajes = 0;
        recaudacion_total = 0;
        nro_internoAnt = viaje.nro_interno;
        while(!feof(fileViajes) && nro_internoAnt == viaje.nro_interno){
            cantidad_viajes++;
            recaudacion_total += tarifa[BusquedaID(viaje.codigo_tarifa ,tarifa, cant)].precio;

            fread(&viaje, sizeof(VIAJE), 1, fileViajes);
        }
        fprintf(fileInterno, "%d\t\t|\t\t%d\t\t\t|\t\t%.2f$\n", nro_internoAnt, cantidad_viajes, recaudacion_total);
    }

    fclose(fileViajes);
}

int BusquedaID(char b[], TARIFA v[], int cant){
    int i = 0, pos = -1;

    while(i < cant && pos == -1){
        if(strcmp(v[i].codigo_tarifa, b) == 0){
            pos = i;
        }else{
            i++;
        }
    }   

    return pos;
}
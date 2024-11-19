/*Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
empresa. Por cada llamada se dispone de la siguiente información:
• Sector (15 caracteres máximo)
• Duración en segundos (entero)
• Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:
a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
c. En un archivo llamado costos.dat hay un único registro que contiene los costos por segundo de los
tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que totalice los gastos de
llamadas de cada sector.
d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
generar con nombresector.dat y debe contener:
• Duración en segundos (entero)
• Tipo de llamada (entero)
• Costo de la llamada (float) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sector[15];
    int duracion;
    int tipo_llamada; //1, 2 ,3
}LLAMADA;

typedef struct{
    char sector[15];
    float costo;
}GASTO;

typedef struct{
    int duracion;
    int tipo_llamada;
    float costo;
}SECTOR;

FILE *OpenFile(char[], char[]);
void ProcesarDatos();
void CargaPrecios(float[], int);
void MostrarGastos();

int main(){
    ProcesarDatos();
    MostrarGastos();
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

void ProcesarDatos(){
    FILE *fileLlamada, *fileGastos, *fileSector; 

    //*Inicializacion LLAMADAS
    fileLlamada = OpenFile("LLAMADAS.dat", "rb");
    LLAMADA llamada;
    char sectorAnt[15], sector_m[15];
    int llamada_1, llamada_2, llamada_3, aux = 0, seg_total = 0;
    //*Inicializacion de GASTOS
    fileGastos = OpenFile("GASTOS.dat", "wb");
    GASTO gasto;
    float precios[3];
    CargaPrecios(precios, 3);
    //*Inicializacion SECTOR
    SECTOR sector;
    char nombre_sector[15];

    //*Corte de control
    fread(&llamada, sizeof(LLAMADA), 1, fileLlamada);
    while(!feof(fileLlamada)){
        strcpy(sectorAnt, llamada.sector);
        llamada_1 = 0;
        llamada_2 = 0;
        llamada_3 = 0;

        gasto.costo = 0;
        //* Crear archivo
        strcpy(nombre_sector, llamada.sector);
        strcat(nombre_sector, ".csv");
        fileSector = OpenFile(nombre_sector, "wt");
        fprintf(fileSector, "---------------%s---------------\n", sectorAnt);
        fprintf(fileSector, "\tDURACION\t|\tTIPO DE LLAMADA\t|\tCOSTO\n");
        //*
        printf("\n---------SECTOR: %s---------", sectorAnt);
        while(!feof(fileLlamada) && strcmp(sectorAnt, llamada.sector) == 0){
            //*Corte de control
            switch (llamada.tipo_llamada){
            case 1:
                llamada_1++;
                break;
            case 2:
                llamada_2++;
            break;
            default:
                llamada_3++;
                break;
            }
            aux += llamada.duracion;
            //*Creacion estructura COSTO
            strcpy(gasto.sector, sectorAnt);
            gasto.costo += precios[llamada.tipo_llamada - 1] * llamada.duracion;
            //*Creacion archivo por SECTOR
            sector.costo = precios[llamada.tipo_llamada - 1];
            sector.duracion = llamada.duracion;
            sector.tipo_llamada = llamada.tipo_llamada;
            fprintf(fileSector, "\t\t%d\t\t|\t\t%d\t\t|\t\t%.2f\n", sector.duracion, sector.tipo_llamada, sector.costo);
            //*

            fread(&llamada, sizeof(LLAMADA), 1, fileLlamada);
        }
        if(aux >= seg_total){
            seg_total = aux;
            strcpy(sector_m, sectorAnt);
        }
        printf("\nLlamadas tipo 1: %d", llamada_1);
        printf("\nLlamadas tipo 2: %d", llamada_2);
        printf("\nLlamadas tipo 3: %d", llamada_3);

        fwrite(&gasto, sizeof(GASTO), 1, fileGastos);

        fclose(fileSector);
    }
    printf("\n\n------------------------------------------\n");
    printf("\nEl sector %s es el que mas hablo por telefono: %d seg", sector_m, seg_total);

    fclose(fileLlamada);
    fclose(fileGastos);
}
 
void CargaPrecios(float precios[], int cant){
    FILE *filePrecios;
    float precio;
    int i = 0;

    filePrecios = OpenFile("COSTOS.dat", "rb");

    fread(&precio, sizeof(float), 1, filePrecios);
    while(!feof(filePrecios) && i < cant){
        precios[i] = precio;
        i++;
        fread(&precio, sizeof(float), 1, filePrecios);
    }

    fclose(filePrecios);
}

void MostrarGastos(){
    FILE *fileGASTOS;
    fileGASTOS = OpenFile("GASTOS.dat", "rb");
    GASTO gasto; 

    printf("\n\n------------------------------------------\n");
    printf("Tabla de GASTOS: \n");
    printf("\tSECTOR\t|\tGASTO\n");
    fread(&gasto, sizeof(GASTO), 1, fileGASTOS);
    while(!feof(fileGASTOS)){
        printf("\t%s\t|\t%.2f\n", gasto.sector, gasto.costo);
        fread(&gasto, sizeof(GASTO), 1, fileGASTOS);
    }

    fclose(fileGASTOS);
}
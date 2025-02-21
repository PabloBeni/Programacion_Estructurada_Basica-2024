/*La empresa RED VIAL S.A. desea controlar el flujo vehicular en sus cabinas de peaje a lo largo del mes. Para
ello se debe procesar la información provista por las barreras que se encuentra almacenada en el archivo
barreras.dat que contiene la siguiente información:
    • Día (entero)
    • Hora (0 a 24)
    • Número de barrera (entero)
Dentro del archivo la información se encuentra ordenada por día y hora. Determinar:
    a. La cantidad de vehículos por cada hora.
    b. La cantidad de vehículos de cada día.
    c. Ingresar por teclado los precios del peaje para horario normal y horario pico (de 7 a 11 y de 17 a
    19). Con esos valores guardar un archivo con la recaudación de cada día.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int hora;
    int nro_barrera;
} BARRERA;

FILE *OpenFile(char[], char[]);
void ProcesarDatos();
float IngresePrecio();

int main(){
    ProcesarDatos();

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
    FILE *fileBarreras, *fileRecaudacion;
    BARRERA barrera; 
    //*Ingreso de precios
    printf("Horario normal\n");
    float precio_1 = IngresePrecio();
    printf("Horario pico\n");
    float precio_2 = IngresePrecio();
    //*

    fileBarreras = OpenFile("barreras.dat", "rb");
    fileRecaudacion = OpenFile("recaudacion.csv", "wt");
    int diaAnt, horaAnt, cant_vehiculos, cant_total, v_pico, v_normal;

    fprintf(fileRecaudacion, "DIA\t|\tRECAUDACION PICO\t|\tRECAUDACION NRL\n");
    fread(&barrera, sizeof(BARRERA), 1, fileBarreras);
    while(!feof(fileBarreras)){
        diaAnt = barrera.dia;
        cant_total = 0;
        v_pico = 0;
        v_normal = 0;

        printf("-------DIA %d-------\n", diaAnt);
        do{
            horaAnt = barrera.hora; 
            cant_vehiculos = 0;


            printf("---HORA %d---\n", horaAnt);
            do{
                cant_vehiculos++;
                if((horaAnt > 6 && horaAnt < 12) || (horaAnt > 16 && horaAnt < 20)) v_pico++;
                else v_normal++;

                fread(&barrera, sizeof(BARRERA), 1, fileBarreras);
            }while(!feof(fileBarreras) && diaAnt == barrera.dia && horaAnt == barrera.hora);
            printf("Cantidad de vehiculos: %d\n", cant_vehiculos);

            cant_total += cant_vehiculos;
        }while(!feof(fileBarreras) && diaAnt == barrera.dia);
        fprintf(fileRecaudacion, "%d\t|\t%.2f\t|\t%.2f\n", diaAnt, v_pico * precio_2, v_normal * precio_1);
        printf("Cantidad de vehiculos en el dia: %d\n", cant_total);
    }
    fclose(fileRecaudacion);
    fclose(fileBarreras);
}

float IngresePrecio(){
    float res, flag = 1;

    do{
        if(flag){
            printf("Ingrese Precio: $");
            scanf("%f", &res);
        }else{
            printf("Dato erroneo\n");
            printf("Ingrese Precio: $");
            scanf("%f", &res);
        }
        flag = 0;
    }while(!(res > 0));

    return res;
}
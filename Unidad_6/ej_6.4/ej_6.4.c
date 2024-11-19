/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres) */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    float precio;
    char description[50];
}PRECIOS;

FILE *AbrirArchivo(char[], char[]);
void IncrementarPrecio();
void MostrarProductos();

int main(){
    IncrementarPrecio();
    MostrarProductos();
    return 0;
}

FILE *AbrirArchivo(char nombre[20], char tipo[3]){
    FILE *fp;

    if((fp = fopen(nombre, tipo)) == NULL){
        printf("No se pudo abrir el archivo");
        system("pause");
        exit(1);
    }

    return fp;
}

void IncrementarPrecio(){
    float incremento = 10; 
    FILE *fp;
    PRECIOS precio;

    fp = AbrirArchivo("PRECIOS.dat", "r+b");

    fread(&precio, sizeof(PRECIOS), 1, fp);
    while(!(feof(fp))){
        precio.precio += (incremento / 100) * precio.precio;
        fseek(fp, sizeof(PRECIOS)*-1, SEEK_CUR);
        fwrite(&precio, sizeof(PRECIOS), 1, fp);
        fflush(fp);

        fread(&precio, sizeof(PRECIOS), 1, fp);
    }
    fclose(fp); 
}

void MostrarProductos(){
    FILE *fp;
    fp = AbrirArchivo("PRECIOS.dat", "rb");
    PRECIOS precio; 

    printf("\n");
    fread(&precio, sizeof(PRECIOS), 1, fp);
    while(!(feof(fp))){
        printf("%d %.2f %s\n", precio.codigo, precio.precio, precio.description);
        fread(&precio, sizeof(PRECIOS), 1, fp);
    }

    fclose(fp);
}
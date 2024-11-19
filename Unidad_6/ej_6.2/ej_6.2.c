/*Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados. */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int DNI;
    char NOMBRE_APELLIDO[30];
    int notas[2];
    float promedio;
}ALUMNO;

FILE *AbrirArchivo(char[], char[]);
void ClasificarAlumnos();
void MostrarAlumnos();

int main(){ 
    ALUMNO alumno[3] = {
        {43569575 ,"Pablo Benito", {10, 10}, 10},
        {43569575 ,"Daniel Antezana", {10, 1}, 8},
        {43569575 ,"Guille Moreno", {5 , 5}, 5}
    };
    FILE *fp; 
    fp = AbrirArchivo("dato_alumno.dat", "wb");
    for(int i = 0; i < 3; i++){
        fwrite(&alumno[i], sizeof(ALUMNO), 1, fp);
    }
    fclose(fp);

    ClasificarAlumnos();
    MostrarAlumnos();

    return 0;
}

FILE *AbrirArchivo(char nombre[20], char tipo[3]){
    FILE *file;

    file = fopen(nombre, tipo);

    if(file == NULL){
        printf("Error al abrir archivo.");
        system("pause");
        exit(1);
    }

    return file;
}

void ClasificarAlumnos(){
    FILE *datoAlumno,
    *w_promocionado,
    *w_cursado,
    *w_reprobado;
    ALUMNO alumno;

    datoAlumno = AbrirArchivo("dato_alumno.dat", "rb");
    w_promocionado = AbrirArchivo("PROMOCIONADO.dat", "wb");
    w_cursado = AbrirArchivo("CURSADO.dat", "wb");
    w_reprobado = AbrirArchivo("REPROBADO.dat", "wb");

    while(!feof(datoAlumno)){
        fread(&alumno, sizeof(ALUMNO), 1, datoAlumno);

        if(alumno.notas[0] > 6 && alumno.notas[1] > 6){
            fwrite(&alumno, sizeof(ALUMNO), 1, w_promocionado);
        }else if(alumno.notas[0] > 3 && alumno.notas[1] > 3){
            fwrite(&alumno, sizeof(ALUMNO), 1, w_cursado);
        }else{
            fwrite(&alumno, sizeof(ALUMNO), 1, w_reprobado);
        }
    }

    fclose(datoAlumno);
    fclose(w_cursado);
    fclose(w_promocionado);
    fclose(w_reprobado);
}

void MostrarAlumnos(){
    ALUMNO alumno;
    FILE *promocionados,
    *cursados,
    *reprobados;

    promocionados = AbrirArchivo("PROMOCIONADO.dat", "rb");
    cursados = AbrirArchivo("CURSADO.dat", "rb");
    reprobados = AbrirArchivo("REPROBADO.dat", "rb");

    printf("\n");
        fread(&alumno, sizeof(ALUMNO), 1, promocionados);
    while(!feof(promocionados)){
        printf("%s\n", alumno.NOMBRE_APELLIDO);
        fread(&alumno, sizeof(ALUMNO), 1, promocionados);
    }
    printf("\n");
        fread(&alumno, sizeof(ALUMNO), 1, cursados);
    while(!feof(cursados)){
        printf("%s\n", alumno.NOMBRE_APELLIDO);
        fread(&alumno, sizeof(ALUMNO), 1, cursados);
    }
    printf("\n");
        fread(&alumno, sizeof(ALUMNO), 1, reprobados);
    while(!feof(reprobados)){
        printf("%s\n", alumno.NOMBRE_APELLIDO);
        fread(&alumno, sizeof(ALUMNO), 1, reprobados);
    }
    
    fclose(promocionados);
    fclose(cursados);
    fclose(reprobados);
}
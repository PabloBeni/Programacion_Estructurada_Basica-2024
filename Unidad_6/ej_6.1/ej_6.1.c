/*Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA. */
#include <stdio.h>

typedef struct{
    int DNI;
    char NOMBRE_APELLIDO[30];
    int notas[2];
    float promedio;
}ALUMNO;

void CargaDatos(FILE *, int*);
void MostrarDatos(FILE *, int);

int main(){
    int cantidad = 0;
    FILE *fp;

    CargaDatos(fp, &cantidad);
    MostrarDatos(fp, cantidad);

    return 0;
}

void CargaDatos(FILE *fp, int *cantidad){
    ALUMNO alumno;
    fp = fopen("dato_alumno.dat", "wb");

    do{ 
        printf("Ingrese DNI del alumno: ");
        scanf("%d", &alumno.DNI);
    }while(!(alumno.DNI > -1 && alumno.DNI < 100000000));

    while(alumno.DNI != 0){
        fflush(stdin);
        printf("Ingrese nombre y el apellido del alumno: ");
        fgets(alumno.NOMBRE_APELLIDO, 31, stdin);

        for(int i = 0; i < 2; i++){
            do{
                printf("Ingrese nota %d: ", i+1);
                scanf("%d", &alumno.notas[i]);
            }while(!(alumno.notas[i] > 0 && alumno.notas[i] < 11));
        }

        alumno.promedio = (alumno.notas[0] + alumno.notas[1]) / 2;

        //Carga de datos
        fwrite(&alumno, sizeof(ALUMNO), 1, fp);
        *cantidad += 1;
        //

        do{ 
            printf("Ingrese DNI del alumno: ");
            scanf("%d", &alumno.DNI);
        }while(!(alumno.DNI > -1 && alumno.DNI < 10000000));
    }

    fclose(fp);
}

void MostrarDatos(FILE *fp ,int cantidad){
    int i = 0;
    ALUMNO alumnos[cantidad];
    
    fp = fopen("dato_alumno.dat", "rb");
    for(i = 0; i < cantidad; i++){
        fread(&alumnos[i], sizeof(ALUMNO), 1, fp);
    }
    printf("Datos de los Alumnos\n");
    for(i = 0; i < cantidad; i++){
        printf("%d: %s, %d, n1:%d n2:%d, %.2f\n", i+1, alumnos[i].NOMBRE_APELLIDO, alumnos[i].DNI, alumnos[i].notas[0], alumnos[i].notas[1], alumnos[i].promedio);
    }
    fclose(fp);
}
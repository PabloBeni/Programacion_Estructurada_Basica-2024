/* Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI. */
#include <stdio.h>
#define LENGTH 60

void CargarDatos(int[], int[], int);
int Buscar(int[], int, int);

int main(){
    int alumnos[LENGTH] = {0}, notas[LENGTH];

    CargarDatos(alumnos, notas, LENGTH);

    return 0;
}

void CargarDatos(int alumnos[], int notas[], int l){
    int dni, nota, i = 0, flag = 1, pos;

    do{
        if(flag){
            printf("Ingrese DNI del alumno: ");
            scanf("%d", &dni);
        }else{
            printf("Dato incorrecto, ingrese DNI nuevamente: ");
            scanf("%d", &dni);
        }

        flag = 0;
    }while(!(dni > 9999999 && dni < 100000000) && !(dni < 0));

    while(dni < 0 && i < l){
        do{
            printf("Ingrese nota del alumno: ");
            scanf("%d", &nota);
        }while(!(nota > -1 && nota < 11));

        alumnos[i] = dni;
        notas[i] = nota;

        i++;

        do{
            printf("Ingrese DNI del alumno: ");
            scanf("%d", &dni);

            pos = Buscar(alumnos, l, dni);

        }while(!(dni > 9999999 && dni < 100000000) && !(dni < 0) && pos == -1);
    }

    printf("No se cargo datos");
}

int Buscar(int dni[], int l, int b){
    int i = 0, pos = -1;

    while(pos == -1 && i < l){
        if(dni[i] == b){
            pos = i;
        }else{
            i++;
        }
    }

    return pos;
}
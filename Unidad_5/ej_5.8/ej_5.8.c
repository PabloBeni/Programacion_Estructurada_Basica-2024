/*Dada la estructura alumno:
struct alumno
{
char nom[31];
int dni;
};
Realizar un programa que permita cargar alumnos y mostrarlos. Como máximo permitir 50 alumnos. El ingreso
finaliza con un DNI igual a 0. Realizar una función para cargar y otra para mostrar usando notación de punteros. */
#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50

struct alumno {
    char nom[31];
    int dni;
};

void cargarAlumnos(struct alumno *alumnos, int *cantidad) {
    struct alumno *p = alumnos;
    int i = 0;

    do{
        printf("Ingrese DNI del alumno: ");
        scanf("%d", &p->dni);
    }while(!(p->dni >= 0));

    while(p->dni != 0 && i < 50){
        fflush(stdin);
        printf("Ingrese Nombre del alumno: ");
        fgets(p->nom, 32, stdin);

        p++;
        i++;

        do{
            printf("Ingrese DNI del alumno: ");
            scanf("%d", &p->dni);
        }while(!(p->dni >= 0));
    }

    *cantidad = i;

}

void mostrarAlumnos(struct alumno *alumnos, int cantidad) {
    struct alumno *p = alumnos;

    printf("\nListado de Alumnos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %s, DNI: %d\n", p->nom, p->dni);
        p++;  // Avanza al siguiente elemento
    }
}

int main() {
    struct alumno alumnos[MAX_ALUMNOS];
    int cantidad;

    cargarAlumnos(alumnos, &cantidad);
    mostrarAlumnos(alumnos, cantidad);

    return 0;
}
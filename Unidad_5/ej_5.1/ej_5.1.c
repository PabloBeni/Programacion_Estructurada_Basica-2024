/*Crear una variable entera y un puntero a dicha variable
Asignar el valor 10 a la variable mediante el puntero
Mostrar:
a) la dirección de la variable
b) la dirección del puntero
c) el contenido de la variable
d) el contenido de la variable accediendo mediante el puntero
e) el contenido del puntero */
#include <stdio.h>

int main(){
    int *p, a = 10;

    p = &a;

    printf("Direccion de la variable: %d\n", &a);    
    printf("Direccion del puntero:  %d\n", &p);    
    printf("Contenido de la variable: %d\n", a);
    printf("Contenido del puntero: %d\n", *p);

    return 0;
}
/*Definir dos números enteros y dos punteros a dichos números. Accediendo mediante los punteros sumar
ambos números y mostrar el resultado por pantalla. */
#include <stdio.h>

int main(){
    int a = 1, b = 2, *p1, *p2;

    p1 = &a;
    p2 = &b;

    printf("Aritmetica de punteros: %d", *p1 + *p2);

    return 0;
}
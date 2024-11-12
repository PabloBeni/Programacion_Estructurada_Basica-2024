/*Realizar una función que permita ingresar por teclado un valor entero, un flotante y un carácter. La función
no debe retornar ningún valor. Las variables se declaran y se muestran en el programa principal. */
#include <stdio.h>

void Carga(float*, char*);

int main(){
    float f;
    char c;

    //Paso la direccion de memoria de las variables, se considera puntero
    Carga(&f, &c);

    printf("FLoat: %.2f", f);
    printf("Char: %c", c);

    return 0;
};

void Carga(float *f, char *c){
    printf("Ingrese un float: ");
    scanf("%f", f);

    fflush(stdin);
    printf("Ingrese un char: ");
    scanf("%c", c);
}
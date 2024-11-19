/*Puntos)Implemente una función que calcule el valor promedio del pasaje de subte según la cantidad de viajes
realizados en un mes. El prototipo de la función es el siguiente.

float pasajePromedio (int viajesRealizados, float *tarifa, int *viajes, int tarifaCant);

Donde:
● viajesRealizados: Es la cantidad de viajes realizados en un mes
● tarifa: Es un puntero a un vector con los valores del pasaje.
● viajes: Es un puntero al vector que contiene a partir de que viaje se aplica una tarifa del vector tarifa.
● tarifaCant: Es la cantidad de tarifas disponibles.
La función devuelve el pasaje promedio calculado.
Ejemplo de tarifas:

    tarifa | 757    | 605.60    | 529.90    | 454.20
    viajes | 1 a 20 | 21 a 30   | 31 a 40   | 41 en adelante
*/
#include <stdio.h>
#define CANT_TARIFAS 5

float pasajePromedio (int viajesRealizados, float tarifa[], int viajes[], int tarifaCant);

int main(){ 
    float tarifas[CANT_TARIFAS] = {757, 605.60, 529.90, 454.20, 500};
    int viajes[CANT_TARIFAS] = {1, 21, 31, 41, 51};
    int viajesRealizados = 65;

    float data = pasajePromedio(viajesRealizados, tarifas, viajes, CANT_TARIFAS);

    printf("El promedio de viajes es: %.2f", data);

    return 0;
}

float pasajePromedio (int viajesRealizados, float tarifa[], int viajes[], int tarifaCant){
    int i, j = 0;
    float result = 0;

    for(i = 1; i <= viajesRealizados; i++){
        if(i < viajes[j + 1]){
            result += tarifa[j];
        }else if(j != tarifaCant){
            j++;
            result += tarifa[j];
        }
    }

    return result / viajesRealizados;
}
/*Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating en
los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio. */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int canal;
    char programa[36];
    float rating;
}RATING;

FILE *OpenFile(char name[], char type[]);

int main(){
    FILE *fileR;
    fileR = OpenFile("RATING.dat", "rb");
    RATING rating;
    float puntos, mayorPuntos = 0; 
    int canalAnt, canalMayor;

    fread(&rating, sizeof(RATING), 1, fileR);
    while(!feof(fileR)){
        puntos = 0;
        canalAnt = rating.canal;

        while(!feof(fileR) && canalAnt == rating.canal){
            puntos += rating.rating;    

            fread(&rating, sizeof(RATING), 1, fileR);
        }
        if(puntos < 14){
            printf("\n");
            printf("*******CANAL %d*******\n", canalAnt);
            printf("Puntos de RATING EN TOTAL %.2f", puntos);
            printf("\n");
        }       
        if(mayorPuntos <= puntos){
            mayorPuntos = puntos;
            canalMayor = canalAnt;
        }
    }
    printf("\nEl canal con mayor rating es el %d, con: %.2f puntos", canalMayor, mayorPuntos);

    fclose(fileR);
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
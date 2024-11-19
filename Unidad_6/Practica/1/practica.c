#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[14];
    int edad;
}LLAMADAS;

int main(){
    FILE *fp;
    LLAMADAS llamadas[5];
    // LLAMADAS llamadas[5] = {
    //     {"PABLO", 22},
    //     {"DANIEL", 21},
    //     {"BIANCA", 8},
    //     {"GUILLE", 18},
    //     {"SANTI", 22}
    // };

    // fp = fopen("datos.dat", "wb");
    // for(int i = 0; i < 5; i++){
    //     fwrite(&llamadas[i], sizeof(LLAMADAS), 1, fp);
    // }
    // fclose(fp);

    fp = fopen("datos.dat", "rb");
    for(int i = 0; i < 5; i++){
        fread(&llamadas[i], sizeof(LLAMADAS), 1, fp);
    }

    for(int i = 0; i < 5; i++){
        printf("%d\n", llamadas[i].edad);
    }

    fclose(fp);

    return 0;
}
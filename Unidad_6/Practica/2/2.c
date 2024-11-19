#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dex;
    char name[25];
    int level;
}POKEMON;

FILE *OpenFile(char[], char[]);
void InitFile();
void SortPokemon();
int Size();
void ShowPokemon();

int main(){
    // InitFile();
    SortPokemon();
    ShowPokemon();

    return 0;
}

FILE *OpenFile(char name[30], char type[3]){
    FILE *file;
    file = fopen(name, type);

    if(file == NULL){
        printf("No se pudo abrir el archivo");
        system("Pause");
        exit(1);
    }
    
    return file;
}

void InitFile(){
    POKEMON pokemon[5] = {
        {1000, "Goldengo", 29},
        {542, "Leavanny", 32},
        {750, "Mudslade", 55},
        {1006, "Ferropaladin", 80},
        {358, "Chimecho", 20}
    };
    FILE *file;
    file = OpenFile("POKEMON.dat", "wb");

    for(int i = 0; i < 5; i++){
        fwrite(&pokemon[i], sizeof(POKEMON), 1, file);
    }
    fclose(file);
}

void SortPokemon(){
    FILE *file;
    file = OpenFile("POKEMON.dat", "r+b");
    int ln = Size(file), i, j;
    POKEMON aux1, aux2;

    for(i = 0; i < ln-1; i++){
        for(j = 0; j < ln-1; j++){
            fseek(file, j * sizeof(POKEMON), SEEK_SET);
            fread(&aux1, sizeof(POKEMON), 1, file);
            fread(&aux2, sizeof(POKEMON), 1, file);

            if(aux1.dex <= aux2.dex){
                fseek(file, -2 * sizeof(POKEMON), SEEK_CUR);
                fwrite(&aux2, sizeof(POKEMON), 1, file);
                fwrite(&aux1, sizeof(POKEMON), 1, file);
            }
        }
    }

    fclose(file);
}

int Size(FILE *file){
    int ln;

    fseek(file, 0, SEEK_END);
    ln = ftell(file) / sizeof(POKEMON);
    rewind(file);

    return ln;
}

void ShowPokemon(){
    FILE *file;
    file = OpenFile("POKEMON.dat", "rb");
    POKEMON pokemon;

    fread(&pokemon, sizeof(POKEMON), 1, file);
    while(!feof(file)){
        printf("%s\n", pokemon.name);
        fread(&pokemon, sizeof(POKEMON), 1, file);
    }

    fclose(file);
}
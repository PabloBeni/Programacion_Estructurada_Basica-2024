/*¿Dónde está Wally?
Wally posee problemas mentales y siempre se escapa del neuropsiquiátrico donde lo interna su pobre amigo
Odlaw. Para encontrarlo, Odlaw consiguió una imagen de baja resolución de toda la ciudad en forma de vector y
sabe que el patrón de Wally es un vector el cual se intercala un carácter si y uno no con el dibujo. Encontra a
Wally y devolve un puntero a su posición.. Si no lo encuentra Odlaw se vuelve loco y devuelve NULL

char * odlaw(char *dibujo, char *wally)

Ejemplo
para cant = 3
wally = “WLY”
dibujo = “XXxWGLFYxXXXXWLAAAAAA”; //-- Aca esta wally --
dibujo = “XXXWLYXXXXXA”; //-- Aca esta NO wally -- */
#include <stdio.h>
#include <string.h>

char* odlaw(char *dibujo, char *wally);

int main(){

    char wally[3] = "WLY"; 
    char dibujo[60] = "XXxWGLFYxXXXXWLAAAAAA";

    char *p = odlaw(dibujo, wally);

    printf("%c", *p);

    return 0;
}

char* odlaw(char *dibujo, char *wally){
    int d = strlen(dibujo);
    int i;
    char *result = NULL;

    for(i = 0; i < d; i++){
        if(*(dibujo+i) == *(wally+0) && *(dibujo+i+2) == *(wally+1) && *(dibujo+i+4) == *(wally+2)){
            result = dibujo+i;  
            printf("%d", i);
        }
    }


    return result;
}
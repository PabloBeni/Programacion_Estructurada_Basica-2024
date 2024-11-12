/* De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)

Se solicita realizar los siguientes procesos:
a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
anteriormente y llamarla PERSONA.
b. Mostrar los datos de la Estructura de Datos del punto a.
c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
utilizarla en una nueva Estructurad de Datos llamada PERSONA2.
d. Mostrar los datos de la Estructura de Datos del punto c.
e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
al programa principal (main).
f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
ser hasta 36 materias) y llamarla PERSONA3.
g. Crear una FUNCION que realice el punto f.
h. Mostrar los datos de la Lista creada en el punto f.
i. Crear una FUNCION que realice el punto h. */
#include <stdio.h>

typedef struct{
    int legajo;
    char apellido[16];
    char nombre[16];
    float altura;
    char sexo;
    int diaNacimiento;
    int mesNacimiento;
    int anoNacimiento;
}PERSONA;

int comprobacionDatos(int, int, int);
float comprobacionDatosF(float, float, float);
void ingresoDatos(PERSONA);

int main(){
    PERSONA persona; 

    ingresoDatos(persona);

    printf("%d %d %d",persona.diaNacimiento, persona.mesNacimiento, persona.anoNacimiento);

    return 0;
}

void ingresoDatos(PERSONA persona){
    printf("Ingrese nro de legajo: ");
    persona.legajo = comprobacionDatos(0, 10001, 1);

    fflush(stdin);
    printf("Ingrese nombre: ");
    fgets(persona.nombre, 16, stdin);

    fflush(stdin);
    printf("Ingrese apellido: ");
    fgets(persona.apellido, 16, stdin);

    printf("Ingrese altura: ");
    persona.altura = comprobacionDatosF(0, 1000, 1);

    fflush(stdin);
    printf("Ingrese genero: ");
    fgets(&persona.sexo, 2, stdin);

    printf("Ingrese dia de nacimiento: ");
    persona.diaNacimiento = comprobacionDatos(0, 32, 1);

    printf("Ingrese mes de nacimiento: ");
    persona.mesNacimiento = comprobacionDatos(0, 13, 1);

    printf("Ingrese anio de nacimiento: ");
    persona.anoNacimiento = comprobacionDatos(1949, 2019, 1);
}

int comprobacionDatos(int min, int max, int o){
    int dato;

    do{
        scanf("%d", &dato);
    }while(!(dato > min && dato < max) && dato != o);

    return dato;
}

float comprobacionDatosF(float min, float max, float o){
    float dato;

    do{
        scanf("%f", &dato);
    }while(!(dato > min && dato < max) && dato != o);

    return dato;
}
/*Se dispone del archivo llamadas.dat con las llamadas telefónicas del día realizadas por una
empresa. Dicho archivo se encuentra ordenado por Sector. Cada registro contiene: Sector
de la empresa (texto de 15 caracteres máximo), duración de la llamada en segundos (entero),
tipo de llamada (char: L local, I internacional, E dentro de la empresa).
Las llamadas realizadas dentro de la empresa no tienen costo.
Para valorizar las llamadas locales e internacionales se debe recuperar el costo por segundo
del archivo costos.dat que tiene; tipo de llamada (char), mes (entero), año (entero) y costo
por segundo (float). Se deben tomar en cuenta los costos del mes 6 del año 2024. Los costos
se deben recuperar mediante una función que reciba por referencia las dos variables donde
guardar los costos requeridos.
Por otro lado, se dispone del archivo gastosXSector.dat que contiene: Sector, importe total
gastado en el mes.
Se desea:
a) Usando corte de control generar un archivo de texto csv que indique: nombre del sector
y cantidad de llamadas de cada tipo
b) Actualizar el archivo de gastosXSector acumulando el gasto de las llamadas del día en
cada sector. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char sector[16];
    int duracion;
    char tipo;
}regLLamada;

typedef struct
{
    char tipo;
    int mes;
    int anio;
    float costoSeg;
}regCosto;

typedef struct
{
    char sector[16];
    float importe;
}regGastoXSector;

FILE * AbrirArchivo(char[],char[]);
int RecuperarCostos (float *,float *, int, int);
void ActualizarGastos(char[], float, FILE *);
void ProcesarLLamadas(float,float);

int main()
{
    float costoLocal, costoInter;
    if (RecuperarCostos(&costoLocal, &costoInter, 2024,6))
        ProcesarLLamadas(costoLocal,costoInter);
    else
        printf("No existen costos para el mes 6 del 2024.");

    return 0;
}

int RecuperarCostos (float *costoLocal,float *costoInt, int anio, int mes)
{
    FILE * archCostos;
    regCosto costo;
    archCostos = AbrirArchivo("costos.dat","rb");
    int cont =0;
    fread(&costo, sizeof(regCosto),1, archCostos);
    while (cont<2 && !feof(archCostos))
    {
        if (costo.anio == anio && costo.mes == mes)
        {
            if (costo.tipo == 'I')
            {
                *costoInt = costo.costoSeg;
                cont++;
            }
            else
                if (costo.tipo == 'L')
                {
                    *costoLocal = costo.costoSeg;
                    cont++;
                }
        }
        fread(&costo, sizeof(regCosto),1, archCostos);
    }
    fclose(archCostos);
    if (cont <2)
        cont=0;
    return cont;
}

void ProcesarLLamadas(float costoL, float costoI)
{
    FILE *archLlamadas,*archGastosXSec,*archResumen;
    regLLamada llamada;
    char secAnt[16];
    int cantLocal,cantEmpresa, cantInternac;
    float totXSec;

    archLlamadas = AbrirArchivo("llamadas.dat","rb");
    archGastosXSec = AbrirArchivo("gastosXSector.dat","r+b");
    archResumen =AbrirArchivo("LlamXSec.csv","wt");
    fprintf(archResumen,"SECTOR;LOCALES;INTERNACIONALES;EMPRESA\n");

    fread(&llamada,sizeof(regLLamada),1, archLlamadas);
    while (!feof(archLlamadas))
    {
        strcpy(secAnt,llamada.sector);
        cantEmpresa=0;
        cantInternac=0;
        cantLocal=0;
        totXSec=0;
        do
        {
            switch(llamada.tipo)
            {
                case 'E':
                    cantEmpresa++;
                    break;
                case 'I':
                    cantInternac++;
                    totXSec+=llamada.duracion*costoI;
                    break;
                case 'L':
                    cantLocal++;
                    totXSec+=llamada.duracion*costoL;
            }
            fread(&llamada,sizeof(regLLamada),1, archLlamadas);
        }while(!feof(archLlamadas) && strcmp(secAnt,llamada.sector)==0);
        fprintf(archResumen,"%s;%d;%d;%d\n",secAnt,cantLocal,cantInternac,cantEmpresa);
        ActualizarGastos (secAnt,totXSec,archGastosXSec);
    }

    fclose(archGastosXSec);
    fclose(archLlamadas);
    fclose(archResumen);
}

FILE * AbrirArchivo(char nombre[],char modo[])
{
    FILE * arch;
    arch= fopen(nombre,modo);
    if (arch == NULL)
    {
        printf("Error al abrir el archivo %s", nombre);
        system("pause");
        exit(1);
    }
    return arch;
}

void ActualizarGastos(char sec[], float impo, FILE *ag)
{
    regGastoXSector gxs;
    rewind(ag);
    fread(&gxs,sizeof(regGastoXSector),1, ag);
    int encontrado =0;
    while(!encontrado && !feof(ag))
    {
        if (strcmp(gxs.sector,sec)==0)
        {
            gxs.importe+=impo;
            fseek(ag,sizeof(regGastoXSector)*-1,SEEK_CUR);
            fwrite(&gxs,sizeof(regGastoXSector),1, ag);
            fflush(ag);
            encontrado =1;
        }
        else
            fread(&gxs,sizeof(regGastoXSector),1, ag);
    }
    if (!encontrado) //OPCIONAL
        printf("no se encontro el sector %s",sec);
}
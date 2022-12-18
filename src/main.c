/*	Autor: Paula Martins de Sousa		Fecha de creación:  18/12/2022 */

/*
**	ENUNCIADO DEL PROGRAMA
**	Hacer un programa en C que lea los precios (float)
que hay en un fichero de texto llamado “precios.txt” y los vaya guardando en un array 
de floats llamado vPrecios con una dimensión máxima de 100 elementos. 
Posteriormente el programa pedirá al usuario un número entre 1 y 20 que será el 
importe que se incrementará a todos los precios del fichero.
Una vez realizado el incremento en el array, debe almacenar los precios incrementados 
en un nuevo el fichero llamado “preciosModificados.txt”.
Será en el propio procedimiento “exportarDatos” que se creará con “w” el nuevo 
fichero.
NOTA: Una vez cargada la plantilla, debes guardar el fichero “precios.txt” 
proporcionado de la práctica en la raíz de la carpeta donde tengas tu 
proyecto/ejercicio.

**
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCADENA 100

int pideNumEntreRango(int min, int max);
void importarDatos(FILE *f, float vPrecios[], int *numE);
void incrementarPrecios(float vPrecios[], int numE, int incremento);
void exportarDatos(float vPrecios[], int numE);


int main(){

float vPrecios[MAXCADENA];
int numE = 0;

FILE *f;

f = fopen("precios.txt", "r");

if (f == NULL)
{
	puts("Error: No se encontró el archivo.");
}
else{
	printf("Lee correctamente.");
}	


	getch();
	
	return 0;
}

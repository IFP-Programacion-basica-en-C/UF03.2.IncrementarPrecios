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

int main()
{

	float vPrecios[MAXCADENA];
	int numE = 0;
	int incremento;

	FILE *f;

	f = fopen("precios.txt", "w");

	if (f == NULL)
	{
		puts("Error: No se encontró el archivo.");
	}
	else
	{
		printf("*******BIENVENIDO AL INCREMENTADOR AUTOMATICO DE PRECIOS*******\n\n");
		pideNumEntreRango(1, 20);
		importarDatos(f, vPrecios, &numE);
		incrementarPrecios(vPrecios, numE, incremento);
		exportarDatos(vPrecios, numE);
		fclose(f);
	}


	getch();

	return 0;
}

pideNumEntreRango(int min, int max)
{

	int num;

	do
	{
		printf("\nIntroduce un numero entre 1 y 20: ");
		scanf("%d", &num);
	} while (num < 1 || num > 20);

	return num;
}
void importarDatos(FILE *f, float vPrecios[], int *numE)
{

	int i = 0;
	float precios[10];

	while (feof(f) == 0)
	{

		fgets(precios, MAXCADENA, f);
		vPrecios[i] = atof(precios);
		i++;
	}
	(*numE) = i;
	rewind(f);
}

void incrementarPrecios(float vPrecios[], int numE, int incremento)
{
	printf("Introduce un numero entre 1 y 20: ");
	scanf("%d", incremento);

	for (int i = 0; i < numE; i++)
	{
		vPrecios[i] += incremento;
	}
}

void exportarDatos(float vPrecios[], int numE)
{
	FILE *f2;

	f2 = fopen("preciosModificados.txt", "w");

	if (f2 == NULL)
		printf("\nEl fichero no se ha podido crear el fichero.");
	else
	{
		fprintf(f2, "Listado de precios modificados:\n");
		for (int i = 0; i < numE; i++)
	{
		
		fprintf("%f", vPrecios[i]);
	}
	fclose(f2);
	}
}

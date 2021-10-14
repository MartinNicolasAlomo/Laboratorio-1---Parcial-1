#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "Ingresos.h"
#include "Clientes.h"


int CalcularMayor(int* pNumero, int numeroUno, int numero2){
	int retorno = -1;

	if(pNumero != NULL){
		if (numeroUno == numero2){
			retorno = 0;
		}
		else if (numeroUno > numero2){
			retorno = 1;
			*pNumero = numeroUno;
		}
		else{
			retorno = 1;
			*pNumero = numero2;
		}
	}
	return retorno;
}

int InicializarVectorFlotantes(float vector[], int limite, float valorInicial){
	int i;
	int retorno = 0;

	if (vector != NULL && limite > 0) {
		retorno = 1;
		for (i = 0; i < limite; i++) {
			vector[i] = valorInicial;
		}
	}
	return retorno;
}

int InicializarVectorEnteros(int vector[], int limite, int valorInicial){
	int i;
	int retorno = 0;

	if (vector != NULL && limite > 0) {
		retorno = 1;
		for (i = 0; i < limite; i++) {
			vector[i] = valorInicial;
		}
	}
	return retorno;
}

int CargarTemperatura(float vector[], int limite){
	int i;
	int retorno = 0;
	int respuesta;
	int dia;
	float temperatura;

	if (vector != NULL && limite > 0) {
		retorno = 1;
		respuesta = IngresarEntero(&dia,"Que dia quiere modiificar?","Dia invalido",1,limite,2);
		if(respuesta == 1){
			respuesta = IngresarFlotante(&temperatura,"Indique la temperatura: \n","Temperatura invalida\n",-50,70,2);
			if(respuesta == 1){
				vector[dia-1] = temperatura;
			}
		}

		for (i = 0; i < limite; i++) {
			printf("Indice: [%d]  -  Valor: %f",i,vector[i]);
		}
	}
	return retorno;
}

int CargarVectorEnterosAleatorioPorNumero(int vector[], int limite){
	int index;
	int auxiliar;
	int retorno = 0;
	char seguir;

	do {
		IngresarEntero(&auxiliar, "Ingrese un numero: \n", "Error, reingrese un numero: \n", 0, limite,2);
		IngresarEntero(&index, "Ingrese la posiicion: \n", "Error, reingrese un numero: \n", 0, limite,2);
		vector[index] = auxiliar;
		printf("Desea ingresar otro numero: \n");
		fflush(stdin);
		scanf("%c", &seguir);
	} while (seguir == 's');
	return retorno;
}

int ListarVectoresEnteros(int vector[], int limite){
	int retorno = 0;
	int i;

	if (vector != NULL && limite >= 0) {
		retorno = 1;for (i = 0; i < limite; i++) {
			printf("Listado - Indice: %d y su valor es: %d\n\n", i, vector[i]);
		}
	}
	return retorno;
}

int MostrarAlumnos(int legajo[], char nombre[][50], float nota[],int edad[],int limite){
	int i;
	int retorno = 0;

	for(i=0; i<limite; i++)	{
		printf("%4d\t %4s\t %4.2f\t \%4d\n",legajo[i],nombre[i],nota[i],edad[i]);
	}

	return retorno;
}

int ListarVectoresFlotantes(float vector[], int limite){
	int retorno = 0;
	int i;

	if (vector != NULL && limite >= 0) {
		retorno = 1;
		for (i = 0; i < limite; i++) {
			printf("Listado - Indice: %d y su valor es: %f\n\n", i, vector[i]);
		}
		retorno = 1;
	}
	return retorno;
}

int OrdernarVectoresMenorAMayor(int vector[], int limite){
	int i;
	int flagSwap;
	int contador = 0;
	int retorno = -1;
	int auxiliar;
	int nuevoLimite;

	if (vector != NULL && limite >= 0) {
		nuevoLimite = limite -1;
		do {
			flagSwap = 0;
			for (i = 0; i < nuevoLimite; i++) {
				if(vector[i] > vector[i+1]){
					flagSwap = 1;
					auxiliar = vector[i];
					vector[i] = vector[i+1];
					vector[i+1] = auxiliar;
				}
				contador++;
			}
			nuevoLimite--;
		} while (flagSwap == 1);
		retorno = contador;
	}
	return retorno;
}

int OrdernarVectoresMayorAMenor(int vector[], int limite){
	int i;
	int flagSwap;
	int contador = 0;
	int retorno = -1;
	int auxiliar;
	int nuevoLimite;

	if (vector != NULL && limite >= 0) {
		nuevoLimite = limite -1;
		do {
			flagSwap = 0;
			for (i = 0; i < nuevoLimite; i++) {
				if(vector[i] < vector[i+1]){
					flagSwap = 1;
					auxiliar = vector[i];
					vector[i] = vector[i+1];
					vector[i+1] = auxiliar;
				}
				contador++;
			}
			nuevoLimite--;
		} while (flagSwap == 1);
		retorno = contador;
	}
	return retorno;
}

int PromediarVectoresEnteros(int vector[], int limite, float* promedioVector){
	int i;
	int contador = 0;
	int suma = 0;
	float promedio;
	int retorno = 0;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
				suma = suma + vector[i];
				contador++;
			}
		}
	if(contador > 0){
	promedio = (float) suma / contador;
	*promedioVector = promedio;
	retorno = 1;
	}
	return retorno;
}

int PromediarVectoresFlotantes(float vector[], int limite, float* promedioVector){
	int i;
	int contador = 0;
	int suma = 0;
	float promedio;
	int retorno = 0;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
				suma = suma + vector[i];
				contador++;
			}
		}
	if(contador > 0){
	promedio = suma / contador;
	*promedioVector = promedio;
	retorno = 1;
	}
	return retorno;
}

int SumarVectoresEnteros(int* pPromedio, int vector[], int limite){
	int i;
	float retorno = 0;
	int acumulador = 0;

	if(limite>0 && pPromedio!=NULL && vector!=NULL){
		for (i = 0; i < limite; i++) {
			acumulador = acumulador + vector[i];
		}
		*pPromedio = acumulador;
		retorno = 1;
	}
	return retorno;
}

int SumarVectoresFlotantes(int* pPromedio, float vector[], int limite){
	int i;
	float retorno = 0;
	int acumulador = 0;

	if(limite>0 && pPromedio!=NULL && vector!=NULL){
		for (i = 0; i < limite; i++) {
			acumulador = acumulador + vector[i];
		}
		*pPromedio = acumulador;
		retorno = 1;
	}
	return retorno;
}

int MostrarVectoresCantidadPositivos(int vector[], int limite, int *cantidadPositivos){
	int i;
	int flagPositivos = 0;
	int contadorPositivos = 0;

	if (vector != NULL && limite >= 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] > 0) {
				flagPositivos = 1;
				contadorPositivos++;
			}
		}
	}
	*cantidadPositivos = contadorPositivos;
	return flagPositivos;
}

int MostrarVectoresCantidadNegativos(int vector[], int limite, int *cantidadNegativos){
	int i;
	int flagNegativos = 0;
	int contadorNegativos = 0;

	if (vector != NULL && limite >= 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] < 0) {
				flagNegativos = 1;
				contadorNegativos++;
			}
		}
	}
	*cantidadNegativos = contadorNegativos;
	return flagNegativos;
}

int SumarVectoresPares(int vector[], int limite, int *sumaPares){
	int i;
	int flagSumaPares = 0;
	int suma = 0;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] % 2 == 0) {
				flagSumaPares = 1;
				suma = suma + vector[i];
			}
		}
	}
	*sumaPares = suma;
	return flagSumaPares;
}

int SumarVectoresImpares(int vector[], int limite, int *sumaImpares){
	int i;
	int flagSumaPares = 0;
	int suma = 0;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] % 2 == 1) {
				flagSumaPares = 1;
				suma = suma + vector[i];
			}
		}
	}
	*sumaImpares = suma;
	return flagSumaPares;
}

int BuscarVectorMayorImpar(int vector[], int limite, int *maximoImpar){
	int i;
	int mayorImpar;
	int flagPrimerImpar = 0;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] % 2 == 1){
				if(i == 0 || vector[i] > mayorImpar){
					flagPrimerImpar = 1;
					mayorImpar = vector[i];
				}
			}
		}
	}
	*maximoImpar = mayorImpar;
	return flagPrimerImpar;
}

int ListarVectoresPosicionesImpares(int vector[], int limite){
	int retorno = 0;
	int i;

	if (vector != NULL && limite >= 0) {
		for (i = 0; i < limite; i++) {
			if (i % 2 == 1) {
				printf(
						"Vectores Posiciones Impares - Indice: %d y su valor es: %d\n\n", i, vector[i]);
			}
		}
		retorno = 1;
	}
	return retorno;
}

int ListarVectoresPares(int vector[], int limite){
	int i;
	int retorno = 0;
	int contadorPares = 0;

	if (vector != NULL && limite >= 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] % 2 == 0) {
				contadorPares++;
				printf("Vectores Pares - Indice: %d y su valor es: %d\n\n", i, vector[i]);
			}
		}
		retorno = 1;
	}
	if (contadorPares == 0) {
		printf(
				"No se puede realizar una lista ya que no ingresaron numeros pares\n\n");
	}
	return retorno;
}

int BorrarVectorImpares(int vector[], int limite){
	int retorno = 0;
	int i;

	if (vector != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (vector[i] % 2 == 1) {
				vector[i] = 0;
			}
		}
	}
	return retorno;
}

int ContarPalabras(char vector[], int limite, int* pPalabras){
	int i;
	int retorno = 0;
	int contador = 0;

	if (vector != NULL && limite > 0 && pPalabras != NULL) {
		retorno = 1;
		for (i = 0; i < limite && vector[1] != '\0'; i++) {
			if (vector[1] == ' ') {
				contador++;
			}
		}
		*pPalabras = contador;
	}

	return retorno;
}



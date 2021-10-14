#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Clientes.h"

void InicializarVectorIDClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial){
	int i;

	if (vectorPersonas != NULL && cantidadElementos > 0) {
		for (i = 0; i < cantidadElementos; i++) {
			vectorPersonas[i].idCliente = valorInicial;
		}
	}
}

int BuscarPrimerOcurrenciaClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial){
	int i;

	if (vectorPersonas != NULL && cantidadElementos > 0) {
		for (i = 0; i < cantidadElementos; i++) {
			if(vectorPersonas[i].idCliente == valorInicial){
				return i;
			}
		}
	}
	return -1;
}

int ImprimirListaClientes(Clientes vector[], int limite) {
	int i;
	int retorno = 0;

	if (vector != NULL && limite > 0) {
		retorno = 1;
		printf("Nombre\tApellido\tLegajo\n");
		for (i = 0; i < limite; i++) {
			if (vector[i].idCliente != -1) {
				printf("%8s %8s %4d\n",vector[i].nombreEmpresa, vector[i].cuit, vector[i].idCliente);
			}
		}
	}
	return retorno;
}

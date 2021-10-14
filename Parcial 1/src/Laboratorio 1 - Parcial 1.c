/*============================================================================
 	 	 	 	 	 Martin Alomo - Division E
Una empresa de recolecci�n y reciclado de pl�sticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolecci�n. El programa contar� con el siguiente men�:

1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit direcci�n y localidad.
Se generar� un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar la direcci�n y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n.
4) Crear pedido de recolecci�n: Se imprimir�n los clientes por pantalla y se pedir� que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectar�n del cliente. Se generar� un ID para el pedido y
el mismo quedar� en estado �Pendiente� hasta que se obtengan los residuos del cliente y se trasladen a la empresa.
5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de pl�stico que la empresa puede reciclar. Se imprimir�n los pedidos por
pantalla y se pedir� seleccionar el ID de uno de ellos. Luego deber�n ingresarse la cantidad de kilos
de pl�stico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por �ltimo, se marcar� al pedido como �Completado�.
6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos
de recolecci�n� que posee en estado �Pendiente�.
7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado
�Pendiente� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.
8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado
�Completado� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo
de pl�stico.
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes).

Los tipos de pl�stico que la empresa puede reciclar son:
� HDPE:	Polietileno de alta densidad (Envases para l�cteos, perfumes, detergentes l�quidos, etc.)
� LDPE:	Polietileno de baja densidad (Bolsas de congelaci�n de alimentos, tapas flexibles o bolsas de basura.)
� PP:	Polipropileno (Pl�sticos utilizados en la industria automovil�stica y en la construcci�n.)
El resto de la basura recolectada es desechada

Recomendaciones:
� Agregar al campo �isEmpty� a cada entidad.
� Generar un ID auto incrementable para cada entidad.
� Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y c�mo se
relacionan.
� Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
� Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.

Nota 0: El sistema soportar� una capacidad m�xima de 100 clientes y 1000 pedidos
Nota 1: Se deber�n desarrollar bibliotecas por cada entidad (Cliente y Pedido) las cuales contendr�n las
funciones (Alta, Baja, Modificar, etc.).Los informes deber�n estar en una biblioteca aparte.
Nota 2: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar
las reglas de estilo de la c�tedra.
 ============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "Ingresos.h"
#include "Clientes.h"
#define CANTPERSONAS 200




int main(void) {
	setbuf(stdout, NULL);
	Clientes arrayClientes[CANTPERSONAS];
	char auxiliarEmpresa[50];
	char auxiliarDireccion[50];
	char auxiliarLocalidad[50];
	int auxiliarCuit;
	int auxiliarIDCLiente;
	int contadorID = 1;
	int indiceLugarLibre;
	int indiceResultadoBusqueda;
	int flagInicial = 0;
	int opcion = 0;
	char confirmacionBaja;

	do {
		if (IngresarEntero(&opcion,
				"Seleccione una opcion: \n\n1-Alta de cliente\n2-Modificar datos del cliente cliente\n3-Baja de cliente\n"
				"4-Crear pedido de recoleccion\n5-Procesar residuos\n6-Imprimir Clientes\n7-Imprimir pedidos pendientes\n8-Imprimir pedidos procesados\n"
				"9-Ingresar localidad e indicar la cantidad de pedidos pendientes\n10-Promedio polipropileno reciclado por cliente\n11-Salir",
				"No es una opcion valida, reintentelo de nuevo\n", 1, 11, 3)
				== 1) {

			switch (opcion) {
			case 1:
				indiceLugarLibre = BuscarPrimerOcurrenciaClientes(arrayClientes,CANTPERSONAS,-1);
				if(indiceLugarLibre == -1){
					printf("No quedan espacios libres!\n");
					break;
				}

				puts("Alta\n");

				if(IngresarNombre(auxiliarEmpresa,50,"Ingrese nombre de la empresa: \n","Error\n",2) == 1){
					printf("%s\n",auxiliarEmpresa);
				}
				else{
					puts("El nombre debe tener letras\n");
					break;
				}

				if(IngresarEntero(&auxiliarCuit, "Ingrese el CUIT: \n", "Error\n", 1, 10, 2) == 1){
					printf("%d\n",auxiliarCuit);
				}
				else{
					puts("El cuit debe tener numeros y dos guiones como maximo\n");
					break;
				}
				if(IngresarAlfanumerico(auxiliarDireccion,50,"Ingrese la direccion: \n","Error\n",2) == 1){
					printf("%s\n",auxiliarDireccion);
				}
				else{
					puts("La direccion debe tener un nombre y un numero\n");
					break;
				}
				if(IngresarNombre(auxiliarLocalidad,50,"Ingrese la Localidad: \n","Error\n",2) == 1){
					printf("%s\n",auxiliarLocalidad);
				}
				else{
					puts("La localidad debe tener solo letras\n");
					break;
				}
				if(BuscarPrimerOcurrenciaClientes(arrayClientes,CANTPERSONAS,auxiliarIDCLiente) != -1){
					puts("El legajo ya existe\n");
				}
				strcpy(arrayClientes[indiceLugarLibre].nombreEmpresa,auxiliarEmpresa);
				strcpy(arrayClientes[indiceLugarLibre].direccion,auxiliarDireccion);
				strcpy(arrayClientes[indiceLugarLibre].localidad,auxiliarLocalidad);
				arrayClientes[indiceLugarLibre].cuit = auxiliarCuit;

				contadorID++;
				auxiliarIDCLiente = contadorID;
				printf("El nuevo ID del cliente es: %d",auxiliarIDCLiente);
				flagInicial = 1;
				break;

			case 2:
				if(flagInicial == 1){
					if(IngresarEntero(&auxiliarIDCLiente, "Ingrese el ID a modificar: \n", "Error\n", 1, 10, 2) == 1){
						printf("El ID a modificar es: %d\n",auxiliarIDCLiente);
					}
					else{
						puts("El ID debe tener numeros\n");
					}
					indiceResultadoBusqueda = BuscarPrimerOcurrenciaClientes(arrayClientes, CANTPERSONAS, auxiliarIDCLiente);

					if(indiceResultadoBusqueda == -1){
						puts("No se encuentra el ID del cliente\n");
						break;
					}
					if(IngresarAlfaNumerico(auxiliarDireccion,50,"Ingrese la nueva direccion: \n","Error\n",2) == 1){
						printf("%s\n",auxiliarDireccion);
					}
					else{
						puts("La direccion debe tener un nombre y un numero\n");
						break;
					}
					if(IngresarNombre(auxiliarLocalidad,50,"Ingrese la nueva Localidad: \n","Error\n",2) == 1){
						printf("%s\n",auxiliarLocalidad);
					}
					else{
						puts("La localidad debe tener solo letras\n");
						break;
					}
					strcpy(arrayClientes[indiceResultadoBusqueda].direccion,auxiliarDireccion);
					strcpy(arrayClientes[indiceResultadoBusqueda].localidad,auxiliarDireccion);
				}


				break;


			case 3:
				if(flagInicial == 1){
					while(confirmacionBaja != 's'){
						if(IngresarEntero(&auxiliarIDCLiente, "ID a dar de baja: \n", "Error\n", 1, 10, 2) == 1){
							printf("%d\n",auxiliarIDCLiente);
						}
						else{
							puts("El ID debe tener numeros\n");
						}
						indiceResultadoBusqueda = BuscarPrimerOcurrenciaClientes(arrayClientes, CANTPERSONAS, auxiliarIDCLiente);

						if(indiceResultadoBusqueda == -1){
							puts("No se encuentra el ID del cliente\n");
							break;
						}
						arrayClientes[indiceResultadoBusqueda].idCliente = -1;
						puts("Esta seguro/a que desea dar de baja este cliente");
						scanf("%c",confirmacionBaja);
					}
				}
				break;

			case 5:

				break;
			case 6:
				puts("Listado de clientes\n");
				ImprimirListaClientes(arrayClientes,CANTPERSONAS);
				break;
			case 7:
				puts("Listado de clientes\n");
				break;
			case 8:
				puts("Listado de clientes\n");
				break;
			case 9:
				puts("Listado de clientes\n");
				break;
			case 10:
				puts("Listado de clientes\n");
				break;
			case 11:
				puts("Listado de clientes\n");
				break;
			}
		}
	} while (opcion != 11);


	return EXIT_SUCCESS;
}

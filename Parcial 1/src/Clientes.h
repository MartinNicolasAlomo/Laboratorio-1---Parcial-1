
#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{
	char nombreEmpresa[50];
	int idCliente;
	int cuit;
	char direccion[50];
	char localidad[50];
	int isEmpty;
}Clientes;


void InicializarVectorIDClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial);
int BuscarPrimerOcurrenciaClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial);
int ImprimirListaClientes(Clientes vector[], int limite);


#endif /* CLIENTES_H_ */

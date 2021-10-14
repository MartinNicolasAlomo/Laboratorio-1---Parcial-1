
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


#endif /* CLIENTES_H_ */

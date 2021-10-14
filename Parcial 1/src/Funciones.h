#ifndef FUNCIONES_H_
#define FUNCIONES_H_


int CalcularMayor(int* pNumero, int numeroUno, int numero2);




int InicializarVectorFlotantes(float vector[], int limite, float valorInicial);

int InicializarVectorEnteros(int vector[], int limite, int valorInicial);

/// @brief Imprime el contenido del vector de enteros
/// @param vector es el puntero que se va a imprimir
/// @param limite define el tamaño del array
/// @return Devuelve 1 (exito) o 0 (error)
int MostrarVectorEnteros(int vector[], int limite);

int MostrarVectorFlotantes(float vector[], int limite);

int CargarTemperatura(float vector[], int limite);

int CargarVectorEnterosAleatorioPorNumero(int vector[], int limite);

int ListarVectoresEnteros(int vector[], int limite);

int ListarVectoresFlotantes(float vector[], int limite);

int OrdernarVector(int vector[], int limite);

int PromediarVectoresEnteros(int vector[], int limite, float* promedioVector);


int PromediarVectoresFlotantes(float vector[], int limite, float* promedioVector);


int SumarVectoresEnteros(int* pPromedio, int vector[], int limite);


int SumarVectoresFlotantes(int* pPromedio, float vector[], int limite);

int MostrarVectoresCantidadPositivos(int vector[], int limite, int *cantidadPositivos);

int MostrarVectoresCantidadNegativos(int vector[], int limite, int *cantidadNegativos);

int SumarVectoresPares(int vector[], int limite, int *sumaPares);

int SumarVectoresImpares(int vector[], int limite, int *sumaImpares);

int BuscarVectorMayorImpar(int vector[], int limite, int *maximoImpar);

int ListarVectoresPosicionesImpares(int vector[], int limite);

int ListarVectoresPares(int vector[], int limite);

int ContarPalabras(char vector[], int limite, int* pPalabras);


void InicializarVectorIDClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial);
int BuscarPrimerOcurrenciaClientes(Clientes vectorPersonas[], int cantidadElementos, int valorInicial);
int ImprimirListaClientes(Clientes vector[], int limite);


#endif /* FUNCIONES_H_ */

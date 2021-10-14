#ifndef INGRESOS_H_
#define INGRESOS_H_

int IngresarEntero(int *pEntero, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int ValidarRangoEntero(int numeroIngresado, int minimo, int maximo);
int RecibirEntero(int *pResultado);
/// @brief 	Verifica si el valor ingresado es numerico.
/// @param cadena Es el vector con la cadena que sera analizada.
/// @return	devuelve 1 si es numerico o 0 si no lo es.
int esNumerica(char *cadena, int limite);


int IngresarFlotante(float *pFlotante, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos) ;
int ValidarRangoFlotante(float numeroIngresado, float minimo, float maximo);
int RecibirFlotante(float *pResultado);
int esFlotante(char *cadena,int limite);

int IngresarCaracter(char *pCaracter, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);

int PedirDatos(char *cadena, int longitud);

int CargarVectorEnterosSecuencial(int vector[], int limite);

int CargarVectorFlotantesSecuencial(float vector[], int limite);

/// @brief Verifica si el valor ingresado contiene letras
/// @param cadena Es el vector con la cadena que sera analizada.
/// @return	devuelve 1 si tiene solo espacios en blanco y/o letras, o 0 si no los tiene.
int esSoloLetras(char *cadena);

/// @brief Verifica si el valor ingresado contiene letras y numeros.
/// @param cadena Es el vector con la cadena que sera analizada.
/// @return	devuelve 1 si tiene espacios en blanco y/o letras y numeros, o 0 si no los tiene.
int esAlfaNumerico(char *cadena);

/// @brief 	Verifica si la cadena ingresada es un telefono, con numeros, espacios en blanco o signo menos
/// @param cadena Es el vector con la cadena que sera analizada.
/// @return devuelve 1 si contiene numeros, espacio en blanco y/o guion
int esTelefono(char *cadena);


int MenuOpciones(int vector[], int limite, int estadoInicial, int minimo, int maximo);


#endif /* INGRESOS_H_ */

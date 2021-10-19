#include "Input.h"
//------------------------------------------------

int MostrarMenu (char mensaje [])
{
        int opcionIngresada;


         printf("\nElija una opcion \n");
         printf("1. Dar de Alta un cliente \n");
         printf("2. Modificar datos de cliente \n");
         printf("3. Baja de cliente: \n");
         printf("4. Crear pedido de recolección \n");
         printf("5. Procesar residuos:\n");
         printf("6. Imprimir Clientes: \n");
         printf("7. Imprimir Pedidos pendientes:\n");
         printf("8. Imprimir Pedidos procesados\n");
         printf("9. Cantidad de pedidos pendientes por localidad \n");
         printf("10.Cantidad de kilos de polipropileno reciclado promedio por cliente \n");
         printf("11.Cliente con más pedidos pendientes. \n");
         printf("12.Cliente con más pedidos completados. \n");
         printf("13.Agregar Nueva Localidad. \n");
         printf("14.Borrar una localidad existente. \n");
         printf("15.Salir \n");
         fflush(stdin);


         opcionIngresada = PedirUnEntero("Ingrese una opcion:");

         return opcionIngresada;
}

//-------------------------------------------

int ValidarEntero (char numero[])
{
    int retorno;
    int tamArray;

    retorno = 1;  //cero es falso

    tamArray = strlen(numero);  // guardo en tamArray el tamaño


    if (isdigit(numero[0]) != 0 || (tamArray > 1 && (numero[0] == '-' || numero [0]== '+')))
    {
    for (int i = 1; i < tamArray && retorno == 1; i++)
    {
        if (isdigit(numero[i]) == 0) // cero = no es un numero, !isdigit negado devuelve un 1 y entra al if (si no encuentra un numero)
        {
            retorno = 0;
        }

    }

    }
    else
    {
    	retorno = 0;
    }

    return retorno;
}

//---------------------------------------------------------------------------------------------------------


int PedirUnEntero(char mensaje[])
{
    char numeroIngresado[11];

    int numeroValidado;
    int numeroARetornar;
    int retornoDeMyGets;

    printf("%s",mensaje);

    retornoDeMyGets = myGets(numeroIngresado,11);

    numeroValidado = ValidarEntero(numeroIngresado);

    while (retornoDeMyGets == -1 || numeroValidado == 0)
    {
       printf("Error: %s \n",mensaje);
       retornoDeMyGets = myGets(numeroIngresado,11);
       numeroValidado = ValidarEntero(numeroIngresado);
    }

    numeroARetornar = atoi(numeroIngresado);

    return numeroARetornar;
}

//---------------------------------------------------------------------------------------------------------

/*
int PedirUnEnteroConRango (char mensaje[],int minimo, int maximo)
{

	char numeroAverificar[11];
	int numeroIngresado;
	printf("%s", mensaje);
	while((getString(numeroAverificar, sizeof(numeroAverificar))== -1 || ValidarEntero(numeroAverificar)) || !VerificarRangoEntero(&numeroAverificar,minimo,maximo))
	{
		printf("Error %s ",mensaje);
	}
}
//-----------------------------------------------------------------------
int VerificarRangoEntero (char numeroAverificar[], int *numeroAretornar,int minimo, int maximo)
{
	int aux;
	int numero;

	aux = 0;

	while (numero >= minimo && numero <= maximo)
	{
		aux = 1;
		*numeroAretornar = numero;
	}

	numero = atoi(numeroAverificar);
	return aux;
}*/
//-----------------------------------------------------------------------

int myGets (char cadena [], int longitud)
{  // Recibo una cadena y la longitud de la misma
   int retorno = -1;
   char bufferString[4096];

   if (cadena != NULL && longitud > 0)
   {
       fflush(stdin); // Limpio el stdin
       //Leo el stdin hasta que el usuario ingresa un "Enter" o Hasta el limite del bufferstring con ziseof
       if (fgets(bufferString,sizeof(bufferString),stdin) != NULL)
       { //Si se llego al limite no remplazo con un \0
           if (bufferString[strlen(bufferString)-1] == '\n')
           {  //Si no se llego al limite remplazo con un \0
               bufferString[strlen(bufferString)-1] = '\0';
           }
         //Si la longitud  resultante de la cadena ingresada es menor que la longitud
           if (strlen(bufferString) <= longitud && strlen(bufferString)>0)
           {  //Copio lo ingresado a la cadena (al espacio de memoria que me paso el usuario)
               strncpy(cadena,bufferString,longitud);
               retorno = 0;
           }
       }
   }
    return retorno;
}

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
float PedirFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}
//------------------------------------------------------------------------------------------------
void PedirCadena(char array[],char message[],char messageError[])
{
    char buffer[100];

     printf("%s",message);
    while(myGets(buffer, sizeof(buffer))== -1 || !validateStringOfLetters(buffer))
    {
    	printf("%s",messageError);

    }
    strcpy(array,buffer);

}


//------------------------------------------------------------------------------------------------
int validateStringOfLetters(char cadena[]) {

    int esSoloLetras;
    int longitud;

    esSoloLetras = 1;
    longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++)
    {
        if (!isalpha(cadena[i]))
        {
            esSoloLetras = 0;
        }
    }


    return esSoloLetras;
}
//-----------------------------------------------------------------------------------------------
// PARA VALIDAR FLOTANTES

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0){
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+')){
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' ){
				if(cadena[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,
							float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------
void PedirCadenaB(char array[],char message[])
{

    char buffer[100];
    printf("%s",message);
    myGets(buffer, sizeof(buffer));
    strcpy(array,buffer);
}
//------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

int PedirUnEnteroRango(char mensaje[],int minimo, int maximo)
{
    char numeroAverificar[11];
    int numeroIngresado;

    printf("%s",mensaje);


    while(myGets(numeroAverificar,sizeof(numeroAverificar))== -1 || !ValidarEntero(numeroAverificar) || !VerificarRangoInt(numeroAverificar, &numeroIngresado, minimo, maximo))
    	{
    	printf("Error:  %s",mensaje);
		}
    //numeroARetornar = atoi(numeroIngresado);

    return numeroIngresado;
}

//-------------------------------------------------------------------------
int VerificarRangoInt (char numeroAverificar[], int *numeroAretornar, int minimo ,int maximo)
{
	int enRango;
	int numeroAuxiliar;

	enRango = 0;
	numeroAuxiliar = atoi(numeroAverificar);

	if (numeroAuxiliar >= minimo && numeroAuxiliar <=maximo)
	{
		enRango =1;
		*numeroAretornar = numeroAuxiliar;
	}
	return enRango;
}


#define CARGADO 1
#define VACIO 0


#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "Input.h"
#include "Localidad.h"





typedef struct
{
	int   id;   //pk
	char  nombreEmpresa[51];
	char  cuit[20];
	char  direccion[51];
	int   localidad; //fk
	int   isEmpty;

}eCliente;



/// @fn int FindFreeSpace(eCliente[], int)
/// @brief Encuentra un lugar libre y lo devuelve para ser usado como index
/// @param lista
/// @param len
/// @return Una posicion para ser usada como index
int FindFreeSpace (eCliente lista[],int len);
/// @fn int InicializarArray(eCliente[], int)
/// @brief Inicializa el array para que todas las posiciones sean vacias
/// @param lista
/// @param len
/// @return Un valor de verdad
int InicializarArray(eCliente lista[],int len);
/// @fn void PedirListaCliente(eCliente[], int, int, eLocalidad[], int)
/// @brief Pide los datos para ser usados como lista
/// @param lista
/// @param len
/// @param id
/// @param listaLocalidad
/// @param lenLocalidad
void PedirListaCliente (eCliente lista[], int len, int id,eLocalidad listaLocalidad[],int lenLocalidad);
/// @fn int addCliente(eCliente[], int, int, char[], char[], char[], int)
/// @brief  Recibe por parametros los datos para cargar en el array
/// @param list
/// @param len
/// @param id
/// @param nombreEmpresa
/// @param cuit
/// @param direccion
/// @param localidad
/// @return Un valor de verdad
int addCliente(eCliente list[], int len, int id, char nombreEmpresa[],char cuit[],char direccion[],int localidad);
/// @fn int GenerarId(int)
/// @brief Genera una id sumando la que recibe por parametro
/// @param id
/// @return la id sumada
int GenerarId (int id);
/// @fn void HarcodearClientes(eCliente[], int)
/// @brief Carga una lista de clientes para realizar pruebas
/// @param lista
/// @param len
void HarcodearClientes (eCliente lista[],int len);
/// @fn int printClientes(eCliente[], int, eLocalidad[], int)
/// @brief imprime una lista de clientes
/// @param list
/// @param len
/// @param listaLocalidad
/// @param lenLocalidad
/// @return UN valor de verdad
int printClientes(eCliente list[], int len, eLocalidad listaLocalidad[],int lenLocalidad);
/// @fn void ModificarCliente(eCliente[], int, eLocalidad[], int)
/// @brief Recibe el index por parametro y permite modificar los datos de un cliente
/// @param list
/// @param index
/// @param listaLocalidad
/// @param lenLocalidad
void ModificarCliente(eCliente list[],int index, eLocalidad listaLocalidad[],int lenLocalidad);
/// @fn int findClienteById(eCliente[], int, int)
/// @brief Busca una id cargada en el array
/// @param list
/// @param len
/// @param id Parametro a buscar
/// @return Retorna un valor de verdad si encontro la id o no la encontro
int findClienteById(eCliente list[], int len,int id);
/// @fn int removeCliente(eCliente[], int, int)
/// @brief Recibe el in por parametro y permite borrar un cliente
/// @param list
/// @param len
/// @param id
/// @return Un valor de verdad
int removeCliente(eCliente list[], int len, int id);
/// @fn void showCliente(eCliente, eLocalidad[], int)
/// @brief Imprime solamente un cliente con su localidad
/// @param lista
/// @param localidad
/// @param lenLocalidad
void showCliente(eCliente lista, eLocalidad localidad[],int lenLocalidad);



#endif /* CLIENTES_H_ */

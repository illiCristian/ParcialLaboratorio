
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define CARGADO 1   //Completado
#define VACIO 0		//
#define PENDIENTE 2

#include "Input.h"
#include "Clientes.h"


#define PENDIENTE 2
#define CARGADO 1
#define VACIO 0

typedef struct
{
	float HDPE;
	float LDPE;
	float PP;
}eResiduos;

typedef struct
{
	int idPedidos; //pk
	int idCliente; //fk
	eResiduos residuos;
	float kilosARecolectar;
	int isEmpty;
}ePedidos;





/// @fn int FindFreeSpacePedidos(ePedidos[], int)
/// @brief Encuentra un lugar libre y lo devuelve para ser usado como index
/// @param lista
/// @param len
/// @returnUna posicion para ser usada como index
int FindFreeSpacePedidos (ePedidos lista[],int len);
/// @fn int InicializarArrayPedidos(ePedidos[], int)
/// @brief Inicializa el array para que todas las posiciones sean vacias
/// @param lista
/// @param len
/// @return Un valor de verdad
int InicializarArrayPedidos(ePedidos lista[],int len);
/// @fn int GenerarIdPedidos(int)
/// @brief Genera una id para pedidos
/// @param id
/// @return la id generada
int GenerarIdPedidos (int id);
/// @fn void showPedido(ePedidos)
/// @brief Muestra un pedido individual
/// @param lista
void showPedido(ePedidos lista);
///
//int PrintPedidosCase6(ePedidos list[], int len);
/// @fn void HarcodearPedidos(ePedidos[], int)
/// @brief Caraga una lista de pedidos para realizar pruebas en el programa
/// @param lista
/// @param len
void HarcodearPedidos (ePedidos lista[],int len);
/// @fn int IngresarKgsResiduos(ePedidos[], int, int)
/// @brief Carga los kgs necesarios en la lista ePedidos
/// @param lista
/// @param len
/// @param index
/// @return Un valor de verdad
int IngresarKgsResiduos (ePedidos lista[], int len,int index);
/// @fn int BuscarIdPedidos(ePedidos[], int, int)
/// @brief Busca una id cargada en el array
/// @param list
/// @param len
/// @param id Parametro a buscar
/// @return Retorna un valor de verdad si encontro la id o no la encontro
int BuscarIdPedidos(ePedidos list[], int len,int id);
int MostrarClienteMasPedidosCompletados (eCliente listaC[],int lenC,ePedidos listaP[],int lenP);


#endif /* PEDIDOS_H_ */




#ifndef NEXO_H_
#define NEXO_H_

typedef struct
{
    int id;
    int contador;
}eAuxiliar;


#include "Clientes.h"
#include "Pedidos.h"


//void print(eCliente listaClientes[],int TAM_Clientes,eLocalidad listaLocalidades[],int TAM_Localidades);
/// @fn int PrintClientesPedidosPendientes(eCliente[], int, ePedidos[], int)
/// @brief
/// @param listaClientes
/// @param lenClientes
/// @param listaPedidos
/// @param lenPedidos
/// @return
int PrintClientesPedidosPendientes(eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[],int lenPedidos);
/// @fn int PrintPedidosProcesados(eCliente[], int, ePedidos[], int)
/// @brief
/// @param listaC
/// @param lenC
/// @param listaP
/// @param lenP
/// @return
int PrintPedidosProcesados (eCliente listaC[],int lenC, ePedidos listaP[], int lenP);
/// @fn int printClientesPedidos(eCliente[], int, ePedidos[], int)
/// @brief
/// @param listaClientes
/// @param lenClientes
/// @param listaPedidos
/// @param lenPedidos
/// @return
int printClientesPedidos(eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[],int lenPedidos);
/// @fn int case6(eCliente[], int, ePedidos[], int, eLocalidad[], int)
/// @brief
/// @param listaC
/// @param lenClientes
/// @param listaPedidos
/// @param lenPedidos
/// @param listL
/// @param lenlocalidad
/// @return
int case6 (eCliente listaC[],int lenClientes,ePedidos listaPedidos[],int lenPedidos,eLocalidad listL[],int lenlocalidad);
/// @fn int CrearPedidoRecoleccion(eCliente[], int, ePedidos[], int, eLocalidad[], int, int*)
/// @brief
/// @param listaClientes
/// @param lenClientes
/// @param listaPedidos
/// @param lenPedidos
/// @param listaLocalidad
/// @param lenLocalidad
/// @param idPedidos
/// @return
int CrearPedidoRecoleccion (eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[], int lenPedidos,eLocalidad listaLocalidad[],int lenLocalidad,int *idPedidos);
/// @fn int MostrarPedidosPendientesPorLocalidad(eCliente[], int, ePedidos[], int, eLocalidad[], int, int)
/// @brief
/// @param listaC
/// @param lenC
/// @param listaP
/// @param lenP
/// @param listL
/// @param lenL
/// @param indexL
/// @return
int MostrarPedidosPendientesPorLocalidad (eCliente listaC[],int lenC,ePedidos listaP[],int lenP,eLocalidad listL[],int lenL, int indexL);
/// @fn int MostrarCantidadDePPReciclado(eCliente[], int, ePedidos[], int)
/// @brief
/// @param listaC
/// @param lenC
/// @param listaP
/// @param lenP
/// @return
int MostrarCantidadDePPReciclado(eCliente listaC[],int lenC,ePedidos listaP[],int lenP);
int MostrarClienteMasPedidosPendiente (eCliente listaC[],int lenC,ePedidos listaP[],int lenP);

#endif /* NEXO_H_ */

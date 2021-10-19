
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Input.h"
#include "Nexo.h"
//#include "Localidad.h"

#define TAM_Clientes 10
#define TAM_Pedidos 10
#define TAM_Localidades 10




int main(void)
{
		setbuf(stdout,NULL);


		eCliente listaClientes[TAM_Clientes];
		ePedidos listaPedidos[TAM_Pedidos];
		eLocalidad listaLocalidades[TAM_Localidades];

		int id;
		int idABuscar;
		int idABorrar;
		int idPedidos;
		int idPedidos5;
		int indexPedidos5;
		int indexLocalidad;
		int idABuscarLocalidad;
		//int flag;
		int opcionIngresada;
		int indexAModificar;
		//float kgsARecolectar;


		InicializarArray(listaClientes, TAM_Clientes);
		InicializarArrayPedidos(listaPedidos,TAM_Pedidos);
		InicializarArrayLocalidad(listaLocalidades, TAM_Localidades);
		HarcodearClientes (listaClientes,TAM_Clientes);
		CargarLocalidades (listaLocalidades,TAM_Localidades);
		HarcodearPedidos(listaPedidos,TAM_Pedidos);
	//	flag = 0;
		id= 1;
		idPedidos =1;

		printf("\n-------------------------------------------------------- \n");
		printf("\n Bienvenido al Parcial de labo Creado por Cristian Illi \n");
		printf("\n--------------------------------------------------------\n");

		do
		{
			opcionIngresada = MostrarMenu("Ingrese una opcion \n");
			switch (opcionIngresada)
			{
			case 1:

			if(FindFreeSpace(listaClientes, TAM_Clientes) != -1)
			{
				id = GenerarId(id);
				PedirListaCliente(listaClientes,TAM_Clientes,id,listaLocalidades,TAM_Localidades);
			//	flag =1;
			}else{
				printf("No hay lugar disponible para cargar Empleados \n");
			}

			break;

			case 2:

				//if(flag !=0)
					//{
					printClientes(listaClientes,TAM_Clientes,listaLocalidades,TAM_Localidades);
					idABuscar = PedirUnEntero("Ingrese el id a buscar: ");
					indexAModificar = findClienteById(listaClientes, TAM_Clientes, idABuscar);

					if (indexAModificar != -1)
						{
							printf("Se encontro el id ingresado en la lista \n");
							ModificarCliente(listaClientes, indexAModificar,listaLocalidades,TAM_Localidades);
						}
					else{
							printf("No se encontro el id ingresado en la lista \n");
						}
					//}else{
						//printf("Primero tiene que cargar un empleado para despues poder modificarlo \n");
					//	}
			break;

			case 3:
					printClientes(listaClientes,TAM_Clientes,listaLocalidades,TAM_Localidades);
					idABorrar = PedirUnEntero("Ingrese la id del empleado que desea borrar: \n");
					removeCliente(listaClientes,TAM_Clientes,idABorrar);

				break;
			case 4:

					if(CrearPedidoRecoleccion(listaClientes, TAM_Clientes, listaPedidos ,TAM_Pedidos,listaLocalidades,TAM_Localidades,&idPedidos)!= -1)
					{
						printf("Se creo el pedido de recoleccion correctamente con la id:  %d\n",idPedidos);
					}

				break;
			case 5:
				if(PrintClientesPedidosPendientes(listaClientes,TAM_Clientes,listaPedidos,TAM_Pedidos)!=-1)
				{
					idPedidos5 = PedirUnEntero("Ingrese un id de pedido: ");
					indexPedidos5 = BuscarIdPedidos(listaPedidos,TAM_Pedidos,idPedidos5);

					if(indexPedidos5 !=-1)
					{
						if(IngresarKgsResiduos(listaPedidos,TAM_Pedidos,indexPedidos5)!= -1)
						{
							printf("-----------------------------------\n");
							printf("Se proceso el pedido correctamente \n");
							printf("-----------------------------------\n");
						}
					}
					else{
						printf("No se encuentra el id en la lista de pedidos pendientes \n");
					}
				}
				else
				{
					printf("No se imprime nada \n");
				}
					break;


			case 6:
				/*6) Imprimir Clientes: Se imprimirá una lista de clientes
				 * con todos sus datos junto con la cantidad de “pedidos de recolección” que posee en estado “Pendiente”.*/
				case6(listaClientes, TAM_Clientes, listaPedidos, TAM_Pedidos, listaLocalidades, TAM_Localidades);
				break;
			case 7:
				if(printClientesPedidos(listaClientes,TAM_Clientes,listaPedidos,TAM_Pedidos)!= -1)
				{
					printf("Se muestra la lista de clientes con pedidos PENDIENTES \n");
				}
				else
				{
					printf("No hay clientes con pedidos pendientes, Well done \n");
				}
				break;
			case 8:
				/*Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
				“Completado” con la información: Cuit del cliente,
				 *dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
				 * */
			//printClientes(listaClientes,TAM_Clientes,listaLocalidades,TAM_Localidades);
				if(PrintPedidosProcesados(listaClientes,TAM_Clientes,listaPedidos,TAM_Pedidos)!=-1)
				{
					printf("------------------------------------------------------------------------------\n");
				}else
				{
					printf("No hay pedidos procesados para mostrar \n");
				}
				break;

			case 9:
				ImprimirLocalidades(listaLocalidades, TAM_Localidades);
				idABuscarLocalidad= PedirUnEntero("Ingrese la localidad a buscar: \n");

				indexLocalidad = findLocalidadById(listaLocalidades, TAM_Localidades, idABuscarLocalidad);

				if(MostrarPedidosPendientesPorLocalidad(listaClientes, TAM_Clientes, listaPedidos ,TAM_Pedidos,listaLocalidades,TAM_Localidades,indexLocalidad)== -1)
				{
					printf("No hay pedidos pendientes en la localidad: %s ",listaLocalidades[indexLocalidad].localidad);
				}

				break;
			case 10:
				/*10) Cantidad de kilos de polipropileno reciclado promedio por cliente.
				 * (kilos totales / cantidad de clientes)*/
				if(MostrarCantidadDePPReciclado(listaClientes,TAM_Clientes,listaPedidos,TAM_Pedidos)== -1)
				{
					printf("No hay pedidos completados que se hayan reciclado PP \n");
				}
				break;
			case 11:
				MostrarClienteMasPedidosPendiente(listaClientes, TAM_Clientes, listaPedidos, TAM_Pedidos);

				break;
			case 12:
				 MostrarClienteMasPedidosCompletados (listaClientes, TAM_Clientes, listaPedidos, TAM_Pedidos);

				break;
			case 13:
				AgregarNuevaLocalidad(listaLocalidades, TAM_Localidades);
				break;
			case 14:
				DarDeBajaUnaLocalidad(listaLocalidades, TAM_Localidades);
				break;

			}
		} while (opcionIngresada !=15);

	return EXIT_SUCCESS;
}











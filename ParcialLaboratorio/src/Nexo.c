


//----------------------------------------------------------------------
#include "Nexo.h"
int CrearPedidoRecoleccion (eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[], int lenPedidos,eLocalidad listaLocalidades[],int lenLocalidad,int *idPedidos)
{
	int retorno;
	retorno =-1;
	int idCliente;
	int indexPedidos;
	float kgsARecolectar;
//falta terminar acaaaa
	printClientes(listaClientes,lenClientes,listaLocalidades,lenLocalidad);

	idCliente = PedirUnEntero("Ingrese el id a buscar: ");
	indexPedidos = FindFreeSpacePedidos(listaPedidos, lenPedidos);

	if(findClienteById(listaClientes, lenClientes, idCliente) != -1)
	{


	utn_getNumeroFlotante(&kgsARecolectar, "Ingrese el la cantidad de kgs a recolectar [0-500kg]: ", "Cantidad Incorrecta, Reingrese: .\n", 0, 500.00, 5);

			listaPedidos[indexPedidos].kilosARecolectar = kgsARecolectar;
			listaPedidos[indexPedidos].idCliente =idCliente;
			listaPedidos[indexPedidos].idPedidos=*idPedidos;
			listaPedidos[indexPedidos].isEmpty =PENDIENTE;

			*idPedidos +=1;
			retorno = 0;
	}else
	{
		printf("No se encontro el id ingresado en la lista \n");
	}


	return retorno;
}
//------------------------------------------------------------------------------------------------------
int printClientesPedidos(eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[],int lenPedidos)
{
	int retorno;
	retorno = -1;

	for (int i = 0; i < lenClientes; ++i)
	{
		for (int j = 0; j < lenPedidos; ++j)
		{
			if(listaClientes[i].id == listaPedidos[j].idCliente && listaPedidos[j].isEmpty == PENDIENTE)
			{ //tengo que acomodar esto mas lindo
				printf("%-7s %-10s %.2f \n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].kilosARecolectar);

				retorno = 0;
			}
		}
	}

	return retorno;
}


int PrintClientesPedidosPendientes (eCliente listaClientes[],int lenClientes,ePedidos listaPedidos[],int lenPedidos)
{
	int retorno;
	retorno = -1;
	printf("Cuit ---------------Direccion--------------Kgs a Recolectar-------Id Pedido \n");
	for (int i = 0; i < lenClientes; ++i)
	{
		if (listaClientes[i].isEmpty == CARGADO)
		{
			for (int j = 0; j < lenPedidos; ++j)
			{

					if(listaPedidos[j].isEmpty == PENDIENTE)
					{
					   if(listaClientes[i].id == listaPedidos[j].idCliente)
					   {
						   printf("---------------------------------------------------------------------------\n");
						   printf("%-18s %-23s %-25.2f %d \n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].kilosARecolectar,listaPedidos[j].idPedidos);

						   retorno = 0;
					   }
					}
			}
		}

	}
	return retorno;
}


//---------------------------------------------------------------------
int case6 (eCliente listaC[],int lenClientes,ePedidos listaPedidos[],int lenPedidos,eLocalidad listL[],int lenlocalidad)
{
	int retorno;
	retorno = -1;
	int contadorPedidosPorCliente;


	printf("Cuit ---------------Direccion--------------Kgs a Recolectar-------Id Pedido \n");
	for (int i = 0; i < lenClientes; ++i)
	{
		if (listaC[i].isEmpty == CARGADO)
		{
			contadorPedidosPorCliente =0;

			for (int j = 0; j < lenPedidos; ++j)
			   {

					if(listaPedidos[j].isEmpty == PENDIENTE)
					{
					   if(listaC[i].id == listaPedidos[j].idCliente)
					   {
						   contadorPedidosPorCliente ++;
						   retorno = 0;
					   }
					}
			   }
		printf("---------------------------------------------------------------------------\n");
		showCliente(listaC[i],listL,lenlocalidad);
		printf("Cantidad de pedidos Pendientes que tiene el cliente: %d \n",contadorPedidosPorCliente);
		}
	}
	return retorno;
}

int PrintPedidosProcesados (eCliente listaC[],int lenC, ePedidos listaP[], int lenP)
{
	int retorno;
	retorno = -1;

	for (int i = 0; i < lenP; ++i)
	{
		if(listaP[i].isEmpty == 1)
			for (int j = 0; j < lenC; ++j)
			{
				if (listaC[j].id == listaP[i].idCliente)
				{
				printf("-------------------------------------------------------------------------------------------\n");
				printf("Cuit            Direccion            HDPE       LPDE        PP \n");
				printf("%-15s %-20s %-10.1f %-10.1f %-10.1f \n", listaC[j].cuit, listaC[j].direccion, listaP[i].residuos.HDPE,
							listaP[i].residuos.LDPE,listaP[i].residuos.PP);
				retorno = 0;
				}
			}
	}


	return retorno;
}
//--------------------------------------------------------------------------------------
int MostrarPedidosPendientesPorLocalidad (eCliente listaC[],int lenC,ePedidos listaP[],int lenP,eLocalidad listL[],int lenL, int indexL)
{
	int retorno;
	retorno = -1;
	int contadorPorLocalidad;

	contadorPorLocalidad = 0;

		for (int i = 0; i < lenC; ++i)
		{
			if(listaC[i].isEmpty == CARGADO && listaC[i].localidad == listL[indexL].iDlocalidad)
			{
				for (int j = 0; j < lenP; ++j)
				{
					if(listaP[j].isEmpty == PENDIENTE && listaC[i].id == listaP[j].idCliente)
					{
						contadorPorLocalidad++;
						retorno = 0;
					}
				}
			}
		}

		printf("Los pedidos pendientes de la siguente localidad %s: %d \n",listL[indexL].localidad,contadorPorLocalidad);

	return retorno;
}
//----------------------------------------------------------------------------------------------------------
int MostrarCantidadDePPReciclado(eCliente listaC[],int lenC,ePedidos listaP[],int lenP)
{
	int retorno;
	retorno =-1;
	float acumuladorPP;
	float contadorClientes;
	float promedio;
	contadorClientes = 0;
	acumuladorPP = 0;


	for (int i = 0; i < lenC; ++i)
	{
		if(listaC[i].isEmpty == CARGADO)
		{
			for (int j = 0; j < lenP; ++j)
			{
				if(listaP[j].isEmpty == 1 && listaP[j].idCliente == listaC[i].id)
				{
					contadorClientes++;
					printf("%f \n",contadorClientes);
					break;
				}
			}
			retorno = 0;
		}
	}

	for (int j = 0; j < lenP; ++j)
	{
		if(listaP[j].isEmpty == CARGADO)
		{
			acumuladorPP = acumuladorPP +listaP[j].residuos.PP;
			printf("%f \n",acumuladorPP);
		}
	}

	promedio = acumuladorPP / contadorClientes;
	printf("La cantidad de kgs reciclados de polipropileno promedio por clientes es :%.2f \n",promedio);


	return retorno;
}


int MostrarClienteMasPedidosPendiente (eCliente listaC[],int lenC,ePedidos listaP[],int lenP)
{
	eAuxiliar contador[lenC];
	int retorno;
	int maximo;
	int flag;
	retorno =-1;

	flag = 1;


	for (int i = 0; i < lenC; ++i)
	{
		if(listaC[i].isEmpty == CARGADO)
		{
			contador[i].contador = 0;
			contador[i].id = listaC[i].id;
		}
	}
//---------------------------------------------------------------------------------------------
	for (int i = 0; i < lenC; ++i)
	{
		if(listaC[i].isEmpty == CARGADO)
		{
			for (int j = 0; j < lenP; ++j)
			{
				if(listaP[j].isEmpty == PENDIENTE && (contador[i].id == listaP[j].idCliente))
				{
					contador[i].contador++;
				}
			}
		}
	}
//---------------------------------------------------------------------------------------------

	for(int i = 0; i < lenC; i++)
	{

		if((contador[i].contador > maximo || flag) && listaC[i].isEmpty == CARGADO)
		{
	       maximo = contador[i].contador;

	       flag = 0;
	    }
	}
//---------------------------------------------------------------------------------------------
	printf("Cliente con más pedidos pendientes es: \n");

	for (int i = 0; i < lenC; ++i)
	{
	 if(maximo == contador[i].contador)
	 {
		 printf("%s \n",listaC[i].nombreEmpresa);

	 }

	}


	return retorno;
}

//---------------------------------------------------------------------------------------------
int MostrarClienteMasPedidosCompletados (eCliente listaC[],int lenC,ePedidos listaP[],int lenP)
{
	eAuxiliar contador[lenC];
	int retorno;
	int maximo;
	int flag;
	retorno =-1;

	flag = 1;


	for (int i = 0; i < lenC; ++i)
	{
		if(listaC[i].isEmpty == CARGADO)
		{
			contador[i].contador = 0;
			contador[i].id = listaC[i].id;
		}
	}
//---------------------------------------------------------------------------------------------
	for (int i = 0; i < lenC; ++i)
	{
		if(listaC[i].isEmpty == CARGADO)
		{
			for (int j = 0; j < lenP; ++j)
			{
				if(listaP[j].isEmpty == 1 && (contador[i].id == listaP[j].idCliente))
				{
					contador[i].contador++;

				}
			}
		}
	}
//---------------------------------------------------------------------------------------------

	for(int i = 0; i < lenC; i++)
	{

		if((contador[i].contador > maximo || flag) && listaC[i].isEmpty == CARGADO)
		{
	       maximo = contador[i].contador;

	       flag = 0;
	    }
	}
//---------------------------------------------------------------------------------------------
	printf("Cliente con más pedidos pendientes es: \n");

	for (int i = 0; i < lenC; ++i)
	{
	 if(maximo == contador[i].contador)
	 {
		 printf("%s \n",listaC[i].nombreEmpresa);

	 }

	}

	return retorno;
}








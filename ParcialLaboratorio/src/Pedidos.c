#include "Pedidos.h"
//----------------------------------------------------------------------
int InicializarArrayPedidos(ePedidos lista[],int len)
{
	for (int i; i < len; i++)
	{
		lista[i].isEmpty = VACIO;
	}
	return 0;
}


//-----------------------------------------------------------------------------
int FindFreeSpacePedidos (ePedidos lista[],int len)
{
	int retorno;
	int i;

	retorno = -1;

	for (i = 0; i < len; i++)
	{
		if (lista[i].isEmpty == VACIO)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------
void showPedido(ePedidos lista)
{
   printf("%-7d %-10.2f  \n", lista.idPedidos, lista.kilosARecolectar);

}
//---------------------------------------------------------------------------------------
/*int PrintPedidosCase6(ePedidos list[], int len)
{
	printf("\n---------------------- Lista De Empleados ---------------------- \n");
	printf(" Id     Nombre     Cuit            Direccion            Localidad\n");

	for (int i = 0; i<len; i++)
	{
		if (list[i].isEmpty == PENDIENTE)
		{
			showPedido(list[i]);
		}
	}
	printf("\n___________________________________________________________________________\n");
	return 0;
}*/
//---------------------------------------------------------------------------------------
int GenerarIdPedidos (int id)
{
    id++;
    return id;
}
void HarcodearPedidos (ePedidos lista[],int len)
{
	ePedidos listaHardcodeada[] =
			{{993,101,{10,25,30},38,1},
			{992,102,{12,29,33},380,2},
			{999,102,{15,21,20},350,2},
			{994,103,{0,0,0},450,2},//
			{995,102,{0,0,0},210,1}};


	for (int i = 0;i < 5; i++)
	{
		lista[i]=listaHardcodeada[i];
	}
}
//-------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
int BuscarIdPedidos(ePedidos list[], int len,int id)
{
	int retorno;

	retorno = -1;

	for (int i = 0; i < len; ++i)
	{
		if(list[i].idPedidos == id)
		{
			retorno = i;
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------
int IngresarKgsResiduos (ePedidos lista[], int len, int index)
{
	int opcionMenu;
	float hdpe;
	float lpde;
	float pp;
	int retorno;
	float kgsTotales;
	lista[index].residuos.HDPE = 0;
	lista[index].residuos.LDPE = 0;
	lista[index].residuos.PP = 0;

	kgsTotales = lista[index].kilosARecolectar;

	retorno =-1;
	do {
		printf("Ingrese el tipo de plastico que desea procesar \n 1)HDPE -Polietileno de alta densidad- \n 2)LPDE -Polietileno de baja densidad \n 3)PP -Polipropileno- \n 4) SALIR \n");
		opcionMenu = PedirUnEnteroRango("Ingrese una opcion: ",1, 4);

		switch (opcionMenu)
		{

			case 1:
				printf("------------------------------------------------------\n");
				printf("Cantidad de kgs Disponibles para procesar es = %.2f \n",kgsTotales);
				printf("------------------------------------------------------\n");
				utn_getNumeroFlotante(&hdpe, "Ingrese la cantidad de Kgs de HDPE: \n", "Error:",0,kgsTotales,10);
				lista[index].residuos.HDPE = hdpe;
				kgsTotales = kgsTotales - hdpe;
				break;
			case 2:
				printf("------------------------------------------------------\n");
				printf("Cantidad de kgs Disponibles para procesar es = %.2f \n",kgsTotales);
				printf("------------------------------------------------------\n");
				utn_getNumeroFlotante(&lpde, "Ingrese la cantidad de Kgs de LPDE: \n", "Error:",0,kgsTotales,10);
				lista[index].residuos.LDPE = lpde;
				kgsTotales = kgsTotales - lpde;
				break;
			case 3:
				printf("------------------------------------------------------\n");
				printf("Cantidad de kgs Disponibles para procesar es = %.2f \n",kgsTotales);
				printf("------------------------------------------------------\n");
				utn_getNumeroFlotante(&pp, "Ingrese la cantidad de Kgs de PP: \n", "Error:",0,kgsTotales,10);
				lista[index].residuos.PP = pp;
				kgsTotales = kgsTotales - pp;
				break;

		}

		lista[index].isEmpty= CARGADO;
		retorno = 0;

	} while (opcionMenu != 4 && kgsTotales > 0);
	printf("-----------------------------------------\n");
	printf("No hay mas kgs disponibles para procesar \n");

return retorno;
}

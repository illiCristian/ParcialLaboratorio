

#include "Localidad.h"

//Pasar a localidad.h
//-----------------------------------------------------------------------------------
int InicializarArrayLocalidad(eLocalidad lista[],int len)
{
	for (int i; i < len; i++)
	{
		lista[i].isEmpty = VACIO;
	}
	return 0;
}

//-----------------------------------------------------------------------------
int FindFreeSpaceLocalidad (eLocalidad lista[],int len)
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


//----------------------------------------------------------------------------------------------
void CargarLocalidades (eLocalidad lista[],int len)
{
	eLocalidad listaHardcodeada[] = {{1,"Avellaneda",1},{2,"Quilmes",1},{3,"Lanus",1},{4,"Berazategui",1},{5,"Monte Grande",1},{6,"Ezpeleta",1}, {7,"Hudson"},{8,"Platanos",1}, {9,"Pereira",1},{10,"Villa Elisa",1}};
	for (int i = 0; i < len; i++)
	{
		lista[i]=listaHardcodeada[i];
	}
}
void MostrarLocalidad(eLocalidad lista)
//------------------------------------------------------------------------------------------------
{
   printf("%-5d %-10s",lista.iDlocalidad,lista.localidad);
}
//---------------------------------------------------------------------------------------
int ImprimirLocalidades(eLocalidad list[], int len)
{
	printf("\n------- Lista De Localidades --------- \n");
	printf("--  Localidades Disponibles\n");

	for (int i = 0; i<len; i++)
	{

			MostrarLocalidad(list[i]);
			printf("\n");
	}
	printf("\n___________________________________________________________________________\n");
	return 0;
}
//----------------------------------------------------------------------------------------------
int findLocalidadById(eLocalidad list[], int len,int id)
{
	int index;

	index = -1;

	for (int i = 0; i < len; ++i)
	{
		if(list[i].iDlocalidad == id)
		{
			index = i;
		}
	}
	return index;
}
//------------------------------------------------------------------------------------------
void AgregarNuevaLocalidad(eLocalidad list[], int lenLocalidad)
{
	int respuesta;
	int index;
	char nuevaLocalidad[51];


	respuesta = PedirUnEntero("Desea añadir una nueva localidad al sistema? 1 Para confirmar, 2 para salir");
		{
			if (respuesta == 1)
			{
				index = FindFreeSpaceLocalidad(list, lenLocalidad);
				if(index != -1)
				{
					list[index].iDlocalidad = PedirUnEntero("Ingrese el ID de la nueva localidad");
					PedirCadenaB(nuevaLocalidad, "Ingrese el nombre de la nueva localidad");
					strcpy(list[index].localidad,nuevaLocalidad);
					list[index].isEmpty = 1;
				}
			}
		}

}
//------------------------------------------------------------------------------------------
int DarDeBajaUnaLocalidad (eLocalidad list[], int lenLocalidad)
{
	int retorno;
	retorno = -1;
	int idAborrar;
	int respuesta;
	int idABuscar;

	ImprimirLocalidades(list, lenLocalidad);

	idABuscar = PedirUnEntero("Ingrese el id de la localidad que desea borrar");
	idAborrar = findLocalidadById(list, lenLocalidad, idABuscar);
	if (idAborrar != -1)
	{

		respuesta = PedirUnEntero("¿Esta seguro que desea borrar la localidad 1 para confirmar \n");
		if(respuesta == 1)
		{
			list[idAborrar].isEmpty = VACIO;
			printf("Se borro la localidad correctamente \n");
			retorno = 0;
		}
		else{
			printf("No se borro el empleado \n");
		}
	}
	return retorno;
}

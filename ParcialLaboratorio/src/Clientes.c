/*
 * Clientes.c
 *
 *  Created on: 12 oct 2021
 *      Author: Cris
 */
#include "Clientes.h"

//-----------------------------------------------------------------------------
int InicializarArray(eCliente lista[],int len)
{
	for (int i; i < len; i++)
	{
		lista[i].isEmpty = VACIO;
	}
	return 0;
}
//-----------------------------------------------------------------------------
int FindFreeSpace (eCliente lista[],int len)
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
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void PedirListaCliente (eCliente lista[], int len, int id,eLocalidad listaLocalidad[],int lenLocalidad)
{

		char nombreEmpresa[51];
		char  cuit[51];
		char direccion[51];
		int localidad;

	PedirCadenaB(nombreEmpresa, "Ingrese el nombre de la empresa: ");
	PedirCadenaB(cuit,"Ingrese el Cuit: ");
	PedirCadenaB(direccion, "Ingrese la direccion: ");

	ImprimirLocalidades(listaLocalidad, lenLocalidad);
	localidad = PedirUnEntero("Ingrese un numero para indicar la localidad");

	if(addCliente(lista, len, id, nombreEmpresa, cuit, direccion, localidad) != -1)
		{
			printf("Se cargo el empleado exitoxamente con la ID %d \n",id);
		}
	else
		{
			printf("No se puede cargar mas datos por que no hay espacio libre \n");
		}
}




//-----------------------------------------------------------------------------

int addCliente(eCliente list[], int len, int id, char nombreEmpresa[],char cuit[],char direccion[],int localidad)
{
	int index;
	int retorno;


	retorno = -1;

	index = FindFreeSpace(list,len);

	if (index != -1)
	{
		list[index].id = id;
		strcpy(list[index].nombreEmpresa,nombreEmpresa);
		strcpy(list[index].cuit,cuit);
		strcpy(list[index].direccion,direccion);
		list[index].localidad = localidad;
		list[index].isEmpty = CARGADO;
		retorno = 0;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------
int GenerarId (int id)
{
    id++;
    return id;
}
//-------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void showCliente(eCliente lista, eLocalidad localidad[],int lenLocalidad)
{
	for (int i = 0; i <lenLocalidad ; ++i)
	{
		if(lista.localidad == localidad[i].iDlocalidad) //TENGO QUE CAMBIAR LOS NOMBRES DE LOCALIDAD
		{
			printf("%-7d %-10s %-15s %-20s %s \n", lista.id, lista.nombreEmpresa,lista.cuit,lista.direccion,localidad[i].localidad);
		}
	}
}

//---------------------------------------------------------------------------------------
int printClientes(eCliente list[], int len, eLocalidad listaLocalidad[],int lenLocalidad)
{
	printf("\n---------------------- Lista De Clientes --------------------------- \n");
	printf(" Id     Nombre     Cuit            Direccion            Localidad\n");

	for (int i = 0; i<len; i++)
	{
		if (list[i].isEmpty == CARGADO)
		{
			printf("--------------------------------------------------------------------\n");
			showCliente(list[i],listaLocalidad,lenLocalidad);

		}
	}
	printf("\n___________________________________________________________________________\n");
	return 0;
}

//----------------------------------------------------------------------------------------------
void HarcodearClientes (eCliente lista[],int len)
{
	eCliente listaHardcodeada[] =
			{{100,"Empresa1","180001112223","Av San Martin 3456",1,1},
			{101,"Empresa2","252221112223","Av Nazca 2534",4,1},
			{102,"Empresa3","362581112587","Av Los Lagos 213",2,1},
			{104,"Empresa4","180069982375","Av Flotante 3.14",3,1},
			{103,"Empresa5","280536837511","Av Flotante 3.14",10,1}};

	for (int i = 0;i < 5; i++)
	{
		lista[i]=listaHardcodeada[i];
	}
}
//----------------------------------------------------------------------------------------------
int findClienteById(eCliente list[], int len,int id)
{
	int index;

	index = -1;

	for (int i = 0; i < len; ++i)
	{
		if(list[i].id == id)
		{
			index = i;
		}
	}
	return index;
}
//----------------------------------------------------------------------------------------------
void ModificarCliente(eCliente list[],int index, eLocalidad listaLocalidad[],int lenLocalidad)
{
	char direccion[51];
	int localidad;


					PedirCadenaB(direccion, "Ingrese la direccion: ");
					ImprimirLocalidades(listaLocalidad, lenLocalidad);
					localidad = PedirUnEntero("Ingrese un numero para indicar la localidad");
					strcpy(list[index].direccion,direccion);
					list[index].localidad= localidad;

					printf("\nSe modificaron correctamente los datos del empleado \n");

}


//--------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
int removeCliente(eCliente list[], int len, int id)
{
	int retorno;
	retorno = -1;
	int idAborrar;
	int respuesta;

	idAborrar = findClienteById(list, len, id);
	if (idAborrar != -1)
	{

		respuesta = PedirUnEntero("¿Esta seguro que desea borrar el Cliente? 1 para confirmar \n");
		if(respuesta == 1)
		{
			list[idAborrar].isEmpty = VACIO;
			printf("Se borro el Cliente correctamente \n");
			retorno = 0;
		}
		else{
			printf("No se borro el empleado \n");
		}
	}
	return retorno;
}
//------------------------------------------------------------




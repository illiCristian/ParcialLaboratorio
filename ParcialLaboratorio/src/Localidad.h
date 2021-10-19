

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include "Input.h"

#define CARGADO 1
#define VACIO 0


typedef struct
{
	int iDlocalidad;
	char localidad[50];
	int isEmpty;
}eLocalidad;


/// @fn int FindFreeSpaceLocalidad(eLocalidad[], int)
/// @brief Encuentra un lugar libre y lo devuelve para ser usado como index
/// @param lista
/// @param len
/// @return Una posicion para ser usada como index
int FindFreeSpaceLocalidad (eLocalidad lista[],int len);
/// @fn int InicializarArrayLocalidad(eLocalidad[], int)
/// @brief Inicializa el array para que todas las posiciones sean vacias
/// @param lista
/// @param len
/// @return Un valor de verdad
int InicializarArrayLocalidad(eLocalidad lista[],int len);
/// @fn void CargarLocalidades(eLocalidad[], int)
/// @brief Inicializa el array para que todas las posiciones sean vacias
/// @param lista
/// @param len
void CargarLocalidades (eLocalidad lista[],int len);
/// @fn void MostrarLocalidad(eLocalidad)
/// @brief
/// @param lista
void MostrarLocalidad(eLocalidad lista);
/// @fn int ImprimirLocalidades(eLocalidad[], int)
/// @brief
/// @param list
/// @param len
/// @return
int ImprimirLocalidades(eLocalidad list[], int len);
/// @fn int findLocalidadById(eLocalidad[], int, int)
/// @brief  Busca una id cargada en el array
/// @param list
/// @param len
/// @param id Parametro a buscar
/// @return Retorna un valor de verdad si encontro la id o no la encontro
int findLocalidadById(eLocalidad list[], int len,int id);
/// @fn void AgregarNuevaLocalidad(eLocalidad[], int)
/// @brief
/// @param list
/// @param lenLocalidad
void AgregarNuevaLocalidad(eLocalidad list[], int lenLocalidad);
/// @fn int DarDeBajaUnaLocalidad(eLocalidad[], int)
/// @brief
/// @param list
/// @param lenLocalidad
/// @return
int DarDeBajaUnaLocalidad (eLocalidad list[], int lenLocalidad);


#endif /* LOCALIDAD_H_ */

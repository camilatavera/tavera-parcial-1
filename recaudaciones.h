/*
 * recaudaciones.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

typedef struct{
	int idContribuyente;
	int mes;
	int tipo; //1)ARBA 2)IIBB 3)GANANCIAS
	int idRecaudacion;
	int estado;
	int isEmpty;
}recaudacion;

#include "contribuyente.h"

int listadoTiposRecaudaciones(void);

int recaudacionIsEmpty(recaudacion *list, int len);

int initRecaudaciones(recaudacion* list, int len);

int buscarLibreAviso(recaudacion *array, int leng, int *posicionLibre);

int ingresarValoresRecaudacion(recaudacion *bufferAviso, contribuyente *list, int len);

int addRecaudacion(recaudacion* aRecaudacion, int lenRecaudacion, contribuyente* aContribuyente

		int addRecaudacion(recaudacion* aRecaudacion, int lenRecaudacion, contribuyente* aContribuyente,
				int lenContribuyente, int idRecaudacion);

int printIdRecaudaciones(int id);

int bajaRecaudacionByIdContribuyente(recaudacion *list, int len, int idContribuyente);


int listarRecaudacionesByIdContribuyente(recaudacion *list, int len, int idContribuyente);

int getDescripcionTipo(int nTipo, char *descTipo);

int getIdRecaudacionValido(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos);

int findRecaudacionById(recaudacion *list, int len, int id, int *posicion);

int refinanciarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente);


int saldarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente);
#endif /* RECAUDACIONES_H_ */



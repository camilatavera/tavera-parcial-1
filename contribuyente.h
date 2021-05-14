/*
 * contribuyente.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#define LEN_STR 15


typedef struct{
	char nombre[LEN_STR];
	char apellido[LEN_STR];
	char cuil[LEN_STR];
	int id;
	int isEmpty;

}contribuyente;

#include "getsDatos.h"
#include "recaudacion.h"

int initContribuyente(contribuyente* list, int len);

int buscarLibreContribuyente(contribuyente *array, int leng, int *posicionLibre);

int ingresarValoresContribuyente(contribuyente *bufferContribuyente);
int addContribuyente(contribuyente* list, int len, int id);


int printIdContribuyente(int id);


int listarContribuyentes(contribuyente *list, int len);

int printContribuyente(contribuyente *list, int len, int idContribuyente);


int getIdContribuyenteValido(contribuyente *list, int len, int* pResultado, char* mensaje, char* mensajeError,
							int reintento);

int FindConstribuyenteById(contribuyente *list, int len, int id, int *posicion);

int modificarContribuyente(contribuyente *list, int len);


int contribuyenteIsEmpty(contribuyente *list, int len);

int bajaContribuyente(contribuyente *aContribuyente, int lenContribuyente,
						recaudacion *aRecaudacion, int lenRecaudacion);

#endif /* CONTRIBUYENTE_H_ */

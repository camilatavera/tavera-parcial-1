/*
 * recaudaciones.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#include "recaudaciones.h"
#define REFINANCIAR 0
#define SALDADA -1
#define ACTIVA 1


int listadoTiposRecaudaciones(void){
	int ret=-1;
	printf("1. ARBA   2.IIBB  3.GANANCIAS\n");
	ret=0;
	return ret;
}



int recaudacionIsEmpty(recaudacion *list, int len){

	int ret=-1;
	if(list!=NULL && len>0){
		ret=1;

		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0){
				ret=0;
				break;
			}
		}
	}
	return ret;
}



int initRecaudaciones(recaudacion* list, int len){
	int ret=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0; i<len; i++){
			list[i].isEmpty=1;
		}
		ret=0;
	}
	return ret;
}



int buscarLibreAviso(recaudacion *array, int leng, int *posicionLibre){
	int i;
	int ret=-1;

	if(array!=NULL && leng>0){
		for(i=0; i<leng; i++){
				if(array[i].isEmpty==1){
					*posicionLibre=i;
					ret=0;
					break;
				}
		}
	}
	return ret;
}


int ingresarValoresRecaudacion(recaudacion *bufferAviso, contribuyente *list, int len){

	int ret=-1;
	recaudacion auxAviso;


	if(bufferAviso!=NULL && list!=NULL && len>0){

		if(getIdValido(list, len, &auxAviso.idContribuyente, "Ingrese el id del contribuyente\n",
				"Error. ", 15)==0 &&

			listadoTiposRecaudaciones()==0 &&
			getNumero(&auxAviso.tipo, "Ingrese el tipo de recaudacion\n", "Error. ",
					1, 3, 20)==0 ){

					*bufferAviso=auxAviso;
					ret=0;
			}
	}
	return ret;
}




int addRecaudacion(recaudacion* aRecaudacion, int lenRecaudacion, contribuyente* aContribuyente,
		int lenContribuyente, int idRecaudacion){

	int ret=-1;
	int posicion;

	recaudacion bufferRec;


	if(aRecaudacion!=NULL && lenRecaudacion>0 && aContribuyente!=NULL && lenContribuyente>0){

		if(buscarLibreRecaudacion(aRecaudacion, lenRecaudacion, &posicion)==0 &&
			ingresarValoresRecaudacion(&bufferRec, aContribuyente, lenContribuyente)==0){

			aRecaudacion[posicion]=bufferRec;
			aRecaudacion[posicion].idRecaudacion=idRecaudacion;
			aRecaudacion[posicion].estado=ACTIVA;
			aRecaudacion[posicion].isEmpty=0;
			ret=0;
		}
	}
	return ret;
}


int printIdRecaudaciones(int id){
	int ret=-1;
	printf("El id de la recaudacion es %d", id);
	ret=0;
	return ret;
}


int bajaRecaudacionByIdContribuyente(recaudacion *list, int len, int idContribuyente){

	int ret=-1;

	if(list!=NULL && len>0){

		for(int i=0; i<len; i++){

			if(list[i].isEmpty==0 && list[i].idContribuyente==idContribuyente){
				list[i].isEmpty=1;
				ret=0;
			}
		}
	}
	return ret;
}

int listarRecaudacionesByIdContribuyente(recaudacion *list, int len, int idContribuyente){

	int ret=-1;
	int i;
	char descTipo[LEN_STR];

	if(list!=NULL && len>0){
		ret=0;
		printf("Mes        Tipo           Id Recaudacion\n");

		for(i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].idContribuyente==idContribuyente){

				getDescripcionTipo(list[i].tipo, descTipo);

				printf("%-3d       %-4s          %s\n", list[i].mes, descTipo,
														list[i].idRecaudacion);
			}
		}
	}
	return ret;
}


int getDescripcionTipo(int nTipo, char *descTipo){


	int ret=-1;
	if(descTipo!=NULL){
		ret=0;

		switch(nTipo){
		case 1:
			descTipo="ARBA";
			break;
		case 2:
			descTipo="IIBB";
			break;
		case 3:
			descTipo="GANANCIAS";
			break;
		}
	}
	return ret;
}

int getIdRecaudacionValido(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos){

	 int ret=-1;
	 int bufferInt;
	 int i;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0){
			 reintentos--;
			 printf("%s", mensaje);

			 if(getInt(&bufferInt)==0){

				 for(i=0; i<len; i++){
					 if(list[i].idRecaudacion==bufferInt && list[i].isEmpty==0){

						 *pResultado = bufferInt;
						  ret=0;
						  break;
					 }
					 else{
						 fflush(stdin);
						 printf("%s", mensajeError);
					 }
				 }
			 }
		 }
	 }
	 return ret;
}



int findRecaudacionById(recaudacion *list, int len, int id, int *posicion){

	int ret=-1;
	int i;
	if(list!=NULL && len>0 && posicion!=NULL){

		for(i=0; i<len; i++){


			if(list[i].isEmpty==0 && list[i].idRecaudacion==id){
				*posicion=i;
				ret=0;
				break;
			}
		}
	}
	return ret;
}





int refinanciarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int idRecaudacion;
	int idContribuyente
	int posRec;
	char seguir;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

			if(getIdRecaudacionValido(aRecaudacion, lenRecaudacion, &idRecaudacion,
					"Ingrese el id de la recaudacion\n", "Error. ", 15)==0 &&
				findRecaudacionById(aRecaudacion, lenRecaudacion, idRecaudacion, &posRec)==0){

					idContribuyente=aRecaudacion[posRec].idContribuyente;

					printContribuyente(aContribuyente, lenContribuyente, idContribuyente);

					validarChar(&seguir, "Quiere cambiar el estado a REFINANCIAR? Ingrese 's':si o 'n':no\n", "Error",
													's', 'n', 20);

					if(seguir=='s'){
						aRecaudacion[posRec].estado=REFINANCIAR;
						ret=0;
					}
					else{
						ret=1;
					}
			}
		}
		return ret;
}



int saldarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int idRecaudacion;
	int idContribuyente
	int posRec;
	char seguir;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

			if(getIdRecaudacionValido(aRecaudacion, lenRecaudacion, &idRecaudacion,
					"Ingrese el id de la recaudacion\n", "Error. ", 15)==0 &&
				findRecaudacionById(aRecaudacion, lenRecaudacion, idRecaudacion, &posRec)==0){

					idContribuyente=aRecaudacion[posRec].idContribuyente;

					printContribuyente(aContribuyente, lenContribuyente, idContribuyente);

					validarChar(&seguir, "Quiere cambiar el estado a SALDADO? Ingrese 's':si o 'n':no\n", "Error",
													's', 'n', 20);

					if(seguir=='s'){
						aRecaudacion[posRec].estado=SALDADA;
						ret=0;
					}
					else{
						ret=1;
					}
			}
		}
		return ret;
}




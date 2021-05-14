/*
 * menu.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */


#include "menu.h"




int listadoMenu(void){
	printf("Menu:\n1. ALTA PANTALLA\n2. MODIFICAR PANTALLA\n3. BAJA PANTALLA\n4. CONTRATAR PUBLICIDAD\n"
			"5. MODIFICAR PUBLICIDAD\n6. CANCELAR PUBLICACION\n7. CONSULTA FACTURACION\n"
			"8. LISTAR CONTRATACION\n9. LISTAR PANTALLAS\n10. INFORMAR \n11. SALIR");
	return 0;
}

void listadoInformes(void){
	printf("Menu:\n1. Lista de cada cliente con cantidad de contrataciones e importe a pagar por cada una.\n"
			"2. 2. Cliente con importe más alto a facturar\n");
}

int menu(int opcionIngresada, contribuyente *aContribuyente, int lenContribuyente,
		int *idIncrementalCont, recaudacion *aRecaudacion, int lenRecaudacion,
		int *idIncrementalRecau){

	int ret=-1;
	int idContribuyente=*idIncrementalCont;
	int idRecaudacion=*idIncrementalRecau;


	if(aContribuyente!=NULL && lenContribuyente>0 && idPantalla!=NULL && lenTipo>0 && aTipo!=NULL){


		switch(opcionIngresada){
			case 1:
				if(addContribuyente(aContribuyente, lenContribuyente, idContribuyente)==0){
					printIdContribuyente(idContribuyente);
					(*idIncrementalCont)++;
				}
				break;
			case 2:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0){
					modificarContribuyente(aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay contribuyentes de alta para modificar\n");
				}
				break;
			case 3:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0){
					bajaContribuyente(aContribuyente, lenContribuyente, aRecaudacion, lenRecaudacion);
				}
				else{
					printf("No hay contribuyentes activos para dar de baja\n");
					}
				break;
			case 4:
				if(addRecaudacion(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente,
						idRecaudacion)==0){
					printIdRecaudaciones(idRecaudacion);
					(*idIncrementalRecau)++;
				}
				break;
			case 5:
				if(recaudacionIsEmpty(aRecaudacion, lenRecaudacion)==0){
					refinanciarRecaudacion(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay recaudaciones activas para refinanciar");
				}
				break;

			case 6:
				if(reanudarAviso(aAviso, lenAviso, aCliente, lenCliente)==0){
					printf("El aviso se activo exitosamente");
				}
				break;
			case 7:
				printClientes(aCliente, lenCliente, aAviso, lenAviso);
				break;
			case 8:
				submenuInformes(aCliente, lenCliente, aAviso, lenAviso);
				break;
			}//cierro switch
		ret=0;
	}
	return ret;
}

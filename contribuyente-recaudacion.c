/*
 ============================================================================
 Name        : contribuyente-recaudacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "menu.h"
#define MAX_CONTRIBUYENTE 50
#define MAX_RECAUDACION 50


int main(void) {


	setbuf(stdout, NULL);

		int opcion;
		int idContribuyenteIncremental=1000;
		int idRecaudacionIncremental=100;

		contribuyente aContribuyente[MAX_CONTRIBUYENTE];
		recaudacion aRecaudacion[MAX_RECAUDACION];

		initContribuyente(aContribuyente, MAX_CONTRIBUYENTE);
		initRecaudaciones(aRecaudacion, MAX_RECAUDACION);

		do{

			getNumero(&opcion, "ingrese\n", "Error. ", 1, 10, 15);
			menu(opcion, aContribuyente, MAX_CONTRIBUYENTE, &idContribuyenteIncremental,
					aRecaudacion, MAX_RECAUDACION, &idRecaudacionIncremental);
		}while(opcion!=10);

		return 0;
}

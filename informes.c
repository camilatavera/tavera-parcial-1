/*
 * informes.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */


int listarContrib_Recaud(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

		int listarContribuyentes(contribuyente *list, int len){

			int ret=-1;
			int i;
			if(list!=NULL && len>0){
				printf("Nombre         Apellido       Cuil        Id     Id\n");
				ret=0;

				for(i=0; i<len; i++){
					if(list[i].isEmpty==0){
						printf("%-10s    %-10s    %-10s     %d\n",  list[i].nombre,
																	list[i].apellido,
																	list[i].cuil
																	list[i].id);

					}
				}
			}
			return ret;
		}


	}
}


int listarRecaudacionesSaldadas(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int i;
	int posContribuyente;


	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){


	if(list!=NULL && len>0){
		printf("RECAUDACIONES SALDADAS\n");
		printf("id Recaudacion      Nombre contribuyente       Cuil           \n");
		ret=0;

		for(i=0; i<len; i++){
			if(aRecaudacion[i].estado==SALDADA){
				FindConstribuyenteById(aContribuyente, lenContribuyente, id, &posContribuyente)

				printf("%-10s    %-10s    %-10s     %d\n",  aRecaudacion[i].idRecaudacion,
															aContribuyente[posContribuyente].nombre,
															aContribuyente[posContribuyente].cuil
															aContribuyente[posContribuyente].cuil);

			}
		}
	}
	return ret;
}

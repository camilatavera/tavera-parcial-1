/*
 * informes.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "recaudaciones.h"

int listarRecaudacionesSaldadas(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);

#endif /* INFORMES_H_ */

/*************************************************************************/
/*                                                                       */
/*   modelado.h                                                          */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castellón             */
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

#include "glut.h"

/* Identificadores de las display lists */
GLuint arco, arcos, adoquinado_simple, seccion_adoquinado, pasillo_simple,
pasillo_central, pasillo_vertical, pasillo_horizontal, escalon, escalera,
seccion_suelo, suelo, puerta, ventana, ventana_balcon, tejas, tejado_simple,
pared_puerta, pared_simple, persona, escena;


/* Funciones de modelado */
/* Crea las distintas display lists */
void IniciaDisplayLists (void);

/* Dibuja la escena */
void DibujaEscena (void);

/* Crea una display list para un arco */
void CreaArco (void);

/* Crea una display list para todos los arcos */
void CreaArcos (void);

/* Crea una display list para el adoquinado */
void CreaAdoquinadoSimple(void);

/* Crea una display list para la seccion adoquinada del suelo */
void CreaSeccionAdoquinado(void);

void CreaPasilloSimple(void);

void CreaPasilloCentral(void);

void CreaPasilloVertical(void);

void CreaPasilloHorizontal(void);

void CreaEscalon(void);

void CreaEscalera(void);

void CreaSeccionSuelo(void);

/* Crea una display list para el suelo */
void CreaSuelo(void);

void CreaPuerta(void);

void CreaVentana(void);

void CreaVentanaBalcon(void);

void CreaTejas(void);

void CreaTejadoSimple(void);

void CreaParedPuerta(void);

void CreaParedSimple(void);

/* Crea una display list para la persona */
void CreaPersona(void);

/*  Crea una display list para toda la escena */
void CreaEscena(void);





#endif
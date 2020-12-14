/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castellón             */
/*                                                                       */
/*************************************************************************/

#include <stdio.h>
#include "glig.h"
#include "modelado.h"


/******************************************************************************************/
/* Crea las distintas display lists                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{
	CreaArco ();
	CreaArcos ();
	CreaPasilloSimple();
	CreaPasilloCentral();
	CreaPasilloPequenho();
	CreaAdoquinadoSimple();
	CreaSeccionAdoquinado();
	CreaSeccionSuelo();
	CreaSuelo();
	CreaParedSimple();
	CreaPersona();
	CreaEscena ();
}


/******************************************************************************************/
/* Dibuja la escena                                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void DibujaEscena (void)
{
	glCallList (escena);
}


/******************************************************************************************/
/* Crea una display list para un arco                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaArco (void)
{
	arco = glGenLists (1);

	if (arco != 0)
	{
		glNewList (arco, GL_COMPILE);
		glPushMatrix();
			glTranslatef(0.75,0.0,0.0);
			glScalef(0.5,2.0,0.5);
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.75,0.0,0.0);
			glScalef(0.5,2.0,0.5);
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0,0.75,0.0);
			glScalef(2.0,0.5,0.5);
			igSolidCube();
		glPopMatrix();
		glEndList ();
	}
	else puts ("Se ha producido un error creando la display list para un arco.");
}


/******************************************************************************************/
/* Crea una display list para todos los arcos                                             */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaArcos (void)
{
	int i;

	arcos = glGenLists (1);

	if (arcos != 0)
	{
		glNewList (arcos, GL_COMPILE);
		glScalef(0.9,0.9,0.9);
		for(i = 0; i < 12; i++)
		{
			glPushMatrix();
				glRotatef(i*30.0,0.0,1.0,0.0);
				glTranslatef(0.0,0.0,-2.0);
				glScalef(0.5,0.5,0.5);
				/*arco();*/
				glCallList (arco);
			glPopMatrix();
		}
		glEndList ();
	}
	else puts ("Se ha producido un error creando la display list para los arcos.");
}

void CreaPasilloSimple(void)
{
	pasillo_simple = glGenLists(1);

	if (pasillo_simple != 0)
	{
		glNewList(pasillo_simple, GL_COMPILE);
			glPushMatrix();
				glTranslatef(0.0, 0, 0.0); //posición: lados,altura,profundidad
				glScalef(1, 0.01, 0.5); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un pasillo simple.");
}

void CreaPasilloCentral(void)
{
	int i;
	int j;

	pasillo_central = glGenLists(1);

	if (pasillo_central != 0)
	{
		glNewList(pasillo_central, GL_COMPILE);

		float profundidad = 0;
		for (j = 0; j < 19; j++) {
			glPushMatrix();
				glTranslatef(0.0, 0.0, profundidad);
				glCallList(pasillo_simple);
			glPopMatrix();
			profundidad = profundidad + 0.6;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una seccion adoquinado.");
}

void CreaPasilloPequenho(void)
{
	int i;
	int j;

	pasillo_pequenho = glGenLists(1);

	if (pasillo_pequenho != 0)
	{
		glNewList(pasillo_pequenho, GL_COMPILE);

		float profundidad = 0;
		for (j = 0; j < 19; j++) {
			glPushMatrix();
			glTranslatef(0.0, 0.0, profundidad);
			glCallList(pasillo_simple);
			glPopMatrix();
			profundidad = profundidad + 0.6;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una seccion adoquinado.");
}


void CreaAdoquinadoSimple(void)
{
	adoquinado_simple = glGenLists(1);

	if (adoquinado_simple != 0)
	{
		glNewList(adoquinado_simple, GL_COMPILE);
			glPushMatrix();
				glTranslatef(0, 0, 0.0); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.1, 0, 0.0); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 0, 0.1); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.1, 0, 0.1); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un adoquinado.");
}

void CreaSeccionAdoquinado(void)
{
	int i;
	int j;

	seccion_adoquinado = glGenLists(1);

	if (seccion_adoquinado != 0)
	{
		glNewList(seccion_adoquinado, GL_COMPILE);
		float lado = 0;
		float profundidad = 0;
		for (j = 0; j < 10; j++) {
			for (i = 0; i < 10; i++)
			{
				glPushMatrix();
					glTranslatef(lado, 0.0, profundidad);
					glCallList(adoquinado_simple);
				glPopMatrix();
				lado = lado + 0.22;
			}
			lado = 0;
			profundidad = profundidad + 0.24;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una seccion adoquinado.");
}

void CreaSeccionSuelo(void)
{
	int i;
	int j;

	seccion_suelo = glGenLists(1);

	if (seccion_suelo != 0)
	{
		glNewList(seccion_suelo, GL_COMPILE);
		float lado = 0;
		float profundidad = 0;
		float profundidad_pasillo_h = 2.63;
		float profundidad_pasillo_v = 2.63;
		for (j = 0; j < 4; j++) {
			for (i = 0; i < 4; i++)
			{
				glPushMatrix();
					glTranslatef(lado, 0.0, profundidad);
					glCallList(seccion_adoquinado);
				glPopMatrix();
				lado = lado + 3;
				glPushMatrix();
					glTranslatef(0.0, 0.0, profundidad_pasillo_v); //posición: lados,altura,profundidad
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					glScalef(0.5, 1.0, 1.0); //tamaño: lados,altura,profundidad
					glCallList(pasillo_pequenho);
				glPopMatrix();
			}
			lado = 0;
			profundidad = profundidad + 3;
			glPushMatrix();
				glTranslatef(0.0, 0.0, profundidad_pasillo_h); //posición: lados,altura,profundidad
				glRotatef(90.0, 0.0, 1.0, 0.0);
				glScalef(0.5, 1.0, 1.0); //tamaño: lados,altura,profundidad
				glCallList(pasillo_pequenho);
			glPopMatrix();
			profundidad_pasillo_h = profundidad_pasillo_h + 3;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para el suelo.");
}

/******************************************************************************************/
/* Crea una display list para el suelo                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaSuelo(void)
{
	int i;
	int j;
	
	suelo = glGenLists(1);

	if (suelo != 0)
	{
		glNewList(suelo, GL_COMPILE);
			//glPushMatrix();
				glTranslatef(0.0, -0.5, 0.0); //posición: lados,altura,profundidad
				// Parte del pasillo/escalera de la entrada
				//glPushMatrix();
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					//glTranslatef(3, 0.0, 0.0);
					//glCallList(pasillo_simple);
				//glPopMatrix();
				// Parte del adoquinado central
				// Adoquinado izquierda
				glPushMatrix();
					glTranslatef(0.6, 0.0, 0.0);
					glCallList(seccion_suelo);
				glPopMatrix();
				// Pasillo central
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.2);
					glCallList(pasillo_central);
				glPopMatrix();
				// Adoquinado derecha
				glPushMatrix();
					glTranslatef(-11.7, 0.0, 0.0);
					glCallList(seccion_suelo);
				glPopMatrix();
			//glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para el suelo.");
}

void CreaParedSimple(void)
{
	pared_simple = glGenLists(1);

	if (pared_simple != 0)
	{
		glNewList(pared_simple, GL_COMPILE);
			glPushMatrix();
				glScalef(0.2, 0.05, 0.1); //tamaño: lados,altura,profundidad
				glTranslatef(0, 0.0, 0.0); //posición: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glScalef(0.2, 0.05, 0.1); //tamaño: lados,altura,profundidad
				glTranslatef(1.2, 0.0, 0.0); //posición: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
				glPushMatrix();
				glScalef(0.2, 0.05, 0.1); //tamaño: lados,altura,profundidad
				glTranslatef(0, 0.0, 1.3); //posición: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
				glPushMatrix();
				glScalef(0.2, 0.05, 0.1); //tamaño: lados,altura,profundidad
				glTranslatef(1.1, 0.0, 1.3); //posición: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un adoquinado.");
}

void CreaPersona(void)
{
	float alto_cuerpo = 0.50f;
	float ancho_cuerpo = 0.3f;
	float largo_cuerpo = 0.125f;
	float alto_brazo = 0.385f;
	float ancho_brazo = 0.125f;
	float largo_brazo = 0.125f;
	float radio_cabeza = 0.135f;
	float alto_pierna = 0.55f;
	float ancho_pierna = 0.125f;
	float largo_pierna = 0.125f;
	persona = glGenLists(1);

	if (persona != 0)
	{
		glNewList(persona, GL_COMPILE);
			//torso
			glPushMatrix();
			glScalef(ancho_cuerpo, alto_cuerpo, largo_cuerpo);
			glColor3f(0.0, 0.3, 0.8);
			//glutSolidCube(1);
			igSolidCube();
			glPopMatrix();

			// dibujamos brazo derecho
			glPushMatrix();
			glTranslatef(-(ancho_cuerpo) / 2, (alto_cuerpo - alto_brazo) / 2, 0);
			glTranslatef(0, alto_brazo / 2, 0);
			glRotatef(-30, 0, 0, 1);
			glTranslatef(0, -alto_brazo / 2, 0);
			glPushMatrix();
			glScalef(ancho_brazo, alto_brazo, largo_brazo);
			igSolidCube();
			glPopMatrix();
			// dibujamos mano derecha
			glTranslatef(0, -(alto_brazo + ancho_brazo) / 2, 0);
			glColor3f(1, 0.6, 0.6);
			glScalef(ancho_brazo, ancho_brazo, largo_brazo);
			igSolidCube();
			glPopMatrix();

			// dibujamos brazo izquierdo
			glColor3f(0.0, 0.3, 0.8);
			glPushMatrix();
			glTranslatef((ancho_cuerpo) / 2, (alto_cuerpo - alto_brazo) / 2, 0);
			glTranslatef(0, alto_brazo / 2, 0);
			glRotatef(30, 0, 0, 1);
			glTranslatef(0, -alto_brazo / 2, 0);
			glPushMatrix();
			glScalef(ancho_brazo, alto_brazo, largo_brazo);
			igSolidCube();
			glPopMatrix();
			// dibujamos mano izquierda
			glTranslatef(0, -(alto_brazo + ancho_brazo) / 2, 0);
			glColor3f(1, 0.6, 0.6);
			glScalef(ancho_brazo, ancho_brazo, largo_brazo);
			igSolidCube();
			glPopMatrix();

			// dibujamos pierna derecha
			glColor3f(0.0, 0.3, 0.8);
			glPushMatrix();
			glTranslatef(-(ancho_cuerpo - ancho_pierna) / 2, -
				(alto_cuerpo + alto_pierna) / 2, 0);
			glPushMatrix();
			glScalef(ancho_pierna, alto_pierna, largo_pierna);
			igSolidCube();
			glPopMatrix();
			// ahora pie derecho
			glTranslatef(0, -(alto_pierna + ancho_pierna) / 2, largo_pierna);
			glColor3f(0.3, 0.4, 0.4);
			glScalef(ancho_pierna, ancho_pierna, largo_pierna * 2);
			igSolidCube();
			glPopMatrix();

			//Dibujamos pierna izquierda
			glColor3f(0.0, 0.3, 0.8);
			glPushMatrix();
			glTranslatef((ancho_cuerpo - ancho_pierna) / 2, -
				(alto_cuerpo + alto_pierna) / 2, 0);
			glPushMatrix();
			glScalef(ancho_pierna, alto_pierna, largo_pierna);
			igSolidCube();
			glPopMatrix();
			// dibujamos pie izquierdo
			glTranslatef(0, -(alto_pierna + ancho_pierna) / 2, largo_pierna);
			glColor3f(0.3, 0.4, 0.4);
			glScalef(ancho_pierna, ancho_pierna, largo_pierna * 2);
			igSolidCube();
			glPopMatrix();

			// dibujamos cabeza
			glColor3f(1, 0.6, 0.6);
			glPushMatrix();
			glTranslatef(0, alto_cuerpo / 2 + radio_cabeza * 3 / 4, 0);
			glutSolidSphere(radio_cabeza, 10, 10);
			glPopMatrix();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la persona.");
}


/******************************************************************************************/
/*  Crea una display list para toda la escena                                             */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaEscena(void)
{
	escena = glGenLists (1);

	if (escena != 0)
	{
		glNewList (escena, GL_COMPILE);
		glPushMatrix();
			glScalef(3.0,3.0,3.0);
			//glPushMatrix();
				//glTranslatef(0.0,0.0,-5.0); // lados,altura,profundidad 
				//glColor3f(1.0,1.0,1.0); //color arcos
				/*arcos();*/
				//glCallList (arcos);
				//glColor3f(1.0,1.0,1.0);//color suelo
				/*suelo();*/
				//glCallList (adoquinado_simple);
				/*persona();*/
				//glCallList(persona);
			//glPopMatrix();
			glPushMatrix();
				//glColor3f(0.0,1.0,1.0);
				/*arcos();*/
				//glCallList (arcos);
				glColor3f(0.5, 0.5, 0.5);
				/*suelo();*/
				glCallList (suelo);
				//glCallList(pasillo_simple);
				//glCallList(pared_simple);
				/*persona();*/
				//glCallList(persona);
			glPopMatrix();
			//glPushMatrix();
				//glTranslatef(0.0,0.0,5.0);
				//glColor3f(0.0,1.0,1.0);
				/*arcos();*/
				//glCallList (arcos);
				//glColor3f(0.0,0.0,1.0);
				/*suelo();*/
				//glCallList (suelo);
				/*persona();*/
				//glCallList(persona);
			//glPopMatrix();
		glPopMatrix();
		glEndList ();
	}
	else puts ("Se ha producido un error creando la display list de la escena.");
}
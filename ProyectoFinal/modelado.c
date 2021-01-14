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
	CreaPasilloVertical();
	CreaPasilloHorizontal();
	CreaEscalon();
	CreaEscalera();
	CreaAdoquinadoSimple();
	CreaSeccionAdoquinado();
	CreaSeccionSuelo();
	CreaSuelo();
	CreaPuerta();
	CreaPuertaArco();
	CreaVentana();
	CreaVentanaBalcon();
	CreaVentanaBalconRecta();
	CreaVentanaAlargada();
	CreaVentanaRedonda();
	CreaPivote();
	CreaTejas();
	CreaTejadoSimple();
	CreaTejadoCono();
	CreaParedPuerta();
	CreaParedVentana();
	CreaParedSimple();
	CreaFachada();
	CreaTorre();
	CreaFondo();
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
		glColor3f(0.4, 0.4, 0.4);
		float profundidad = 0;
		for (j = 0; j < 19; j++) {
			glPushMatrix();
				glTranslatef(0.0, 0.0, profundidad);
				glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
				glCallList(pasillo_simple);
			glPopMatrix();
			profundidad = profundidad + 0.6;
		}
		glColor3f(0.5, 0.5, 0.5);
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una seccion adoquinado.");
}

void CreaPasilloVertical(void)
{
	int i;
	int j;

	pasillo_vertical = glGenLists(1);

	if (pasillo_vertical != 0)
	{
		glNewList(pasillo_vertical, GL_COMPILE);

		float profundidad = 0;
		for (j = 0; j < 19; j++) {
			glPushMatrix();
				glTranslatef(0.0, 0.0, profundidad);
				glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
				glCallList(pasillo_simple);
			glPopMatrix();
			profundidad = profundidad + 0.6;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un pasillo vetical.");
}

void CreaPasilloHorizontal(void)
{
	int i;
	int j;

	pasillo_horizontal = glGenLists(1);

	if (pasillo_horizontal != 0)
	{
		glNewList(pasillo_horizontal, GL_COMPILE);

		float profundidad = 0;
		for (j = 0; j < 4; j++) {
			glPushMatrix();
				glTranslatef(0.0, 0.0, profundidad);
				glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
				glCallList(pasillo_simple);
			glPopMatrix();
			profundidad = profundidad + 0.56;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un pasillo horizontal.");
}

void CreaEscalon(void)
{
	escalon = glGenLists(1);

	if (escalon != 0)
	{
		glNewList(escalon, GL_COMPILE);
			glPushMatrix();
				glTranslatef(0.0, 0, 0.0); //posición: lados,altura,profundidad
				glScalef(0.5, 0.1, 1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un escalon.");
}

void CreaEscalera(void)
{
	int i;
	int j;

	escalera = glGenLists(1);

	if (escalera != 0)
	{
		glNewList(escalera, GL_COMPILE);
		// nivel 1
		float lado = -11.5;
		float profundidad = -0.7;
		glColor3f(0.4, 0.4, 0.4);
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 42; j++) {
				glPushMatrix();
					if (i > 2) {
						glColor3f(0.35, 0.35, 0.35);
					}
					glTranslatef(lado, 0.0, profundidad);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(escalon);
				glPopMatrix();
				lado = lado + 0.56;
			}
			lado = -11.5;
			profundidad = profundidad + -1.1;
		}
		glColor3f(0.35, 0.35, 0.35);
		// nivel 2
		profundidad = -4;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 42; j++) {
				glPushMatrix();
					glTranslatef(lado, 0.1, profundidad);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(escalon);
				glPopMatrix();
				lado = lado + 0.56;
			}
			lado = -11.5;
			profundidad = profundidad + -1.1;
		}
		glColor3f(0.5, 0.5, 0.5);
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una escalera.");
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
			for (i = 0; i < 10; i++) {
				glPushMatrix();
					glTranslatef(lado, 0.0, profundidad);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
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
		// Adoquinado de una seccion
		float lado = 0;
		float profundidad = 0;
		float profundidad_pasillo_h = 2.63;
		float lado_pasillo_v = 2.55;
		for (j = 0; j < 4; j++) {
			for (i = 0; i < 4; i++) {
				glPushMatrix();
					glTranslatef(lado, 0.0, profundidad);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(seccion_adoquinado);
				glPopMatrix();
				lado = lado + 3;
			}
			lado = 0;
			profundidad = profundidad + 3;
		}
		// Pasillo pequenho horizontal
		float lado_pasillo_h = 0.2;
		glColor3f(0.4, 0.4, 0.4);
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 3; j++) {
				glPushMatrix();
					glTranslatef(lado_pasillo_h, 0.0, profundidad_pasillo_h); //posición: lados,altura,profundidad
					glRotatef(90.0, 0.0, 1.0, 0.0);
					glScalef(0.5, 1.0, 1.0); //tamaño: lados,altura,profundidad
					glCallList(pasillo_horizontal);
				glPopMatrix();
				profundidad_pasillo_h = profundidad_pasillo_h + 3;
			}
			profundidad_pasillo_h = 2.63;
			lado_pasillo_h = lado_pasillo_h + 3;
		}
		// Pasillo pequenho vertical
		for (j = 0; j < 3; j++) {
			glPushMatrix();
				glTranslatef(lado_pasillo_v, 0.0, 0.2); //posición: lados,altura,profundidad
				//glRotatef(90.0, 0.0, 1.0, 0.0);
				glScalef(0.7, 1.0, 1.0); //tamaño: lados,altura,profundidad
				glCallList(pasillo_vertical);
			glPopMatrix();
			lado_pasillo_v = lado_pasillo_v + 3;
		}
		glColor3f(0.5, 0.5, 0.5);

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
				glPushMatrix();
					glTranslatef(0, 0.0, 0.0);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(escalera);
				glPopMatrix();
				// Parte del adoquinado
				// Adoquinado izquierda
				glPushMatrix();
					glTranslatef(0.6, 0.0, 0.0);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(seccion_suelo);
				glPopMatrix();
				// Pasillo central
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.2);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(pasillo_central);
				glPopMatrix();
				// Adoquinado derecha
				glPushMatrix();
					glTranslatef(-11.7, 0.0, 0.0);
					glScalef(1, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(seccion_suelo);
				glPopMatrix();
			//glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para el suelo.");
}

void CreaPuerta(void)
{
	int i;

	puerta = glGenLists(1);

	if (puerta != 0)
	{
		glNewList(puerta, GL_COMPILE);
		for (i = 0; i < 12; i++)
		{
			// marco
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, -0.9, 0.0);
				glScalef(1.4, 3.2, 0.1);
				igSolidCube();
			glPopMatrix();
			// puerta
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, -0.9, 0.0);
				glScalef(1.2, 3.0, 0.1);
				igSolidCube();
			glPopMatrix();
		}
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la puerta.");

}

void CreaPuertaArco(void)
{
	int i;

	puerta_arco = glGenLists(1);

	if (puerta_arco != 0)
	{
		glNewList(puerta_arco, GL_COMPILE);
		for (i = 0; i < 12; i++)
		{
			// arco superior
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.005, 1.1, -0.10);
				glScalef(1.5, 1.1, 0.1);  //tamaño: lados,altura,profundidad
				igSolidSemiSphere(20, 150);
			glPopMatrix();
			// marco
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, -0.9, 0.0);
				glScalef(1.4, 3.2, 0.1);
				igSolidCube();
			glPopMatrix();
			// puerta
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, -0.9, 0.0);
				glScalef(1.2, 3.0, 0.1);
				igSolidCube();
			glPopMatrix();
		}
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la puerta con arco.");

}

void CreaVentana(void)
{
	int i;

	ventana = glGenLists(1);

	if (ventana != 0)
	{
		glNewList(ventana, GL_COMPILE);
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// cristales ventana
			glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(-0.2, 0.3, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(0.2, 0.3, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
				glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(-0.2, 0.0, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(0.2, 0.0, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(-0.2, -0.3, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.117, 0.117, 0.219);
				glTranslatef(0.2, -0.3, 0.0);
				glScalef(0.25, 0.25, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana.");
}

void CreaVentanaBalcon(void)
{
	int i;
	float lado = -0.69;

	ventana_balcon = glGenLists(1);

	if (ventana_balcon != 0)
	{
		glNewList(ventana_balcon, GL_COMPILE);
			// parte central
			glPushMatrix();
				glColor3f(0.847, 0.772, 0.772);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.5, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// semiesfera superior
			glPushMatrix();
				glColor3f(0.847, 0.772, 0.772);
				glTranslatef(0.005, 0.6, -0.10);
				glScalef(0.763, 0.6, 0.1);  //tamaño: lados,altura,profundidad
				igSolidSemiSphere(20, 150);
			glPopMatrix();
			// balconcillo
			for (i = 0; i < 10; i++) {
				glPushMatrix();
					glColor3f(0.854, 0.705, 0.345);
					glTranslatef(lado, -0.42, 0.1); //posición: lados,altura,profundidad
					glScalef(0.102, 0.4, 0.1); //tamaño: lados,altura,profundidad
					igSolidCube();
				glPopMatrix();
				lado = lado + 0.151;
			}
			// apoyo balconcillo
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, -0.2, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.1, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// marco ventana
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.5, 0.0);
				glScalef(0.07, 1.3, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.35, 0.45, 0.0);
				glScalef(0.07, 1.22, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(-0.35, 0.45, 0.0);
				glScalef(0.07, 1.22, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.1, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.05, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.5, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.05, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana balcon.");
}

void CreaVentanaBalconRecta(void)
{
	int i;
	float lado = -0.69;

	ventana_balcon_recta = glGenLists(1);

	if (ventana_balcon_recta != 0)
	{
		glNewList(ventana_balcon_recta, GL_COMPILE);
			// marco
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.7, 1.4, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// parte central
			glPushMatrix();
				glColor3f(0.847, 0.772, 0.772);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.5, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// balconcillo
			for (i = 0; i < 10; i++) {
				glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(lado, -0.42, 0.1); //posición: lados,altura,profundidad
				glScalef(0.102, 0.4, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
				glPopMatrix();
				lado = lado + 0.151;
			}
			// apoyo balconcillo
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, -0.2, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.1, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// marco ventana
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.22, 0.0);
				glScalef(0.07, 0.75, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.35, 0.22, 0.0);
				glScalef(0.07, 0.75, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(-0.35, 0.22, 0.0);
				glScalef(0.07, 0.75, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.0, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.05, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.4, 0.1); //posición: lados,altura,profundidad
				glScalef(1.5, 0.05, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glColor3f(0.5, 0.5, 0.5);
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana balcon.");
}

void CreaVentanaAlargada(void)
{
	int i;

	ventana_alargada = glGenLists(1);

	if (ventana_alargada != 0)
	{
		glNewList(ventana_alargada, GL_COMPILE);
			// marco
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.4, 0.7, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			// ventana
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.2, 0.5, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana alargada.");
}

void CreaVentanaRedonda(void)
{
	int i;

	ventana_redonda = glGenLists(1);

	if (ventana_redonda != 0)
	{
		glNewList(ventana_redonda, GL_COMPILE);
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1.2, 1.4, 0.1);  //tamaño: lados,altura,profundidad
				igSolidSphere(50, 50);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(1, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidSphere(50, 50);
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana redonda.");
}

void CreaPivote(void)
{
	int i;

	pivote = glGenLists(1);

	if (pivote != 0)
	{
		glNewList(pivote, GL_COMPILE);
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.50, 0.0);
				glScalef(0.2, 0.2, 0.2);  //tamaño: lados,altura,profundidad
				igSolidSphere(50, 50);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.2, 0.0);
				glScalef(0.1, 0.6, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.854, 0.705, 0.345);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(0.3, 0.5, 0.3);  //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana redonda.");
}

void CreaTejas(void)
{
	tejas = glGenLists(1);

	if (tejas != 0)
	{
		glNewList(tejas, GL_COMPILE);
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(0, 0.0, -0.02); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(0.11, 0.0, -0.02); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.701, 0.125, 0.019);
				glTranslatef(0, 0, 0.1); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(0.11, 0, 0.1); //posición: lados,altura,profundidad
				glScalef(0.1, 0.005, 0.1); //tamaño: lados,altura,profundidad
				igSolidCube();
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para tejas.");
}

void CreaTejadoSimple(void)
{
	tejado_simple = glGenLists(1);

	int i;
	int j;

	float lado= -1.5;
	float profundidad = -0.1;
	float altura = 1.55;

	if (tejado_simple != 0)
	{
		glNewList(tejado_simple, GL_COMPILE);
		for (j = 0; j < 10; j++) {
			for (i = 0; i < 20; i++) {
				glPushMatrix();
					glTranslatef(lado, altura, profundidad);
					glRotatef(30.0, 1.0, 0.0, 0.0);
					glScalef(1.3, 1, 1); //tamaño: lados,altura,profundidad
					glCallList(tejas);
				glPopMatrix();
				lado = lado + 0.15;
			}
			lado = -1.5;
			altura = altura + 0.1;
			profundidad = profundidad - 0.15;
		}
		glEndList();
	}
}

void CreaTejadoCono(void)
{
	int i;

	tejado_cono = glGenLists(1);

	if (tejado_cono != 0)
	{
		glNewList(tejado_cono, GL_COMPILE);
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glRotatef(-45.0, 1.0, 0.0, 0.0);
				glScalef(1.8, 2.0, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCone(55, 55);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(0.0, 0.0, -2.8);
				glRotatef(45.0, 1.0, 0.0, 0.0);
				glScalef(1.8, 2.0, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCone(55, 55);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(-1.5, -0.05, -1.45);
				glRotatef(-45.0, 0.0, 0.0, 1.0);
				glScalef(0.1, 2.0, 1.8);  //tamaño: lados,altura,profundidad
				igSolidCone(55, 55);
			glPopMatrix();
			glPushMatrix();
				glColor3f(0.701, 0.125, 0.019);
				glTranslatef(1.3, -0.05, -1.45);
				glRotatef(45.0, 0.0, 0.0, 1.0);
				glScalef(0.1, 2.0, 1.8);  //tamaño: lados,altura,profundidad
				igSolidCone(55, 55);
			glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana alargada.");
}

void CreaParedPuerta(void)
{
	int i;
	int j;

	pared_puerta = glGenLists(1);

	if (pared_puerta != 0)
	{
		glNewList(pared_puerta, GL_COMPILE);
		float lado = 0;
		float altura = 0;
		// bloque inferior a ventana
		for (i = 0; i < 26; i++) {
			glColor3f(0.913, 0.776, 0.447);
			for (j = 0; j < 3; j++) {
				glPushMatrix();
				if (i < 2 || i == 11 || i == 18 || i == 19) {
					// las dos primeras filas sobresalen y se dibujan mas oscuras
					glColor3f(0.854, 0.705, 0.345);
				}
				glScalef(1, 0.4, 0.1); //tamaño: lados,altura,profundidad
				if (i < 2 || i == 11) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 18) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 19) {
					glTranslatef(lado, altura, 0.2); //posición: lados,altura,profundidad
				}
				else {
					glTranslatef(lado, altura, -0.5); //posición: lados,altura,profundidad
				}
				igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque puerta
		glPushMatrix();
		glTranslatef(1.05, 1.7, -0.10);
		glCallList(puerta_arco);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
		glTranslatef(1.05, 5.9, -0.10);
		glScalef(1.5, 1.5, 1.0); //tamaño: lados,altura,profundidad
		glCallList(ventana);
		glPopMatrix();

		// bloque ventana redonda
		glPushMatrix();
		glTranslatef(1.05, 9.25, -0.10);
		glCallList(ventana_balcon);
		glPopMatrix();

		// bloque tejado
		glPushMatrix();
		glTranslatef(1.05, 9.25, -0.10);
		glCallList(tejado_simple);
		glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una pared puerta.");
}

void CreaParedVentana(void)
{
	int i;
	int j;

	pared_ventana = glGenLists(1);

	if (pared_ventana != 0)
	{
		glNewList(pared_ventana, GL_COMPILE);
		float lado = 0;
		float altura = 0;
		// bloque inferior a ventana
		for (i = 0; i < 26; i++) {
			glColor3f(0.913, 0.776, 0.447);
			for (j = 0; j < 3; j++) {
				glPushMatrix();
				if (i < 2 || i == 11 || i == 18 || i == 19) {
					// las dos primeras filas sobresalen y se dibujan mas oscuras
					glColor3f(0.854, 0.705, 0.345);
				}
				glScalef(1, 0.4, 0.1); //tamaño: lados,altura,profundidad
				if (i < 2 || i == 11) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 18) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 19) {
					glTranslatef(lado, altura, 0.2); //posición: lados,altura,profundidad
				}
				else {
					glTranslatef(lado, altura, -0.5); //posición: lados,altura,profundidad
				}
				igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			/*if (i == 3) {
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(1.05, 3.15, -0.4);
				glScalef(1, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			}*/
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque ventana inferior
		glPushMatrix();
		glTranslatef(1.05, 1.7, -0.10);
		glCallList(ventana);
		glPopMatrix();

		// bloque ventana inferior 2
		glPushMatrix();
		glTranslatef(1.05, 3.36, -0.10);
		glCallList(ventana);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
		glTranslatef(1.05, 5.9, -0.10);
		glCallList(ventana);
		glPopMatrix();

		// bloque ventana balcon
		glPushMatrix();
			glTranslatef(1.05, 9.25, -0.10);
			glCallList(ventana_balcon);
		glPopMatrix();

		// bloque tejado
		glPushMatrix();
			glTranslatef(1.05, 9.25, -0.10);
			glCallList(tejado_simple);
		glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una pared simple.");
}

void CreaParedSimple(void)
{
	int i;
	int j;

	pared_simple = glGenLists(1);

	if (pared_simple != 0)
	{
		glNewList(pared_simple, GL_COMPILE);
		float lado = 0;
		float altura = 0;
		// bloque inferior a ventana
		for (i = 0; i < 26; i++) {
			glColor3f(0.913, 0.776, 0.447);
			for (j = 0; j < 3; j++) {
				glPushMatrix();
					if (i < 2 || i == 11 || i == 18 || i == 19) {
						// las dos primeras filas sobresalen y se dibujan mas oscuras
						glColor3f(0.854, 0.705, 0.345);
					}
					glScalef(1, 0.4, 0.1); //tamaño: lados,altura,profundidad
					if (i < 2 || i == 11) {
						glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
					}
					else if (i == 18) {
						glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
					}
					else if (i == 19) {
						glTranslatef(lado, altura, 0.2); //posición: lados,altura,profundidad
					}
					else {
						glTranslatef(lado, altura, -0.5); //posición: lados,altura,profundidad
					}
					igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque ventana inferior
		glPushMatrix();
			glTranslatef(1.05, 1.7, -0.10);
			glCallList(ventana);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
			glTranslatef(1.05, 5.9, -0.10);
			glCallList(ventana);
		glPopMatrix();

		// bloque ventana balcon
		glPushMatrix();
			glTranslatef(1.05, 9.25, -0.10);
			glCallList(ventana_balcon);
		glPopMatrix();

		// bloque tejado
		glPushMatrix();
			glTranslatef(1.05, 9.25, -0.10);
			glCallList(tejado_simple);
			glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una pared simple.");
}

void CreaTorre(void)
{
	int i;
	int j;

	torre = glGenLists(1);

	if (torre != 0)
	{
		glNewList(torre, GL_COMPILE);
		float lado = 0;
		float altura = 0;
		
		
		// bloque tejado
		glPushMatrix();
			glTranslatef(1.05, 12.85, -0.20);
			//glScalef(0.4, 0.7, 1); //tamaño: lados,altura,profundidad
			glCallList(tejado_cono);
		glPopMatrix();
		// lateral
		glPushMatrix();
			glColor3f(0.913, 0.776, 0.447);
			glTranslatef(-0.45, 11.76, -1.70);
			glScalef(0.1, 2.1, 3.15); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.913, 0.776, 0.447);
			glTranslatef(2.55, 11.76, -1.70);
			glScalef(0.1, 2.0, 3.15); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		// bloque inferior a ventana
		for (i = 0; i < 31; i++) {
			glColor3f(0.913, 0.776, 0.447);
			for (j = 0; j < 3; j++) {
				glPushMatrix();
				if (i < 2 || i == 11 || i == 18 || i == 19 || i == 26) {
					// las dos primeras filas sobresalen y se dibujan mas oscuras
					glColor3f(0.854, 0.705, 0.345);
				}
				glScalef(1, 0.4, 0.1); //tamaño: lados,altura,profundidad
				if (i < 2 || i == 11) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 18) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 19) {
					glTranslatef(lado, altura, 0.2); //posición: lados,altura,profundidad
				}
				else {
					glTranslatef(lado, altura, -0.5); //posición: lados,altura,profundidad
				}
				igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque puerta
		glPushMatrix();
			glTranslatef(1.05, 1.7, -0.10);
			glCallList(puerta);
		glPopMatrix();

		// bloque ventana pequenha alargada
		glPushMatrix();
			glTranslatef(1.05, 3.0, -0.10);
			glCallList(ventana_alargada);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
			glTranslatef(1.05, 5.9, -0.10);
			glCallList(ventana);
		glPopMatrix();

		// bloque ventanas balcones
		float lado_ventana = -0.02;
		for (i = 0; i < 3; i++) {
			glPushMatrix();
				glTranslatef(lado_ventana, 9.25, -0.10);
				glScalef(0.5, 0.8, 1); //tamaño: lados,altura,profundidad
				glCallList(ventana_balcon_recta);
			glPopMatrix();
			lado_ventana = lado_ventana + 1.07;
		}
		
		// bloque ventanas alargadas
		lado_ventana = -0.02;
		for (i = 0; i < 3; i++) {
			glPushMatrix();
				glTranslatef(lado_ventana, 10.25, -0.10);
				glScalef(0.5, 0.4, 1); //tamaño: lados,altura,profundidad
				glCallList(ventana_alargada);
			glPopMatrix();
			lado_ventana = lado_ventana + 1.07;
		}

		// bloque ventanas balcon
		lado_ventana = -0.02;
		for (i = 0; i < 3; i++) {
			glPushMatrix();
				glTranslatef(lado_ventana, 11.8, -0.10);
				glScalef(0.4, 0.7, 1); //tamaño: lados,altura,profundidad
				glCallList(ventana_balcon);
			glPopMatrix();
			lado_ventana = lado_ventana + 1.07;
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una torre.");
}


void CreaFondo(void)
{
	int i;
	int j;

	float lado = 0.32;
	float altura = 0.0;

	fondo = glGenLists(1);

	if (fondo != 0)
	{
		glNewList(fondo, GL_COMPILE);
			for (i = 0; i < 10; i++) {
				glColor3f(0.913, 0.776, 0.447);
				for (j = 0; j < 22; j++) {
					glPushMatrix();
						glScalef(1.0175, 0.409, 0.1); //tamaño: lados,altura,profundidad
						glTranslatef(lado, altura, -5.0); //posición: lados,altura,profundidad
						igSolidCube();
					glPopMatrix();
					lado = lado + 1.05;
				}
				lado = 0.32;
				altura = altura + 1.05;
			}
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para la ventana alargada.");
}

void CreaFachada(void)
{
	int i;
	int j;

	fachada = glGenLists(1);

	if (fachada != 0)
	{
		glNewList(fachada, GL_COMPILE);
		float lado = 0;
		float altura = 0;
		// bloque inferior a ventana
		for (i = 0; i < 26; i++) {
			glColor3f(0.894, 0.757, 0.428);// 0.913, 0.776, 0.447
			for (j = 0; j < 32; j++) {
				glPushMatrix();
				if (i < 2 || i == 18 || i == 19 || i == 26) {
					// las dos primeras filas sobresalen y se dibujan mas oscuras
					glColor3f(0.854, 0.705, 0.345);
				}
				glScalef(0.5, 0.4, 0.1); //tamaño: lados,altura,profundidad
				if (i < 2 || i == 11) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 18) {
					glTranslatef(lado, altura, 0.0); //posición: lados,altura,profundidad
				}
				else if (i == 19) {
					glTranslatef(lado, altura, 0.2); //posición: lados,altura,profundidad
				}
				else {
					glTranslatef(lado, altura, -0.5); //posición: lados,altura,profundidad
				}
				igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque tejado
		glPushMatrix();
			glTranslatef(8.0, 9.25, -0.10);
			glScalef(5.5, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(tejado_simple);
		glPopMatrix();

		// bloque puerta5
		glPushMatrix();
			glTranslatef(8.15, 3.0, 0.0);
			glScalef(1.7, 1.2, 1.2);
			glCallList(puerta);
		glPopMatrix();

		// bloque ventana redonda
		glPushMatrix();
			glTranslatef(2.25, 2.3, 0.0);
			glScalef(0.5, 0.5, 1.0);
			glCallList(ventana_redonda);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(14.25, 2.3, 0.0);
			glScalef(0.5, 0.5, 1.0);
			glCallList(ventana_redonda);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
			glTranslatef(2.25, 5.9, 0.0);
			glCallList(ventana);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(14.25, 5.9, 0.0);
			glCallList(ventana);
		glPopMatrix();

		// bloque columnas
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(5.35, 2.0, 0.3);
			glScalef(0.2, 2.3, 0.2); //tamaño: lados,altura,profundidad
			igSolidSphere(20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(6.35, 2.0, 0.3);
			glScalef(0.2, 2.3, 0.2); //tamaño: lados,altura,profundidad
			igSolidSphere(20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(9.9, 2.0, 0.3);
			glScalef(0.2, 2.3, 0.2); //tamaño: lados,altura,profundidad
			igSolidSphere(20, 20);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(10.9, 2.0, 0.3);
			glScalef(0.2, 2.3, 0.2); //tamaño: lados,altura,profundidad
			igSolidSphere(20, 20);
		glPopMatrix();

		// bloque losa superior
		glPushMatrix();
			glTranslatef(8.2, 4.3, 0.3);
			glScalef(6.9, 0.40, 0.2); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		// bloque losa inferior
		glPushMatrix();
			glTranslatef(8.2, 0.0, 0.3);
			glScalef(6.9, 0.40, 0.2); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		// bloque ventana redonda
		glPushMatrix();
			glTranslatef(2.25, 9.3, 0.0);
			glScalef(0.5, 0.5, 1.0);
			glCallList(ventana_redonda);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(14.25, 9.3, 0.0);
			glScalef(0.5, 0.5, 1.0);
			glCallList(ventana_redonda);
		glPopMatrix();

		// bloque inscripcion
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(8.15, 6.3, 0.0);
			glScalef(2.5, 1.0, 0.10);
			igSolidCube();
		glPopMatrix();

		// bloque escudo
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(8.15, 10.0, 0.00);
			glRotatef(180, 0, 0, 1);
			glScalef(0.55, 1.25, 0.10);
			igSolidSemiSphere(10, 10);
		glPopMatrix();

		// bloque separador tejado
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(1.55, 10.50, 0.0);
			glScalef(3.7, 0.40, 0.2); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(14.68, 10.50, 0.0);
			glScalef(3.7, 0.40, 0.2); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		// bloque triangulos laterales
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(2.35, 11.70, 0.0);
			glRotatef(225, 0, 0, 1);
			glScalef(1.50, 1.50, 0.1); //tamaño: lados,altura,profundidad
			igSolidCone(20, 20);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(13.90, 11.70, 0.0);
			glRotatef(135, 0, 0, 1);
			glScalef(1.60, 1.60, 0.1); //tamaño: lados,altura,profundidad
			igSolidCone(20, 20);
		glPopMatrix();

		// bloque triangulo superior
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(8.10, 13.12, 0.3);
			glScalef(4.75, 1.50, 0.1); //tamaño: lados,altura,profundidad
			igSolidCone(20, 20);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(5.25, 13.57, 0.45);
			glRotatef(18, 0, 0, 1);
			glScalef(4.3, 0.25, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(10.9, 13.75, 0.35);
			glRotatef(-18, 0, 0, 1);
			glScalef(4.65, 0.25, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(8.1, 13.20, 0.4);
			glScalef(8.2, 0.25, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		//bloque pared superior
		lado = 7.35;
		altura = 27.3;
		for (i = 0; i < 6; i++) {
			glColor3f(0.894, 0.757, 0.428); // 0.913, 0.776, 0.447
			for (j = 0; j < 18; j++) {
				glPushMatrix();
					glScalef(0.50, 0.4, 0.1); //tamaño: lados,altura,profundidad
					glTranslatef(lado, altura, -0.50);
					igSolidCube();
				glPopMatrix();
				lado = lado + 1.05;
			}
			lado = 7.35;
			altura = altura + 1.05;
		}

		// ventana
		glPushMatrix();
			glTranslatef(8.15, 11.5, 0.10);
			glCallList(ventana);
		glPopMatrix();

		// bloque H
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(4.5, 10.5, 0.3);
			glScalef(0.5, 3.8, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(6.8, 10.5, 0.3);
			glScalef(0.5, 3.8, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(9.5, 10.5, 0.3);
			glScalef(0.5, 3.8, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(11.8, 10.5, 0.3);
			glScalef(0.5, 3.8, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(5.65, 10.5, 0.3);
			glScalef(1.75, 0.5, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(10.67, 10.5, 0.3);
			glScalef(1.75, 0.5, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();

		//bloque escudo superior
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(8.0, 15.25, 0.3);
			glScalef(0.74, 0.5, 0.1);  //tamaño: lados,altura,profundidad
			igSolidSemiSphere(20, 150);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(8.0, 14.5, 0.3);
			glScalef(1.45, 1.5, 0.1); //tamaño: lados,altura,profundidad
			igSolidCube();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.854, 0.705, 0.345);
			glTranslatef(8.0, 15.0, 0.3);
			glRotatef(180, 0, 0, 1);
			glScalef(0.55, 1.25, 0.10);
			igSolidSemiSphere(10, 10);
		glPopMatrix();

		// bloque pinchos
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(1.3, 10.65, 0.0);
			glScalef(0.3, 3.45, 0.25); //tamaño: lados,altura,profundidad
			igSolidCone(20, 20);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.894, 0.757, 0.428);
			glTranslatef(15.2, 10.65, 0.0);
			glScalef(0.3, 3.45, 0.25); //tamaño: lados,altura,profundidad
			igSolidCone(20, 20);
		glPopMatrix();

		// bloque pivotes
		// tejado
		lado = -0.4;
		for (i = 0; i < 5; i++) {
			glPushMatrix();
				glTranslatef(lado, 10.90, 0.0);
				glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
				glCallList(pivote);
			glPopMatrix();
			lado = lado - 3.0;
		}
		glPushMatrix();
			glTranslatef(-19.50, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-22.30, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-25.0, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();

		lado = 16.6;
		for (i = 0; i < 5; i++) {
			glPushMatrix();
				glTranslatef(lado, 10.90, 0.0);
				glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
				glCallList(pivote);
			glPopMatrix();
			lado = lado + 3.0;
		}
		glPushMatrix();
			glTranslatef(36.0, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(38.7, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(41.20, 10.90, 0.0);
			glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		

		//puerta principal
		glPushMatrix();
			glTranslatef(5.3, 4.75, 0.3);
			glScalef(1.5, 1.5, 1.5); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(6.3, 4.75, 0.3);
			glScalef(1.5, 1.5, 1.5); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(9.9, 4.75, 0.3);
			glScalef(1.5, 1.5, 1.5); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(10.9, 4.75, 0.3);
			glScalef(1.5, 1.5, 1.5); //tamaño: lados,altura,profundidad
			glCallList(pivote);
		glPopMatrix();
		


		glEndList();
	}
	else puts("Se ha producido un error creando la display list para una pared simple.");
}

void CreaPersona(void)
{
	float alto_cuerpo = 1.30f;
	float ancho_cuerpo = 0.4f;
	float largo_cuerpo = 0.165f;
	float alto_brazo = 0.385f;
	float ancho_brazo = 0.125f;
	float largo_brazo = 0.125f;
	float radio_cabeza = 0.135f;
	float alto_pierna = 0.25f;
	float ancho_pierna = 0.125f;
	float largo_pierna = 0.125f;
	persona = glGenLists(1);

	if (persona != 0)
	{
		glNewList(persona, GL_COMPILE);
			//torso
			glPushMatrix();
			glScalef(ancho_cuerpo, alto_cuerpo, largo_cuerpo);
			glColor3f(0.0, 0.0, 0.0);
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
			glColor3f(0.0, 0.0, 0.0);
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
			glColor3f(0.0, 0.0, 0.0);
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
			glColor3f(0.0, 0.0, 0.0);
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
			glPushMatrix();
				glTranslatef(-11.57, -0.3, -6.7);
				glScalef(1.0, 1.0, 1.0); //tamaño: lados,altura,profundidad
				glCallList(fondo);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-11.57, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_ventana);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-9.37, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(torre);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-10.47, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_ventana);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-8.27, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-8.27, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-7.17, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-6.07, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_puerta);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-4.97, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-3.87, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(3.1, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(4.2, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(5.3, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_puerta);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(6.4, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			
			glPushMatrix();
				glTranslatef(9.7, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_ventana);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(8.6, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(torre);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(7.5, -0.3, -6.7);
			glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
			glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(10.8, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(pared_ventana);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-2.865, -0.3, -6.7);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(fachada);
			glPopMatrix();


			glPushMatrix();
				glColor3f(0.5, 0.5, 0.5);
				glCallList (suelo);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 0.0, -5.0);
				glScalef(0.35, 0.35, 0.35); //tamaño: lados,altura,profundidad
				glCallList(persona);
			glPopMatrix();
		glPopMatrix();
		glEndList ();
	}
	else puts ("Se ha producido un error creando la display list de la escena.");
}
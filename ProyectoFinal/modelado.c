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
	CreaVentana();
	CreaVentanaBalcon();
	CreaTejas();
	CreaTejadoSimple();
	CreaParedPuerta();
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
			// arco superior
			glPushMatrix();
				glColor3f(0.847, 0.772, 0.772);
				glTranslatef(0.005, 0.6, -0.10);
				glScalef(0.763, 0.6, 0.1);  //tamaño: lados,altura,profundidad
				igSolidSemiSphere(20, 150);
			glPopMatrix();
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
		/*glPushMatrix();
			glTranslatef(0.0, 1.55, -0.1);
			glRotatef(30.0, 1.0, 0.0, 0.0);
			glScalef(1.0, 1.2, 1.2); //tamaño: lados,altura,profundidad
			glCallList(tejas);
		glPopMatrix();*/
		glEndList();
	}
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
			/*if (i == 3) {
				glColor3f(0.356, 0.133, 0.043);
				glTranslatef(1.05, 3.15, -0.4);
				glScalef(1, 1.2, 0.1);  //tamaño: lados,altura,profundidad
				igSolidCube();
			}*/
			lado = 0;
			altura = altura + 1.05;
		}
		// bloque puerta
		glPushMatrix();
		glTranslatef(1.05, 1.7, -0.10);
		glCallList(puerta);
		glPopMatrix();

		// bloque ventana superior
		glPushMatrix();
		glTranslatef(1.05, 5.9, -0.10);
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

		// bloque ventana superior
		glPushMatrix();
			glTranslatef(1.05, 5.9, -0.10);
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
	else puts("Se ha producido un error creando la display list para una pared simple.");
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
			glPushMatrix();
				glTranslatef(-11.55, -0.3, -6.7);
				glScalef(0.4, 0.4, 0.4); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-10.3, -0.3, -6.7);
				glScalef(0.4, 0.4, 0.4); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0, -0.3, -6.7);
				glScalef(0.4, 0.4, 0.4); //tamaño: lados,altura,profundidad
				glCallList(pared_puerta);
			glPopMatrix();
			
			glPushMatrix();
				glTranslatef(9.41, -0.3, -6.7);
				glScalef(0.4, 0.4, 0.4); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(10.67, -0.3, -6.7);
				glScalef(0.4, 0.4, 0.4); //tamaño: lados,altura,profundidad
				glCallList(pared_simple);
			glPopMatrix();
			glPushMatrix();
				//glColor3f(0.0,1.0,1.0);
				/*arcos();*/
				//glCallList (arcos);
				glColor3f(0.5, 0.5, 0.5);
				/*suelo();*/
				glCallList (suelo);
				//glCallList(pasillo_simple);
				//glTranslatef(0.0, 0.0, -8.0); // lados,altura,profundidad 
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
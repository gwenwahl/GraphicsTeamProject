/*
*** FILE NAME   : animation_example.c
*** DESCRIPTION : This program is an example program using OpenGL for animation.
*** DATE        : May 2012
*** WRITTEN By  : JKL
*/

#include "stdafx.h"
#include <stdio.h>               // standard C libraries
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <GL/glut.h>             // GLUT library
#include "cs_graphics_setup.h"   // Header for CS4250/5250/6250 courses

//@@***********************************************************************************@@
// Constants
#define WINDOW_XS 600							// Window size
#define WINDOW_YS 600
#define WINDOW_NAME "OpenGL Animation Example"	// Window name

#define ANI_MSEC 10	 // gap between frames

//@@***********************************************************************************@@
// Structures
typedef struct pt
{
	GLint x, y;
}MyPoint;

//@@***********************************************************************************@@
// Global Variables
MyPoint lowerleftred, upperleftred, lowerrightred, upperrightred;
int go_up = 1;

//@@***********************************************************************************@@
// Function prototypes
void display_func(void);
void keyboard_func(unsigned char c, int x, int y);
void animation_func(int val);

//@@***********************************************************************************@@
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	init_setup(WINDOW_XS, WINDOW_YS, WINDOW_NAME);
	lowerleftred.x = 260;
	lowerleftred.y = 280;
	lowerrightred.x = 340;
	lowerrightred.y = 280;
	upperleftred.x = 260;
	upperleftred.y = 320;
	upperrightred.x = 340;
	upperrightred.y = 320;

	glutDisplayFunc(display_func);
	glutKeyboardFunc(keyboard_func);
	glutTimerFunc(ANI_MSEC, animation_func, 0);
	glutMainLoop();

	return 1;

}	// end of main()

	//@@***********************************************************************************@@
void display_func(void)
{
	glClearColor(1.0, 1.0, 0.87, 1.0);   // background color (white)
	glClear(GL_COLOR_BUFFER_BIT);       // clearing the buffer not to keep the color
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);

	glVertex2i(lowerleftred.x, lowerleftred.y);
	glVertex2i(upperleftred.x, upperleftred.y);
	glVertex2i(upperrightred.x, upperrightred.y);
	glVertex2i(lowerrightred.x, lowerrightred.y);
	glEnd();



	glFlush();

	glutSwapBuffers();	// double buffering

}	// end of display_func()

	//@@***********************************************************************************@@
void animation_func(int val)
{
	// updating one end point for animation






















	glutPostRedisplay();

	glutTimerFunc(ANI_MSEC, animation_func, 0);

}//end animation_func

 //@@***********************************************************************************@@
void keyboard_func(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'Q':
	case 'q':
		printf("Good Bye !\n");
		exit(0);				 // terminates the program
	}  // end of switch

}	// end of keyboard_func()
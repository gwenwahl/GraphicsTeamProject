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

#define ANI_MSEC 15	 // gap between frames

//@@***********************************************************************************@@
// Structures
typedef struct pt
{
	GLint x, y;
}MyPoint;

typedef struct rect {
	MyPoint ll, ul, lr, ur;
};
//Circle Function
void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}

//@@***********************************************************************************@@
// Global Variables
rect red, orange;
int degree = 0;
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
	
	//Red Rect Corners
	red.ll.x = 260;
	red.ll.y = 280;
	red.lr.x = 340;
	red.lr.y = 280;
	red.ul.x = 260;
	red.ul.y = 320;
	red.ur.x = 340;
	red.ur.y = 320;
	
	//Orange Square Corners
	orange.ll.x = 295;
	orange.ll.y = 95;
	orange.lr.x = 305;
	orange.lr.y = 95;
	orange.ul.x = 295;
	orange.ul.y = 105;
	orange.ur.x = 305;
	orange.ur.y = 105;


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
	
	//RED RECTANGLE
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
		glTranslatef(300, 300, 0);
		glRotatef(degree, 0, 0, 1);
		glTranslatef(-300, -300, 0);
		glBegin(GL_QUADS);
			glVertex2i(red.ll.x, red.ll.y);
			glVertex2i(red.ul.x, red.ul.y);
			glVertex2i(red.ur.x, red.ur.y);
			glVertex2i(red.lr.x, red.lr.y);
		glEnd();
	glPopMatrix();

	//BLUE CIRCLE
	glColor3f(0.0, 0.0, 1.0);
	DrawCircle(300, 300, 200, 5000);

	//ORANGE SQUARE
	glColor3f(1.0, 0.67, 0.0);
	glPushMatrix();
		glTranslatef(300, 300, 0);
		glRotatef(degree, 0, 0, 1);
		glTranslatef(-300, -300, 0);
		glBegin(GL_QUADS);
			glVertex2i(orange.ll.x, orange.ll.y);
			glVertex2i(orange.ul.x, orange.ul.y);
			glVertex2i(orange.ur.x, orange.ur.y);
			glVertex2i(orange.lr.x, orange.lr.y);
		glEnd();

	glFlush();

	glutSwapBuffers();	// double buffering

}	// end of display_func()

	//@@***********************************************************************************@@
void animation_func(int val)
{
	//Increment Red Degree
	degree++;
	if (degree > 360) {
		degree = 0;
	}

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
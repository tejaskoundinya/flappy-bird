#include<iostream>
using namespace std;
#include<gl/glut.h>
#include<math.h>
#include "start.h"
#include "bird_control.h"
#include "wall_control.h"

GLfloat bird_x = 100;
GLfloat bird_y = 250;

int game_over = 0;
int score = 0;

void drawBird()
{
	GLfloat angle, x, y;
	glColor3f(1, 0, 0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
	{
		x = 20.0 * sin(angle) + bird_x;
		y = 20.0 * cos(angle) + bird_y;
		glVertex3f(x, y, 0.0);
	}
	glEnd();
	glFlush();
	//glutSwapBuffers();
}

void mainDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawBird();
	generate_walls();
	glFlush();
}

void mainInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 600);
}

void mouse_control(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		bird_jump();
	}
}

void keyboard_control(unsigned char key, int x, int y)
{
	bird_jump();
}

void idleFunc()
{
	if (!game_over)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		fall();
		generate_walls();
		display_wall();
		move_wall();
		check_collision();
		glutSwapBuffers();
	}
	else
	{
		//glutSwapBuffers();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Flappy Bird");
	glutDisplayFunc(mainDisplay);
	mainInit();
	glutMouseFunc(mouse_control);
	glutKeyboardFunc(keyboard_control);
	glutIdleFunc(idleFunc);
	glutMainLoop();
}
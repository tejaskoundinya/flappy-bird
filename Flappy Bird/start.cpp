#include<iostream>
using namespace std;
#include<gl/glut.h>
#include "bird_control.h"

void drawBird()
{

}

void mainDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawBird();
}

void mainInit()
{

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Flappy Bird");
	glutDisplayFunc(mainDisplay);
	mainInit();
	glutMainLoop();
}
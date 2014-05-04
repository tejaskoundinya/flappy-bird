//@author: Tejas Koundinya

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
int game_start = 0;
int score = 0;
int wall_num = -1;

void drawBird()
{
	GLfloat angle, x, y;
	glColor3f(1, 0, 0);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glBegin(GL_POINTS);
	glBegin(GL_POLYGON);
	for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
	{
		x = 20.0 * sin(angle) + bird_x;
		y = 20.0 * cos(angle) + bird_y;
		glVertex3f(x, y, 0.0);
	}
	glEnd();

	glColor3f(0.5, 0.1, 0.1);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0, 500, 0, 600);
	glOrtho(0, 500, 0, 600, -10, 10);
}

void mouse_control(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (!game_over && !game_start)
		{
			bird_jump();
			game_start = 1;
		}
		else if (game_over)
		{
			//
		}
		else
		{
			bird_jump();
		}
	}
}

void keyboard_control(unsigned char key, int x, int y)
{
	if (!game_over && !game_start)
	{
		bird_jump();
		game_start = 1;
	}
	else if (game_over)
	{
		//
	}
	else
	{
		bird_jump();
	}
}

void displayScore()
{
	//glPushMatrix();
	//glLoadIdentity();
	int score_tens = score / 10;
	int score_units = score % 10;
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(400.0, 565.0);
	char str[7] = { 'S', 'c', 'o', 'r', 'e', ':', ' '};
	for (int i = 0; i < 7; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (char)((score / 10) + 48));
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (char)((score % 10) + 48));
	//glPopMatrix();
	glFlush();
}

void displayBG()
{
	glColor3f(0.6, 0.8, 0.92);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 50.0, -1.0);
	glVertex3f(500.0, 50.0, -1.0);
	glVertex3f(500.0, 600.0, -1.0);
	glVertex3f(0.0, 600.0, -1.0);
	glEnd();
	glColor3f(0.3, 0.4, 0.46);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 50.0, -1.0);
	glVertex3f(500.0, 50.0, -1.0);
	glVertex3f(500.0, 600.0, -1.0);
	glVertex3f(0.0, 600.0, -1.0);
	glEnd();

	glColor3f(0.59, 0.295, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(500.0, 0.0, 1.0);
	glVertex3f(500.0, 50.0, 1.0);
	glVertex3f(0.0, 50.0, 1.0);
	glEnd();
	glColor3f(0.29, 0.15, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(500.0, 0.0, 1.0);
	glVertex3f(500.0, 50.0, 1.0);
	glVertex3f(0.0, 50.0, 1.0);
	glEnd();

	glFlush();
}

void displayMenu()
{
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(175.0, 300.0);
	char str[14] = { 'C', 'l', 'i', 'c', 'k', ' ', 't', 'o', ' ', 'S', 't', 'a', 'r', 't' };
	for (int i = 0; i < 14; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	//glPopMatrix();
	glFlush();
}

void displayFinalScore()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(100.0, 270.0, 1.0);
	glVertex3f(400.0, 270.0, 1.0);
	glVertex3f(400.0, 400.0, 1.0);
	glVertex3f(100.0, 400.0, 1.0);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(175.0, 350.0, 2.0);
	char str[10] = { 'G', 'A', 'M', 'E', ' ', 'O', 'V', 'E', 'R', '!' };
	for (int i = 0; i < 10; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	glRasterPos3f(175.0, 300.0, 2.0);
	char str1[13] = { 'F', 'i', 'n', 'a', 'l', ' ', 'S', 'c', 'o', 'r', 'e', ':', ' ' };
	for (int i = 0; i < 13; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
	}
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (char)((score / 10) + 48));
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (char)((score % 10) + 48));
	glFlush();
}

void idleFunc()
{
	if (!game_over && game_start)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		displayBG();
		fall();
		generate_walls();
		display_wall();
		move_wall();
		displayScore();
		glutSwapBuffers();
	}
	else if (!game_over && !game_start)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		displayBG();
		drawBird();
		generate_walls();
		display_wall();
		displayScore();
		displayMenu();
		glutSwapBuffers();
	}
	else if (game_over)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		displayBG();
		drawBird();
		generate_walls();
		display_wall();
		displayFinalScore();
		glutSwapBuffers();
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
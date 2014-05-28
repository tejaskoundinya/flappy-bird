#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gl/glut.h>
#include"wall_control.h"
#include"start.h"

struct wall
{
	int id;
	GLfloat gap_size;
	GLfloat start_y;
	GLfloat x;
};

int count_t = 0;
struct wall **walls;
struct wall *wall1;
struct wall *wall2;
struct wall *wall3;
struct wall *wall4;
struct wall *wall5;


void generate_walls()
{
	if (count_t == 0)
	{
		walls = (struct wall**) malloc(5 * sizeof(wall));
		wall1 = (struct wall*) malloc(sizeof(wall));
		wall1->id = 1;
		wall1->gap_size = 200;
		wall1->start_y = 250;
		wall1->x = 500;

		wall2 = (struct wall*) malloc(sizeof(wall));
		wall2->id = 2;
		wall2->gap_size = 200;
		wall2->start_y = 150;
		wall2->x = 800;

		wall3 = (struct wall*) malloc(sizeof(wall));
		wall3->id = 3;
		wall3->gap_size = 200;
		wall3->start_y = 250;
		wall3->x = 1100;

		wall4 = (struct wall*) malloc(sizeof(wall));
		wall4->id = 4;
		wall4->gap_size = 200;
		wall4->start_y = 100;
		wall4->x = 1400;

		wall5 = (struct wall*) malloc(sizeof(wall));
		wall5->id = 5;
		wall5->gap_size = 200;
		wall5->start_y = 300;
		wall5->x = 1700;

		walls[0] = wall1;
		walls[1] = wall2;
		walls[2] = wall3;
		walls[3] = wall4;
		walls[4] = wall5;
		count_t++;
	}
}

void display_wall()
{
	if (count_t == 0)
		return;
	glColor3f(0.0, 1.0, 0.0);

	for (int i = 0; i < 5; i++)
	{

		//Start Clouds
		GLfloat angle, x, y;
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 100;
			y = 20.0 * sin(angle) + walls[i]->start_y + walls[i]->gap_size;
			glVertex3f(x, y, -0.5);
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 150;
			y = 20.0 * sin(angle) + walls[i]->start_y + walls[i]->gap_size;
			glVertex3f(x, y, -0.5);
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (3.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 125;
			y = 20.0 * sin(angle) + walls[i]->start_y + walls[i]->gap_size + 10;
			glVertex3f(x, y, -0.5);
		}
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(walls[i]->x - 100, walls[i]->start_y + walls[i]->gap_size - 20, -0.5);
		glVertex3f(walls[i]->x - 150, walls[i]->start_y + walls[i]->gap_size - 20, -0.5);
		glVertex3f(walls[i]->x - 150, walls[i]->start_y + walls[i]->gap_size + 10, -0.5);
		glVertex3f(walls[i]->x - 100, walls[i]->start_y + walls[i]->gap_size + 10, -0.5);

		glEnd();

		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 200;
			y = 20.0 * sin(angle) + walls[i]->start_y - 50;
			glVertex3f(x, y, -0.5);
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (2.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 250;
			y = 20.0 * sin(angle) + walls[i]->start_y - 50;
			glVertex3f(x, y, -0.5);
		}
		glEnd();

		glBegin(GL_POLYGON);
		for (angle = 0.0; angle <= (3.0 * GL_PI); angle += GL_PI / 100.0f)
		{
			x = 20.0 * cos(angle) + walls[i]->x - 225;
			y = 20.0 * sin(angle) + walls[i]->start_y - 40;
			glVertex3f(x, y, -0.5);
		}
		glEnd();


		glBegin(GL_POLYGON);
		glVertex3f(walls[i]->x - 200, walls[i]->start_y - 70, -0.5);
		glVertex3f(walls[i]->x - 250, walls[i]->start_y - 70, -0.5);
		glVertex3f(walls[i]->x - 250, walls[i]->start_y - 40, -0.5);
		glVertex3f(walls[i]->x - 200, walls[i]->start_y - 40, -0.5);

		glEnd();


		glColor3f(0, 1, 0);

		//End Clouds

		//glColor3f(0.3, 1.0, 0.247);
		glColor3f(0.1, 0.5, 0.1);
		glBegin(GL_LINE_LOOP);
		glVertex2f(walls[i]->x, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, 0.0);
		glVertex2f(walls[i]->x, 0.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(walls[i]->x, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, 550.0);
		glVertex2f(walls[i]->x, 550.0);
		glEnd();

		glColor3f(0.0, 1.0, 0.0);

		glBegin(GL_POLYGON);
		glVertex2f(walls[i]->x, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, 0.0);
		glVertex2f(walls[i]->x, 0.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(walls[i]->x, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, 550.0);
		glVertex2f(walls[i]->x, 550.0);
		glEnd();
		glFlush();
		if (abs((int)bird_x - (int)walls[i]->x) < 20 || abs((int)bird_x - ((int)walls[i]->x + 50)) < 20)
		{
			if (bird_y > walls[i]->start_y + 20 && bird_y < walls[i]->start_y + walls[i]->gap_size - 20)
			{
				if (((bird_x - walls[i]->x) < 1.0) && wall_num != walls[i]->id)
				{
					wall_num = walls[i]->id;
					score++;
					printf("%d", score);
				}
			}
			else
			{
				game_over = 1;
			}
			
		}
	}
}

void move_wall()
{
	for (int i = 0; i < 5; i++)
	{
		if (walls[i]->x + 50.0 > 0)
		{
			//walls[i]->x -= 0.025; // Original
			walls[i]->x -= 0.3;
		}
		else
		{
			walls[i]->x += 1500;
		}
	}
}

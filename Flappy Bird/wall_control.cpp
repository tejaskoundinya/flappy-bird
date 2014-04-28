#include<stdio.h>
#include<stdlib.h>
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

int count = 0;
struct wall **walls;
struct wall *wall1;
struct wall *wall2;
struct wall *wall3;
struct wall *wall4;
struct wall *wall5;


void generate_walls()
{
	if (count == 0)
	{
		walls = (struct wall**) malloc(5 * sizeof(wall));
		wall1 = (struct wall*) malloc(sizeof(wall));
		wall1->id = 1;
		wall1->gap_size = 200;
		wall1->start_y = 200;
		wall1->x = 500;

		wall2 = (struct wall*) malloc(sizeof(wall));
		wall2->id = 2;
		wall2->gap_size = 200;
		wall2->start_y = 100;
		wall2->x = 800;

		wall3 = (struct wall*) malloc(sizeof(wall));
		wall3->id = 3;
		wall3->gap_size = 200;
		wall3->start_y = 200;
		wall3->x = 1100;

		wall4 = (struct wall*) malloc(sizeof(wall));
		wall4->id = 4;
		wall4->gap_size = 200;
		wall4->start_y = 50;
		wall4->x = 1400;

		wall5 = (struct wall*) malloc(sizeof(wall));
		wall5->id = 5;
		wall5->gap_size = 200;
		wall5->start_y = 250;
		wall5->x = 1700;

		walls[0] = wall1;
		walls[1] = wall2;
		walls[2] = wall3;
		walls[3] = wall4;
		walls[4] = wall5;
		count++;
	}
}

void display_wall()
{
	if (count == 0)
		return;
	glColor3f(0.0, 1.0, 0.0);

	for (int i = 0; i < 5; i++)
	{

		glBegin(GL_POLYGON);
		glVertex2f(walls[i]->x, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y);
		glVertex2f(walls[i]->x + 50, 0.0);
		glVertex2f(walls[i]->x, 0.0);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(walls[i]->x, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, walls[i]->start_y + walls[i]->gap_size);
		glVertex2f(walls[i]->x + 50, 500.0);
		glVertex2f(walls[i]->x, 500.0);
		glEnd();
		glFlush();
		if (abs((int)bird_x - (int)walls[i]->x) < 20 || abs((int)bird_x - ((int)walls[i]->x + 50)) < 20)
		{
			if (bird_y > walls[i]->start_y + 20 && bird_y < walls[i]->start_y + walls[i]->gap_size - 20)
			{
				if (((bird_x - walls[i]->x) < 1.0)  && wall_num != walls[i]->id)
				{
					wall_num = walls[i]->id;
					score++;
					score_lock = 0;
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
			walls[i]->x -= 0.025;
		}
		else
		{
			walls[i]->x += 1500;
		}
	}
}

void check_collision()
{

}
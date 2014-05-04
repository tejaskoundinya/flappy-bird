#include "bird_control.h"
#include<gl/glut.h>
#include"start.h"

GLfloat g = 0.0;

void bird_jump()
{
	GLfloat cur_x, cur_y, dest_x, dest_y;
	cur_x = bird_x;
	cur_y = bird_y;
	dest_x = cur_x;
	//dest_y = cur_y + 75; // Original
	dest_y = cur_y + 115;
	while (cur_y <= dest_y)
	{
		if (cur_y >= 550)
		{
			drawBird();
			break;
		}
		else
		{
			//glClear(GL_COLOR_BUFFER_BIT);
			drawBird();
			cur_y++;
			bird_y++;
			//cur_y += 0.05;
			//bird_y += 0.05;
			//glutSwapBuffers();
		}
	}
	g = 0.0;
}

void fall()
{
	if (bird_y <= 70)
	{
		drawBird();
		game_over = 1;
	}
	else
	{
		//bird_y -= 0.03 + g; //Original
		//g += 0.00002; //Original
		bird_y -= 0.35 + g;
		//g += 0.00002;
		g += 0.0002;
		drawBird();
	}
}
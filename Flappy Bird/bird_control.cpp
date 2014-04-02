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
	dest_y = cur_y + 75;
	while (cur_y <= dest_y)
	{
		if (cur_y >= 450)
		{
			drawBird();
			break;
		}
		else
		{
			drawBird();
			cur_y++;
			bird_y++;
		}
	}
	g = 0.0;
}

void fall()
{
	if (bird_y <= 50)
		drawBird();
	else
	{
		bird_y -= 0.03 + g;
		g += 0.00001;
		drawBird();
	}
}
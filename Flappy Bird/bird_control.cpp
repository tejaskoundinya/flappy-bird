#include "bird_control.h"
#include<gl/glut.h>
#include"start.h"

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
}

void fall()
{
	if (bird_y <= 50)
		drawBird();
	else
	{
		bird_y -= 0.025;
		drawBird();
	}
}
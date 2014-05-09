#include "bird_control.h"
#include<gl/glut.h>
#include"start.h"

GLfloat g = 0.0;

void bird_jump()
{
	bird_y = ((bird_y + 120) < 550) ? bird_y + 120 : 550;
	g = 0.0;
}

void fall()
{
	if (bird_y <= 70)
	{
		//drawBird();
		game_over = 1;
	}
	else
	{
		//bird_y -= 0.03 + g; //Original
		//g += 0.00002; //Original
		bird_y -= 0.35 + g;
		//g += 0.00002;
		g += 0.0002;
		//drawBird();
	}
}
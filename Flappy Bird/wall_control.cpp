#include<stdlib.h>
#include<gl/glut.h>

//struct wall
//{
//	int id;
//	GLfloat gap_size;
//	GLfloat start_y;
//};

GLfloat wall_up[4][3] = { { 500.0, 0.0, 0.0 }, { 500.0, 200.0, 0.0 }, { 550.0, 200.0, 0.0 }, { 550.0, 0.0, 0.0 } };
GLfloat wall_down[4][3] = { { 500.0, 500.0, 0.0 }, { 500.0, 300.0, 0.0 }, { 550.0, 300.0, 0.0 }, { 550.0, 500.0, 0.0 } };

GLfloat **walls = (GLfloat**) malloc (5 * 2 * 4 * 3 * sizeof(GLfloat));

//void generate_walls()
//{
//	struct wall wall1;
//	wall1.id = 1;
//	wall1.gap_size = 100;
//	wall1.start_y = 200;
//}

void display_wall()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(wall_up[0]);
	glVertex3fv(wall_up[1]);
	glVertex3fv(wall_up[2]);
	glVertex3fv(wall_up[3]);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3fv(wall_down[0]);
	glVertex3fv(wall_down[1]);
	glVertex3fv(wall_down[2]);
	glVertex3fv(wall_down[3]);
	glEnd();
	glFlush();
	//glutSwapBuffers();
}

void move_wall()
{
	if (wall_up[2][1] > 0)
	{
		display_wall();
		for (int i = 0; i < 4; i++)
		{
			wall_up[i][0] -= 0.025;
			wall_down[i][0] -= 0.025;
		}
	}
}
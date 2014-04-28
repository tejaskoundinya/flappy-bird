#include<gl/glut.h>
#define GL_PI 3.1412

extern GLfloat bird_x;
extern GLfloat bird_y;

extern int game_over;
extern int score;
extern int score_lock;
extern int wall_num;

extern void drawBird();
void mainDisplay();
void mainInit();
void mouse_control(int button, int state, int x, int y);
void idleFunc();
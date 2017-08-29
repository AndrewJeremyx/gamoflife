#include "Game.h"
#include "Printer.h"
#include <iostream>
#include <GL/glut.h>
#include <time.h>
const int LENGTH = 64;
const int HEIGHT = 48;
const int D_LENGTH = 640;
const int D_HEIGHT = 480;
Field field(LENGTH,HEIGHT,1);
void timer(int value)
{
    field.NextGen();
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}
void mouse(int button, int state, int ax, int ay)
{
    if (state == GLUT_DOWN)
    {
        field.setCell(ax / (D_LENGTH / LENGTH), HEIGHT - ay / (D_HEIGHT / HEIGHT) - 1 ,!field.getCell(ax / (D_LENGTH / LENGTH), HEIGHT - ay/ (D_HEIGHT / HEIGHT) -1));
        glutPostRedisplay();
    }
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (field.getCell(i,j) == 1)
            {
                glBegin(GL_QUADS);
                glVertex2f((D_LENGTH / LENGTH) * i,(D_HEIGHT / HEIGHT) * j);
                glVertex2f((D_LENGTH / LENGTH) * (i + 1),(D_HEIGHT / HEIGHT) * (j + 1));
                glVertex2f((D_LENGTH / LENGTH) * i,(D_HEIGHT / HEIGHT) * (j + 1));
                glVertex2f((D_LENGTH / LENGTH) * (i + 1),(D_HEIGHT / HEIGHT) * j);
                glEnd();
                glBegin(GL_QUADS);
                glVertex2f((D_LENGTH / LENGTH) * i,(D_HEIGHT / HEIGHT) * j);
                glVertex2f((D_LENGTH / LENGTH) * i,(D_HEIGHT / HEIGHT) * (j + 1));
                glVertex2f((D_LENGTH / LENGTH) * (i + 1),(D_HEIGHT / HEIGHT) * j);
                glVertex2f((D_LENGTH / LENGTH) * (i + 1),(D_HEIGHT / HEIGHT) * (j + 1));
                glEnd();
            }

        }
    }
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize(D_LENGTH,D_HEIGHT);
    glutCreateWindow("Game of Life");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,D_LENGTH,0,D_HEIGHT);
    glutDisplayFunc(display);
    timer(1);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

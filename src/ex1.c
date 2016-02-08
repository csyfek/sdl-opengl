/******************************************/
/* A Very Simple OpenGL Example!          */
/******************************************/

/* this code just creates a window and draws a rectangle in it */

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

void init(void);
void display(void);

int main (int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("My First OpenGL Application");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void init()
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // clear -> black
  glColor3f(0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // view box
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);  // clear color buffer
  glRectf(-5.0, 5.0, 5.0, -5.0);
  glutSwapBuffers();
}
/**********************************************************************/


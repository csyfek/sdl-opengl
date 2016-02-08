/**********************************************************************/
/******************************************/
/* Example 2: Drawing in 3D               */
/******************************************/

//#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char, int, int);

int main (int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("A 3D Object");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);  /* set keyboard handler */
  glutMainLoop();
  return 0;
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0); // view box
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT); // clear color buffer (pixels)

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 1.0);    /* center square */
  glVertex3f(-3.0, -3.0, 0.0);
  glVertex3f(3.0, -3.0, 0.0);
  glVertex3f(3.0, 3.0, 0.0);
  glVertex3f(-3.0, 3.0, 0.0);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);  /* now draw the four triangles */
  glVertex3f(0.0, 6.5, 0.0);
  glColor3f(0.0, 0.0, 0.9f);
  glVertex3f(-3.0, 3.0, 0.0);
  glVertex3f(3.0, 3.0, 0.0);

  glColor3f(0.0, 0.0, 0.9f);
  glVertex3f(-3.0, -3.0, 0.0);
  glVertex3f(-3.0, 3.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-6.5, 0.0, 0.0);

  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.0, -6.5, 0.0);
  glColor3f(0.0, 0.0, 0.9f);
  glVertex3f(3.0, -3.0, 0.0);
  glVertex3f(-3.0, -3.0, 0.0);

  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(6.5, 0.0, 0.0);
  glColor3f(0.0, 0.0, 0.9f);
  glVertex3f(3.0, 3.0, 0.0);
  glVertex3f(3.0, -3.0, 0.0);
  glEnd();

  glutSwapBuffers(); // double buffered
}

void keyboard(unsigned char key, int x, int y)
{
  /* this is the keyboard event handler
     the x and y parameters are the mouse 
     coordintes when the key was struck */
  switch (key)
    {
    case 'u':
    case 'U':
      glRotatef(3.0, 1.0, 0.0, 0.0); /* rotate up */
      break;
    case 'd':
    case 'D':
      glRotatef(-3.0, 1.0, 0.0, 0.0); /* rotate down */
      break;
    case 'l':
    case 'L':
      glRotatef(3.0, 0.0, 1.0, 0.0); /* rotate left */
      break;
    case 'r':
    case 'R':
      glRotatef(-3.0, 0.0, 1.0, 0.0); /* rotate right */
      break;
    case 'q':
      exit(0); /* quit program */
    }
  display(); /* repaint the window */
}
/**********************************************************************/



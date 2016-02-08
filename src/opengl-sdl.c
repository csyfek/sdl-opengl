/* Example of OpenGL rendering through SDL. */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>

void drawFloorf(float);
void drawScene();
void drawCubef(float, float, float, float);
void init();

void init() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2, 2, -2, 2, -2, 2);
}

void resize(float width, float height) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float h = 2.0;
	float w = h * width / height;

	printf("height: %f\n", h);
	printf("width: %f\n", w);

	glFrustum(w / -2.0, w / 2.0, h / -2.0, h / 2.0, 1, 100);

	/* note we divide our width by our height to get the aspect ratio */
	// gluPerspective(45.0, width / height, 1.0, 400.0);
	/* set initial position */
	// glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main() {
	/* Initialize SDL as usual. */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	atexit(SDL_Quit);

	/* Enable OpenGL double buffering. */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	/* Set the color depth (16-bit 565). */
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	/* Create a 640x480, 16 bit window with support for
	 OpenGL rendering. Unfortunately we won't know
	 whether this is hardware accelerated. */
	if (SDL_SetVideoMode(640, 480, 16, SDL_OPENGL) == NULL) {
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	/* Set a window title. */
	SDL_WM_SetCaption("OpenGL with SDL!", "OpenGL");

	/* We can now use any OpenGL rendering commands. */
	glViewport(0, 0, 640, 480);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();

	init();
	resize(640, 480);

	int i;
	for (i = 0; i < 360; i++) {
		drawScene(i);
		SDL_Delay(13);
	}

	/* Wait a few seconds. */
	SDL_Delay(1000);

	return 0;
}

void drawFloorf(float w) {

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	float x;
	float y = 0;
	float z1 = 10;
	float z2 = -10;
	for (x = -10; x < 10; x += w) {
		glVertex3f(x, y, z1);
		glVertex3f(x, y, z2);
	}

	float x1 = 10;
	float x2 = -10;
	float z;
	for (z = -10; z < 10; z += w) {
		glVertex3f(x1, y, z);
		glVertex3f(x2, y, z);
	}
}

void drawCubef(float w, float x, float y, float z) {
	glBegin(GL_TRIANGLES);

	glColor3f(0, 0, 1.0);

	// front face
	glVertex3f(x, y, z);
	glVertex3f(x + w, y, z);
	glVertex3f(x, y + w, z);

	glVertex3f(x, y + w, z);
	glVertex3f(x + w, y + w, z);
	glVertex3f(x + w, y, z);

	// back face
	glVertex3f(x, y, z + w);
	glVertex3f(x + w, y, z + w);
	glVertex3f(x, y + w, z + w);

	glVertex3f(x, y + w, z + w);
	glVertex3f(x + w, y + w, z + w);
	glVertex3f(x + w, y, z + w);

	// left face
	glVertex3f(x, y, z);
	glVertex3f(x, y + w, z);
	glVertex3f(x, y, z + w);

	glVertex3f(x, y + w, z);
	glVertex3f(x, y + w, z + w);
	glVertex3f(x, y, z + w);

	glEnd();

	glBegin(GL_LINES);

	glColor3f(1.0, 1.0, 0);

	glVertex3f(x, y, z);
	glVertex3f(x + w, y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y + w, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, z + w);

	glVertex3f(x + w, y + w, z + w);
	glVertex3f(x + w, y, z + w);

	glVertex3f(x + w, y + w, z + w);
	glVertex3f(x + w, y + w, z);

	glVertex3f(x + w, y + w, z + w);
	glVertex3f(x, y + w, z + w);

	glEnd();
}

void drawScene(int angle) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
	glRotatef(angle, 0, 1, 0);

//	float l = 1.0;
//	glFrustum(-1 * l, l, -1 * l, l, 1, 100.0);
//	glRotatef(angle, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();

	drawFloorf(0.2);

	glMatrixMode(GL_MODELVIEW);

//	glTranslatef(0, 0, 0);

	drawCubef(0.4, -1.0, 0, -1);
	drawCubef(0.4, -0.2, 0, -1);
	drawCubef(0.4, 0.6, 0, -1);

	SDL_GL_SwapBuffers();
}


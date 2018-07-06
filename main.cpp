#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<Windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include <string>﻿
#include <mmsystem.h>


using namespace std;
void OpeningScreen();
void view1();
void view2();
void view3();

GLfloat position = 0.0f;
GLfloat speedCloud = 0.01f;

void update(int value) {

	if (position > 1.0)
	position = -1.2f;

	position += speedCloud;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/**
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speedCloud += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}**/

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

	case 'a':
		glutDisplayFunc(view1);
		glutMainLoop();
		break;
	case 'b':
		glutDisplayFunc(view2);
		glutMainLoop();
		break;
	case 'c':
		glutDisplayFunc(view3);
		glutMainLoop();
		break;



		glutPostRedisplay();


	}
}

void drawText(const char *text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i<length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void OpeningScreen()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	std::string text1;
	std::string text2;
	std::string text3;
	text1 = "Press A : View 1";
	text2 = "Press B: View 2";
	text3 = "Press C: View 3";
	drawText(text1.data(), text1.size(), 30, 550);
	drawText(text2.data(), text2.size(), 30, 450);
	drawText(text3.data(), text3.size(), 30, 350);

	glutSwapBuffers();
	glFlush();
}


void view1()
{

	glClearColor(0.0f, 50.0f, 100.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	///--------------------------------push pop animation
	glPushMatrix();
	///---code inside here
	glTranslatef(position, 0.0f, 0.0f);

	///cloud
	glBegin(GL_QUADS); ///cloud1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.80f, 0.60f);
	glVertex2f(-0.60f, 0.60f);
	glVertex2f(-0.60f, 0.75f);
	glVertex2f(-0.80f, 0.75f);
	glEnd();

	glBegin(GL_QUADS); ///cloud2 down
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.77f, 0.60f);
	glVertex2f(-0.63f, 0.60f);
	glVertex2f(-0.63f, 0.55f);
	glVertex2f(-0.77f, 0.55f);
	glEnd();

	glBegin(GL_QUADS); ///cloud3 up
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.77f, 0.75f);
	glVertex2f(-0.63f, 0.75f);
	glVertex2f(-0.63f, 0.80f);
	glVertex2f(-0.77f, 0.80f);
	glEnd();

	glBegin(GL_QUADS); ///cloud4 left
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.85f, 0.63f);
	glVertex2f(-0.80f, 0.63f);
	glVertex2f(-0.80f, 0.72f);
	glVertex2f(-0.85f, 0.72f);
	glEnd();


	glBegin(GL_QUADS); ///cloud4 right
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.60f, 0.72f);
	glVertex2f(-0.60f, 0.63f);
	glVertex2f(-0.55f, 0.63f);
	glVertex2f(-0.55f, 0.72f);
	glEnd();

	///---------cloud end

	///pakhi

	glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f, 1.0f);
	glVertex2f(0.60f, 0.85f);
	glVertex2f(0.63f, 0.81f);
	glVertex2f(0.66f, 0.85f);
	glVertex2f(0.63f, 0.78f);
	glVertex2f(0.60f, 0.85f);
	glEnd();


	glPopMatrix();


	///------------------------------STILL CODE (NO ANIMATION)
	///--------------------
	//sun
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(0.90f, 1.0f);
	glVertex2f(0.90f, 0.9f);
	glVertex2f(1.0f, 0.9f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.90f, 1.0f);
	glVertex2f(0.82f, 1.0f);
	glVertex2f(0.82f, 0.97f);
	glVertex2f(0.90f, 0.97f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.90f, 0.97f);
	glVertex2f(0.83f, 0.97f);
	glVertex2f(0.83f, 0.95f);
	glVertex2f(0.90f, 0.95f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.90f, 0.95f);
	glVertex2f(0.84f, 0.95f);
	glVertex2f(0.84f, 0.93f);
	glVertex2f(0.90f, 0.93f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(0.90f, 0.93f);
	glVertex2f(0.85f, 0.93f);
	glVertex2f(0.85f, 0.91f);
	glVertex2f(0.90f, 0.91f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.91f);
	glVertex2f(0.86f, 0.91f);
	glVertex2f(0.86f, 0.89f);
	glVertex2f(1.0f, 0.89f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.89f);
	glVertex2f(0.87f, 0.89f);
	glVertex2f(0.87f, 0.87f);
	glVertex2f(1.0f, 0.87f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.87f);
	glVertex2f(0.88f, 0.87f);
	glVertex2f(0.88f, 0.85f);
	glVertex2f(1.0f, 0.85f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.85f);
	glVertex2f(0.89f, 0.85f);
	glVertex2f(0.89f, 0.83f);
	glVertex2f(1.0f, 0.83f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.83f);
	glVertex2f(0.90f, 0.83f);
	glVertex2f(0.90f, 0.81f);
	glVertex2f(1.0f, 0.81f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.81f);
	glVertex2f(0.91f, 0.81f);
	glVertex2f(0.91f, 0.79f);
	glVertex2f(1.0f, 0.79f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.79f);
	glVertex2f(0.92f, 0.79f);
	glVertex2f(0.92f, 0.77f);
	glVertex2f(1.0f, 0.77f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 0.77f);
	glVertex2f(0.93f, 0.77f);
	glVertex2f(0.93f, 0.75f);
	glVertex2f(1.0f, 0.75f);
	glEnd();




	///--------------------

	///structure
	glBegin(GL_QUADS); //shade
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.7f, 0.25f);
	glVertex2f(-0.65f, 0.25f);
	glVertex2f(0.1f, 0.8f);
	glVertex2f(0.1f, 0.85f);
	glEnd();

	glBegin(GL_QUADS); //opposite reverse
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.1f, 0.8f);
	glVertex2f(0.1f, 0.85f);
	glVertex2f(0.8f, 0.25f);
	glVertex2f(0.75f, 0.25f);
	glEnd();
	//------shade done

	glBegin(GL_QUADS); //bar under shade
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.60f, 0.31f);
	glVertex2f(-0.60f, -1.0f);
	glVertex2f(-0.57f, -1.0f);
	glVertex2f(-0.57f, 0.31f);
	glEnd();

	glBegin(GL_QUADS); //opposite reverse
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.68f, 0.32f);
	glVertex2f(0.68f, -1.0f);
	glVertex2f(0.65f, -1.0f);
	glVertex2f(0.65f, 0.32f);
	glEnd();
	//-----bar done

	glBegin(GL_POLYGON); //middle fill
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.1f, 0.8f);
	glVertex2f(-0.57f, 0.32f);
	glVertex2f(-0.57f, 0.0f);
	glVertex2f(0.68f, 0.0f);
	glVertex2f(0.68f, 0.32f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	std::string text1;
	text1 = "American International University Bangladesh";
	drawText(text1.data(), text1.size(), 300, 350);
	glutSwapBuffers();
	//----------done

	glBegin(GL_QUADS); //middle bar
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.57f, -0.2f);
	glVertex2f(-0.57f, -0.25f);
	glVertex2f(0.65f, -0.25f);
	glVertex2f(0.65f, -0.2f);
	glEnd();

	glBegin(GL_QUADS); //2nd middle bar
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.57f, -0.6f);
	glVertex2f(-0.57f, -0.65f);
	glVertex2f(0.65f, -0.65f);
	glVertex2f(0.65f, -0.6f);
	glEnd();

	glBegin(GL_QUADS); //jail
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.50f, 0.0f);
	glVertex2f(-0.50f, -0.65f);
	glVertex2f(-0.49f, -0.65f);
	glVertex2f(-0.49f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail2
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.43f, 0.0f);
	glVertex2f(-0.43f, -0.65f);
	glVertex2f(-0.42f, -0.65f);
	glVertex2f(-0.42f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail3
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.36f, 0.0f);
	glVertex2f(-0.36f, -0.65f);
	glVertex2f(-0.35f, -0.65f);
	glVertex2f(-0.35f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail4
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.29f, 0.0f);
	glVertex2f(-0.29f, -0.65f);
	glVertex2f(-0.28f, -0.65f);
	glVertex2f(-0.28f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail5
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.22f, 0.0f);
	glVertex2f(-0.22f, -0.65f);
	glVertex2f(-0.21f, -0.65f);
	glVertex2f(-0.21f, -0.0f);
	glEnd();


	glBegin(GL_QUADS); //jail6
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.15f, 0.0f);
	glVertex2f(-0.15f, -0.65f);
	glVertex2f(-0.14f, -0.65f);
	glVertex2f(-0.14f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail7
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.08f, 0.0f);
	glVertex2f(-0.08f, -0.65f);
	glVertex2f(-0.07f, -0.65f);
	glVertex2f(-0.07f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail8
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.01f, 0.0f);
	glVertex2f(-0.01f, -0.65f);
	glVertex2f(-0.00f, -0.65f);
	glVertex2f(-0.00f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail9
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.06f, 0.0f);
	glVertex2f(0.06f, -0.65f);
	glVertex2f(0.07f, -0.65f);
	glVertex2f(0.07f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail10
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.13f, 0.0f);
	glVertex2f(0.13f, -0.65f);
	glVertex2f(0.14f, -0.65f);
	glVertex2f(0.14f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail11
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.20f, 0.0f);
	glVertex2f(0.20f, -0.65f);
	glVertex2f(0.21f, -0.65f);
	glVertex2f(0.21f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail12
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.27f, 0.0f);
	glVertex2f(0.27f, -0.65f);
	glVertex2f(0.28f, -0.65f);
	glVertex2f(0.28f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail13
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.34f, 0.0f);
	glVertex2f(0.34f, -0.65f);
	glVertex2f(0.35f, -0.65f);
	glVertex2f(0.35f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail14
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.41f, 0.0f);
	glVertex2f(0.41f, -0.65f);
	glVertex2f(0.42f, -0.65f);
	glVertex2f(0.42f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail15
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.48f, 0.0f);
	glVertex2f(0.48f, -0.65f);
	glVertex2f(0.49f, -0.65f);
	glVertex2f(0.49f, -0.0f);
	glEnd();

	glBegin(GL_QUADS); //jail16
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.55f, 0.0f);
	glVertex2f(0.55f, -0.65f);
	glVertex2f(0.56f, -0.65f);
	glVertex2f(0.56f, -0.0f);
	glEnd();
	//----jail done

	///----------------will transfer later

	glBegin(GL_QUADS); //middle bar side up left
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.60f, -0.2f);
	glVertex2f(-0.60f, -0.29f);
	glVertex2f(-1.0f, -0.29f);
	glVertex2f(-1.0f, -0.2f);
	glEnd();

	glBegin(GL_QUADS); //middle bar side down left
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.60f, -0.6f);
	glVertex2f(-0.60f, -0.69f);
	glVertex2f(-1.0f, -0.69f);
	glVertex2f(-1.0f, -0.6f);
	glEnd();


	glBegin(GL_QUADS); //middle bar side  up right
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.68f, -0.2f);
	glVertex2f(0.68f, -0.29f);
	glVertex2f(1.0f, -0.29f);
	glVertex2f(1.0f, -0.2f);
	glEnd();

	glBegin(GL_QUADS); //middle bar side up left
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.68f, -0.6f);
	glVertex2f(0.68f, -0.69f);
	glVertex2f(1.0f, -0.69f);
	glVertex2f(1.0f, -0.6f);
	glEnd();

	///middle line

	glBegin(GL_LINES); ///middle line 1 left
	glLineWidth(.9);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-1.0f, -0.4f);
	glVertex2f(-0.60f, -0.4f);
	glEnd();

	glBegin(GL_LINES); ///middle line 2 left
	glLineWidth(.9);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-1.0f, -0.38f);
	glVertex2f(-0.60f, -0.38f);
	glEnd();

	glBegin(GL_LINES); ///middle line 1 left
	glLineWidth(.9);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(1.0f, -0.4f);
	glVertex2f(0.68f, -0.4f);
	glEnd();

	glBegin(GL_LINES); ///middle line 2 left
	glLineWidth(.9);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(1.0f, -0.38f);
	glVertex2f(0.68f, -0.38f);
	glEnd();


	//lines done-----------

	///tree tub
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-1.0f, -0.6f);
	glVertex2f(-0.90f, -0.6f);
	glVertex2f(-0.90f, -0.55f);
	glVertex2f(-1.0f, -0.55f);
	glEnd();

	///tree tub
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-0.85f, -0.6f);
	glVertex2f(-0.75f, -0.6f);
	glVertex2f(-0.75f, -0.55f);
	glVertex2f(-0.85f, -0.55f);
	glEnd();

	///tree tub
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(-0.70f, -0.6f);
	glVertex2f(-0.60f, -0.6f);
	glVertex2f(-0.60f, -0.55f);
	glVertex2f(-0.70f, -0.55f);
	glEnd();

	///tree tub
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(1.0f, -0.6f);
	glVertex2f(0.90f, -0.6f);
	glVertex2f(0.90f, -0.55f);
	glVertex2f(1.0f, -0.55f);
	glEnd();

	///tree tub
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(0.85f, -0.6f);
	glVertex2f(0.75f, -0.6f);
	glVertex2f(0.75f, -0.55f);
	glVertex2f(0.85f, -0.55f);
	glEnd();


	///down pillar
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.90f, -0.69f);
	glVertex2f(-0.90f, -1.0f);
	glVertex2f(-0.92f, -1.0f);
	glVertex2f(-0.92f, -0.69f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(-0.70f, -0.69f);
	glVertex2f(-0.70f, -1.0f);
	glVertex2f(-0.72f, -1.0f);
	glVertex2f(-0.72f, -0.69f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(0.90f, -0.69f);
	glVertex2f(0.90f, -1.0f);
	glVertex2f(0.92f, -1.0f);
	glVertex2f(0.92f, -0.69f);
	glEnd();



	///-----------up generators
	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-1.0f, -0.2f);
	glVertex2f(-1.0f, -0.10f);
	glVertex2f(-0.95f, -0.10f);
	glVertex2f(-0.95f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.90f, -0.2f);
	glVertex2f(-0.90f, -0.06f);
	glVertex2f(-0.85f, -0.06f);
	glVertex2f(-0.85f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.80f, -0.2f);
	glVertex2f(-0.80f, -0.10f);
	glVertex2f(-0.75f, -0.10f);
	glVertex2f(-0.75f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(-0.70f, -0.2f);
	glVertex2f(-0.70f, -0.06f);
	glVertex2f(-0.65f, -0.06f);
	glVertex2f(-0.65f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(1.0f, -0.2f);
	glVertex2f(1.0f, -0.10f);
	glVertex2f(0.95f, -0.10f);
	glVertex2f(0.95f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.90f, -0.2f);
	glVertex2f(0.90f, -0.04f);
	glVertex2f(0.85f, -0.04f);
	glVertex2f(0.85f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(0.80f, -0.2f);
	glVertex2f(0.80f, -0.08f);
	glVertex2f(0.75f, -0.08f);
	glVertex2f(0.75f, -0.2f);
	glEnd();

	///-------generator done


	///--------------up to this


	///-----house done

	///---tree
	glBegin(GL_QUADS); ///bamboo
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(0.78f, -1.0f);
	glVertex2f(0.83f, -1.0f);
	glVertex2f(0.83f, -0.45f);
	glVertex2f(0.78f, -0.45f);
	glEnd();

	glBegin(GL_QUADS); ///leaf1
	glColor3f(0.0f,0.9f, 0.5f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.90f, -0.45f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.75f, -0.20f);
	glEnd();


	glBegin(GL_QUADS); ///leaf2
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.70f, -0.45f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.75f, -0.40f);
	glVertex2f(0.70f, -0.40f);
	glEnd();

	glBegin(GL_QUADS); ///leaf3
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.65f, -0.40f);
	glVertex2f(0.75f, -0.40f);
	glVertex2f(0.75f, -0.35f);
	glVertex2f(0.65f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf4
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.62f, -0.35f);
	glVertex2f(0.75f, -0.35f);
	glVertex2f(0.75f, -0.30f);
	glVertex2f(0.62f, -0.30f);
	glEnd();

	glBegin(GL_QUADS); ///leaf5
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.60f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glVertex2f(0.75f, -0.20f);
	glVertex2f(0.60f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.65f, -0.20f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.65f, -0.15f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.70f, -0.15f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.90f, -0.10f);
	glVertex2f(0.70f, -0.10f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.95f, -0.15f);
	glVertex2f(0.95f, -0.20f);
	glVertex2f(0.90f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.98f, -0.20f);
	glVertex2f(0.98f, -0.30f);
	glVertex2f(0.90f, -0.30f);
	glEnd();


	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.30f);
	glVertex2f(0.95f, -0.30f);
	glVertex2f(0.95f, -0.35f);
	glVertex2f(0.90f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.35f);
	glVertex2f(0.93f, -0.35f);
	glVertex2f(0.93f, -0.40f);
	glVertex2f(0.90f, -0.40f);
	glEnd();

	//--------tree end
	//----------------------------FLAG-----------------
	//flag bLUE
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.6f);
	glVertex2f(-0.50f, 0.0f);
	glVertex2f(-0.50f, -0.25f);
	glVertex2f(-0.32f, -0.25f);
	glVertex2f(-0.32f, 0.0f);
	glEnd();

	//flag(handle)
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.32f, 0.0f);
	glVertex2f(-0.32f, -1.0f);
	glVertex2f(-0.30f, -1.0f);
	glVertex2f(-0.30f, 0.0f);
	glEnd();


	//----blue flag done

	///orange flag
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2f(-0.27f, -0.27f);
	glVertex2f(-0.27f, -0.52f);
	glVertex2f(-0.09f, -0.52f);
	glVertex2f(-0.09f, -0.27f);
	glEnd();

	//orange flag handle
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.09f, -0.27f);
	glVertex2f(-0.09f, -1.0f);
	glVertex2f(-0.07f, -1.0f);
	glVertex2f(-0.07f, -0.27f);
	glEnd();


	///green flag
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.9f, 0.0f);
	glVertex2f(-0.61f, -0.27f);
	glVertex2f(-0.61f, -0.52f);
	glVertex2f(-0.42f, -0.52f);
	glVertex2f(-0.42f, -0.27f);
	glEnd();

	//green flag handle
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.42f, -0.27f);
	glVertex2f(-0.42f, -1.0f);
	glVertex2f(-0.44f, -1.0f);
	glVertex2f(-0.44f, -0.27f);
	glEnd();

	///red flag
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.84f, -0.27f);
	glVertex2f(-0.84f, -0.52f);
	glVertex2f(-0.65f, -0.52f);
	glVertex2f(-0.65f, -0.27f);
	glEnd();

	//red flag handle
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.65f, -0.27f);
	glVertex2f(-0.65f, -1.0f);
	glVertex2f(-0.67f, -1.0f);
	glVertex2f(-0.67f, -0.27f);
	glEnd();

	///sky blue flag
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(0.17f, -0.27f);
	glVertex2f(0.17f, -0.52f);
	glVertex2f(0.0f, -0.52f);
	glVertex2f(0.0f, -0.27f);
	glEnd();

	//sky blue flag handle
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(0.17f, -0.27f);
	glVertex2f(0.17f, -1.0f);
	glVertex2f(0.19f, -1.0f);
	glVertex2f(0.19f, -0.27f);
	glEnd();



	glFlush();

}

void view2()
{
	glClearColor(0.0f, 50.0f, 100.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	int number = 40; /// NUMBER OF VERTICES
	float radius = 0.5f;
	float twopi = 2.0*3.14524;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	for (int i = 0; i <= 40; i++)
	{
		glVertex2f(radius*cosf(i*twopi / number), radius*sinf(i*twopi / number));
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5f, 1.0f, 0.0f);
	glVertex2f(-1.0f, -0.1f);
	glVertex2f(-1.0f, -0.2f);
	glVertex2f(1.0f, -0.4f);
	glVertex2f(1.f, -0.3f);
	glEnd();

	/// Circle End


	glPushMatrix();
	///---code inside here
	glTranslatef(position, 0.0f, 0.0f);

	///cloud
	glBegin(GL_QUADS); ///cloud1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.80f, 0.60f);
	glVertex2f(-0.60f, 0.60f);
	glVertex2f(-0.60f, 0.75f);
	glVertex2f(-0.80f, 0.75f);
	glEnd();

	glBegin(GL_QUADS); ///cloud2 down
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.77f, 0.60f);
	glVertex2f(-0.63f, 0.60f);
	glVertex2f(-0.63f, 0.55f);
	glVertex2f(-0.77f, 0.55f);
	glEnd();

	glBegin(GL_QUADS); ///cloud3 up
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.77f, 0.75f);
	glVertex2f(-0.63f, 0.75f);
	glVertex2f(-0.63f, 0.80f);
	glVertex2f(-0.77f, 0.80f);
	glEnd();

	glBegin(GL_QUADS); ///cloud4 left
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.85f, 0.63f);
	glVertex2f(-0.80f, 0.63f);
	glVertex2f(-0.80f, 0.72f);
	glVertex2f(-0.85f, 0.72f);
	glEnd();


	glBegin(GL_QUADS); ///cloud4 right
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.60f, 0.72f);
	glVertex2f(-0.60f, 0.63f);
	glVertex2f(-0.55f, 0.63f);
	glVertex2f(-0.55f, 0.72f);
	glEnd();

	glPopMatrix();

	///---------cloud end


	///Another Cloud



	glPushMatrix();
	///---code inside here
	glTranslatef(position, 0.0f, 0.0f);

	///cloud
	glBegin(GL_QUADS); ///cloud1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.80f, 0.60f);
	glVertex2f(0.60f, 0.60f);
	glVertex2f(0.60f, 0.75f);
	glVertex2f(0.80f, 0.75f);
	glEnd();

	glBegin(GL_QUADS); ///cloud2 down
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.77f, 0.60f);
	glVertex2f(0.63f, 0.60f);
	glVertex2f(0.63f, 0.55f);
	glVertex2f(0.77f, 0.55f);
	glEnd();

	glBegin(GL_QUADS); ///cloud3 up
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.77f, 0.75f);
	glVertex2f(0.63f, 0.75f);
	glVertex2f(0.63f, 0.80f);
	glVertex2f(0.77f, 0.80f);
	glEnd();

	glBegin(GL_QUADS); ///cloud4 left
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.85f, 0.63f);
	glVertex2f(0.80f, 0.63f);
	glVertex2f(0.80f, 0.72f);
	glVertex2f(0.85f, 0.72f);
	glEnd();


	glBegin(GL_QUADS); ///cloud4 right
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.60f, 0.72f);
	glVertex2f(0.60f, 0.63f);
	glVertex2f(0.55f, 0.63f);
	glVertex2f(0.55f, 0.72f);
	glEnd();

	glPopMatrix();

	///Mati

	glBegin(GL_QUADS);
	glColor3f(1.5f, .35f, 0.05f);
	glVertex2f(-1.0f, -0.2f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.4f);
	glEnd();


	/// Window1

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.8f, -0.4f);
	glVertex2f(-0.8f, -0.7f);
	glVertex2f(-0.5f, -0.7f);
	glVertex2f(-0.5f, -0.4f);
	glEnd();

	///Window2

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.2f, -0.4f);
	glVertex2f(-0.2f, -0.7f);
	glVertex2f(0.1f, -0.7f);
	glVertex2f(0.1f, -0.4f);
	glEnd();

	///Window3

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(0.4f, -0.7f);
	glVertex2f(0.7f, -0.7f);
	glVertex2f(0.7f, -0.4f);
	glEnd();

	///Window1 Black1
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.78f, -0.45f);
	glVertex2f(-0.78f, -0.65f);
	glVertex2f(-0.71f, -0.65f);
	glVertex2f(-0.71f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.69f, -0.45f);
	glVertex2f(-0.69f, -0.65f);
	glVertex2f(-0.61f, -0.65f);
	glVertex2f(-0.61f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.59f, -0.45f);
	glVertex2f(-0.59f, -0.65f);
	glVertex2f(-0.52f, -0.65f);
	glVertex2f(-0.52f, -0.45f);
	glEnd();

	///Window2 Black2

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.18f, -0.45f);
	glVertex2f(-0.18f, -0.65f);
	glVertex2f(-0.11f, -0.65f);
	glVertex2f(-0.11f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.09f, -0.45f);
	glVertex2f(-0.09f, -0.65f);
	glVertex2f(-0.01f, -0.65f);
	glVertex2f(-0.01f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.01f, -0.45f);
	glVertex2f(0.01f, -0.65f);
	glVertex2f(0.08f, -0.65f);
	glVertex2f(0.08f, -0.45f);
	glEnd();

	///Window3 Black3

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.42f, -0.45f);
	glVertex2f(0.42f, -0.65f);
	glVertex2f(0.49f, -0.65f);
	glVertex2f(0.49f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.51f, -0.45f);
	glVertex2f(0.51f, -0.65f);
	glVertex2f(0.59f, -0.65f);
	glVertex2f(0.59f, -0.45f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.61f, -0.45f);
	glVertex2f(0.61f, -0.65f);
	glVertex2f(0.68f, -0.65f);
	glVertex2f(0.68f, -0.45f);
	glEnd();


	///---tree
	glBegin(GL_QUADS); ///bamboo
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(0.78f, -1.0f);
	glVertex2f(0.83f, -1.0f);
	glVertex2f(0.83f, -0.45f);
	glVertex2f(0.78f, -0.45f);
	glEnd();

	glBegin(GL_QUADS); ///leaf1
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.90f, -0.45f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.75f, -0.20f);
	glEnd();


	glBegin(GL_QUADS); ///leaf2
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.70f, -0.45f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.75f, -0.40f);
	glVertex2f(0.70f, -0.40f);
	glEnd();

	glBegin(GL_QUADS); ///leaf3
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.65f, -0.40f);
	glVertex2f(0.75f, -0.40f);
	glVertex2f(0.75f, -0.35f);
	glVertex2f(0.65f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf4
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.62f, -0.35f);
	glVertex2f(0.75f, -0.35f);
	glVertex2f(0.75f, -0.30f);
	glVertex2f(0.62f, -0.30f);
	glEnd();

	glBegin(GL_QUADS); ///leaf5
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.60f, -0.30f);
	glVertex2f(0.75f, -0.30f);
	glVertex2f(0.75f, -0.20f);
	glVertex2f(0.60f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.65f, -0.20f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.65f, -0.15f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.70f, -0.15f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.90f, -0.10f);
	glVertex2f(0.70f, -0.10f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.15f);
	glVertex2f(0.95f, -0.15f);
	glVertex2f(0.95f, -0.20f);
	glVertex2f(0.90f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.20f);
	glVertex2f(0.98f, -0.20f);
	glVertex2f(0.98f, -0.30f);
	glVertex2f(0.90f, -0.30f);
	glEnd();


	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.30f);
	glVertex2f(0.95f, -0.30f);
	glVertex2f(0.95f, -0.35f);
	glVertex2f(0.90f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(0.90f, -0.35f);
	glVertex2f(0.93f, -0.35f);
	glVertex2f(0.93f, -0.40f);
	glVertex2f(0.90f, -0.40f);
	glEnd();

	///Tree END

	///Another Tree


	///---tree
	glBegin(GL_QUADS); ///bamboo
	glColor3f(0.5f, 0.35f, 0.05f);
	glVertex2f(-0.88f, -1.0f);
	glVertex2f(-0.93f, -1.0f);
	glVertex2f(-0.93f, -0.45f);
	glVertex2f(-0.88f, -0.45f);
	glEnd();

	glBegin(GL_QUADS); ///leaf1
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.85f, -0.45f);
	glVertex2f(-0.90f, -0.45f);
	glVertex2f(-0.90f, -0.20f);
	glVertex2f(-0.85f, -0.20f);
	glEnd();


	glBegin(GL_QUADS); ///leaf2
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.80f, -0.45f);
	glVertex2f(-0.85f, -0.45f);
	glVertex2f(-0.85f, -0.40f);
	glVertex2f(-0.80f, -0.40f);
	glEnd();

	glBegin(GL_QUADS); ///leaf3
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.75f, -0.40f);
	glVertex2f(-0.85f, -0.40f);
	glVertex2f(-0.85f, -0.35f);
	glVertex2f(-0.75f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf4
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.72f, -0.35f);
	glVertex2f(-0.85f, -0.35f);
	glVertex2f(-0.85f, -0.30f);
	glVertex2f(-0.72f, -0.30f);
	glEnd();

	glBegin(GL_QUADS); ///leaf5
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.70f, -0.30f);
	glVertex2f(-0.85f, -0.30f);
	glVertex2f(-0.85f, -0.20f);
	glVertex2f(-0.70f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.75f, -0.20f);
	glVertex2f(-1.0f, -0.20f);
	glVertex2f(-1.0f, -0.15f);
	glVertex2f(-0.75f, -0.15f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.80f, -0.15f);
	glVertex2f(-1.0f, -0.15f);
	glVertex2f(-1.0f, -0.10f);
	glVertex2f(-0.80f, -0.10f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.90f, -0.15f);
	glVertex2f(-0.95f, -0.15f);
	glVertex2f(-0.95f, -0.20f);
	glVertex2f(-0.90f, -0.20f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.90f, -0.20f);
	glVertex2f(-1.0f, -0.20f);
	glVertex2f(-1.0f, -0.30f);
	glVertex2f(-0.90f, -0.30f);
	glEnd();


	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.90f, -0.30f);
	glVertex2f(-1.0f, -0.30f);
	glVertex2f(-1.0f, -0.35f);
	glVertex2f(-0.90f, -0.35f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.90f, -0.35f);
	glVertex2f(-0.99f, -0.35f);
	glVertex2f(-0.99f, -0.40f);
	glVertex2f(-0.90f, -0.40f);
	glEnd();

	glBegin(GL_QUADS); ///leaf6
	glColor3f(0.0f, 0.9f, 0.5f);
	glVertex2f(-0.90f, -0.40f);
	glVertex2f(-0.96f, -0.40f);
	glVertex2f(-0.96f, -0.45f);
	glVertex2f(-0.90f, -0.45f);
	glEnd();

	///Circle Lines 1

	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(0.0f, -0.2f);    // x, y
	glVertex2f(0.0f, 0.5f);    // x, y
	glEnd();

	/// Circle Lines 2
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(0.1f, -0.21f);    // x, y
	glVertex2f(0.1f, 0.49f);    // x, y
	glEnd();

	/// Circle Lines 3
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(0.2f, -0.22f);    // x, y
	glVertex2f(0.2f, 0.46f);    // x, y
	glEnd();

	/// Circle Lines 4
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(0.3f, -0.23f);    // x, y
	glVertex2f(0.3f, 0.4f);    // x, y
	glEnd();

	/// Circle Lines 5
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(0.4f, -0.24f);    // x, y
	glVertex2f(0.4f, 0.3f);    // x, y
	glEnd();

	/// Circle Lines 6
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.1f, -0.19f);    // x, y
	glVertex2f(-0.1f, 0.49f);    // x, y
	glEnd();

	///Circle Lines 7
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.2f, -0.18f);    // x, y
	glVertex2f(-0.2f, 0.46f);    // x, y
	glEnd();

	/// Circle Lines 8
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.3f, -0.17f);    // x, y
	glVertex2f(-0.3f, 0.4f);    // x, y
	glEnd();

	/// Circle Lines 9
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.4f, -0.16f);    // x, y
	glVertex2f(-0.4f, 0.3f);    // x, y
	glEnd();

	/// Circle Lines 10
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.4f, 0.3f);    // x, y
	glVertex2f(0.4f, 0.3f);    // x, y
	glEnd();

	/// Circle Lines 11
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.49f, 0.1f);    // x, y
	glVertex2f(0.49f, 0.1f);    // x, y
	glEnd();

	/// Circle Lines 12
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // Black
	glVertex2f(-0.49f, -0.1f);    // x, y
	glVertex2f(0.49f, -0.1f);    // x, y
	glEnd();



	glFlush();

}

void view3() ///EMON
{
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);



	//AIUB LIKHA
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(-0.5f, 1.0f);    // x, y
	glVertex2f(-0.5f, 0.35f);
	glVertex2f(0.5f, 0.35f);
	glVertex2f(0.5f, 1.0f);
	glEnd();



	//White Color Under the AIUB
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.5f, 0.5f);    // x, y
	glVertex2f(-0.5f, 0.45f);
	glVertex2f(0.5f, 0.45f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	//left side of aiub likha beside white
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(-0.5f, 0.5f);    // x, y
	glVertex2f(-1.0f, 0.5f);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(-0.5f, 0.45f);
	glEnd();

	//right side of previous
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(0.5f, 0.5f);    // x, y
	glVertex2f(1.0f, 0.5f);
	glVertex2f(1.0f, 0.45f);
	glVertex2f(0.5f, 0.45f);
	glEnd();


	//left side line
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(-1.0f, 0.45f);    // x, y
	glVertex2f(-0.55f, 0.45f);
	glVertex2f(-0.55f, 0.35f);
	glVertex2f(-1.0f, 0.35f);
	glEnd();




	//right side line
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(0.55f, 0.45f);    // x, y
	glVertex2f(1.0f, 0.45f);
	glVertex2f(1.0f, 0.35f);
	glVertex2f(0.55f, 0.35f);
	glEnd();




	//left side pillar
	glBegin(GL_QUADS);
	glColor3f(0.309804f, 0.309804f, 0.184314f);
	glVertex2f(-0.55f, 0.45f);    // x, y
	glVertex2f(-0.50f, 0.45f);
	glVertex2f(-0.50f, -0.5f);
	glVertex2f(-0.55f, -0.5f);
	glEnd();



	//right side pillar
	glBegin(GL_QUADS);
	glColor3f(0.309804f, 0.309804f, 0.184314f);
	glVertex2f(0.55f, 0.45f);    // x, y
	glVertex2f(0.50f, 0.45f);
	glVertex2f(0.50f, -0.5f);
	glVertex2f(0.55f, -0.5f);
	glEnd();




	//3rd quad line
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(1.0f, 0.20f);    // x, y
	glVertex2f(-1.0f, 0.20f);
	glVertex2f(-1.0f, 0.15f);
	glVertex2f(1.0f, 0.15f);
	glEnd();





	//1st pillar under aiub
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(-0.38f, 0.35f);    // x, y
	glVertex2f(-0.36f, 0.35f);
	glVertex2f(-0.36f, 0.15f);
	glVertex2f(-.38f, 0.15f);
	glEnd();


	//2nd pillar under aiub
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(-0.08f, 0.35f);    // x, y
	glVertex2f(-0.06f, 0.35f);
	glVertex2f(-0.06f, 0.15f);
	glVertex2f(-.08f, 0.15f);
	glEnd();




	//3rd pillar under aiub
	glBegin(GL_QUADS);
	glColor3f(0.90f, 0.91f, 0.98f);
	glVertex2f(0.3f, 0.35f);    // x, y
	glVertex2f(0.32f, 0.35f);
	glVertex2f(0.32f, 0.15f);
	glVertex2f(0.3f, 0.15f);
	glEnd();


	//White Color reiling
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-1.0f, 0.31f);    // x, y
	glVertex2f(1.0f, 0.31f);
	glVertex2f(1.0f, 0.29f);
	glVertex2f(-1.0f, 0.29f);
	glEnd();



	//Green shade under
	glBegin(GL_QUADS);
	glColor3f(0.309804f, 0.309804f, 0.184314f);
	glVertex2f(-0.5f, 0.15f);    // x, y
	glVertex2f(0.5f, 0.15f);
	glVertex2f(0.5f, 0.05f);
	glVertex2f(-0.5f, 0.05f);
	glEnd();



	//Writing A
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.20f, 0.60f);    // x, y
	glVertex2f(-0.15f, 0.75f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.15f, 0.75f);    // x, y
	glVertex2f(-0.10f, 0.60f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.18f, 0.65f);    // x, y
	glVertex2f(-0.12f, 0.65f);    // x, y

	glEnd();

	/////Done


	//Writing I


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.05f, 0.60f);    // x, y
	glVertex2f(-0.05f, 0.75f);    // x, y

	glEnd();





	//Writing U


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.60f);    // x, y
	glVertex2f(0.0f, 0.75f);    // x, y

	glEnd();



	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.61f);    // x, y
	glVertex2f(0.05f, 0.61f);    // x, y

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.05f, 0.60f);    // x, y
	glVertex2f(0.05f, 0.75f);    // x, y

	glEnd();



	//Writing B


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f, 0.60f);    // x, y
	glVertex2f(0.1f, 0.75f);    // x, y

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f, 0.61f);    // x, y
	glVertex2f(0.15f, 0.61f);    // x, y

	glEnd();




	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.15f, 0.60f);    // x, y
	glVertex2f(0.15f, 0.75f);    // x, y

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.15f, 0.74f);    // x, y
	glVertex2f(0.1f, 0.74f);    // x, y

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.15f, 0.67f);    // x, y
	glVertex2f(0.1f, 0.67f);    // x, y

	glEnd();







	//Done




	//Sky   Color left side
	glBegin(GL_QUADS);
	glColor3f(0.196078f, 0.6f, 0.8f);
	glVertex2f(-0.5f, 0.5f);    // x, y
	glVertex2f(-0.5f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(-1.0f, 0.5f);
	glEnd();


	//Sky   Color right side
	glBegin(GL_QUADS);
	glColor3f(0.196078f, 0.6f, 0.8f);
	glVertex2f(0.5f, 0.5f);    // x, y
	glVertex2f(0.5f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.5f);
	glEnd();





	//Up border of aiub


	glBegin(GL_QUADS);

	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(-0.55f, 1.0f);    // x, y
	glVertex2f(-0.53f, 0.95f);    // x, y
	glVertex2f(0.53f, 0.95f);    // x, y
	glVertex2f(0.55f, 1.0f);    // x, y
	glEnd();
	//Border of AIUB


	glBegin(GL_LINES);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(-0.5f, 1.0f);    // x, y
	glVertex2f(-0.5f, 0.50f);    // x, y

	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(-0.5f, 0.50f);    // x, y
	glVertex2f(0.5f, 0.50f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(0.5f, 0.50f);    // x, y
	glVertex2f(0.5f, 1.0f); // x, y
	glEnd();


	//AC Cooler






	glBegin(GL_QUADS);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(-0.7f, 0.5f);    // x, y
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-0.75f, 0.65f);
	glVertex2f(-0.7f, 0.65f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(-0.8f, 0.5f);    // x, y
	glVertex2f(-0.85f, 0.5f);
	glVertex2f(-0.85f, 0.75f);
	glVertex2f(-0.8f, 0.75f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(0.7f, 0.5f);    // x, y
	glVertex2f(0.75f, 0.5f);
	glVertex2f(0.75f, 0.65f);
	glVertex2f(0.7f, 0.65f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glVertex2f(0.8f, 0.5f);    // x, y
	glVertex2f(0.85f, 0.5f);
	glVertex2f(0.85f, 0.75f);
	glVertex2f(0.8f, 0.75f);
	glEnd();




	glPushMatrix();

	glTranslatef(position, 0.0f, 0.0f);
	///---code inside here

	//CAR

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0f, 0.0f);
	glVertex2f(-0.30f, -0.65f);    // x, y
	glVertex2f(-0.25f, -0.50f);
	glVertex2f(0.0f, -0.50f);
	glVertex2f(0.05f, -0.65f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0f, 0.0f);;//yellow
	glVertex2f(-0.40f, -0.65f);    // x, y
	glVertex2f(0.15f, -0.65f);
	glVertex2f(0.15f, -0.80f);
	glVertex2f(-0.40f, -0.80f);
	glEnd();

	//1st tire
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0f, 0.0f);;//yellow
	glVertex2f(-0.30f, -0.80f);    // x, y
	glVertex2f(-0.32f, -0.84f);
	glVertex2f(-0.30f, -0.90f);
	glVertex2f(-0.25f, -0.90f);
	glVertex2f(-0.23f, -0.84f);
	glVertex2f(-0.25f, -0.80f);

	glEnd();

	//2nd tire

	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0f, 0.0f);;//yellow
	glVertex2f(0.05f, -0.80f);    // x, y
	glVertex2f(0.03f, -0.84f);
	glVertex2f(0.05f, -0.90f);
	glVertex2f(0.10f, -0.90f);
	glVertex2f(0.12f, -0.84f);
	glVertex2f(0.10f, -0.80f);

	glEnd();


	glPopMatrix();

	///--------------------PUSH POP ANIMATION DONE

	//Tree


	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.9f, -0.3f);    // x, y
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.6f, -0.4f);
	glVertex2f(-0.9f, -0.4f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.87f, -0.3f);    // x, y
	glVertex2f(-0.63f, -0.3f);
	glVertex2f(-0.63f, -0.25f);
	glVertex2f(-0.87f, -0.25f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.85f, -0.25f);    // x, y
	glVertex2f(-0.65f, -0.25f);
	glVertex2f(-0.65f, -0.2f);
	glVertex2f(-0.85f, -0.2);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.83f, -0.2f);    // x, y
	glVertex2f(-0.67f, -0.2f);
	glVertex2f(-0.67f, -0.18f);
	glVertex2f(-0.83f, -0.18);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.81f, -0.18f);    // x, y
	glVertex2f(-0.69f, -0.18f);
	glVertex2f(-0.69f, -0.16f);
	glVertex2f(-0.81f, -0.16);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.87f, -0.4f);    // x, y
	glVertex2f(-0.63f, -0.4f);
	glVertex2f(-0.63f, -0.45f);
	glVertex2f(-0.87f, -0.45f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.85f, -0.45f);    // x, y
	glVertex2f(-0.65f, -0.45f);
	glVertex2f(-0.65f, -0.5f);
	glVertex2f(-0.85f, -0.5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.83f, -0.5f);    // x, y
	glVertex2f(-0.67f, -0.5f);
	glVertex2f(-0.67f, -0.55f);
	glVertex2f(-0.83f, -0.55);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.647059f, 0.164706f, 0.164706f);
	glVertex2f(-0.76f, -0.55f);    // x, y
	glVertex2f(-0.74f, -0.55f);
	glVertex2f(-0.74f, -1.0f);
	glVertex2f(-0.76f, -1.0);
	glEnd();



	//Right side Tree


	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.9f, -0.3f);    // x, y
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.6f, -0.4f);
	glVertex2f(0.9f, -0.4f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.87f, -0.3f);    // x, y
	glVertex2f(0.63f, -0.3f);
	glVertex2f(0.63f, -0.25f);
	glVertex2f(0.87f, -0.25f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.85f, -0.25f);    // x, y
	glVertex2f(0.65f, -0.25f);
	glVertex2f(0.65f, -0.2f);
	glVertex2f(0.85f, -0.2);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.83f, -0.2f);    // x, y
	glVertex2f(0.67f, -0.2f);
	glVertex2f(0.67f, -0.18f);
	glVertex2f(0.83f, -0.18);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.81f, -0.18f);    // x, y
	glVertex2f(0.69f, -0.18f);
	glVertex2f(0.69f, -0.16f);
	glVertex2f(0.81f, -0.16);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.87f, -0.4f);    // x, y
	glVertex2f(0.63f, -0.4f);
	glVertex2f(0.63f, -0.45f);
	glVertex2f(0.87f, -0.45f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.85f, -0.45f);    // x, y
	glVertex2f(0.65f, -0.45f);
	glVertex2f(0.65f, -0.5f);
	glVertex2f(0.85f, -0.5);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.83f, -0.5f);    // x, y
	glVertex2f(0.67f, -0.5f);
	glVertex2f(0.67f, -0.55f);
	glVertex2f(0.83f, -0.55);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.647059f, 0.164706f, 0.164706f);
	glVertex2f(0.76f, -0.55f);    // x, y
	glVertex2f(0.74f, -0.55f);
	glVertex2f(0.74f, -1.0f);
	glVertex2f(0.76f, -1.0);
	glEnd();


	/// Road

	glBegin(GL_QUADS);

	glColor3f(0.0, 0.0f, 0.0f);;//Black
	glVertex2f(-1.0f, -0.9f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.9f);
	glEnd();

	/// Road Whiteness 1

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0f, 1.0f);;//Black
	glVertex2f(-0.8f, -0.94f);
	glVertex2f(-0.8f, -0.97f);
	glVertex2f(-0.5f, -0.97f);
	glVertex2f(-0.5f, -0.94f);
	glEnd();

	/// Road Whiteness 2

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0f, 1.0f);;//Black
	glVertex2f(-0.2f, -0.94f);
	glVertex2f(-0.2f, -0.97f);
	glVertex2f(0.1f, -0.97f);
	glVertex2f(0.1f, -0.94f);
	glEnd();

	/// Road Whiteness 3

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0f, 1.0f);;//Black
	glVertex2f(0.4f, -0.94f);
	glVertex2f(0.4f, -0.97f);
	glVertex2f(0.7f, -0.97f);
	glVertex2f(0.7f, -0.94f);
	glEnd();



	glFlush();  // Render now
}



void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



	glPushMatrix();
	///---code inside here



	glPopMatrix();



	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("AIUB Campus");
    glutDisplayFunc(OpeningScreen); ///this is the main to open
	//glutDisplayFunc(view2);
	//glutDisplayFunc(View2);


	init();
	glutKeyboardFunc(handleKeypress);
	sndPlaySound("test.wav",SND_ASYNC);
	//PlaySound(TEXT("test.wav"),NULL,SND_SYNC);
	//glutMouseFunc(handleMouse);
	glutTimerFunc(100, update, 0);
	glutMainLoop();
	return 0;
}


#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::KeyboardUpdate);
	glutMainLoop();
	GLUTCallbacks::Timer(REFRESHRATE);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //clears the scene
	DrawRectangle(); //draws rectangle
	DrawTriangle(); //draws Triangle
	glFlush(); //flushes the scene to the GPU
	glutSwapBuffers();
}

void HelloGL::DrawRectangle()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON); //starts to draw polygons
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //blue
		glVertex2f(-0.75, 0.5); //Defines the first polygon in the top left
		glVertex2f(0.75, 0.5); //next point top right
		glVertex2f(0.75, -0.5); // bottom right
		glVertex2f(-0.75, -0.5); //last polygon, bottom left.
		glEnd(); //ends the draw
	}

	glPopMatrix();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(0.75, -0.5); // bottom right
		glVertex2f(-0.75, 0.5); //Defines the first polygon in the top left
		glVertex2f(0.75, 0.5); //next point top right
		glEnd(); //ends the draw
	}
	glPopMatrix();
}


void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;	
	}
}

void HelloGL::KeyboardUpdate(unsigned char key, int x, int y)
{
	{
		if (key == 'd')
		{
			rotation = +0.5;
		}

	}
}


#include "HelloGL.h"

void keyInput(unsigned char key, int x, int y) {
	return;
}

HelloGL::HelloGL(int argc, char* argv[])
{
	cube3D = new Cube3D;
	rotation = 0.0f;	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(keyInput);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	//glutKeyboardFunc(GLUTCallbacks::KeyboardUpdate);
	glMatrixMode(GL_PROJECTION); //loads a matrix mode
	glLoadIdentity(); //loads identity matrix
	glViewport(0, 0, 800, 800); //sets the viewport to the entire window
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	GLUTCallbacks::Timer(REFRESHRATE);
}	

float angle = 0.f;

void HelloGL::Display()

{

	glClear(GL_COLOR_BUFFER_BIT); //clears the scene
	cube3D->DrawCube(angle);
	//draws Triangle
	glFlush(); //flushes the scene to the GPU
	glutSwapBuffers();
	
	angle += 144.4f;

}

void HelloGL::DrawRectangle()
{
	glPushMatrix();
	glRotatef(angle, 0.f, 1.f, 0.f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glBegin(GL_POLYGON); //starts to draw polygons
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //blue
		glVertex3f(-0.75, 0.5, 0.0); //Defines the first polygon in the top left
		glVertex3f(0.75, 0.5, 0.0); //next point top right
		glVertex3f(0.75, -0.5, 0.0); // bottom right
		glVertex3f(-0.75, -0.5, 0.0); //last polygon, bottom left.
		glEnd(); //ends the draw
	}

	glPopMatrix();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	//glRotatef(rotation, rotation, rotation, rotation);

	glBegin(GL_TRIANGLES);
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
	glLoadIdentity();
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


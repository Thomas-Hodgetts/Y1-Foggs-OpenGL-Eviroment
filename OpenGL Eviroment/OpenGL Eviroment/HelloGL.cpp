#include "HelloGL.h"
#include <stdlib.h>

void HelloGL::KeyboardUpdate(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		camera->eye.x += 0.5f;
		camera->centre.x += 0.5f;
		camera->up.x += 0.5f;
		break;
	case 's':
		camera->eye.z -= 0.5f;
		camera->centre.z -= 0.5f;
		camera->up.z -= 0.5f;
		break;
	case 'w':
		camera->eye.z += 0.5f;
		camera->centre.z += 0.5f;
		camera->up.z += 0.5f;
		break;
	case 'a':
		camera->eye.x -= 0.5f;
		camera->centre.x -= 0.5f;
		camera->up.x -= 0.5f;
		break;
	}
}



HelloGL::HelloGL(int argc, char* argv[])
{

	for (int i = 0; i < 200; i++)
	{
		cube3D[i] = new Cube3D( _mesh, ((rand() % 400) / 10.f) - 20.f, ((rand() % 200) / 10.f), (-(rand() % 1000) / 10.f));
	}

	camera = new Camera;
	camera->eye.x = 0.f; camera->eye.y = 0.f; camera->eye.z = 1.f;
	camera->centre.x = 0.f; camera->centre.y = 0.f; camera->centre.z = 0.f;	
	camera->up.x = 0.f; camera->up.y = 1.f; camera->up.z = 0.f;
	rotation = 0.0f;	
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::KeyboardUpdate);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	//glutKeyboardFunc(GLUTCallbacks::KeyboardUpdate);
	glMatrixMode(GL_PROJECTION); //loads a matrix mode
	glLoadIdentity(); //loads identity matrix
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
	glViewport(0, 0, 800, 800); //sets the viewport to the entire window
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	GLUTCallbacks::Timer(REFRESHRATE);
}	

HelloGL::~HelloGL()
{
	delete camera;
	for (int i = 0; i < 200; i++)
	{
		delete cube3D[i];
	}
}

float angle = 0.f;

void HelloGL::Display()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clears the scene
	for (int i = 0; i < 200; i++)
	{
		cube3D[i]->DrawCube(angle);
		cube3D[i]->Load("cube.txt");
	}
	//draws Triangle
	glFlush(); //flushes the scene to the GPU
	glutSwapBuffers();
	angle += 0.4f;

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
	CameraUpdate();
	rotation += 0.5f;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;	
	}
}

void HelloGL::CameraUpdate()
{
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
}

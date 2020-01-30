#pragma once
#include <Windows.h>
#include "GL/freeglut.h"
#include "GL/GLU.h"
#include "gl/GL.h"
#include "GLUTCallBacks.h"


#define REFRESHRATE 16


class HelloGL
{
public:

	HelloGL(int arg, char* argv[]); //constructor
	~HelloGL(void); //destructor

	void Display();
	void DrawRectangle();
	void DrawTriangle();
	void Update();
	void KeyboardUpdate(unsigned char key, int x, int y);

private:
	float rotation;
};


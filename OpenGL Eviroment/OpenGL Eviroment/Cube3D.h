#pragma once
#include <Windows.h>
#include "GL/freeglut.h"
#include "GL/GLU.h"
#include "gl/GL.h"
#include "GLUTCallBacks.h"

class Cube3D
{

public:

	Cube3D();
	~Cube3D();
	void DrawCube(float a);
private:
	//static Vertex indexedVertex[];
	//static Color;
};


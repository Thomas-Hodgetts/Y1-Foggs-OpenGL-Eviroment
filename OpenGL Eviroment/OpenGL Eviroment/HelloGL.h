#pragma once
#include <Windows.h>
#include "GLUTCallBacks.h"
#include "Cube3D.h"
#include "Structures.h"

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
	Cube3D* cube3D[200];
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void CameraUpdate();
private:
	float rotation;
	Camera* camera;
	Mesh* _mesh;
};




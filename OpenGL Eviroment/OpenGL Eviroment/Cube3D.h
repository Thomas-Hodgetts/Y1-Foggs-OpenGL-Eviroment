#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include "GLUTCallBacks.h"
#include "Structures.h"
#include "SceneObject.h"


class Cube3D : public SceneObject
{

public:

	Cube3D(Mesh*, float x, float y, float z);
	~Cube3D();
	void roatation();
	void DrawCube(float a);
	void Cube3D2(Mesh* mesh, float x, float y, float z);
	void DrawCubeFromFile();
	bool Load(std::string path);
private:

	static Vertex* indexedVertices[];
	static Colour* indexedColors[];
    static GLushort* indices[];
		

	//static int numVertices, numColours, numIndices;
	Vector3 m_position;
	GLfloat _rotation;
};

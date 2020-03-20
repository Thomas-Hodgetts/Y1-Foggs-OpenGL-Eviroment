#pragma once
#include "GL/freeglut.h"
#include "GL/GLU.h"
#include "gl/GL.h"


struct Vector3
{
	GLfloat x, y, z;
};
struct Vertex
{
	GLfloat x, y, z;
};
struct Colour
{
	GLfloat r, g, b;
};
struct Camera
{
	Vector3 eye, centre, up;
};
struct Mesh
{
	Vertex* Vertices;
	Colour* Colours;
	GLshort* Indices;
	int VertexCount, ColourCount, IndexCount;
};
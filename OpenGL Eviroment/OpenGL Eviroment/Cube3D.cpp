#include "Cube3D.h"

//Vertex* Cube3D::indexedVertices = nullptr;


Cube3D::Cube3D(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	//indexedVertices = nullptr;
	Vector3 m_position;
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
	Load("E:/University/Foggs/Fresh copy/Y1 - Foggs - OpenGL - Eviroment/OpenGL Eviroment/OpenGL Eviroment");
	//numColours = 0;
	//numIndices = 0;
	//numVertices = 0;

}

Cube3D::~Cube3D()
{

}




void Cube3D::DrawCube(float a)
{

	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glTranslatef(0.f, 0.f, -5.f);
	glRotatef(a, 0.f, 1.f, 1.f);
	glBegin(GL_TRIANGLES);
	{
		//Face One
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);

		//Face two
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);

		//Face 3
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);

		//Face 4
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);

		//Face 5
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);

		//Face 6
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);

		//Face 7
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);

		//Face 8
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);

		//Face 9
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(-1, -1, -1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);

		//Face 10
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, 1, -1);

		//Face 11
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);

		//Face 12
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
	}
	glEnd();
}

void Cube3D::roatation()
{
	_rotation += 0.1f;
}


bool Cube3D::Load(std::string path)
{
	/*
	std::string file;
	int lineNumber = 0;
	std::ifstream inFile;
	
	inFile.open(path, std::ios_base::in);
	if (!inFile.good())
	{
		std::cerr << "Can't open txt file " << path << std::endl;
		return false;
	}
	inFile >> numVertices;

	indexedVertices = new Vertex[numVertices];
	lineNumber++;
	for (int i = 0; i < numVertices; i++)
	{
		getline(inFile, file);
		std::cout << file << std::endl;
		std::cout << numVertices << std::endl;
	
	}
	inFile.close();
	*/
	return true;
}


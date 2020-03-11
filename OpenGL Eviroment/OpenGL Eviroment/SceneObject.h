#pragma once
#include "Structures.h"

class SceneObject
{
public:
	SceneObject(Mesh* _mesh);
	virtual ~SceneObject();
	virtual void Update();
	virtual void Draw();

protected:
	Mesh* _mesh;
};

#pragma once
#include"main.h"

using namespace std;

class Loader
{
public:
	Loader(void);
	~Loader(void);

	//³aduje objekt z pliku
	void load(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec4> &normals, vector<GLushort> &elements);
};


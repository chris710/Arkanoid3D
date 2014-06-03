#pragma once
#include"main.h"

using namespace std;

class Loader
{
public:
	Loader(void);
	~Loader(void);

	//³aduje objekt z pliku
	bool load(const char* filename, std::vector < glm::vec3 > & vertices, std::vector < glm::vec2 > & uvs, std::vector < glm::vec3 > & normals);
	
};


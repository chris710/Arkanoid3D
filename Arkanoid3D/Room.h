#ifndef ROOM_H
#define ROOM_H
//plik nag³ówkowy klasy pokoj
#include"Loader.h"

using namespace glm;

class Room{
private:
	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				
	TGAImg img;	
public:
	mat4 Macierz;
	Room();
	void drawRoom();
};
#endif //ROOM_H
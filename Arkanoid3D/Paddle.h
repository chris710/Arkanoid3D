#ifndef PADDLE_H
#define PADDLE_H
//plik nag³ówkowy klasy paletki
#include"Loader.h"

using namespace glm;

class Paddle {
private:
	float X;	//pozycja X paletki
	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				
	TGAImg img;	
public:
	mat4 Macierz;
	Ball();
	void drawBall();

	int getX() {
		return this->X;
	};
#endif //PADDLE_H
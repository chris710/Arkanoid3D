#ifndef PADDLE_H
#define PADDLE_H
//plik nag³ówkowy klasy paletki
#include"Loader.h"

using namespace glm;

class Paddle {
private:

	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				
	TGAImg img;	
public:
	float X;	//pozycja X paletki
	mat4 Macierz;
	Paddle();
	void drawPaddle();

	float getX() {
		return this->X;
	}
};
#endif //PADDLE_H
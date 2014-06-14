#ifndef PADDLE_H
#define PADDLE_H
//plik nagłówkowy klasy paletki
#include"Loader.h"

using namespace glm;

class Paddle {
private:

	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				
	TGAImg img;	
	float X;	//pozycja X paletki
public:
	mat4 Macierz;
	Paddle();
	void drawPaddle();

	void setX(float x);
	float getX();
};
#endif //PADDLE_H
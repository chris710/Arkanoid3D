#ifndef BALL_H
#define BALL_H
//plik nag³ówkowy klasy kulki
#include"Loader.h"

using namespace glm;

class Ball {
private:
	float X;	//pozycja X kulki
	float Y;	//pozycja Y kulki
	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				
	TGAImg img;	
public:
	mat4 Macierz;
	Paddle();
	void drawPaddle();

	int getX() {
		return this->X;
	}

	int getY() {
		return this->Y;
	};
#endif //BALL_H
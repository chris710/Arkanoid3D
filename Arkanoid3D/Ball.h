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
	Ball();
	void drawBall();

	float getX(); 

	float getY();

	void setX(float x);

	void setY(float y);
};
#endif //BALL_H
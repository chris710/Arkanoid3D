#ifndef BLOCK_H
#define BLOCK_H
//plik nag³ówkowy klasy bloczka
#include"Loader.h"

using namespace glm;

class Block {
protected:
	float X;	//pozycja X bloczka
	float Y;	//pozycja Y bloczka
	int health;	//ile uderzeñ zosta³o do zniszczenia bloczka
	bool destroyed;				//czy zosta³ zniszczony

public:
	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	int id;
	mat4 Macierz;				//macierz jednostkowa

	Block(){
	}

	Block(float x, float y);	//konstruktor
	//TODO destruktor

	bool hitBlock(float &BallY);

	void drawBlock();
	float getX(); 
	float getY();
	int getHealth();
	bool isDestroyed();
	void destroy();
};

#endif //BLOCK_H
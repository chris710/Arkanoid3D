#ifndef BLOCK_H
#define BLOCK_H
//plik nag��wkowy klasy bloczka
#include"Loader.h"

using namespace glm;

class Block {
protected:
	float X;	//pozycja X bloczka
	float Y;	//pozycja Y bloczka
	int health;	//ile uderze� zosta�o do zniszczenia bloczka
	bool destroyed;				//czy zosta� zniszczony

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

	bool hitBlock();

	void drawBlock();
	 
	float getX() {
		return this->X;
	}

	float getY() {
		return this->Y;
	}

	int getHealth() {
		return this->health;
	}

	bool isDestroyed() {
		return this->destroyed;
	}

	void destroy() {
		this->destroyed = true;
	}
};

#endif //BLOCK_H
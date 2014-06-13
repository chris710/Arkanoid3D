#ifndef BLOCK_H
#define BLOCK_H
//plik nag³ówkowy klasy bloczka
#include"Loader.h"

using namespace glm;

class Block {
private:
	float X;	//pozycja X bloczka
	float Y;	//pozycja Y bloczka
	int health;	//ile uderzeñ zosta³o do zniszczenia bloczka
	bool destroyed;	//czy zosta³ zniszczony
	//TODO model i tekstura
	vector<glm::vec3> vertices;
	vector<glm::vec2> uvs;
	vector<glm::vec3> normals;
	GLuint tex;				//Globalnie do tekstury
	TGAImg img;				//Obojêtnie czy globalnie, czy lokalnie do tektury 

public:
	//TODO konstruktor i destruktor
	mat4 Macierz;
	Block(float x, float y);

	void drawBlock(int i, int j);

	int getX() {
		return this->X;
	}

	int getY() {
		return this->Y;
	}

	int getHealth() {
		return this->health;
	}

	int isDestroyed() {
		return this->destroyed;
	}
	/***** 
	* TODO metody:
	*	- efekt zbicia bloczka
	*	- usuniêcie bloczka
	*	- rysowanie bloczka 
	*	- uszkodzenie bloczka
	*****/
	void damage() {
		if(this->health != 0) {
			this->health--;
		} else {
			this->destroy();
		}
	}

	void destroy() {
		this->destroyed = true;
	}
};

#endif //BLOCK_H
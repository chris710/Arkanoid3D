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
public:
	//TODO konstruktor i destruktor
	mat4 Macierz;
	Block(float x, float y);

	void drawBlock(int i, int j);

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
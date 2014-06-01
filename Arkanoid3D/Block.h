#ifndef BLOCK_H
#define BLOCK_H
//plik nag³ówkowy klasy bloczka
#include"main.h"

class Block {
private:
	float X;	//pozycja X bloczka
	float Y;	//pozycja Y bloczka
	int health;	//ile uderzeñ zosta³o do zniszczenia bloczka
	bool destroyed;	//czy zosta³ zniszczony
	

	//TODO model i tekstura
public:
	//TODO konstruktor i destruktor
	Block(float x, float y) {
		this->X = x;
		this->Y = y;
		this->health = 1;
		this->destroyed = false;
	}

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
#ifndef BLOCK_H
#define BLOCK_H
//plik nag��wkowy klasy bloczka

class Block {
private:
	int X;	//pozycja X bloczka
	int Y;	//pozycja Y bloczka
	int health;	//ile uderze� zosta�o do zniszczenia bloczka
	bool destroyed;	//czy zosta� zniszczony
	//TODO model i tekstura
public:
	//TODO konstruktor i destruktor
	Block(int x, int y) {
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
	*	- usuni�cie bloczka
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
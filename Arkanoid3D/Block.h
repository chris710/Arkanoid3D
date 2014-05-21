#ifndef BLOCK_H
#define BLOCK_H
//plik nag³ówkowy klasy bloczka

class Block {
private:
	int X;	//pozycja X bloczka
	int Y;	//pozycja Y bloczka
	int health;	//ile uderzeñ zosta³o do zniszczenia bloczka
	//TODO model i tekstura
public:
	//TODO konstruktor i destruktor
	int getX() {
		return this->X;
	}

	int getY() {
		return this->Y;
	}

	int getHealth() {
		return this->health;
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
		//TODO
	}
};

#endif //BLOCK_H
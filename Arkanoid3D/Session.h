#ifndef SESSION_H
#define SESSION_H
//plik nag��wkowy klasy, dotycz�cej aktualnej rozgrywki

#include "Block.h"
#include<vector>

using namespace std;
//stan bloczk�w i stan gry
class Session { 
	/***** 
	* TODO:
	*	- liczba bloczk�w
	*	- wykrycie zwyci�stwa
	*	- 
	*
	*****/
public:
	vector<Block> grid;		//macierz bloczk�w

	Session();
	//sprawdza, czy s� jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

	//funkcja tworz�ca rz�dy bloczk�w
	void createBlocks();

	//funkcja tworz�ca pomieszczenie z gr�
	void createRoom();

	//funckja rysuj�ca
	void drawAll();
};

#endif //SESSION_H
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
	vector<vector<Block> > grid;		//macierz bloczk�w

	//sprawdza, czy s� jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

};

#endif //SESSION_H
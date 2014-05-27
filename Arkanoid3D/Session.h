#ifndef SESSION_H
#define SESSION_H
//plik nag³ówkowy klasy, dotycz¹cej aktualnej rozgrywki

#include "Block.h"
#include<vector>

using namespace std;
//stan bloczków i stan gry
class Session { 
	/***** 
	* TODO:
	*	- liczba bloczków
	*	- wykrycie zwyciêstwa
	*	- 
	*
	*****/
public:
	vector<vector<Block> > grid;		//macierz bloczków

	//sprawdza, czy s¹ jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

};

#endif //SESSION_H
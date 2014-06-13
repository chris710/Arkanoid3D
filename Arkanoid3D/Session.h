#ifndef SESSION_H
#define SESSION_H
//plik nag³ówkowy klasy, dotycz¹cej aktualnej rozgrywki

#include "Block.h"
#include "Paddle.h"

#include<vector>

using namespace std;
//stan bloczków i stan gry
class Session { 

public:
	vector <vector<Block>> grid;		//macierz bloczków
	Paddle *Paletka;

	Session();

	//sprawdza, czy s¹ jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

	//funkcja tworz¹ca rzêdy bloczków
	void createBlocks();

	//funkcja tworz¹ca paletkê
	void createPaddle();

	//funkcja tworz¹ca pomieszczenie z gr¹
	void createRoom();

	//funckja rysuj¹ca
	void drawAll();
};

#endif //SESSION_H
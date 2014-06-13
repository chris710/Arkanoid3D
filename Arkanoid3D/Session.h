#ifndef SESSION_H
#define SESSION_H
//plik nag��wkowy klasy, dotycz�cej aktualnej rozgrywki

#include "Block.h"
#include "Paddle.h"

#include<vector>

using namespace std;
//stan bloczk�w i stan gry
class Session { 

public:
	vector <vector<Block>> grid;		//macierz bloczk�w
	Paddle *Paletka;

	Session();

	//sprawdza, czy s� jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

	//funkcja tworz�ca rz�dy bloczk�w
	void createBlocks();

	//funkcja tworz�ca paletk�
	void createPaddle();

	//funkcja tworz�ca pomieszczenie z gr�
	void createRoom();

	//funckja rysuj�ca
	void drawAll();
};

#endif //SESSION_H
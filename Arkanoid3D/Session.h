#ifndef SESSION_H
#define SESSION_H
//plik nag��wkowy klasy, dotycz�cej aktualnej rozgrywki

#include "Block.h"
#include "Paddle.h"
#include "Ball.h"
#include "Room.h"

#include<vector>

using namespace std;
//stan bloczk�w i stan gry
class Session { 

private:
	GLuint tex;					//uchwyt na tekstur� bloczka			
	TGAImg img;					//obraz z tekstur� bloczka
public:
	vector <vector<Block>> grid;		//macierz bloczk�w
	Paddle *Paletka;
	Ball *Kulka;
	Room *Pokoj;

	Session();

	//sprawdza, czy s� jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

	//funkcja tworz�ca rz�dy bloczk�w
	void createBlocks();

	//funkcja tworz�ca paletk�
	void createPaddle();

	//funkcja tworz�ca kulk�
	void createBall();

	//funkcja tworz�ca pomieszczenie z gr�
	void createRoom();

	//funckja rysuj�ca
	void drawAll();

	//czyszczenie syfu		//TODO
	void clean();
};

#endif //SESSION_H
#ifndef SESSION_H
#define SESSION_H
//plik nag��wkowy klasy, dotycz�cej aktualnej rozgrywki

#include "Block.h"
#include "Paddle.h"
#include "Ball.h"
#include "Room.h"
#include "BlueBlock.h"
#include "RedBlock.h"
#include "SilverBlock.h"

#include<vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

	//funckja rysuj�ca odpowiednie bloczki
	void DrawBlocks(char* filename, int ID);

	//funckja rysuj�ca
	void drawAll();

	//kolizje pi�ki
	int collision(float &X, float &Y);

	//kolizja z paletk�

	//czyszczenie syfu		//TODO
	void clean();
};

#endif //SESSION_H
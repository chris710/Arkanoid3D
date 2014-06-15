#ifndef SESSION_H
#define SESSION_H
//plik nag³ówkowy klasy, dotycz¹cej aktualnej rozgrywki

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
//stan bloczków i stan gry
class Session { 

private:
	GLuint tex;					//uchwyt na teksturê bloczka			
	TGAImg img;					//obraz z tekstur¹ bloczka
public:
	vector <vector<Block>> grid;		//macierz bloczków
	Paddle *Paletka;
	Ball *Kulka;
	Room *Pokoj;

	Session();

	//sprawdza, czy s¹ jeszcze klocki
	bool win();
	
	//usuwa blok o podanych koordach
	void removeBlock(int x, int y);

	//funkcja tworz¹ca rzêdy bloczków
	void createBlocks();

	//funkcja tworz¹ca paletkê
	void createPaddle();

	//funkcja tworz¹ca kulkê
	void createBall();

	//funkcja tworz¹ca pomieszczenie z gr¹
	void createRoom();

	//funckja rysuj¹ca odpowiednie bloczki
	void DrawBlocks(char* filename, int ID);

	//funckja rysuj¹ca
	void drawAll();

	//kolizje pi³ki
	int collision(float &X, float &Y);

	//kolizja z paletk¹

	//czyszczenie syfu		//TODO
	void clean();
};

#endif //SESSION_H
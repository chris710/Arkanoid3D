#ifndef REDBLOCK_H
#define REDBLOCK_H
//plik nag³ówkowy klasy czerwonego bloczka, którego zbicie powoduje ewolucje kulki na ognist¹ na 10 sek.

#include "Block.h"

class RedBlock : public Block {
	/***** 
	* TODO:
	*	- funkcja z super moc¹
	*	- funkcja zmieniaj¹ca teksturê ?
	*	-
	*
	*****/
public:
	RedBlock(Block *wzor, int j);

//	void uderzenie();
};

#endif //REDBLOCK_H
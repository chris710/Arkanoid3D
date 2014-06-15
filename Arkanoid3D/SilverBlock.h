#ifndef SILVERBLOCK_H
#define SILVERBLOCK_H
//plik nag³ówkowy klasy srebrnego bloczka, którego mo¿na zbiæ tlyko przez odbicie od górnej œciany

#include "Block.h"

class SilverBlock : public Block {
	/***** 
	* TODO:
	*	- funkcja sprawdzaj¹ca czy zosta³ klocek zosta³ uderzony z góry
	*	- funkcja zmieniaj¹ca teksturê ?
	*	-
	*
	*****/
public:
	SilverBlock(Block *wzor, int j);

//	void uderzenie();	
};

#endif //SILVERBLOCK_H
#ifndef REDBLOCK_H
#define REDBLOCK_H
//plik nag��wkowy klasy czerwonego bloczka, kt�rego zbicie powoduje ewolucje kulki na ognist� na 10 sek.

#include "Block.h"

class RedBlock : public Block {
	/***** 
	* TODO:
	*	- funkcja z super moc�
	*	- funkcja zmieniaj�ca tekstur� ?
	*	-
	*
	*****/
public:
	RedBlock(Block *wzor, int j);

//	void uderzenie();
};

#endif //REDBLOCK_H
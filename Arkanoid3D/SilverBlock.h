#ifndef SILVERBLOCK_H
#define SILVERBLOCK_H
//plik nag��wkowy klasy srebrnego bloczka, kt�rego mo�na zbi� tlyko przez odbicie od g�rnej �ciany

#include "Block.h"

class SilverBlock : public Block {
	/***** 
	* TODO:
	*	- funkcja sprawdzaj�ca czy zosta� klocek zosta� uderzony z g�ry
	*	- funkcja zmieniaj�ca tekstur� ?
	*	-
	*
	*****/
public:
	SilverBlock(Block *wzor, int j);

//	void uderzenie();	
};

#endif //SILVERBLOCK_H
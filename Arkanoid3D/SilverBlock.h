#ifndef SILVERBLOCK_H
#define SILVERBLOCK_H
//plik nag��wkowy klasy srebrnego bloczka, kt�rego mo�na zbi� tlyko przez odbicie od g�rnej �ciany

#include "Block.h"

class SilverBlock : public Block {

public:
	SilverBlock(Block *wzor, int j);

	bool hitBlock();	
};

#endif //SILVERBLOCK_H
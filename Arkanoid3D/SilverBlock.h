#ifndef SILVERBLOCK_H
#define SILVERBLOCK_H
//plik nag³ówkowy klasy srebrnego bloczka, którego mo¿na zbiæ tlyko przez odbicie od górnej œciany

#include "Block.h"

class SilverBlock : public Block {

public:
	SilverBlock(Block *wzor, int j);

	bool hitBlock();	
};

#endif //SILVERBLOCK_H
#ifndef REDBLOCK_H
#define REDBLOCK_H
//plik nag³ówkowy klasy czerwonego bloczka, którego zbicie powoduje przyspieszenie kulki razy 2

#include "Block.h"

class RedBlock : public Block {

public:
	RedBlock(Block *wzor, int j);

	bool hitBlock();
};

#endif //REDBLOCK_H
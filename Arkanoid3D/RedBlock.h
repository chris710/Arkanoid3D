#ifndef REDBLOCK_H
#define REDBLOCK_H
//plik nag��wkowy klasy czerwonego bloczka, kt�rego zbicie powoduje przyspieszenie kulki razy 2

#include "Block.h"

class RedBlock : public Block {

public:
	RedBlock(Block *wzor, int j);

	bool hitBlock();
};

#endif //REDBLOCK_H
#ifndef BLUEBLOCK_H
#define BLUEBLOCK_H
//plik nag��wkowy klasy niebieskiego bloczka, do kt�rego zbicia potrzebne s� 2 uderzenia;

#include "Block.h"

class BlueBlock: public Block {

public:
	BlueBlock(Block *wzor, int j);
	
	bool hitBlock();
};

#endif //BLUEBLOCK_H
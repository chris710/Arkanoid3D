#ifndef BLUEBLOCK_H
#define BLUEBLOCK_H
//plik nag³ówkowy klasy niebieskiego bloczka, do którego zbicia potrzebne s¹ 2 uderzenia;

#include "Block.h"

class BlueBlock: public Block {

public:
	BlueBlock(Block *wzor, int j);
	
	bool hitBlock();
};

#endif //BLUEBLOCK_H
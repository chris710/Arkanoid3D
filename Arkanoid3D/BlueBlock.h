#ifndef BLUEBLOCK_H
#define BLUEBLOCK_H
//plik nag��wkowy klasy niebieskiego bloczka, do kt�rego zbicia potrzebne s� 2 uderzenia;

#include "Block.h"

class BlueBlock: public Block {
	/***** 
	* TODO:
	*	- funkcja z super moc�
	*	- funkcja zmieniaj�ca tekstur� ?
	*	-
	*
	*****/
public:
	BlueBlock(Block *wzor, int j);

//	void uderzenie();

};

#endif //BLUEBLOCK_H
#include "SilverBlock.h"
//plik �r�d�a klasy srebrnego bloczka, kt�rego mo�na zbi� tlyko przez odbicie od g�rnej �ciany

SilverBlock::SilverBlock(Block *wzor, int j){
	id = j;
	health = wzor->getHealth() + 1;
	X = wzor->getX();	
	Y = wzor->getY();	
	destroyed = false;	
	vertices = wzor->vertices;
	uvs = wzor->uvs;
	normals = wzor->normals;	
}

bool SilverBlock::hitBlock(){
	// czy g�rna �ciana
	this->health--;
	if (this->health == 0)
		return true;
	else
		return false;
};
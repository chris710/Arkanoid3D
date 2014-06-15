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

bool SilverBlock::hitBlock(float pilka){
	if( this->getX() + 0.4 < pilka){
		this->health--;
		if (this->health == 0)
			return true;
		else
			return false;
	}else
		return false;
};
#include "SilverBlock.h"
//plik Ÿród³a klasy srebrnego bloczka, którego mo¿na zbiæ tlyko przez odbicie od górnej œciany

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
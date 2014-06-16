#include "SilverBlock.h"
//plik Ÿród³a klasy srebrnego bloczka, którego mo¿na zbiæ tlyko przez odbicie od górnej œciany

SilverBlock::SilverBlock(Block *wzor, int j){
	id = j;
	health = wzor->getHealth();
	X = wzor->getX();	
	Y = wzor->getY();	
	destroyed = false;	
	vertices = wzor->vertices;
	uvs = wzor->uvs;
	normals = wzor->normals;	
}

bool SilverBlock::hitBlock(float &BallY){

	if( this->getY() + 1 < BallY){
		this->health--;
		if (this->health == 0)
			return true;
		else
			return false;
	}else
		return false;
};
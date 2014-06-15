#include "BlueBlock.h"
//plik Ÿród³a klasy niebieskiego bloczka, do którego zbicia potrzebne s¹ 2 uderzenia;

BlueBlock::BlueBlock(Block *wzor, int j){
	id = j;
	health = wzor->getHealth() + 1;
	X = wzor->getX();	
	Y = wzor->getY();	
	destroyed = false;	
	vertices = wzor->vertices;
	uvs = wzor->uvs;
	normals = wzor->normals;	
}

bool BlueBlock::hitBlock(){
	this->health--;
	if (this->health == 0)
		return true;
	else
		return false;
};
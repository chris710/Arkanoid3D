#include "RedBlock.h"
//plik �r�d�a klasy czerwonego bloczka, kt�rego zbicie powoduje przyspieszenie kulki razy 2

RedBlock::RedBlock(Block *wzor, int j){
	id = j;
	health = wzor->getHealth() + 1;
	X = wzor->getX();	
	Y = wzor->getY();	
	destroyed = false;	
	vertices = wzor->vertices;
	uvs = wzor->uvs;
	normals = wzor->normals;	
}


bool RedBlock::hitBlock(){
	// przyspieszenie KULKI 
	this->health--;
	if (this->health == 0)
		return true;
	else
		return false;
};
#include "RedBlock.h"
//plik Ÿród³a klasy czerwonego bloczka

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

//void BlueBlock::uderzenie(){ }
	
;
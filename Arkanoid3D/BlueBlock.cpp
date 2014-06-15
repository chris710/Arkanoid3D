#include "BlueBlock.h"
//plik Ÿród³a klasy niebieskiego bloczka

BlueBlock::BlueBlock(Block *wzor){
	health = wzor->getHealth() + 1;
	X = wzor->getX();	
	Y = wzor->getY();	
	destroyed = false;	
	//vertices = wzor->vertices;
	//uvs = wzor->uvs;
	//normals = wzor->normals;	
}

//void BlueBlock::zbicie(){ }
				

//void BlueBlock::drugaKulka(){ }
;
#include "Session.h"
//plik Ÿród³a klasy sesji 

Session::Session(){
	createRoom();
	createBlocks();
	createPaddle();
	createBall();
}

bool Session::win() {
	if(this->grid.empty()) {
		return true;
	}
	return false;
}

void Session::removeBlock(int x, int y) {
	if(this->grid[y][x].isDestroyed()) {
		//this.grid[y][x]->
	}
}

void Session::createBlocks() {
	for(int j=0; j<12; j++){
		vector<Block> row;
		for(int i = 0; i<12; i++){
			Block *Bloczek = new Block(i,j);
			row.push_back(*Bloczek);
		}
		this->grid.push_back(row);
	}
}

void Session::createPaddle() {
	this->Paletka = new Paddle();
}

void Session::createBall(){
	this->Kulka = new Ball();
}

void Session::createRoom() {
	this->Pokoj = new Room();
}


void Session::drawAll() {	
	this->Pokoj->drawRoom();	
	//// TEKSTURY
	glEnable(GL_TEXTURE_2D);	
	if (img.Load("res/bloczek.tga")==IMG_OK){
		glGenTextures(1,&tex); //Zainicjuj uchwyt tex
		glBindTexture(GL_TEXTURE_2D,tex); //Przetwarzaj uchwyt tex
	if (img.GetBPP()==24) //Obrazek 24bit
		glTexImage2D(GL_TEXTURE_2D,0,3,img.GetWidth(),img.GetHeight(),0,
		GL_RGB,GL_UNSIGNED_BYTE,img.GetImg());
	else if (img.GetBPP()==32) //Obrazek 32bit
		glTexImage2D(GL_TEXTURE_2D,0,4,img.GetWidth(),img.GetHeight(),0,
		GL_RGBA,GL_UNSIGNED_BYTE,img.GetImg());
	else {
	//Obrazek 16 albo 8 bit, takimi si? nie przejmujemy
	}}
	for(int j = 0; j<this->grid.size(); ++j)
		for(int i = 0; i<this->grid.size(); ++i)
			this->grid[i][j].drawBlock(i,j);
	glDeleteTextures(1,&tex);
	this->Paletka->drawPaddle();
	this->Kulka->drawBall();
	
}
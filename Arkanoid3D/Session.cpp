#include "Session.h"
//plik Ÿród³a klasy sesji 


Session::Session(){
	//createRoom();
	createBlocks();
	//createPaddle();
	//createBall();
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
		// TEKSTURY	
	if (this->blockImg.Load("res/bloczek.tga")==IMG_OK){
		glGenTextures(1,&(this->blockTex)); //Zainicjuj uchwyt tex
		//glBindTexture(GL_TEXTURE_2D,this->blockTex); //Przetwarzaj uchwyt tex
	if (this->blockImg.GetBPP()==24) //Obrazek 24bit
		glTexImage2D(GL_TEXTURE_2D,0,3,this->blockImg.GetWidth(),this->blockImg.GetHeight(),0,
		GL_RGB,GL_UNSIGNED_BYTE,this->blockImg.GetImg());
	else if (this->blockImg.GetBPP()==32) //Obrazek 32bit
		glTexImage2D(GL_TEXTURE_2D,0,4,this->blockImg.GetWidth(),this->blockImg.GetHeight(),0,
		GL_RGBA,GL_UNSIGNED_BYTE,this->blockImg.GetImg());
	else {
		//Obrazek 16 albo 8 bit, takimi siê nie przejmujemy
	}} 
	//glBindTexture(GL_TEXTURE_2D, 0);

	for(int j=0; j<12; j++){
		vector<Block> row;
		for(int i = 0; i<12; i++){
			Block *Bloczek = new Block(i,j,this->blockTex);
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
	//this->Pokoj->drawRoom();
	
	for(int j = 0; j<this->grid.size(); ++j)
		for(int i = 0; i<this->grid.size(); ++i)
			this->grid[i][j].drawBlock(i,j);

	//glDeleteTextures(1,&tex);		//TODO wywaliæ do clean

	//this->Paletka->drawPaddle();
	//this->Kulka->drawBall();
	
}
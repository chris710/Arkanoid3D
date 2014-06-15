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
	srand (time(NULL));
	for(int j=0; j<12; j++){
		vector<Block> row;
		for(int i = 0; i<12; i++){
			Block *Bloczek = new Block(i,j);
			row.push_back(*Bloczek);
		}
		this->grid.push_back(row);
	}

	for (int j=1; j<4; j++)
		for (int i=0; i<10; i++){
			int x = rand() % 12;
			int y = rand() % 12;
			while(this->grid[x][y].id != 0 ){
				x = rand() % 12;
				y = rand() % 12;
			}
			if (j==1){

			} else if (j==2){

			} else {

			}
			this->grid[x][y].id = j;
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

int Session::collision() {
	if((this->Kulka->getY()+0.5)<=-14.5) {
		if(1>=abs(this->Paletka->getX()+1-(this->Kulka->getX()+0.5))) {
			return 1;
		}
	}
	return 0;
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
			this->grid[i][j].drawBlock();
	glDeleteTextures(1,&tex);
	this->Paletka->drawPaddle();
	this->Kulka->drawBall();
	
}
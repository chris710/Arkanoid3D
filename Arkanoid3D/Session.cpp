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
		for (int i=0; i<15; i++){
			int x = rand() % 12;
			int y = rand() % 12;
			while(this->grid[x][y].id != 0 ){
				x = rand() % 12;
				y = rand() % 12;
			}
			if (j==1){
				BlueBlock *Bloczek = new BlueBlock(&this->grid[x][y], j);
				this->grid[x][y] = *Bloczek;
			} else if (j==2){
				RedBlock *Bloczek = new RedBlock(&this->grid[x][y], j);
				this->grid[x][y] = *Bloczek;
			} else {
				SilverBlock *Bloczek = new SilverBlock(&this->grid[x][y], j);
				this->grid[x][y] = *Bloczek;
			}
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

int Session::collision(float &X, float &Y) {
	if((this->Kulka->getY()+0.5)<=-14.5) {
		if(3.5>=abs(this->Paletka->getX()-(this->Kulka->getX()))) {
			Y = -Y*(cos(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/3.5));
			X = -sin(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/3.5)/500;
		}
	}
	return 0;
		//nic nie stoi na przeszkodzie
	//kolizja z paletk¹
	//kolizja z bloczkiem
	//przegrana
}

void Session::DrawBlocks(char* filename, int ID){
//// TEKSTURY
	glEnable(GL_TEXTURE_2D);	
	if (img.Load(filename)==IMG_OK){
		glGenTextures(1,&tex); //Zainicjuj uchwyt tex
		glBindTexture(GL_TEXTURE_2D,tex); //Przetwarzaj uchwyt tex
	if (img.GetBPP()==24) //Obrazek 24bit
		glTexImage2D(GL_TEXTURE_2D,0,3,img.GetWidth(),img.GetHeight(),0,
		GL_RGB,GL_UNSIGNED_BYTE,img.GetImg());
	else if (img.GetBPP()==32) //Obrazek 32bit
		glTexImage2D(GL_TEXTURE_2D,0,4,img.GetWidth(),img.GetHeight(),0,
		GL_RGBA,GL_UNSIGNED_BYTE,img.GetImg());
	else {
	//Obrazek 16 albo 8 bit, takimi siê nie przejmujemy
	}}

//// BLOCZKI
	for(int j = 0; j<this->grid.size(); ++j)
		for(int i = 0; i<this->grid.size(); ++i)
			if(this->grid[i][j].id == ID )
				this->grid[i][j].drawBlock();
	glDeleteTextures(1,&tex);
}

void Session::drawAll() {	
	this->Pokoj->drawRoom();	
	this->DrawBlocks("res/bloczek.tga", 0);
	this->DrawBlocks("res/niebieski.tga", 1);
	this->DrawBlocks("res/czerwony.tga", 2);
	this->DrawBlocks("res/srebrny.tga", 3);
	this->Paletka->drawPaddle();
	this->Kulka->drawBall();
	
}
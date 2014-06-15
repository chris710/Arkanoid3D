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

void Session::removeBlock(int x, int y) {
	this->grid[x][y].destroy();
	this->grid[x].erase(this->grid[x].begin() + y);
	
}

bool Session::collision(float &BallX, float &BallY, float &PaddleX) {
//// PORA¯KA
	if(this->Kulka->getY()<-17) {												
		return false;
	}

//// KOLIZJA Z PALETK¥
	if((this->Kulka->getY())<=-15.1 && (this->Kulka->getY())>=-16.9) {			
		if(3.5>=abs(this->Paletka->getX()-(this->Kulka->getX()))) {
			BallY = -BallY*(cos(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/100));
			BallX += -sin(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/3.5)/100;
			PaddleX = 0;
		}
	}

//// KOLIZJE Z BLOCZKAMI
	for(int i=0;i<this->grid.size(); i++)
		for(int j=0;j<this->grid[i].size(); j++) {	
			if((abs(this->Kulka->getY() - this->grid[i][j].getY()) <= 0.9) && (abs(this->Kulka->getX() - this->grid[i][j].getX()) <= 2.97)) {		//kolizje poziome){ //&& (this->Kulka->getY())>=-16.9)) {		//kolizje pionowe
				if(this->Kulka->getY() >= (this->grid[i][j].getY() +1) || this->Kulka->getY() <= (this->grid[i][j].getY()-1) )
					BallX = -BallX;
				else
					BallY = -BallY;
				if (this->grid[i][j].hitBlock() == true){
					std::cout << (this->grid[i][j].getX()+11.1)/2.01 << "\t" << (this->grid[i][j].getY()-7.5)/(-0.802) << endl;
					this->removeBlock((this->grid[i][j].getY()-7.5)/(-0.802), ((this->grid[i][j].getX()+11.1)/2.01));
					j--;
				}
			}
		}

//// KOLIZJE ZE SCIANAMI
	float wallX = 12.5, wallY = 9.5;
	if (this->Kulka->getX() <= -wallX ){
		BallX = -BallX;//*(cos(3.1415962/2*(wallY-(this->Kulka->getX()))/3.5));
		//BallY = -sin(3.1415962/2*(wallY-(this->Kulka->getX()))/3.5)/300;
	}
	if (this->Kulka->getX() >= wallX ) {	//prawa œciana
		BallX = -BallX;				//*(cos(3.1415962/2*(wallY-(this->Kulka->getX()))/3.5));
		//BallY = -sin(3.1415962/2*(wallY-(this->Kulka->getX()))/3.5)/300;
	}
	if (this->Kulka->getY() >= wallY){	//sufit
		BallY = -BallY;		//*(cos(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/3.5));
		BallX = -BallX;		//-sin(3.1415962/2*(this->Paletka->getX()-(this->Kulka->getX()))/3.5)/300;
	}

	
	return true;

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
		for(int i = 0; i<this->grid[j].size(); ++i)
			if(this->grid[j][i].id == ID )
				this->grid[j][i].drawBlock();
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
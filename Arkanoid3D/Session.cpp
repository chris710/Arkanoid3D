#include "Session.h"
//plik Ÿród³a klasy sesji 


Session::Session(){
	createBlocks();
}


bool Session::win() {
	if(this->grid.empty()) {
		return true;
	}
	return false;
}

void Session::removeBlock(int x, int y) {
	if(this->grid[x].isDestroyed()) {
		//this.grid[x][y]->
	}
}

void Session::createBlocks() {
	vector<Block> row;
	for(int i = 0; i<3; ++i) {}
	Block *Bloczek1 = new Block(0,0);
	this->grid.push_back(*Bloczek1);
}

void Session::createRoom() {
	//glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	//glutSolidCube(3.5f);		//stwórz wielki bia³y szeœcian
}

//void Session::loadingImages() {
//	if (img.Load("bloczek.tga")==IMG_OK) {
//		glGenTextures(1,&tex); //Zainicjuj uchwyt tex
//		glBindTexture(GL_TEXTURE_2D,tex); //Przetwarzaj uchwyt tex
//	if (img.GetBPP()==24) //Obrazek 24bit
//		glTexImage2D(GL_TEXTURE_2D,0,3,img.GetWidth(),img.GetHeight(),0,
//		GL_RGB,GL_UNSIGNED_BYTE,img.GetImg());
//	else if (img.GetBPP()==32) //Obrazek 32bit
//		glTexImage2D(GL_TEXTURE_2D,0,4,img.GetWidth(),img.GetHeight(),0,
//		GL_RGBA,GL_UNSIGNED_BYTE,img.GetImg());
//	else {
//		//Obrazek 16 albo 8 bit, takimi siê nie przejmujemy
//	}} else {
//		//b³¹d
//	}
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glEnable(GL_TEXTURE_2D);
//
//}

void Session::drawAll() {
	for(int i = 0; i<this->grid.size(); ++i) {
		this->grid[i].drawBlock();
	}
}
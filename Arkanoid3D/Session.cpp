#include "Session.h"
//plik �r�d�a klasy sesji 


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
	for(int i = 0; i<12; i++)
	{
		Block *Bloczek = new Block(0,0);
		this->grid.push_back(*Bloczek);
	}
}

void Session::createRoom() {
	//glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	//glutSolidCube(3.5f);		//stw�rz wielki bia�y sze�cian
}



void Session::drawAll() {
	for(int i = 0; i<this->grid.size(); ++i) {
		this->grid[i].drawBlock(i);
	}
}
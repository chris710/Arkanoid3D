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

void Session::createRoom() {
	//glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	//glutSolidCube(3.5f);		//stwórz wielki bia³y szeœcian
}



void Session::drawAll() {
	for(int j = 0; j<this->grid.size(); ++j)
		for(int i = 0; i<this->grid.size(); ++i)
			this->grid[i][j].drawBlock(i,j);
}
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
	for(int j = 0; j<this->grid.size(); ++j)
		for(int i = 0; i<this->grid.size(); ++i)
			this->grid[i][j].drawBlock(i,j);
	this->Paletka->drawPaddle();
	this->Kulka->drawBall();
	
}
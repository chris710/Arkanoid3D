#include "Session.h"
//plik Ÿród³a klasy sesji 


bool Session::win() {
	if(this->grid.empty()) {
		return true;
	}
	return false;
}

void Session::removeBlock(int x, int y) {
	if(this->grid[x][y].isDestroyed()) {
		//this.grid[x][y]->
	}
}
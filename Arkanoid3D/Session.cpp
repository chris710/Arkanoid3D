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

void Session::createBlocks() {
	for(int i = 0; i<3; ++i) {
		
	}
}

void Session::createRoom() {
	//glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	//glutSolidCube(3.5f);		//stwórz wielki bia³y szeœcian
}
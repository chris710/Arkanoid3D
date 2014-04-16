#include "main.h"
#include "init.h"

//funkcja tworz¹ca rzêdy bloczków
void createBlocks() {
	for(int i = 0; i<3; ++i) {
		
	}
}

//funkcja tworz¹ca pomieszczenie z gr¹
void createRoom() {
	glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	glutSolidCube(5.5f);		//stwórz wielki bia³y szeœcian
}
#include "main.h"
#include "init.h"

//funkcja tworz�ca rz�dy bloczk�w
void createBlocks() {
	for(int i = 0; i<3; ++i) {
		
	}
}

//funkcja tworz�ca pomieszczenie z gr�
void createRoom() {
	glColor3d(1.0f,1.0f,1.0f);  //kolorujemy kwadrat
	glutSolidCube(5.5f);		//stw�rz wielki bia�y sze�cian
}
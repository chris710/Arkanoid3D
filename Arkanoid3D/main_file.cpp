#include"main_file.h"

int lastTime=0;
int interval;							//czas pomiêdzy klatkami
int fps = 0;							//ile fpsów
float newX = 0;
int lastFPSCheck;						//kiedy ostatnio by³y wyœweitlane fps
Session *NewSession = new Session();

void displayFrame(void) {											//Tutaj kod rysuj¹cy		
	glClearColor(1,1,1,0);											//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				//czyszczenie buforów  //w³aœciwe czyszcenie okna
	NewSession->Paletka->X += newX;
	NewSession->drawAll();											//wyœwietla ca³oœæ
	
	glutSwapBuffers();  //wywala zawartoœæ bufora ZAWSZE NA KOÑCU!!!
}

void nextFrame(void) {//to co robi siê pomiêdzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;
	printFPS(actTime);		//wypisuje fpsy

	//////// CZÊŒÆ NA MECHANIKÊ	////////////		//pamiêtaj aby mno¿yæ razy interval!

//	if (angle>360) angle-=360;

	glutPostRedisplay();
}

void keyDown(int c, int x, int y) {
 if (c==GLUT_KEY_LEFT) {
	newX = -0.2;
 }
 if (c==GLUT_KEY_RIGHT) {
	 newX = 0.2;
 }
   glutPostRedisplay();
}

void keyUp(int c, int x, int y) {
 if (c==GLUT_KEY_LEFT) {
	 newX = 0;	
 }
 if (c==GLUT_KEY_RIGHT) {
	 newX = 0;	
 }
 glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	initialize();
	glutSpecialFunc(keyDown);
	glutSpecialUpFunc(keyUp);
	glutMainLoop();
	return 0;
}

//--------------------------------------------------------------------------------------//

void initialize() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja buforów
	glutInitWindowSize(800,800);			//opcje okna
	glutInitWindowPosition(400,0);
	glutCreateWindow("Arkanoid 3D");		//nadanie tytu³u okna 
	glutDisplayFunc(displayFrame);			//rejestracja obs³ugi odœwie¿aj¹ca okno
	glutIdleFunc(nextFrame);
	//tutaj kod inicjuj¹cy					//TODO to te¿	
	glEnable(GL_DEPTH_TEST);				//w³¹czanie zbuffora
	glEnable(GL_LIGHTING);					//w³¹czamy oœwietlenie


	glEnable(GL_COLOR_MATERIAL);			//kolorek po oœwietleniu
	glShadeModel(GL_SMOOTH);
}


void printFPS(int actTime) {
	fps++;
	if(actTime-lastFPSCheck>=1000) {
		std::cout<<fps/((actTime-lastFPSCheck)/1000.0f)<<std::endl;
		fps = 0;
		lastFPSCheck = actTime;
	}
}
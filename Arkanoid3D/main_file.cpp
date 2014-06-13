#include"main_file.h"

using namespace glm;

float speed=60;							//360 stopni/s
int lastTime=0;
int interval;							//czas pomiêdzy klatkami
int fps = 0;							//ile fpsów
float angle = 0;
int lastFPSCheck;						//kiedy ostatnio by³y wyœweitlane fps
Session *NewSession = new Session();



void displayFrame(void) {											//Tutaj kod rysuj¹cy		
	glClearColor(1,1,1,0);											//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				//czyszczenie buforów  //w³aœciwe czyszcenie okna
																		
	mat4 V = lookAt(										//wspó³rzêdne kamery	//kamera jest sta³a!
	vec3(0.0f,0.0f,30.0f),									//gdzie
	vec3(0.0f,-5.0f,0.0f),									//kierunek
	vec3(0.0f,1.0f,0.0f));									//wektor do góry

// macierze
	mat4 M = mat4(1.0f);								//macierz jednostkowa	
	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);		//w³asnoœci widoku		//TODO zamieniæ na funkcjê 
	//				  (fovy, aspect,zNear,zFar );	
	M=glm::translate(M, glm::vec3(-11.0f,5.0f,0.0f));	// ( <-11,11>, <-5,5>, 0 )			11bloczków w wierszu 
//	W=rotate(M, angle, vec3(0.0f,1.0f,0.0f));		// macierz rotacji
	
// ³adowanie macierzy do modelu
	glMatrixMode(GL_PROJECTION);	//macierz rzutowania
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);		//macierz modelu
	glLoadMatrixf(value_ptr(V*M));



//////	CZÊŒÆ NA FUNKCJE RYSUJ¥CE	///////////
	NewSession->drawAll();



///////////////////////////////////////////////

	glutSwapBuffers();  //wywala zawartoœæ bufora ZAWSZE NA KOÑCU!!!
}


void nextFrame(void) {//to co robi siê pomiêdzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;

	printFPS(actTime);		//wypisuje fpsy

	//////// CZÊŒÆ NA MECHANIKÊ	////////////		//pamiêtaj aby mno¿yæ razy interval!
	angle+=speed*interval/1000.0;
	if (angle>360) angle-=360;

	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	initialize();

	//TODO inicjalizacja klas

	glutMainLoop();

//	glDeleteTextures(1,&tex);
	return 0;
}

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
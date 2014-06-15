#include"main_file.h"


int lastTime=0;
int interval;							//czas pomiêdzy klatkami
int fps = 0;							//ile fpsów
float newX = 0;							//zmiana po³o¿enia paletki
float BallX = 0;						//po³o¿enie X pi³ki
float BallY = -0.003;						//po³o¿enie Y pi³ki
const float PADDLE_SPEED = 0.01;				//prêdkoœæ paletki
int lastFPSCheck;						//kiedy ostatnio by³y wyœweitlane fps
Session *NewSession = new Session();







void displayFrame(void) {											//Tutaj kod rysuj¹cy		
	glClearColor(1,1,1,0);											//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				//czyszczenie buforów  //w³aœciwe czyszcenie okna

	NewSession->drawAll();											//wyœwietla ca³oœæ
	
	glutSwapBuffers();												//wywala zawartoœæ bufora ZAWSZE NA KOÑCU!!!
}

void nextFrame(void) {									//to co robi siê pomiêdzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;
	printFPS(actTime);		//wypisuje fpsy

	//////// CZÊŒÆ NA MECHANIKÊ	////////////		//pamiêtaj aby mno¿yæ razy interval!
	if ( (NewSession->Paletka->getX() + newX*interval < 10.0) && (NewSession->Paletka->getX() + newX*interval > -10.0) )
		NewSession->Paletka->setX(NewSession->Paletka->getX() + newX*interval);
						//TODO to ma byæ funkcja!!!
	NewSession->collision(BallX,BallY); 
	
	NewSession->Kulka->setX(NewSession->Kulka->getX() + BallX*interval);
	NewSession->Kulka->setY(NewSession->Kulka->getY() + BallY*interval);
	glutPostRedisplay();
}

void keyDown(int c, int x, int y) {
 if (c==GLUT_KEY_LEFT) {
	newX = -PADDLE_SPEED;
}
 if (c==GLUT_KEY_RIGHT) {
	 newX = PADDLE_SPEED;
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


	//    ŒWIAT£O	 TODO wywaliæ do main_file
	GLenum id = GL_LIGHT0;		
    GLfloat position[ 4 ] = { 0.0f, 10.0f, 10.0f, 1.0f };
    GLfloat ambient[ 4 ] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat diffuse[ 4 ] ={ 0.8f, 0.8f, 0.8f, 1.0f }; 
    GLfloat specular[ 4 ] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
	glLightfv( id, GL_AMBIENT, ambient );
    glLightfv( id, GL_DIFFUSE, diffuse );
    glLightfv( id, GL_SPECULAR, specular );
    glLightfv( id, GL_POSITION, position );
    glEnable( id );
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
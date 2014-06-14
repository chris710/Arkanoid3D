#include"main_file.h"


int lastTime=0;
int interval;							//czas pomi�dzy klatkami
int fps = 0;							//ile fps�w
float newX = 0;
int lastFPSCheck;						//kiedy ostatnio by�y wy�weitlane fps
Session *NewSession = new Session();
	GLuint blockTex;					//uchwyt na tekstur� bloczka			
	TGAImg blockImg;					//obraz z tekstur� bloczka




void displayFrame(void) {											//Tutaj kod rysuj�cy		
	glClearColor(1,1,1,0);											//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				//czyszczenie bufor�w  //w�a�ciwe czyszcenie okna

	NewSession->drawAll();											//wy�wietla ca�o��
	
	glutSwapBuffers();												//wywala zawarto�� bufora ZAWSZE NA KO�CU!!!
}

void nextFrame(void) {									//to co robi si� pomi�dzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;
	printFPS(actTime);		//wypisuje fpsy

	//////// CZʌ� NA MECHANIK�	////////////		//pami�taj aby mno�y� razy interval!
	if ( (NewSession->Paletka->getX() + newX < 10.0) && (NewSession->Paletka->getX() + newX > -10.0) )
		NewSession->Paletka->X += newX;
						//TODO to ma by� funkcja!!!
	glutPostRedisplay();
}

void keyDown(int c, int x, int y) {
 if (c==GLUT_KEY_LEFT) {
	newX = -0.1;
}
 if (c==GLUT_KEY_RIGHT) {
	newX = 0.1;
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja bufor�w
	glutInitWindowSize(800,800);			//opcje okna
	glutInitWindowPosition(400,0);
	glutCreateWindow("Arkanoid 3D");		//nadanie tytu�u okna 
	glutDisplayFunc(displayFrame);			//rejestracja obs�ugi od�wie�aj�ca okno
	glutIdleFunc(nextFrame);
	//tutaj kod inicjuj�cy					//TODO to te�	
	glEnable(GL_DEPTH_TEST);				//w��czanie zbuffora
	glEnable(GL_LIGHTING);					//w��czamy o�wietlenie
			// TEKSTURY	
	
	glEnable(GL_TEXTURE_2D);	
	if (blockImg.Load("res/bloczek.tga")==IMG_OK){
		glGenTextures(1,&(blockTex)); //Zainicjuj uchwyt tex
		glBindTexture(GL_TEXTURE_2D,blockTex); //Przetwarzaj uchwyt tex
	if (blockImg.GetBPP()==24) //Obrazek 24bit
		glTexImage2D(GL_TEXTURE_2D,0,3,blockImg.GetWidth(),blockImg.GetHeight(),0,
		GL_RGB,GL_UNSIGNED_BYTE,blockImg.GetImg());
	else if (blockImg.GetBPP()==32) //Obrazek 32bit
		glTexImage2D(GL_TEXTURE_2D,0,4,blockImg.GetWidth(),blockImg.GetHeight(),0,
		GL_RGBA,GL_UNSIGNED_BYTE,blockImg.GetImg());
	else {
		//Obrazek 16 albo 8 bit, takimi si� nie przejmujemy
	}} 

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	

	//    �WIAT�O	 TODO wywali� do main_file
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
	glEnable(GL_COLOR_MATERIAL);			//kolorek po o�wietleniu
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
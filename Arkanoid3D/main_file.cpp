
#include "main.h"
#include "sterowanie.h"
#include "init.h"

using namespace glm;

float speed=360; //360 stopni/s
int lastTime=0;
float angle;
int interval;

void displayFrame(void) {
		//Tutaj kod rysuj�cy
	glClearColor(1,1,1,0);	//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //czyszczenie bufor�w  //w�a�ciwe czyszcenie okna
    
    //okno wyczyszczone mo�na dzia�a�
	mat4 M = mat4(1.0f);	//macierz jednostkowa	
	
	mat4 V = lookAt(	    //wsp�rz�dne kamery
	vec3(0.0f,-3.0f,5.0f),	//gdzie
	vec3(0.0f,0.0f,0.0f),	//kierunek
	vec3(0.0f,1.0f,0.0f));	//wektor do g�ry

	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);	//w�asno�ci widoku		//TODO zamieni� na fcj�
	/*				  (fovy, aspect,zNear,zFar);*/
	//mat4 W=rotate(M, angle, vec3(0.0f,1.0f,0.0f));
	
	    //�adowanie macierzy do modelu		//WTF???
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(value_ptr(V*W));

	    //od teraz mo�na rysowa�
	//////	CZʌ� NA FUNKCJE RYSUJ�CE	///////////
	createRoom();
	createBlocks();

	//printf("FPS: %f\n",60/interval*1000);		//TODO spos�b na wy�wietlanie FPS w konsoli

	glutSwapBuffers();  //wywala zawarto�� bufora ZAWSZE NA KO�CU!!!
}


void nextFrame(void) {//to co robi si� pomi�dzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);		//TODO FPSy!!!
	interval=actTime-lastTime;
	lastTime=actTime;
	
	//////// CZʌ� NA MECHANIK�	////////////
	angle+=speed*interval/1000.0;
	if (angle>360) angle-=360;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
        glutInit(&argc, argv);						//TODO wywali� do fcji
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja bufor�w
        glutInitWindowSize(800,800);	//opcje okna
        glutInitWindowPosition(0,0);
        glutCreateWindow("Program OpenGL");       //nadanie tytu�u okna 
		glutDisplayFunc(displayFrame);	//rejestracja obs�ugi od�wie�aj�ca okno
		glutIdleFunc(nextFrame);
	//tutaj kod inicjuj�cy				//TODO to te�	
	glEnable(GL_LIGHTING);	    //w��czamy o�wietlenie
	glEnable(GL_LIGHT0);	    //w��czamy �wiat�o
	glEnable(GL_DEPTH_TEST);    //w��czanie zbuffora
	glEnable(GL_COLOR_MATERIAL);    //kolorek po o�wietleniu

        glutMainLoop();
        return 0;
}
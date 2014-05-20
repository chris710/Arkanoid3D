
#include "main.h"
#include "sterowanie.h"
#include "init.h"

using namespace glm;

float speed=360; //360 stopni/s
int lastTime=0;
float angle;
int interval;

void displayFrame(void) {
		//Tutaj kod rysuj¹cy
	glClearColor(1,1,1,0);	//czyszczenie okna do koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //czyszczenie buforów  //w³aœciwe czyszcenie okna
    
    //okno wyczyszczone mo¿na dzia³aæ
	mat4 M = mat4(1.0f);	//macierz jednostkowa	
	
	mat4 V = lookAt(	    //wspó³rzêdne kamery
	vec3(0.0f,-3.0f,5.0f),	//gdzie
	vec3(0.0f,0.0f,0.0f),	//kierunek
	vec3(0.0f,1.0f,0.0f));	//wektor do góry

	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);	//w³asnoœci widoku		//TODO zamieniæ na fcjê
	/*				  (fovy, aspect,zNear,zFar);*/
	//mat4 W=rotate(M, angle, vec3(0.0f,1.0f,0.0f));
	
	    //³adowanie macierzy do modelu		//WTF???
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(value_ptr(V*W));

	    //od teraz mo¿na rysowaæ
	//////	CZÊŒÆ NA FUNKCJE RYSUJ¥CE	///////////
	createRoom();
	createBlocks();

	//printf("FPS: %f\n",60/interval*1000);		//TODO sposób na wyœwietlanie FPS w konsoli

	glutSwapBuffers();  //wywala zawartoœæ bufora ZAWSZE NA KOÑCU!!!
}


void nextFrame(void) {//to co robi siê pomiêdzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);		//TODO FPSy!!!
	interval=actTime-lastTime;
	lastTime=actTime;
	
	//////// CZÊŒÆ NA MECHANIKÊ	////////////
	angle+=speed*interval/1000.0;
	if (angle>360) angle-=360;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
        glutInit(&argc, argv);						//TODO wywaliæ do fcji
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja buforów
        glutInitWindowSize(800,800);	//opcje okna
        glutInitWindowPosition(0,0);
        glutCreateWindow("Program OpenGL");       //nadanie tytu³u okna 
		glutDisplayFunc(displayFrame);	//rejestracja obs³ugi odœwie¿aj¹ca okno
		glutIdleFunc(nextFrame);
	//tutaj kod inicjuj¹cy				//TODO to te¿	
	glEnable(GL_LIGHTING);	    //w³¹czamy oœwietlenie
	glEnable(GL_LIGHT0);	    //w³¹czamy œwiat³o
	glEnable(GL_DEPTH_TEST);    //w³¹czanie zbuffora
	glEnable(GL_COLOR_MATERIAL);    //kolorek po oœwietleniu

        glutMainLoop();
        return 0;
}
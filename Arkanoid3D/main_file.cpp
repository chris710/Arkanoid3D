#include <windows.h> //Wymagane dla implementacji OpenGL w Visual Studio.
#include "gl\gl.h"	//procedury opengl
#include "gl\glut.h" //grafika i sterowanie
#include "stdio.h" //Przydatne do wypisywania komunikatów na konsoli
#include "glm\glm.hpp"	//matematyka
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

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
	mat4 M = mat4(1.0f);	
	
	mat4 V = lookAt(	    //wspó³rzêdne kamery
	vec3(0.0f,0.0f,-5.0f),
	vec3(0.0f,0.0f,0.0f),
	vec3(0.0f,1.0f,0.0f));

	/*mat4 perspective(	    //w³asnoœci widoku
	float fovy,
	float aspect,
	float zNear,
	float zFar);*/
	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);
	mat4 W=rotate(M, angle, vec3(0.0f,1.0f,0.0f));
	
	    //³adowanie macierzy do modelu
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(value_ptr(V*W));
	    //od teraz mo¿na rysowaæ

	glutSolidTeapot(1.5f);

	//printf("FPS: %f\n",60/interval*1000);
	glutSwapBuffers();  //wywala zawartoœæ bufora ZAWSZE NA KOÑCU!!!
}


void nextFrame(void) {//to co robi siê pomiêdzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;
	
	angle+=speed*interval/1000.0;
	if (angle>360) angle-=360;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja buforów
        glutInitWindowSize(800,800);	//opcje okna
        glutInitWindowPosition(0,0);
        glutCreateWindow("Program OpenGL");       //nadanie tytu³u okna 
		glutDisplayFunc(displayFrame);	//rejestracja obs³ugi odœwie¿aj¹ca okno
		glutIdleFunc(nextFrame);
	//tutaj kod inicjuj¹cy	
	glColor3d(1.0f,1.0f,0.0f);  //kolorujemy
	glEnable(GL_LIGHTING);	    //w³¹czamy oœwietlenie
	glEnable(GL_LIGHT0);	    //w³¹czamy œwiat³o
	glEnable(GL_DEPTH_TEST);    //w³¹czanie zbuffora
	glEnable(GL_COLOR_MATERIAL);    //kolorek po oœwietleniu

        glutMainLoop();
        return 0;
}
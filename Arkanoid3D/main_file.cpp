#include <windows.h> //Wymagane dla implementacji OpenGL w Visual Studio.
#include "gl\gl.h"	//procedury opengl
#include "gl\glut.h" //grafika i sterowanie
#include "stdio.h" //Przydatne do wypisywania komunikat�w na konsoli
#include "glm\glm.hpp"	//matematyka
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

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
	mat4 M = mat4(1.0f);	
	
	mat4 V = lookAt(	    //wsp�rz�dne kamery
	vec3(0.0f,0.0f,-5.0f),
	vec3(0.0f,0.0f,0.0f),
	vec3(0.0f,1.0f,0.0f));

	/*mat4 perspective(	    //w�asno�ci widoku
	float fovy,
	float aspect,
	float zNear,
	float zFar);*/
	mat4 P=perspective(50.0f, 1.0f, 1.0f, 50.0f);
	mat4 W=rotate(M, angle, vec3(0.0f,1.0f,0.0f));
	
	    //�adowanie macierzy do modelu
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(value_ptr(P));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(value_ptr(V*W));
	    //od teraz mo�na rysowa�

	glutSolidTeapot(1.5f);

	//printf("FPS: %f\n",60/interval*1000);
	glutSwapBuffers();  //wywala zawarto�� bufora ZAWSZE NA KO�CU!!!
}


void nextFrame(void) {//to co robi si� pomi�dzy klatkami
	int actTime=glutGet(GLUT_ELAPSED_TIME);
	interval=actTime-lastTime;
	lastTime=actTime;
	
	angle+=speed*interval/1000.0;
	if (angle>360) angle-=360;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	//inicjalizacja bufor�w
        glutInitWindowSize(800,800);	//opcje okna
        glutInitWindowPosition(0,0);
        glutCreateWindow("Program OpenGL");       //nadanie tytu�u okna 
		glutDisplayFunc(displayFrame);	//rejestracja obs�ugi od�wie�aj�ca okno
		glutIdleFunc(nextFrame);
	//tutaj kod inicjuj�cy	
	glColor3d(1.0f,1.0f,0.0f);  //kolorujemy
	glEnable(GL_LIGHTING);	    //w��czamy o�wietlenie
	glEnable(GL_LIGHT0);	    //w��czamy �wiat�o
	glEnable(GL_DEPTH_TEST);    //w��czanie zbuffora
	glEnable(GL_COLOR_MATERIAL);    //kolorek po o�wietleniu

        glutMainLoop();
        return 0;
}
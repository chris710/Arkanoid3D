#ifndef MAIN_H
#define MAIN_H
//plik nag��wkowy z includami

#include <windows.h> //Wymagane dla implementacji OpenGL w Visual Studio.
#include "gl\gl.h"	//procedury opengl
#include "gl\glut.h" //grafika i sterowanie
#include "stdio.h" //Przydatne do wypisywania komunikat�w na konsoli
#include "glm\glm.hpp"	//matematyka
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include<iostream>


void initialize();					//w��cza wszystkie openglowe rzeczy

 		
void printFPS(int actTime);			//liczy klatki na sekund� i wy�wietla je na konsoli

#endif //MAIN_H
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
#include<vector>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<sstream>
#include "tga.h"

#define BALL_SPEED 0.003;				//pr�dko�� pi�ki
#define PADDLE_SPEED 0.01;				//pr�dko�� paletki


#endif //MAIN_H
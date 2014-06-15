#ifndef MAIN_H
#define MAIN_H
//plik nag³ówkowy z includami

#include <windows.h> //Wymagane dla implementacji OpenGL w Visual Studio.
#include "gl\gl.h"	//procedury opengl
#include "gl\glut.h" //grafika i sterowanie
#include "stdio.h" //Przydatne do wypisywania komunikatów na konsoli
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

#define BALL_SPEED 0.003;				//prêdkoœæ pi³ki
#define PADDLE_SPEED 0.01;				//prêdkoœæ paletki


#endif //MAIN_H
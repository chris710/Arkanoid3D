#ifndef MAIN_FILE_H
#define MAIN_FILE_H
//plik nag��wkowy do maina

#include"RedBlock.h"
#include"BlueBlock.h"
#include"SilverBlock.h"
#include "sterowanie.h"
#include"Session.h"

void initialize();					//w��cza wszystkie openglowe rzeczy
 		
void printFPS(int actTime);			//liczy klatki na sekund� i wy�wietla je na konsoli (pobiera aktualny czas)

#endif //MAIN_FILE_H
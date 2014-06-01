#ifndef MAIN_FILE_H
#define MAIN_FILE_H
//plik nag³ówkowy do maina

#include"RedBlock.h"
#include"BlueBlock.h"
#include"SilverBlock.h"
#include "sterowanie.h"
#include"Session.h"

void initialize();					//w³¹cza wszystkie openglowe rzeczy
 		
void printFPS(int actTime);			//liczy klatki na sekundê i wyœwietla je na konsoli (pobiera aktualny czas)

#endif //MAIN_FILE_H
#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "utile.h"

//폰트 색상
void fontcolor(FONT_COLOR color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "utile.h"

//��Ʈ ����
void fontcolor(FONT_COLOR color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "inf.h"
#include "ui.h"
#include "b_manager.h"
#include "file_read.h"
#include "file_search.h"
#include "time.h"

int main() {

	//최종 수정 : 10월 26일 4:30
	system("mode con cols=40 lines=50");

	SetConsoleTitle(TEXT("도서 관리 프로그램 ver1"));
	fontcolor(LIGHT_CYAN);
	set_cursot_type(NOCURSOR);
	title();
	_getch();
	system("cls");
	
	fontcolor(14);
	set_cursot_type(NORMAL_CURSOR);

	
	while (1) {
		bok_menu();
	}
}
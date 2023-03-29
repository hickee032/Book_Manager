#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "inf.h"
#include "ui.h"
#include "utile.h"

int main() {

	system("mode con cols=40 lines=30");
	fontcolor(LIGHT_CYAN);
	set_cursot_type(NOCURSOR);
	title();
	_getch();
	system("cls");
	fontcolor(14);
	set_cursot_type(NORMAL_CURSOR);

	while (1) {
		switch (main_menu()) {
		case BOK_SHOW:
			//책 목록
			break;
		case BOK_SEARCH:
			//책 검색
			break;
		case BOK_LEND:
			//책 대여
			break;
		case BOK_BACK:
			//책 반납
			break;

		case BOK_EXIT:
			printf("프로그램을 종료합니다.\n");
			exit(0);
			break;

		case M_MANAGER:
			//관리자 메뉴
			break;
		}

}
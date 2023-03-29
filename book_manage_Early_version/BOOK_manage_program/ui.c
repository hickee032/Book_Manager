#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "ui.h"


void title() {

	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■                                    ■\n");
	printf("■▶  메뉴 이동은 아무키나 누르세요 ◀■\n");
	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n");
	printf("※ 도움말 ※\n");
	printf("▶ 메뉴 이동은 아무키나 누르세요 ◀");
}


//커서를 안보이게 처리
void set_cursot_type(CURSOR_TYPE type) {

	CONSOLE_CURSOR_INFO curinfo;
	memset(&curinfo, 0, sizeof(curinfo));
	switch (type) {
	case NOCURSOR:
		curinfo.dwSize = 1;
		curinfo.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		curinfo.dwSize = 100;
		curinfo.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		curinfo.dwSize = 20;
		curinfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}
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
			//å ���
			break;
		case BOK_SEARCH:
			//å �˻�
			break;
		case BOK_LEND:
			//å �뿩
			break;
		case BOK_BACK:
			//å �ݳ�
			break;

		case BOK_EXIT:
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
			break;

		case M_MANAGER:
			//������ �޴�
			break;
		}

}
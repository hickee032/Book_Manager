#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "ui.h"


void title() {

	Sleep(30);
	printf("���������������������\n"); Sleep(20);
	printf("��                                    ��\n"); Sleep(10);
	printf("��    #####    ###     ###   ##       ��\n"); Sleep(10);
	printf("��     #   #  #   #   #   #   #       ��\n"); Sleep(10);
	printf("��     #   # #     # #     #  #       ��\n"); Sleep(10);
	printf("��     ####  #     # #     #  # ###   ��\n"); Sleep(10);
	printf("��     #  #  #     # #     #  # ##    ��\n"); Sleep(10);
	printf("��     #   # #     # #     #  ##      ��\n"); Sleep(10);
	printf("��     #   #  #   #   #   #   # #     ��\n"); Sleep(10);
	printf("��     #####   ###     ###   ## ##    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("���������������������\n"); 
	printf("\n"); Sleep(500);
	printf("      �޴� �̵��� �ƹ�Ű�� ��������     \n");
	
	


}

void exit_Bok() {

	system("cls");
	fontcolor(LIGHT_CYAN);
	Sleep(10);
	printf("���������������������\n"); 
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��        #####                       ��\n"); Sleep(10);
	printf("��         #   #                      ��\n"); Sleep(10);
	printf("��         #   #                      ��\n"); Sleep(10);
	printf("��         ####  ###  ##  ###         ��\n"); Sleep(10);
	printf("��         #  #   ##  #  #   #        ��\n"); Sleep(10);
	printf("��         #   #   # ##  #####        ��\n"); Sleep(10);
	printf("��         #   #   # #   #            ��\n"); Sleep(10);
	printf("��        #####     #     ####        ��\n"); Sleep(10);
	printf("��                 #                  ��\n"); Sleep(10);
	printf("��               ##                   ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��                                    ��\n"); Sleep(10);
	printf("��            Thank You               ��\n"); Sleep(10);
	printf("���������������������\n");

	exit(0);

}

//Ŀ���� �Ⱥ��̰� ó��
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

//��Ʈ ����
void fontcolor(FONT_COLOR color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
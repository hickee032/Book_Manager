#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "ui.h"


void title() {

	printf("���������������������\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("��                                    ��\n");
	printf("�ᢺ  �޴� �̵��� �ƹ�Ű�� �������� ����\n");
	printf("���������������������\n");
	printf("\n");
	printf("�� ���� ��\n");
	printf("�� �޴� �̵��� �ƹ�Ű�� �������� ��");
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
#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "inf.h"
#include "ui.h"



void list_show(BOOK_INFO lect) {

	fontcolor(11);
	printf("�� ����: %s\n", lect.book_title);
	printf("�� ����: %s\n", lect.book_writer);
	printf("�� ���ǻ�: %s\n", lect.book_pub);
	fontcolor(14);

	printf("----------------------------------------\n");
	
	if (lect.book_curent == 1) {

		fontcolor(12);
		printf("�� �뿩 ����: %s\n", "�뿩 �Ұ�");
		printf("�� �뿩 ��¥: %s\n", lect.out_date);
		printf("�� �ݳ� ���� ��¥: %s\n", lect.in_date);
		fontcolor(14);
	}
	else {
		fontcolor(10);
		printf("�� �뿩 ����: %s\n", "�뿩 ����");
		fontcolor(14);
	}
	fontcolor(14);
	printf("\n");
}

void list_read() {

	system("cls");

	int count = 1;

	FILE* fpr = fopen("D:\\book_list.bin", "rb");
	if (fpr == NULL) {
		printf("�� ������ �������� �����ϴ�.\n");
		return;
	}

	BOOK_INFO lect = { 0, };
	while (fread(&lect, sizeof(BOOK_INFO), 1, fpr) == 1) {

		printf("��  %d #################################\n",count);

		list_show(lect);
		count++;
		Sleep(200);
	}
	printf("�� �� ���� ���� %d �� �Դϴ�.          #\n\n", count-1);
	system("pause");
	fclose(fpr);
	
}
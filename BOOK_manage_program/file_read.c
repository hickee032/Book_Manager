#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include "inf.h"
#include "ui.h"



void list_show(BOOK_INFO lect) {

	fontcolor(11);
	printf("▷ 제목: %s\n", lect.book_title);
	printf("▷ 저자: %s\n", lect.book_writer);
	printf("▷ 출판사: %s\n", lect.book_pub);
	fontcolor(14);

	printf("----------------------------------------\n");
	
	if (lect.book_curent == 1) {

		fontcolor(12);
		printf("▶ 대여 상태: %s\n", "대여 불가");
		printf("▶ 대여 날짜: %s\n", lect.out_date);
		printf("▶ 반납 예정 날짜: %s\n", lect.in_date);
		fontcolor(14);
	}
	else {
		fontcolor(10);
		printf("▶ 대여 상태: %s\n", "대여 가능");
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
		printf("▶ 파일을 읽을수가 없습니다.\n");
		return;
	}

	BOOK_INFO lect = { 0, };
	while (fread(&lect, sizeof(BOOK_INFO), 1, fpr) == 1) {

		printf("▶  %d #################################\n",count);

		list_show(lect);
		count++;
		Sleep(200);
	}
	printf("◈ 총 도서 수는 %d 권 입니다.          #\n\n", count-1);
	system("pause");
	fclose(fpr);
	
}
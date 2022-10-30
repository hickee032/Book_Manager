#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "inf.h"
#include "file_search.h"
#include "file_read.h"
#include "file_rent.h"
#include "time.h"
#include "ui.h"

void file_rent() {

	system("cls");
	char book_name[40];
	printf("◆------------------------------------◆\n");
	printf("◆------------------------------------◆\n");
	printf("     대출할 도서명을 입력해주세요 \n\n");
	printf("▷▷ 입력 : ");

	// 대출할 도서명 입력받기
	scanf("%[^\n]s", book_name);
	// 도서정보 불러오기 -> 대출여부 바꾸기(0가능 -> 1불가능)
	book_search_rent(book_name);
}

void book_search_rent(char book_name[]){

	FILE* fpr = fopen("d:/book_list.bin", "rb");
	if (fpr == NULL) {
		printf("▶ 목록을 읽을 수 없습니다.\n");
		return;
	}

	BOOK_INFO b_k = { 0, };
	int count = 1;
	static BOOK_INFO dest[256] = { 0, }; //구조체 배열
	char input = 0;
	int idx = 0;
	int found = 0; // 책을 찾으면 1로 변경, 찾지 못하면 0
	while (fread(&b_k, sizeof(BOOK_INFO), 1, fpr) == 1) {

		memcpy(&dest[idx], &b_k, sizeof(BOOK_INFO));

		if (strcmp(book_name, b_k.book_title) == 0) {

			book_show_rent(b_k);
			
			Sleep(1000);
			rewind(stdin);

			if (b_k.book_curent == 0) {
				Sleep(500);
				printf("▶ 위 책을 대출하겠습니까? [Y/N]\n");
				printf("▷▷ 입력 : ");
				scanf("%c", &input);

				Sleep(500);

				if (input == 'Y' || input == 'y') {

					dest[idx].book_curent = 1;

					char curtime[40] = { 0, };
					char rettime[40] = { 0, };

					get_time(curtime);

					strcpy(dest[idx].out_date, curtime);
					strcpy(rettime,get_time_due(curtime, 7));
					strcpy(dest[idx].in_date, rettime);

					found = 1;
				}
				else if (input == 'N' || input == 'n') {
					printf("▶ 대출을 취소합니다.\n");
				}
				else {
					printf("▶ 잘못 입력하셨습니다.\n");
				}
			}
			
		}
		idx++;
	}
	fclose(fpr); //파일을 닫아준다. 

	if (found == 0) {
		printf("▶ 원하는 책이 존재하지 않습니다.\n");
		return;
	}

	fpr = fopen("d:/book_list.bin", "wb");
	// 파일을 wb로 열어준다.
	if (fpr == NULL) {
		printf("▶ 목록을 생성할 수 없습니다.\n");
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].book_title, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK_INFO), 1, fpr);
		}
		else break;
	}
	// 대출된 정보 보여주기
	// 덮어쓰기
	fclose(fpr);
	memset(dest, 0, sizeof(BOOK_INFO) * 256);
	Sleep(2000);
}

void book_show_rent(BOOK_INFO book)
// 도서 정보를 보여줌
{
	BOOK_INFO b_k = { 0, };
	//대출기간
	int period = 7;

	int count = 1;
	static BOOK_INFO dest[256] = { 0, }; //구조체로 만들어줌
	int idx = 0;
	int found = 0; // 책을 찾으면 1로 변경, 찾지 못하면 0

	if (book.book_curent == 0) {
		//dest[idx].book_curent = 1;
		fontcolor(12);
		printf("\n");
		printf("▶ 도서가 대출됩니다.\n");
		printf("----------------------------------------\n");
		printf("▶ 대출 도서 정보\n");
		printf("----------------------------------------\n");
		printf("▶ 도서명: %s\n", book.book_title);
		printf("▶ 저자: %s\n", book.book_writer);
		printf("▶ 출판사: %s\n", book.book_pub);
		char curtime[40] = { 0, };
		get_time(curtime);
		strcpy(dest[idx].out_date, curtime);
		printf("▶ 대출날짜:%s\n", curtime);
		printf("----------------------------------------\n");

		//char rettime[40] = { 0, };
		//strcpy(&rettime, get_time_due(curtime, period));
		//get_time_due(curtime,period); //반납 예정일 curtime 리턴
	//	printf("get_time_due : %s\n", rettime);
		strcpy(dest[idx].in_date, get_time_due(curtime, period));

		//printf("rettime : %s", rettime);
		//printf("dest : %s", dest[idx].in_date);

		printf("▶ 대여 기간은 7일 \n"); 
		printf("▶ 반납일은 %s 입니다.\n\n", dest[idx].in_date);
		fontcolor(14);
		//Sleep(3000);
	}
	else if (book.book_curent == 1) {

		fontcolor(12);
		printf("----------------------------------------\n");
		printf("▶ 이미 대출된 도서입니다\n");
		printf("▶ 반납 예정일은\n");
		printf("▶ %s 입니다.\n",book.in_date);
		printf("----------------------------------------\n");
		fontcolor(14);
	}

}

void file_return() {

	system("cls");
	char book_name[40];

	printf("◆------------------------------------◆\n");
	printf("◆------------------------------------◆\n");
	printf("     반납할 도서명을 입력해주세요 \n\n");
	printf("입력 ▷ ");
	scanf("%[^\n]s", book_name);
	// 대출할 도서명 입력받기
	//BOOK_INFO B_K = { 0, };
	//system("pause");
	book_search_return(book_name);
}

void book_search_return(char book_name[]) {

	long lateMoney = 0;
	int period = 7;

	FILE* fpr = fopen("d:/book_list.bin", "rb");
	if (fpr == NULL) {
		printf("▶ 목록을 읽을 수 없습니다.\n");
		return;
	} // 파일을 rb로 읽음

	BOOK_INFO b_k = { 0, };

	int count = 1;

	static BOOK_INFO dest[256] = { 0, }; //구조체로 만들어줌

	int idx = 0;

	int found = 0; // 책을 찾으면 1로 변경, 찾지 못하면 0

	while (fread(&b_k, sizeof(BOOK_INFO), 1, fpr) == 1) {

		memcpy(&dest[idx], &b_k, sizeof(BOOK_INFO));

		if (strcmp(book_name, b_k.book_title) == 0) {

			if (b_k.book_curent == 0) {
				printf("▶ 해당 책은 반납할 책이 아닙니다.\n");
				Sleep(2000);
				break;
			}

			lateMoney = get_time_diff(dest[idx].in_date);

			//printf("lateMoney : %ld\n", lateMoney);

			if (lateMoney < 0|| lateMoney == 0) {
				fontcolor(12);
				printf("----------------------------------------\n");
				printf("▶ 연체료가 없습니다.\n");
				printf("----------------------------------------\n");
				fontcolor(14);
				Sleep(2000);
			}
			else {
				fontcolor(12);
				printf("----------------------------------------\n");
				printf("▶ 연체료가 발생합니다.\n");
				printf("▶ 연체료는 %d 입니다.\n", lateMoney * 100);
				printf("----------------------------------------\n");
				fontcolor(14);
				printf("▶ 연체료를 수납 후 엔터\n");
				system("pause");
			}

			dest[idx].book_curent = 0;
			found = 1;
		}
		idx++;
	}
	fclose(fpr); //파일을 닫아준다. 

	if (found == 0) {
		printf("▶ 원하는 책이 존재하지 않습니다.\n");
		return;
	}

	fpr = fopen("d:/book_list.bin", "wb");
	// 파일을 wb로 열어준다.
	if (fpr == NULL) {
		printf("▶ 목록을 생성할 수 없습니다.\n");
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].book_title, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK_INFO), 1, fpr);
		}
		else break;
	}
	// 대출된 정보 보여주기
	// 덮어쓰기
	fclose(fpr);
	memset(dest, 0, sizeof(BOOK_INFO) * 256);
	Sleep(2000);

}
#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "inf.h"
#include "ui.h"
#include "file_search.h"
#include "file_read.h"

void list_search() {
	system("cls");

	int input = 0;
	char user_search[40] = { 0, };

	BOOK_INFO B_K = { 0, };

	while (1) {

		printf("◆====================================◆\n");
		printf("◆                                    ◆\n");
		printf("◆      1.책 제목으로 검색합니다.     ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      2.책 저자로 검색합니다.       ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      3.책 출판사로 검색합니다.     ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      4.단어로 검색합니다.          ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      5.되돌아가기                  ◆\n");
		printf("◆                                    ◆\n");
		printf("◆====================================◆\n");
		printf("\n");
		printf("◆도움말◆\n");
		printf("\n");
		printf("▶ 1. 제목으로 검색\n");
		printf("▶ 2. 저자로 검색\n");
		printf("▶ 3. 출판사로 검색\n");
		printf("▶ 4. 제목에 포함된 단어로 검색\n");
		printf("\n");
		printf("▷▷  입력 : ");

		scanf("%d", &input);

		system("cls");
		if (input == 1) {
			rewind(stdin);
			printf("▷ 검색할 제목를 입력해주세요\n");
			printf("▷▷  입력 : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 1);
			break;

			if (strlen(user_search) == 0) {
				printf("▶ 올바른 입력이 아닙니다.");
			}
		}
		else if (input == 2) {
			rewind(stdin);
			printf("▷ 검색할 저자를 입력해주세요\n");
			printf("▷▷  입력 : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 2);
			break;

			if (strlen(user_search) == 0) {
				printf("▶ 올바른 입력이 아닙니다.");
			}
		}
		else if (input == 3) {
			rewind(stdin);
			printf("▷ 검색할 출판사를 입력해주세요\n");
			printf("▷▷  입력 : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 3);
			break;

			if (strlen(user_search) == 0) {
				printf("올바른 입력이 아닙니다.");
			}
		}
		else if (input == 4) {
			rewind(stdin);
			printf("▷ 검색할 단어를 입력해주세요\n");
			printf("▷▷  입력 : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 4);
			break;

			if (strlen(user_search) == 0) {
				printf("올바른 입력이 아닙니다.");
			}
		}
		else if (input == 5) {		
			break;
		}
		else {
			printf("▶ 잘못된 입력입니다.\n");
			printf("▶ 다시 입력하세요.\n");
			rewind(stdin);
			Sleep(1000);
			system("cls");

		}
	}
}

void book_search_show(char* input, int num) {

	fontcolor(11);

	FILE* fpr;
	fpr = fopen("d:/book_list.bin", "rb");
	if (fpr == NULL) {
		printf("▶ 목록을 불러올 수 없습니다.\n");
		return;

	}
	BOOK_INFO src = { 0, };
	static BOOK_INFO dest[256] = { 0, };

	char inputyn = ' ';
	int found = 1;
	int count = 1;

	if (num == 1) {
		while (fread(&src, sizeof(BOOK_INFO), 1, fpr) == 1) {

			if (strcmp(src.book_title, input) == 0) {
				fontcolor(14);
				printf("▶ %d ###################################\n\n", count);
				list_show(src);

				if (src.book_curent == 1) {
					printf("▶ 위 책의 정보를\n ");
					printf("▶ 교보문고를 통해\n");
					printf("          확인해보시겠습니까? [Y/N]\n");
					printf("▷▷ 입력 : ");
					rewind(stdin);
					scanf("%c", &inputyn);

					if (inputyn == 'Y' || inputyn == 'y') {
						system(src.book_URL);
					}
					else if (inputyn == 'N' || inputyn == 'n') {
						found = 0;
						count++;
						break;
					}
					else {
						printf("▶ 잘못 입력하셨습니다.\n");
						break;
					}
				}
				found = 0;
				count++;
			}
		}
		fontcolor(14);
		if (found == 1) {
			fontcolor(4);
			printf("▶ 검색한 내용을 찾을수 없습니다\n");
			Sleep(2000);
			fontcolor(14);
		}
		else {
			system("pause");
		}
	}
	else if (num == 2) {
		while (fread(&src, sizeof(BOOK_INFO), 1, fpr) == 1) {

			if (strcmp(src.book_writer, input) == 0) {
				list_show(src);
				found = 0;
				count++;

			}
		}
		fontcolor(14);
		if (found == 1) {
			fontcolor(4);
			printf("▶ 검색한 내용을 찾을수 없습니다\n");
			Sleep(2000);
			fontcolor(14);
		}
		else {
			system("pause");
		}

	}
	else if (num == 3) {
		while (fread(&src, sizeof(BOOK_INFO), 1, fpr) == 1) {

			if (strcmp(src.book_pub, input) == 0) {
				list_show(src);
				found = 0;
				count++;
			}
		}
		fontcolor(14);
		if (found == 1) {
			fontcolor(4);
			printf("▶ 검색한 내용을 찾을수 없습니다\n");
			Sleep(2000);
			fontcolor(14);
		}
		else {
			system("pause");
		}

	}
	else if (num == 4) {
		while (fread(&src, sizeof(BOOK_INFO), 1, fpr) == 1) {

			if (strstr(src.book_title,input) != NULL) {
				list_show(src);
				found = 0;
				count++;
			}
		}
		fontcolor(14);
		if (found == 1) {
			fontcolor(4);
			printf("▶ 검색한 내용을 찾을수 없습니다\n");
			Sleep(2000);
			fontcolor(14);
		}
		else {
			system("pause");
		}

	}
	fontcolor(14);
	fclose(fpr);
}


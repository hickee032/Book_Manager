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

		printf("��====================================��\n");
		printf("��                                    ��\n");
		printf("��      1.å �������� �˻��մϴ�.     ��\n");
		printf("��                                    ��\n");
		printf("��      2.å ���ڷ� �˻��մϴ�.       ��\n");
		printf("��                                    ��\n");
		printf("��      3.å ���ǻ�� �˻��մϴ�.     ��\n");
		printf("��                                    ��\n");
		printf("��      4.�ܾ�� �˻��մϴ�.          ��\n");
		printf("��                                    ��\n");
		printf("��      5.�ǵ��ư���                  ��\n");
		printf("��                                    ��\n");
		printf("��====================================��\n");
		printf("\n");
		printf("�ߵ��򸻡�\n");
		printf("\n");
		printf("�� 1. �������� �˻�\n");
		printf("�� 2. ���ڷ� �˻�\n");
		printf("�� 3. ���ǻ�� �˻�\n");
		printf("�� 4. ���� ���Ե� �ܾ�� �˻�\n");
		printf("\n");
		printf("����  �Է� : ");

		scanf("%d", &input);

		system("cls");
		if (input == 1) {
			rewind(stdin);
			printf("�� �˻��� ���� �Է����ּ���\n");
			printf("����  �Է� : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 1);
			break;

			if (strlen(user_search) == 0) {
				printf("�� �ùٸ� �Է��� �ƴմϴ�.");
			}
		}
		else if (input == 2) {
			rewind(stdin);
			printf("�� �˻��� ���ڸ� �Է����ּ���\n");
			printf("����  �Է� : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 2);
			break;

			if (strlen(user_search) == 0) {
				printf("�� �ùٸ� �Է��� �ƴմϴ�.");
			}
		}
		else if (input == 3) {
			rewind(stdin);
			printf("�� �˻��� ���ǻ縦 �Է����ּ���\n");
			printf("����  �Է� : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 3);
			break;

			if (strlen(user_search) == 0) {
				printf("�ùٸ� �Է��� �ƴմϴ�.");
			}
		}
		else if (input == 4) {
			rewind(stdin);
			printf("�� �˻��� �ܾ �Է����ּ���\n");
			printf("����  �Է� : ");
			scanf("%[^\n]s", user_search);
			book_search_show(user_search, 4);
			break;

			if (strlen(user_search) == 0) {
				printf("�ùٸ� �Է��� �ƴմϴ�.");
			}
		}
		else if (input == 5) {		
			break;
		}
		else {
			printf("�� �߸��� �Է��Դϴ�.\n");
			printf("�� �ٽ� �Է��ϼ���.\n");
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
		printf("�� ����� �ҷ��� �� �����ϴ�.\n");
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
				printf("�� %d ###################################\n\n", count);
				list_show(src);

				if (src.book_curent == 1) {
					printf("�� �� å�� ������\n ");
					printf("�� �������� ����\n");
					printf("          Ȯ���غ��ðڽ��ϱ�? [Y/N]\n");
					printf("���� �Է� : ");
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
						printf("�� �߸� �Է��ϼ̽��ϴ�.\n");
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
			printf("�� �˻��� ������ ã���� �����ϴ�\n");
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
			printf("�� �˻��� ������ ã���� �����ϴ�\n");
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
			printf("�� �˻��� ������ ã���� �����ϴ�\n");
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
			printf("�� �˻��� ������ ã���� �����ϴ�\n");
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


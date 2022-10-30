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
	printf("��------------------------------------��\n");
	printf("��------------------------------------��\n");
	printf("     ������ �������� �Է����ּ��� \n\n");
	printf("���� �Է� : ");

	// ������ ������ �Է¹ޱ�
	scanf("%[^\n]s", book_name);
	// �������� �ҷ����� -> ���⿩�� �ٲٱ�(0���� -> 1�Ұ���)
	book_search_rent(book_name);
}

void book_search_rent(char book_name[]){

	FILE* fpr = fopen("d:/book_list.bin", "rb");
	if (fpr == NULL) {
		printf("�� ����� ���� �� �����ϴ�.\n");
		return;
	}

	BOOK_INFO b_k = { 0, };
	int count = 1;
	static BOOK_INFO dest[256] = { 0, }; //����ü �迭
	char input = 0;
	int idx = 0;
	int found = 0; // å�� ã���� 1�� ����, ã�� ���ϸ� 0
	while (fread(&b_k, sizeof(BOOK_INFO), 1, fpr) == 1) {

		memcpy(&dest[idx], &b_k, sizeof(BOOK_INFO));

		if (strcmp(book_name, b_k.book_title) == 0) {

			book_show_rent(b_k);
			
			Sleep(1000);
			rewind(stdin);

			if (b_k.book_curent == 0) {
				Sleep(500);
				printf("�� �� å�� �����ϰڽ��ϱ�? [Y/N]\n");
				printf("���� �Է� : ");
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
					printf("�� ������ ����մϴ�.\n");
				}
				else {
					printf("�� �߸� �Է��ϼ̽��ϴ�.\n");
				}
			}
			
		}
		idx++;
	}
	fclose(fpr); //������ �ݾ��ش�. 

	if (found == 0) {
		printf("�� ���ϴ� å�� �������� �ʽ��ϴ�.\n");
		return;
	}

	fpr = fopen("d:/book_list.bin", "wb");
	// ������ wb�� �����ش�.
	if (fpr == NULL) {
		printf("�� ����� ������ �� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].book_title, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK_INFO), 1, fpr);
		}
		else break;
	}
	// ����� ���� �����ֱ�
	// �����
	fclose(fpr);
	memset(dest, 0, sizeof(BOOK_INFO) * 256);
	Sleep(2000);
}

void book_show_rent(BOOK_INFO book)
// ���� ������ ������
{
	BOOK_INFO b_k = { 0, };
	//����Ⱓ
	int period = 7;

	int count = 1;
	static BOOK_INFO dest[256] = { 0, }; //����ü�� �������
	int idx = 0;
	int found = 0; // å�� ã���� 1�� ����, ã�� ���ϸ� 0

	if (book.book_curent == 0) {
		//dest[idx].book_curent = 1;
		fontcolor(12);
		printf("\n");
		printf("�� ������ ����˴ϴ�.\n");
		printf("----------------------------------------\n");
		printf("�� ���� ���� ����\n");
		printf("----------------------------------------\n");
		printf("�� ������: %s\n", book.book_title);
		printf("�� ����: %s\n", book.book_writer);
		printf("�� ���ǻ�: %s\n", book.book_pub);
		char curtime[40] = { 0, };
		get_time(curtime);
		strcpy(dest[idx].out_date, curtime);
		printf("�� ���⳯¥:%s\n", curtime);
		printf("----------------------------------------\n");

		//char rettime[40] = { 0, };
		//strcpy(&rettime, get_time_due(curtime, period));
		//get_time_due(curtime,period); //�ݳ� ������ curtime ����
	//	printf("get_time_due : %s\n", rettime);
		strcpy(dest[idx].in_date, get_time_due(curtime, period));

		//printf("rettime : %s", rettime);
		//printf("dest : %s", dest[idx].in_date);

		printf("�� �뿩 �Ⱓ�� 7�� \n"); 
		printf("�� �ݳ����� %s �Դϴ�.\n\n", dest[idx].in_date);
		fontcolor(14);
		//Sleep(3000);
	}
	else if (book.book_curent == 1) {

		fontcolor(12);
		printf("----------------------------------------\n");
		printf("�� �̹� ����� �����Դϴ�\n");
		printf("�� �ݳ� ��������\n");
		printf("�� %s �Դϴ�.\n",book.in_date);
		printf("----------------------------------------\n");
		fontcolor(14);
	}

}

void file_return() {

	system("cls");
	char book_name[40];

	printf("��------------------------------------��\n");
	printf("��------------------------------------��\n");
	printf("     �ݳ��� �������� �Է����ּ��� \n\n");
	printf("�Է� �� ");
	scanf("%[^\n]s", book_name);
	// ������ ������ �Է¹ޱ�
	//BOOK_INFO B_K = { 0, };
	//system("pause");
	book_search_return(book_name);
}

void book_search_return(char book_name[]) {

	long lateMoney = 0;
	int period = 7;

	FILE* fpr = fopen("d:/book_list.bin", "rb");
	if (fpr == NULL) {
		printf("�� ����� ���� �� �����ϴ�.\n");
		return;
	} // ������ rb�� ����

	BOOK_INFO b_k = { 0, };

	int count = 1;

	static BOOK_INFO dest[256] = { 0, }; //����ü�� �������

	int idx = 0;

	int found = 0; // å�� ã���� 1�� ����, ã�� ���ϸ� 0

	while (fread(&b_k, sizeof(BOOK_INFO), 1, fpr) == 1) {

		memcpy(&dest[idx], &b_k, sizeof(BOOK_INFO));

		if (strcmp(book_name, b_k.book_title) == 0) {

			if (b_k.book_curent == 0) {
				printf("�� �ش� å�� �ݳ��� å�� �ƴմϴ�.\n");
				Sleep(2000);
				break;
			}

			lateMoney = get_time_diff(dest[idx].in_date);

			//printf("lateMoney : %ld\n", lateMoney);

			if (lateMoney < 0|| lateMoney == 0) {
				fontcolor(12);
				printf("----------------------------------------\n");
				printf("�� ��ü�ᰡ �����ϴ�.\n");
				printf("----------------------------------------\n");
				fontcolor(14);
				Sleep(2000);
			}
			else {
				fontcolor(12);
				printf("----------------------------------------\n");
				printf("�� ��ü�ᰡ �߻��մϴ�.\n");
				printf("�� ��ü��� %d �Դϴ�.\n", lateMoney * 100);
				printf("----------------------------------------\n");
				fontcolor(14);
				printf("�� ��ü�Ḧ ���� �� ����\n");
				system("pause");
			}

			dest[idx].book_curent = 0;
			found = 1;
		}
		idx++;
	}
	fclose(fpr); //������ �ݾ��ش�. 

	if (found == 0) {
		printf("�� ���ϴ� å�� �������� �ʽ��ϴ�.\n");
		return;
	}

	fpr = fopen("d:/book_list.bin", "wb");
	// ������ wb�� �����ش�.
	if (fpr == NULL) {
		printf("�� ����� ������ �� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].book_title, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK_INFO), 1, fpr);
		}
		else break;
	}
	// ����� ���� �����ֱ�
	// �����
	fclose(fpr);
	memset(dest, 0, sizeof(BOOK_INFO) * 256);
	Sleep(2000);

}
#include "def.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "inf.h"
#include "ui.h"
#include "b_manager.h"
#include "file_read.h"
#include "file_search.h"
#include "file_rent.h"



//���� �޴�
int bok_menu() {
	system("cls");
	int select = 0;
	printf("��------------------------------------��\n");
	printf("��------------------------------------��\n");
	printf("��              ���� ����             ��\n");
	printf("��------------------------------------��\n");
	printf("��                                    ��\n");
	printf("��           �� å ��� ����          ��\n");
	printf("��                                    ��\n");
	printf("��           �� å �˻� �ϱ�          ��\n");
	printf("��                                    ��\n");
	printf("��           �� å �뿩 �ϱ�          ��\n");
	printf("��                                    ��\n");
	printf("��           �� å �ݳ� �ϱ�          ��\n");
	printf("��                                    ��\n");
	printf("��------------------------------------��\n");
	printf("��                                    ��\n");
	printf("��           �� ���� �ϱ�             ��\n");
	printf("��                                    ��\n");
	printf("��------------------------------------��\n");
	printf("��                                    ��\n");
	printf("��           �� ����                ��\n");
	printf("��                                    ��\n");
	printf("��------------------------------------��\n");
	printf("��------------------------------------��\n");
	printf("��                                    ��\n");
	printf("��           �� ������ �޴�           ��\n");
	printf("��                                    ��\n");
	printf("��------------------------------------��\n");
	printf("��        �޴��� �����ϼ��� ��        ��\n");
	printf("��------------------------------------��\n");
	printf("\n");
	printf("���� �Է� : ");

	scanf("%d", &select);
	rewind(stdin);

	bok_menu_select(select);
	return select;


}

void bok_menu_select(int num) {
	if (1 <= num && num <= 7) {

		if (num == BOK_SHOW) {
			list_read();
		}
		else if (num == BOK_SEARCH) {

			list_search();

		}
		else if (num == BOK_LEND) {
			file_rent();
		}
		else if (num == BOK_BACK) {
			file_return();
		}
		else if (num == BOK_EXIT) {
			exit_Bok();

		}
		else if (num == BOK_HINT) {
			showHint();

		}
		else if (num == M_MANAGER) {
			manage_gate();
		}
	}
	else {
		printf("�� �߸� �Է��ϼ̽��ϴ�.\n");
		printf("�� 1~7������ ���ڸ� �Է� �����մϴ�.\n");
		Sleep(1000);
	}

}

//����
void showHint() {

	system("cls");

	printf("----------------------------------------\n");
	printf("             �� ���� ��               \n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� å ����� �α�� �Ǵ�\n");
	printf("\n");
	printf("                  ��ȣ������ �����ݴϴ�.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� å �̸�, ���ǻ� ,���ڷ�           \n");
	printf("\n");
	printf("                             �˻��մϴ�.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� å�� �뿩�մϴ�. �뿩��           \n");
	printf("\n");
	printf("      7���� �����  ��ü�ᰡ �߻��մϴ�.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� å�� �ݳ��մϴ�. ��ü�� �߻���    \n");
	printf("\n");
	printf("                    ��ü�Ḧ �����մϴ�.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� ���α׷��� �����մϴ�.    \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� ������ ����մϴ�.    \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("�� �� ������ �޴��� ȣ���մϴ�.        \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("----------------------------------------\n");
	Sleep(2000);
	printf("----------------------------------------\n");
	printf("�� �ƹ�Ű�� ��������\n");
	printf("                      �޴��� �̵��մϴ�.\n");
	printf("----------------------------------------\n");
	_getch();

}

//���� �����޴�

//void setting() {
//	system("cls");
//
//	int input = 0;
//	while (1) {
//
//		fontcolor(9); printf("1.�Ķ���\n");
//		fontcolor(10); printf("2.�ʷϻ�\n");
//		fontcolor(11); printf("3.����\n");
//		fontcolor(13); printf("4.�����\n");
//		fontcolor(15); printf("5.���\n");
//		fontcolor(14); printf("6.����Ʈ\n");
//
//		printf("�ٲٽ� �� ��ȣ�� �Է��ϼ����\n");
//		scanf("%d", &input);
//
//		if (1 <= input && input <= 6) {
//			if (input == 1) {
//				show_color(9);
//			}
//			else if (input == 2) {
//				show_color(10);
//			}
//			else if (input == 3) {
//				show_color(11);
//			}
//			else if (input == 4) {
//				show_color(13);
//			}
//			else if (input == 5) {
//				show_color(15);
//			}
//			else if (input == 6) {
//				show_color(14);
//			}
//		}
//		else {
//			printf("1~6 ������ ���ڸ� �Է����ּ���\n");
//		}
//
//	}
//}
//
//void show_color(int num){
//	fontcolor(num);
//	printf("�� ����� ��ü �մϴ�.\n");
//}





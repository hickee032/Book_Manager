#include "def.h"
#include <stdio.h>
#include "inf.h"


//���� �޴�
int bok_menu() {

	int select = 0;

	printf("��-----------------��\n");
	printf("��    ���� ����    ��\n");
	printf("��-----------------��\n");
	printf("�� �� å ��� ���� ��\n");
	printf("�� �� å �˻� �ϱ� ��\n");
	printf("�� �� å �뿩 �ϱ� ��\n");
	printf("�� �� å �ݳ� �ϱ� ��\n");
	printf("��-----------------��\n");
	printf("��  �� ���� �ϱ�   ��\n");
	printf("��-----------------��\n");
	printf("��-�� ������ �޴� -��\n");
	printf("��-----------------��\n");

	printf("�� �޴��� �����ϼ��� ��");

	scanf_s("%d", &select);

	return select;

}
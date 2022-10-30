              #include "def.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <malloc.h> //?
#include <conio.h>
#include "inf.h"
#include "ui.h"
#include "b_manager.h"

//������ ���̵� ��й�ȣ
MA_IDPASS id_pass[5] = { 0, };

//���� ���̵�
char curID[10] = { 0, };

//������ �ּ�
char fileAddr[] = "D:\\book_list.bin ";

//������ �÷���
int idx = 0;

//������ ���̵� ��й�ȣ �Է�
void manage_gate() {
	system("cls");

	int flag = 0;

	while (1) {

		char inputID[20];
		char inputPASS[20];

		printf("�� ������ �޴��Դϴ�.\n");
		printf("�� ���̵�� ��й�ȣ�� �ʿ��մϴ�.\n");
		printf("�� ���̵� �Է� : ");
		scanf("%s", inputID);
		printf("�� ��й�ȣ �Է� : ");
		scanf("%s", inputPASS);

		managerRead();

		flag = 1;
		flag = idPassC(inputID, inputPASS);
		if (flag == 1) {
			manage_ui();
			break;
		}
		else if (flag == 0) {
			break;
		}
	}	
	Sleep(2000);
}

//�����ڰ� �ƴ��� ���̵� ��й�ȣ üũ
int idPassC(char a[], char n[]) {

	int flag = 1;

	for (int i = 0; i < sizeof(id_pass) / sizeof(MA_IDPASS); i++) {

		if (strcmp(id_pass[i].id, a) == 0) {
			idx = i;
			flag = 0;
		}
	}

	if (flag == 0) {
		if (strcmp(id_pass[idx].pass,n)==0) {
			strcpy(curID, a);
			return 1;
		}
		else {
			printf("�� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
			Sleep(400);
			return 0;
		}
	}

	else {
		printf("�� �����ڰ� �ƴմϴ�.\n");
		Sleep(400);
		getchar();
		return 0;
	}
}

//������ �޴� ������
void manage_ui() {
	while (1) {


		system("cls");
		int input = 0;

		printf("��------------------------------------��\n");
		printf("    %s �� �������  \n", id_pass[idx].id);
		printf("��------------------------------------��\n");
		printf("��             ������ �޴�            ��\n");
		printf("��------------------------------------��\n");
		printf("��                                    ��\n");
		printf("��      �� ���� ���� ��� ����        ��\n");
		printf("��                                    ��\n");
		printf("��      �� å �߰�                    ��\n");
		printf("��                                    ��\n");
		printf("��      �� å ����                    ��\n");
		printf("��                                    ��\n");
		printf("��      �� ������ �߰�                ��\n");
		printf("��                                    ��\n");
		printf("��      �� ������ ����                ��\n");
		printf("��                                    ��\n");
		printf("��------------------------------------��\n");
		printf("��      �� �ǵ��ư���                 ��\n");
		printf("��------------------------------------��\n");
		printf("�� ��ȣ�� �����ϼ���                  ��\n");
		printf("��------------------------------------��\n");
		printf("���� �Է� : ");

		rewind(stdin);

		scanf("%d", &input);
		
		if (1<=input&&input <=6 ) {
			if (input == 6) {
				printf("�� ���θ޴��� ���ư��ϴ�.\n");
				break;
			}
			else {
				manage_menu(input);
			}
		}
		else {
			system("cls");
			printf("�� �޴��� �ִ� ���ڸ� �Է����ּ���.\n");
			printf("�� 1 ~ 6������ ���ڸ� �Է� �����մϴ�.\n");
			Sleep(1000);
			rewind(stdin);
		}

		
	}	
}
//���õ� ������ �޴��� �̵�
void manage_menu(int a) {

		if (a == FILEADDR) {
			//���� �ּ� ����
			addrChange();
		}
		else if (a == BOK_ADD) {
			//å �߰�
			book_add_input();
		}
		else if (a == BOK_DEL) {
			//å ����
			book_del_input();
		}
		else if (a == MA_ADD) {
			//������ �߰�
			managerAdd();
		}
		else if (a == MA_DEL) {
			//������ ����
			managerDelete_input();
		}
}

//���� ���� �ּ� ����
void addrChange() {
	rewind(stdin);
	system("cls");
	char input = 0;
	char addr[20];

	printf("���������������������\n");
	printf("�� ���� ����Ǵ� ������ �ּҴ�\n");
	printf("�� %s �Դϴ�.\n",fileAddr );
	printf("\n");
	printf("�� �ٲٽðڽ��ϱ�? [Y/N]\n");
	scanf("%c", &input);

	switch (input) {
	case 'Y':
	case 'y':
		printf("�� ����� ��θ� �Է��ϼ���\n");
		scanf("%s", addr);
		strcmp(fileAddr,addr);
		printf("�� ���� %s\n", fileAddr);
		printf("�� ����˴ϴ�.\n");
		break;
	case 'N':
	case 'n':
		printf("�� ��� ������ ����մϴ�.\n");
		
		break;
	default:
		printf("Y,y (����)\n");
		printf("N,n (���)�� �Է°����մϴ�.\n");
		break;
	}
	
}

//�޴� 2 å �߰� ���

//å �߰� - �Է�
void book_add_input() {
	while (1) {

	
	printf("��------------------------------------��\n");
	printf("�� å�� �߰� �մϴ�.\n");
	printf("��------------------------------------��\n");

	int input = 0;

	printf("�� �߰��� å�� �� ���� �Է��ϼ���\n");
	printf("�� �ִ� 20���� �Է��Ҽ� �ֽ��ϴ� ��\n");

	scanf("%d", &input);
	fflush(stdin);
	if (input == 0 || input < 0) {
		fontcolor(12);
		printf("�� ���ڸ� �߸� �Է��ϼ̽��ϴ�.\n");
		Sleep(1000);
		fontcolor(14);
		break;
		//manage_ui();
	}

	BOOK_INFO book[20] = { 0, };

	for (int i = 0; i < input; i++) {

		char arr[80] = "explorer https://product.kyobobook.co.kr/detail/";
		char arr1[20] = " ";

		printf("�� �߰��� å ������ �Է��ϼ��� ��\n");
		rewind(stdin);
		scanf("%[^\n]s", book[i].book_title);
		
		printf("�� %s �� ���ڸ� �Է��ϼ��� ��\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", book[i].book_writer);
		
		printf("�� %s �� ���ǻ縦 �Է��ϼ��� ��\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", book[i].book_pub);

		printf("�� %s �� URL�� �Է��ϼ��� ��\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", arr1);
		strcpy(book[i].book_URL, strcat(arr, arr1));
		
		book[i].book_curent = 0;
		strcpy(book[i].in_date, "0-0-0"); //�ݳ� ����
		strcpy(book[i].out_date, "0-0-0"); //���� ��¥
	}

	for (int i = 0; i < input; i++) {

		printf("-------------------------------------\n");
		printf("�� å ���� %s \n", book[i].book_title);
		printf("�� ���� %s \n", book[i].book_writer);
		printf("�� ���ǻ� %s \n", book[i].book_pub);
		printf("�� ��ǥ URL %s\n", book[i].book_URL);
		printf("�� ���⿩�� %d\n", book[i].book_curent);

		printf("-------------------------------------\n");
		printf("�� ���� �� %s\n", book[i].out_date);
		printf("�� �ݳ� ���� �� %s\n", book[i].in_date);
		printf("-------------------------------------\n");

	}

	//char input1 = ' ';
	char mod = ' ';
	rewind(stdin);
	printf("�� �� ������ �Է��մϴ�.\n");
	printf("�� ���� ���� �ұ��? [Y/N]\n");
	printf("�� Y - ���� ����\n");
	printf("�� N - ���� ���Ͽ� �߰�\n");

	char input1;

	scanf("%c", &input1);

	Sleep(1000);

	if (input1 == 'Y' || input1 == 'y') {
		mod = 'w';
	}
	else if (input1 == 'N' || input1 == 'n') {
		mod = 'a';
	}
	else {
		printf("�� �߸� �Է��ϼ̽��ϴ�.\n");
		break;
	}

	book_file_write(book, mod, input);
	break;
	}
}

//å �߰� - ���Ͽ� �߰�
void book_file_write(BOOK_INFO book[], char a ,int b) {

	rewind(stdin);

	FILE* fw = NULL;

	if (a == 'w') {
		fw = fopen(fileAddr, "wb");
	}
	else if (a == 'a') {
		fw = fopen(fileAddr, "ab");
	}

	if (fw == NULL) {
		printf("�� ����� �����Ҽ� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < b; i++) {
		fwrite(&book[i], sizeof(BOOK_INFO), 1, fw);
	}

	
	fclose(fw);

	printf("�� %s\n", fileAddr);
	printf("�� ��η� ����� �ۼ� ���Դϴ�.\n");

	system("cls");
	//system("pause");
}

//�޴� 3 å ���� ���

//������ å�� �Է� -> ã�� 
void book_del_input() {

	printf("��------------------------------------��\n");
	printf("�� å�� ���� �մϴ�.\n");
	printf("��------------------------------------��\n");

	char input[30] = { 0, };
	rewind(stdin);
	printf("�� ������ å ������ �Է����ּ���\n");
	scanf("%[^\n]s", input);

	book_file_delete(input);

}
//������ å�� ���� -> ���� ���� 
void book_file_delete(char* title) {
	rewind(stdin);

	FILE* fp = fopen(fileAddr, "rb");
	if (fp == NULL) {
		printf("�� ����� �ҷ��� �� �����ϴ�.\n");
		return;
	}

	BOOK_INFO src = { 0, };
	static BOOK_INFO bRead[256] = { 0, };
	int idx = 0;
	int found = 0;

	while (fread(&src, sizeof(BOOK_INFO), 1, fp) == 1) {
		if (strcmp(title, src.book_title) != 0) {
			bRead[idx++] = src;
		}
		else {
			found = 1;
		}
	}
	fclose(fp);

	if (found == 0) {
		fontcolor(12);
		printf("�� ������ å�� �����ϴ�.\n");
		fontcolor(14);
		Sleep(1000);
		return;
	}

	fp = fopen(fileAddr, "wb");
	if (fp == NULL) {
		printf("�� ����� ������ �� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < 256; i++) {
		if (strcmp(bRead[i].book_title, "") != 0) {
			fwrite(&bRead[i], sizeof(BOOK_INFO), 1, fp);
		}
		else break;
	}
	fclose(fp);
	memset(bRead, 0, sizeof(BOOK_INFO) * 256);
	
	printf("�� %s ������ �������Դϴ�...\n", title);
	Sleep(1000);
	
}

//������ �߰�
void managerAdd() {

	MA_IDPASS mAdd = { 0, };

	printf("��------------------------------------��\n");
	printf("�� �����ڸ� �߰� �մϴ�.\n");
	printf("��------------------------------------��\n");

	if (strcmp(id_pass[0].id,curID)==0) {

		while (1) {

			
			printf("�� ���̵� �Է� ��\n");
			scanf("%s", mAdd.id);
			//printf("���̵� : %s", mAdd.id);
			//getchar();

			if (3 > strlen(mAdd.id) || strlen(mAdd.id) > 6) {
				fontcolor(12);
				printf("�� ���̵�� 4�����̰ų�\n");
				printf("         5���ڿ��� �մϴ�.\n");
				fontcolor(14);
			}
			else {
				//getchar();
				printf("�� ��й�ȣ �Է� ��\n");
				scanf("%s", mAdd.pass);

				if (3 > strlen(mAdd.pass) || strlen(mAdd.pass) > 6) {
					fontcolor(12);
					printf("�� ��й�ȣ�� 4�����̰ų�\n");
					printf("           5���ڿ��� �մϴ�.\n");
					fontcolor(14);
				}
				else {
					printf("�� %s ����\n", mAdd.id);
					printf("�����ڷ� �߰� �ϴ� ���Դϴ�. \n");
					Sleep(300);
					break;
				}
			}
		}

		printf("\n");
		printf("��  ������ ���̵� ��� \n");

		managerShow(mAdd);

		managerWrite(mAdd);

	}
	else {
		fontcolor(12);
		printf("�� ������ �߰� ������ �����ϴ�.\n");
		printf("�� ������ �߰���\n");
		printf("   �⺻ �����ڷ� �α��� �ؾ��մϴ�.\n");
		fontcolor(14);
		Sleep(2000);
	}
}

void managerShow(MA_IDPASS mid) {
	fontcolor(10);
	printf("- ID : %s\n", mid.id);
	fontcolor(14);
}

void managerWrite(MA_IDPASS mid) {

	FILE* fp = NULL;
	fp = fopen("d:/IDPASS.bin", "ab");
	if (fp == NULL) {
		printf("�� ����� ������ �� �����ϴ�.\n");
		return;
	}
	fwrite(&mid, sizeof(mid), 1, fp);
	fclose(fp);
}

void managerRead() {

	FILE* fpr = fopen("d:/IDPASS.bin", "rb");
	if (fpr == NULL) {
		printf("�� ����� �ҷ��� �� �����ϴ�.\n");
		return;
	}

	MA_IDPASS mid = { 0, };

	int count = 0;

	printf("��  ������ ���̵� ��� \n");
	while (fread(&mid, sizeof(MA_IDPASS), 1, fpr) == 1) {
		
		managerShow(mid);
		strcpy(id_pass[count].id, mid.id);
		strcpy(id_pass[count].pass, mid.pass);
		count++;

	}

	printf("��------------------------------------��\n");
	Sleep(500);

	fclose(fpr);

	//printf("count : %d\n",count);
	

}

void managerDelete_input() {

	printf("��------------------------------------��\n");
	printf("�� �����ڸ� ���� �մϴ�.\n");
	printf("��------------------------------------��\n");

	char input[20] = { 0, };

	managerRead();

	//printf("curID %s\n", curID);
	//printf("id_pass[0].id %s\n", id_pass[0].id);

	if (strcmp(curID, id_pass[0].id) == 0) {

		printf("�� ������ ������ ���̵� �Է��ϼ���\n");
		scanf("%s", input);

		if (strcmp(id_pass[0].id, input) == 0) {
			fontcolor(12);
			printf("�� �⺻ �����ڴ� ���� �Ҽ� �����ϴ�.");
			fontcolor(14);
			Sleep(1000);
		}
		else {
			managerDelete(input);
		}
	}
	else if (strcmp(curID, id_pass[0].id) == 1) {
		fontcolor(12);
		printf("�� ������ ���� ������ �����ϴ�.\n");
		printf("�� ������ ������\n");
		printf("   �⺻ �����ڷ� �α��� �ؾ��մϴ�.\n");
		fontcolor(14);
		Sleep(2000);
	}
}

void managerDelete(char* input) {

	FILE* fp = fopen("d:/IDPASS.bin", "rb");
	if (fp == NULL) {
		printf("�� ����� ���� �� �����ϴ�.\n");
		return;
	}

	MA_IDPASS src = { 0, };
	static MA_IDPASS dest[256] = { 0, };
	int idx = 0;
	int found = 0;
	while (fread(&src, sizeof(MA_IDPASS), 1, fp) == 1) {
		if (strcmp(input, src.id) != 0) {
			dest[idx++] = src;
		}
		else {
			found = 1;
		}
	}
	fclose(fp);
	if (found == 0) {
		printf("�� ������ ������ ã�� �� �����ϴ�.\n");
		return;
	}

	fp = fopen("d:/IDPASS.bin", "wb");
	if (fp == NULL) {
		printf("�� ����� ������ �� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].id, "") != 0) {
			fwrite(&dest[i], sizeof(MA_IDPASS), 1, fp);
		}
		else break;
	}
	fclose(fp);

	memset(dest, 0, sizeof(MA_IDPASS) * 256);

	printf("�� %s ������ �������Դϴ�...\n", input);

	Sleep(1000);

}


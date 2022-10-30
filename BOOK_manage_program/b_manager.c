              #include "def.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <malloc.h> //?
#include <conio.h>
#include "inf.h"
#include "ui.h"
#include "b_manager.h"

//기존에 아이디 비밀번호
MA_IDPASS id_pass[5] = { 0, };

//현재 아이디
char curID[10] = { 0, };

//파일의 주소
char fileAddr[] = "D:\\book_list.bin ";

//관리자 플래그
int idx = 0;

//관리자 아이디 비밀번호 입력
void manage_gate() {
	system("cls");

	int flag = 0;

	while (1) {

		char inputID[20];
		char inputPASS[20];

		printf("▶ 관리자 메뉴입니다.\n");
		printf("▶ 아이디와 비밀번호가 필요합니다.\n");
		printf("▷ 아이디 입력 : ");
		scanf("%s", inputID);
		printf("▷ 비밀번호 입력 : ");
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

//관리자가 아닌지 아이디 비밀번호 체크
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
			printf("▶ 비밀번호가 틀렸습니다.\n");
			Sleep(400);
			return 0;
		}
	}

	else {
		printf("▶ 관리자가 아닙니다.\n");
		Sleep(400);
		getchar();
		return 0;
	}
}

//관리자 메뉴 보여줌
void manage_ui() {
	while (1) {


		system("cls");
		int input = 0;

		printf("◆------------------------------------◆\n");
		printf("    %s 님 어서오세요  \n", id_pass[idx].id);
		printf("◆------------------------------------◆\n");
		printf("◆             관리자 메뉴            ◆\n");
		printf("◆------------------------------------◆\n");
		printf("◆                                    ◆\n");
		printf("◆      ① 저장 파일 경로 변경        ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      ② 책 추가                    ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      ③ 책 삭제                    ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      ④ 관리자 추가                ◆\n");
		printf("◆                                    ◆\n");
		printf("◆      ⑤ 관리자 삭제                ◆\n");
		printf("◆                                    ◆\n");
		printf("◆------------------------------------◆\n");
		printf("◆      ⑥ 되돌아가기                 ◆\n");
		printf("◆------------------------------------◆\n");
		printf("◆ 번호를 선택하세요                  ◆\n");
		printf("◆------------------------------------◆\n");
		printf("▷▷ 입력 : ");

		rewind(stdin);

		scanf("%d", &input);
		
		if (1<=input&&input <=6 ) {
			if (input == 6) {
				printf("▶ 메인메뉴로 돌아갑니다.\n");
				break;
			}
			else {
				manage_menu(input);
			}
		}
		else {
			system("cls");
			printf("▶ 메뉴에 있는 숫자를 입력해주세요.\n");
			printf("▶ 1 ~ 6까지의 숫자만 입력 가능합니다.\n");
			Sleep(1000);
			rewind(stdin);
		}

		
	}	
}
//선택된 관리자 메뉴로 이동
void manage_menu(int a) {

		if (a == FILEADDR) {
			//파일 주소 변경
			addrChange();
		}
		else if (a == BOK_ADD) {
			//책 추가
			book_add_input();
		}
		else if (a == BOK_DEL) {
			//책 삭제
			book_del_input();
		}
		else if (a == MA_ADD) {
			//관리자 추가
			managerAdd();
		}
		else if (a == MA_DEL) {
			//관리자 삭제
			managerDelete_input();
		}
}

//파일 저장 주소 변경
void addrChange() {
	rewind(stdin);
	system("cls");
	char input = 0;
	char addr[20];

	printf("■■■■■■■■■■■■■■■■■■■■\n");
	printf("▶ 현재 저장되는 파일의 주소는\n");
	printf("▶ %s 입니다.\n",fileAddr );
	printf("\n");
	printf("▶ 바꾸시겠습니까? [Y/N]\n");
	scanf("%c", &input);

	switch (input) {
	case 'Y':
	case 'y':
		printf("▶ 저장될 경로를 입력하세요\n");
		scanf("%s", addr);
		strcmp(fileAddr,addr);
		printf("▶ 이제 %s\n", fileAddr);
		printf("로 저장됩니다.\n");
		break;
	case 'N':
	case 'n':
		printf("▶ 경로 변경을 취소합니다.\n");
		
		break;
	default:
		printf("Y,y (승인)\n");
		printf("N,n (취소)만 입력가능합니다.\n");
		break;
	}
	
}

//메뉴 2 책 추가 ▼▼

//책 추가 - 입력
void book_add_input() {
	while (1) {

	
	printf("◆------------------------------------◆\n");
	printf("▶ 책을 추가 합니다.\n");
	printf("◆------------------------------------◆\n");

	int input = 0;

	printf("▷ 추가할 책의 권 수를 입력하세요\n");
	printf("▷ 최대 20권을 입력할수 있습니다 ▼\n");

	scanf("%d", &input);
	fflush(stdin);
	if (input == 0 || input < 0) {
		fontcolor(12);
		printf("▶ 숫자를 잘못 입력하셨습니다.\n");
		Sleep(1000);
		fontcolor(14);
		break;
		//manage_ui();
	}

	BOOK_INFO book[20] = { 0, };

	for (int i = 0; i < input; i++) {

		char arr[80] = "explorer https://product.kyobobook.co.kr/detail/";
		char arr1[20] = " ";

		printf("▷ 추가할 책 제목을 입력하세요 ▼\n");
		rewind(stdin);
		scanf("%[^\n]s", book[i].book_title);
		
		printf("▷ %s 의 저자를 입력하세요 ▼\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", book[i].book_writer);
		
		printf("▷ %s 의 출판사를 입력하세요 ▼\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", book[i].book_pub);

		printf("▷ %s 의 URL을 입력하세요 ▼\n", book[i].book_title);
		rewind(stdin);
		scanf(" %[^\n]s", arr1);
		strcpy(book[i].book_URL, strcat(arr, arr1));
		
		book[i].book_curent = 0;
		strcpy(book[i].in_date, "0-0-0"); //반납 예정
		strcpy(book[i].out_date, "0-0-0"); //대출 날짜
	}

	for (int i = 0; i < input; i++) {

		printf("-------------------------------------\n");
		printf("▶ 책 제목 %s \n", book[i].book_title);
		printf("▶ 저자 %s \n", book[i].book_writer);
		printf("▶ 출판사 %s \n", book[i].book_pub);
		printf("▶ 대표 URL %s\n", book[i].book_URL);
		printf("▶ 대출여부 %d\n", book[i].book_curent);

		printf("-------------------------------------\n");
		printf("▶ 대출 일 %s\n", book[i].out_date);
		printf("▶ 반납 예정 일 %s\n", book[i].in_date);
		printf("-------------------------------------\n");

	}

	//char input1 = ' ';
	char mod = ' ';
	rewind(stdin);
	printf("▶ 위 정보로 입력합니다.\n");
	printf("▶ 새로 저장 할까요? [Y/N]\n");
	printf("▷ Y - 새로 저장\n");
	printf("▷ N - 기존 파일에 추가\n");

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
		printf("▶ 잘못 입력하셨습니다.\n");
		break;
	}

	book_file_write(book, mod, input);
	break;
	}
}

//책 추가 - 파일에 추가
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
		printf("▶ 목록을 생성할수 없습니다.\n");
		return;
	}
	for (int i = 0; i < b; i++) {
		fwrite(&book[i], sizeof(BOOK_INFO), 1, fw);
	}

	
	fclose(fw);

	printf("▶ %s\n", fileAddr);
	printf("▶ 경로로 목록을 작성 중입니다.\n");

	system("cls");
	//system("pause");
}

//메뉴 3 책 삭제 ▼▼

//삭제될 책을 입력 -> 찾기 
void book_del_input() {

	printf("◆------------------------------------◆\n");
	printf("▶ 책을 삭제 합니다.\n");
	printf("◆------------------------------------◆\n");

	char input[30] = { 0, };
	rewind(stdin);
	printf("▷ 삭제할 책 제목을 입력해주세요\n");
	scanf("%[^\n]s", input);

	book_file_delete(input);

}
//삭제될 책을 삭제 -> 새로 쓰기 
void book_file_delete(char* title) {
	rewind(stdin);

	FILE* fp = fopen(fileAddr, "rb");
	if (fp == NULL) {
		printf("▶ 목록을 불러올 수 없습니다.\n");
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
		printf("▶ 삭제할 책이 없습니다.\n");
		fontcolor(14);
		Sleep(1000);
		return;
	}

	fp = fopen(fileAddr, "wb");
	if (fp == NULL) {
		printf("▶ 목록을 생성할 수 없습니다.\n");
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
	
	printf("▶ %s 정보가 삭제중입니다...\n", title);
	Sleep(1000);
	
}

//관리자 추가
void managerAdd() {

	MA_IDPASS mAdd = { 0, };

	printf("◆------------------------------------◆\n");
	printf("▶ 관리자를 추가 합니다.\n");
	printf("◆------------------------------------◆\n");

	if (strcmp(id_pass[0].id,curID)==0) {

		while (1) {

			
			printf("▷ 아이디 입력 ▼\n");
			scanf("%s", mAdd.id);
			//printf("아이디 : %s", mAdd.id);
			//getchar();

			if (3 > strlen(mAdd.id) || strlen(mAdd.id) > 6) {
				fontcolor(12);
				printf("▶ 아이디는 4글자이거나\n");
				printf("         5글자여야 합니다.\n");
				fontcolor(14);
			}
			else {
				//getchar();
				printf("▷ 비밀번호 입력 ▼\n");
				scanf("%s", mAdd.pass);

				if (3 > strlen(mAdd.pass) || strlen(mAdd.pass) > 6) {
					fontcolor(12);
					printf("▶ 비밀번호는 4글자이거나\n");
					printf("           5글자여야 합니다.\n");
					fontcolor(14);
				}
				else {
					printf("▶ %s 님을\n", mAdd.id);
					printf("관리자로 추가 하는 중입니다. \n");
					Sleep(300);
					break;
				}
			}
		}

		printf("\n");
		printf("▶  관리자 아이디 목록 \n");

		managerShow(mAdd);

		managerWrite(mAdd);

	}
	else {
		fontcolor(12);
		printf("▶ 관리자 추가 권한이 없습니다.\n");
		printf("▶ 관리자 추가는\n");
		printf("   기본 관리자로 로그인 해야합니다.\n");
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
		printf("▶ 목록을 생성할 수 없습니다.\n");
		return;
	}
	fwrite(&mid, sizeof(mid), 1, fp);
	fclose(fp);
}

void managerRead() {

	FILE* fpr = fopen("d:/IDPASS.bin", "rb");
	if (fpr == NULL) {
		printf("▶ 목록을 불러올 수 없습니다.\n");
		return;
	}

	MA_IDPASS mid = { 0, };

	int count = 0;

	printf("▶  관리자 아이디 목록 \n");
	while (fread(&mid, sizeof(MA_IDPASS), 1, fpr) == 1) {
		
		managerShow(mid);
		strcpy(id_pass[count].id, mid.id);
		strcpy(id_pass[count].pass, mid.pass);
		count++;

	}

	printf("◆------------------------------------◆\n");
	Sleep(500);

	fclose(fpr);

	//printf("count : %d\n",count);
	

}

void managerDelete_input() {

	printf("◆------------------------------------◆\n");
	printf("▶ 관리자를 삭제 합니다.\n");
	printf("◆------------------------------------◆\n");

	char input[20] = { 0, };

	managerRead();

	//printf("curID %s\n", curID);
	//printf("id_pass[0].id %s\n", id_pass[0].id);

	if (strcmp(curID, id_pass[0].id) == 0) {

		printf("▷ 삭제할 관리자 아이디를 입력하세요\n");
		scanf("%s", input);

		if (strcmp(id_pass[0].id, input) == 0) {
			fontcolor(12);
			printf("▶ 기본 관리자는 삭제 할수 없습니다.");
			fontcolor(14);
			Sleep(1000);
		}
		else {
			managerDelete(input);
		}
	}
	else if (strcmp(curID, id_pass[0].id) == 1) {
		fontcolor(12);
		printf("▶ 관리자 삭제 권한이 없습니다.\n");
		printf("▶ 관리자 삭제는\n");
		printf("   기본 관리자로 로그인 해야합니다.\n");
		fontcolor(14);
		Sleep(2000);
	}
}

void managerDelete(char* input) {

	FILE* fp = fopen("d:/IDPASS.bin", "rb");
	if (fp == NULL) {
		printf("▶ 목록을 읽을 수 없습니다.\n");
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
		printf("▶ 삭제할 정보를 찾을 수 없습니다.\n");
		return;
	}

	fp = fopen("d:/IDPASS.bin", "wb");
	if (fp == NULL) {
		printf("▶ 목록을 생성할 수 없습니다.\n");
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

	printf("▶ %s 정보가 삭제중입니다...\n", input);

	Sleep(1000);

}


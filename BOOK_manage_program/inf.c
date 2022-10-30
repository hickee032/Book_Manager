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



//메인 메뉴
int bok_menu() {
	system("cls");
	int select = 0;
	printf("◆------------------------------------◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆              도서 관리             ◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ① 책 목록 보기          ◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ② 책 검색 하기          ◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ③ 책 대여 하기          ◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ④ 책 반납 하기          ◆\n");
	printf("◆                                    ◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ⑤ 종료 하기             ◆\n");
	printf("◆                                    ◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ⑥ 도움말                ◆\n");
	printf("◆                                    ◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆                                    ◆\n");
	printf("◆           ⑦ 관리자 메뉴           ◆\n");
	printf("◆                                    ◆\n");
	printf("◆------------------------------------◆\n");
	printf("◆        메뉴를 선택하세요 ▼        ◆\n");
	printf("◆------------------------------------◆\n");
	printf("\n");
	printf("▷▷ 입력 : ");

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
		printf("▶ 잘못 입력하셨습니다.\n");
		printf("▶ 1~7까지의 숫자만 입력 가능합니다.\n");
		Sleep(1000);
	}

}

//도움말
void showHint() {

	system("cls");

	printf("----------------------------------------\n");
	printf("             ※ 도움말 ※               \n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ① 책 목록을 인기순 또는\n");
	printf("\n");
	printf("                  번호순으로 보여줍니다.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ② 책 이름, 출판사 ,저자로           \n");
	printf("\n");
	printf("                             검색합니다.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ③ 책을 대여합니다. 대여후           \n");
	printf("\n");
	printf("      7일이 경과시  연체료가 발생합니다.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ④ 책을 반납합니다. 연체료 발생시    \n");
	printf("\n");
	printf("                    연체료를 결제합니다.\n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ⑤ 프로그램을 종료합니다.    \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ⑥ 도움말을 출력합니다.    \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("▶ ⑦ 관리자 메뉴를 호출합니다.        \n");
	printf("\n");
	printf("----------------------------------------\n");
	printf("----------------------------------------\n");
	Sleep(2000);
	printf("----------------------------------------\n");
	printf("▷ 아무키나 누르세요\n");
	printf("                      메뉴로 이동합니다.\n");
	printf("----------------------------------------\n");
	_getch();

}

//추후 설정메뉴

//void setting() {
//	system("cls");
//
//	int input = 0;
//	while (1) {
//
//		fontcolor(9); printf("1.파란색\n");
//		fontcolor(10); printf("2.초록색\n");
//		fontcolor(11); printf("3.옥색\n");
//		fontcolor(13); printf("4.보라색\n");
//		fontcolor(15); printf("5.흰색\n");
//		fontcolor(14); printf("6.디폴트\n");
//
//		printf("바꾸실 색 번호를 입력하세요▼\n");
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
//			printf("1~6 까지의 숫자만 입력해주세요\n");
//		}
//
//	}
//}
//
//void show_color(int num){
//	fontcolor(num);
//	printf("이 색깔로 교체 합니다.\n");
//}





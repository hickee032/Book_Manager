#include "def.h"
#include <stdio.h>
#include "inf.h"


//메인 메뉴
int bok_menu() {

	int select = 0;

	printf("◆-----------------◆\n");
	printf("◆    도서 관리    ◆\n");
	printf("◆-----------------◆\n");
	printf("◆ ① 책 목록 보기 ◆\n");
	printf("◆ ② 책 검색 하기 ◆\n");
	printf("◆ ③ 책 대여 하기 ◆\n");
	printf("◆ ④ 책 반납 하기 ◆\n");
	printf("◆-----------------◆\n");
	printf("◆  ⑤ 종료 하기   ◆\n");
	printf("◆-----------------◆\n");
	printf("◆-⑥ 관리자 메뉴 -◆\n");
	printf("◆-----------------◆\n");

	printf("◆ 메뉴를 선택하세요 ◆");

	scanf_s("%d", &select);

	return select;

}
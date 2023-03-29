#ifndef __INF_H__
#define __INF_H__

//숫자 정보를 나타내는 상수 변수
typedef enum {

	BOK_SHOW = 1,
	BOK_SEARCH,
	BOK_LEND, //빌림
	BOK_BACK, //반납
	BOK_EXIT,
	M_MANAGER

}BOK_MENU;

extern int bok_menu();

#endif 
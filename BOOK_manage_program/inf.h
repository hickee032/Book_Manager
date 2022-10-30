#ifndef __INF_H__
#define __INF_H__

//숫자 정보를 나타내는 상수 변수
typedef enum {

	BOK_SHOW = 1,
	BOK_SEARCH,
	BOK_LEND, //빌림
	BOK_BACK, //반납
	BOK_EXIT,
	BOK_HINT,
	M_MANAGER

}BOK_MENU;

typedef struct BOOKINFO {

	char book_title[40];
	char book_writer[40];
	char book_pub[40];
	int book_curent;

	//대출
	char out_date[20];
	//반납
	char in_date[20];

	char book_URL[100];

}BOOK_INFO;

extern int bok_menu();
extern void bok_menu_select(int num);
extern void showHint();
//void setting();
//void show_color(int num);

#endif 
#ifndef __MANAGER_H__
#define __MANAGER_H__

//관리자 메뉴
typedef enum {

	FILEADDR = 1,
	BOK_ADD,
	BOK_DEL,
	MA_ADD,
	MA_DEL,
	RE_MENU

}MANAGE_MENU;

//관리자 아이디,패스워드 
typedef struct _MA_IDPASS {
	char id[10];
	char pass[10];
}MA_IDPASS;

extern void manage_gate();
extern int idPassC(char a[], char n[]);

extern void manage_ui();
extern void manage_menu(int a);

extern void addrChange();

//메뉴 2 책 추가 ▼▼
extern void book_add_input();
extern void book_file_write(BOOK_INFO book[], char a, int b);

//메뉴 3 책 삭제 ▼▼
extern void book_del_input();
extern void book_file_delete(char* title);

// 삭제 ▼▼
extern void managerAdd();
extern void managerShow(MA_IDPASS mid);
extern void managerWrite(MA_IDPASS mid);
extern void managerRead();
extern void managerDelete_input();
extern void managerDelete(char* input);

#endif // !__MANAGER_H__


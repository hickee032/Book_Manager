#ifndef __INF_H__
#define __INF_H__

//���� ������ ��Ÿ���� ��� ����
typedef enum {

	BOK_SHOW = 1,
	BOK_SEARCH,
	BOK_LEND, //����
	BOK_BACK, //�ݳ�
	BOK_EXIT,
	M_MANAGER

}BOK_MENU;

extern int bok_menu();

#endif 
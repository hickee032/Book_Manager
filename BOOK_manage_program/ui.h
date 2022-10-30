#ifndef __UI_H__
#define __UI_H__


//Ŀ��
typedef enum {

	NOCURSOR,
	SOLID_CURSOR,
	NORMAL_CURSOR

}CURSOR_TYPE;

//��Ʈ ����
typedef enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_YELLOW,
	LIGHT_GRAY
}FONT_COLOR;


extern void fontcolor(FONT_COLOR color);

extern void set_cursot_type(CURSOR_TYPE type);
extern void title();
void exit_Bok();

#endif 


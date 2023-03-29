#ifndef __UI_H__
#define __UI_H__


//Ä¿¼­
typedef enum {

	NOCURSOR,
	SOLID_CURSOR,
	NORMAL_CURSOR

}CURSOR_TYPE;

extern void set_cursot_type(CURSOR_TYPE type);
extern void title();

#endif 


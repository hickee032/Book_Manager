#ifndef __TIME_H__
#define __TIME_H__

extern void get_time(char* tinfo);
extern char* get_time_due(char* tdate, int afterday);
long get_time_diff(char* intime);
long cul_days(int year, int month, int day);
char* dateTo_ymd(long d);

#endif

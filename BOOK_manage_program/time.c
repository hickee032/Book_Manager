#include "def.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "inf.h"
#include "file_search.h"
#include "file_read.h"
#include "file_rent.h"
#include "time.h"

void get_time(char* tinfo) {
	time_t timer;
	struct tm* t;
	// timer: 1970년 1월1일 0시 0초부터 ~ 현재까지 초
	timer = time(NULL);
	t = localtime(&timer);
	char buf[40] = { 0, };
	sprintf(buf, "%d-%d-%d",
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday
	);
	strcpy(tinfo, buf);
}

char* get_time_due(char* tdate, int afterday) {

//tdate 현재 시간 , afterday == 7;
	int dy = 0, dm = 0, dd = 0;
	int date_buf[3] = { 0, };
	//char arr_date[40] = { 0, };
	char* cur_time = strtok(tdate, "-");

	int count = 0;

	while (cur_time != NULL) {

		date_buf[count] = atoi(cur_time);
		cur_time = strtok(NULL, "-");
		count++;
	}

	dy = date_buf[0]; dm = date_buf[1]; dd = date_buf[2];
	long totalday= cul_days(dy, dm, dd)+ afterday -1;
	//printf("cur date : %ld\n", cul_days(dy, dm, dd));
	//printf("totalday : %ld\n", totalday);

	char buf[40] = { 0, };
	 
	strcpy(&buf, dateTo_ymd(totalday));

	//printf("buf : %s\n", buf);

	return buf;
}

//현재날짜와 불러온 날짜를 파싱 계산
long get_time_diff(char* intime) {

	int cy=0, cm = 0, cd = 0;
	int in_y = 0, in_m = 0, in_d = 0;
	int cubuf[3] = {0,};
	int inbuf[3] = {0,};

	//현재 날짜 -> 초
	char retdate[40] = { 0, };
	get_time(retdate); //%d-%d-%d

	char* cur_time = strtok(retdate, "-");
	int count = 0;

	while (cur_time != NULL) {
	
		cubuf[count] = atoi(cur_time);
		cur_time = strtok(NULL, "-");
		count++;
	}

	char* in_time = strtok(intime, "-");
	int incount = 0;

	while (in_time != NULL) {

		inbuf[incount] = atoi(in_time);
		in_time = strtok(NULL, "-");
		incount++;
	}

	cy = cubuf[0];cm = cubuf[1];cd = cubuf[2];
	in_y = inbuf[0], in_m = inbuf[1], in_d = inbuf[2];

	long curTimeSec = cul_days(cy, cm, cd);
	long inTimeSec = cul_days(in_y, in_m, in_d);
	return (curTimeSec - inTimeSec);
}

long cul_days(int year, int month, int day) {

	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long total = 0L;
	total = (year - 1) * 365L + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	if (!(year % 4) && year % 100 || !(year % 400))
		months[1]++;
	for (int i = 0; i < month - 1; i++)
		total += months[i];
	total += day;
	return total;
}

char* dateTo_ymd(long d) {

	char result[40] = {0,};

	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int temp_year = d / 365;
	int noOfyoonYear = d / (365 * 4) - d / (365 * 100) + d / (365 * 400);
	int remainDays = d % 365 - noOfyoonYear;
	int year, month, day;
	int i;

	if (remainDays < 0) {
		year = temp_year + remainDays / 365;
		remainDays = 365 + remainDays % 365;
	}
	else { // 0<= remainDays < 365
		year = temp_year + 1;
	}

	if (!(year % 4) && year % 100 || !(year % 400))
		months[1]++;

	for (i = 0; i < 12; i++)
		if (remainDays >= 0)
			remainDays -= months[i];
		else {
			break;
		}

	month = i;
	day = months[i - 1] + remainDays + 1;

	//printf("dateTo_ymd : %d-%d-%d\n", year, month, day);
	
	sprintf(result, "%d-%d-%d\n", year, month, day);
	//printf("result : %s\n", result);

	return result;
}




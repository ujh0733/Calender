#include<stdio.h>
int calLeapYear();
void Calender();

/*int main(void) {
int year;

while (1) {
printf("년도를 입력하면 해당 년도의 달력을 출력합니다.\n");
printf("년도 입력  ");
scanf("%d", &year);

Calender(year);
}
return 0;
}*/

int calLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}

void Calender(int year) {
	int i, j, k;
	int dayCnt, leapYearCnt = 0;
	int lastMonth, thisMonth = 31;
	int month[12][6][7];

	for (i = 1; i < year; i++) {	//윤년인 해가 몇번인지 count
		leapYearCnt += calLeapYear(i);
	}
	lastMonth = (year * 365 + leapYearCnt) % 7;		//1월1일 요일 구하기
	for (k = 0; k < 12; k++) {
		dayCnt = 0;

		if ((k == 0) | (k == 2) | (k == 4) | (k == 6) | (k == 7) | (k == 9) | (k == 11)) {
			thisMonth = 31;
		}
		else if ((k == 3) | (k == 5) | (k == 8) | (k == 10)) {
			thisMonth = 30;
		}
		else if ((k == 1)) {
			if (calLeapYear(year)) {
				thisMonth = 29;
			}
			else {
				thisMonth = 28;
			}
		}

		for (i = 0; i < 6; i++) {
			for (j = 0; j < 7; j++) {
				dayCnt++;
				month[k][i][j] = dayCnt - lastMonth;

				if (month[k][i][j] < 1 || month[k][i][j] > thisMonth)
					month[k][i][j] = 0;
			}
		}
		if ((k == 0) | (k == 2) | (k == 4) | (k == 6) | (k == 7) | (k == 9) | (k == 11)) {
			lastMonth = (lastMonth + 31) % 7;
		}
		else if ((k == 3) | (k == 5) | (k == 8) | (k == 10)) {
			lastMonth = (lastMonth + 30) % 7;
		}
		else if (k == 1) {
			if (calLeapYear(year)) {
				lastMonth = (lastMonth + 29) % 7;
			}
			else {
				lastMonth = (lastMonth + 28) % 7;
			}
		}
	}
	for (k = 0; k < 12; k++) {
		printf("********%d 월********\n", k + 1);
		printf("일 월 화 수 목 금 토\n");
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 7; j++) {
				if (0 == month[k][i][j]) {
					printf("   ");
					continue;
				}
				printf("%2d ", month[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
}
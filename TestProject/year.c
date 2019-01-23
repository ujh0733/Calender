#include<stdio.h>
void LeapYear();	//����� ���� �Լ�
void DayOfWeek();
void computeDay();
void Calender();

int main(void) {
	int year;
	while (1) {
		int sel;
		printf("������ �˰� ��������??\n");
		printf("1. ���� 2. ������¥�� ���� 3. �޷� \n");
		scanf("%d", &sel);

		printf("�˰���� ������ �Է��� �ּ���: ");
		scanf("%d", &year);
		printf("\n");

		switch (sel) {
		case 1:
			LeapYear(year);
			break;
		case 2:
			DayOfWeek(year);
			break;
		case 3:
			Calender(year);
			break;
		}
	}
}
void LeapYear(int year) {
	
	printf("%d���� ������ �˾ƺ��ϴ�\n", year);

	int i, j, day, cnt = 0;
	int cal[6][7];

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d���� �����Դϴ�\n", year);
	else
		printf("%d���� ������ �ƴմϴ�\n", year);

	for (i = 1; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			cnt++;
		}
	}
	

	day = ((year * 365)+cnt) % 7;
	printf("%d���� 1�� 1���� ", year);

	computeDay(day);

	printf("�� �� ȭ �� �� �� ��\n");
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			cal[i][j] = (i*7 + j + 1) - day;
		}
	}

	for (i = 0; i < 6; i++){
		for (j = 0; j < 7; j++) {
			if (cal[i][j] < 1 || cal[i][j] > 31) {
				printf("   ");
				continue;
			}
			printf("%2d ", cal[i][j]);
		}
		printf("\n");
	}
	
}

void DayOfWeek(int year) {
	int month, day;
	int a,b,c,d,w;

	while (1) {
		printf("%d���� ��� ������ ������ �˰� ��������??\n(X�� X��)", year);
		scanf("%d", &month);
		scanf("%d", &day);
		if (month > 12 || ( ((month == 1 || month==3 || month==5|| month==8||month==10||month==12)) && day > 31 ) ||
				((month == 2)&&day > 28) || ((month == 4 || month == 6 || month == 7 || month == 9 || month == 11) && day > 30)) {
			printf("�ٽ� �Է��� �ּ���\n");
		}
		else {
			break;
		}
	}

	printf("%d�� %d��\n", month, day);

	
	
	if (month < 3) {
		a = (year - 1) / 100;
		b = (year - 1) % 100;
		c = month + 12;
	}
	else {
		a = year / 100;
		b = year % 100;
		c = month;
	}
	d = day;
	
	printf("%d%d�� %d�� %d�� �� ������\n", a, b, c, d);

	w = (21 * a / 4) + (5 * b / 4) + (26 * (c + 1) / 10) + (d - 1);
	int dayofweef = w % 7;

	computeDay(dayofweef);
}

void computeDay(int num) {
	switch (num) {
	case 0:
		printf("�Ͽ��� �Դϴ�.\n");
		break;
	case 1:
		printf("������ �Դϴ�.\n");
		break;
	case 2:
		printf("ȭ���� �Դϴ�.\n");
		break;
	case 3:
		printf("������ �Դϴ�.\n");
		break;
	case 4:
		printf("����� �Դϴ�.\n");
		break;
	case 5:
		printf("�ݿ��� �Դϴ�.\n");
		break;
	case 6:
		printf("����� �Դϴ�.\n");
		break;
	}
}
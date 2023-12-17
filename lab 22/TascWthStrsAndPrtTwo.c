#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int isDigitMy(char c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}


int strLenMy(char s[]) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	return len;
}


int strCmpMy(char a[], char b[]) {
	int i = 0;
	while (a[i] != 0 && b[i] != 0 && a[i] == b[i]) {
		i++;
	}
	return(a[i] - b[i]);
}

void strCpyMy(char s2[], char s1[]) {
	int i = 0;
	while (s1[i]!='\0') {
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
}


void strCatMy(char s2[], char s1[]) {
	int i;
	int m = strLenMy(s1);
	for (i = 0; s1[i] != '\0'; i++) {
		s2[m + i] = s1[i];
	}
	s2[m + i] = '\0';
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	


	//Задача 9.1
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strLenMy(s); i++) {
		if (s[i] == ' ') cnt++;
	}

	printf("\nВ ней %d пробелов\n", cnt);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 9.2
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; i < strLenMy(s); i++) {
		if (s[i] == ' ') s[i] = '#';
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/

	
	//Задача 10
	/*char a[80];
	char b[80];
	printf("Введите первый массив = ");
	fgets(a, 79, stdin);
	printf("Введите второй массив = ");
	fgets(b, 79, stdin);
	printf("Первый массив: \"%s\"\n", a);
	printf("Второй массив: \"%s\"\n", b);
	int c = strCmpMy(a, b);
	if (c == 0) {
		printf("Массивы равны\n");
	}
	else {
		printf("Массивы не равны\n");
	}*/


	//Задача 11
	/*char a[80];
	char b[80];
	printf("Введите первый массив = ");
	fgets(a, 79, stdin);
	printf("Первый массив: \"%s\"\n", a);
	strCpyMy(b, a);
	printf("Второй массив: \"%s\"\n", b);*/


	//Задача 12
	/*char a[80];
	char b[80];
	printf("Введите первый массив = ");
	fgets(a, 79, stdin);
	printf("Введите второй массив = ");
	fgets(b, 79, stdin);
	printf("Первый массив: \"%s\"\n", a);
	printf("Второй массив: \"%s\"\n", b);
	strCatMy(b, a);
	printf("Преобразованный второй массив: \"%s\"\n", b);*/

	//Задание из части 2, вариант 5
	/*char s[80];
	printf("Введите массив = ");
	fgets(s, 79, stdin);
	printf("Введённый массив: \"%s\"\n", s);
	int i = 0;
	while (s[i] != '\0') {
		if (isdigit(s[i])) {
			s[i] = 'X';
		}
		i++;
	}
	printf("Преобразованный массив: \"%s\"\n", s);*/
}



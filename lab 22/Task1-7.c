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


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задача 1
	/*char name[12];
	printf("Введите ваше имя: ");
	fgets(name, 11, stdin);
	printf("Приветствую тебя, %s\n", name);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 2
	/*printf("Введите символ = ");
	int ch = getchar();

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 3
	/*printf("Введите символ = ");
	int ch = getchar();

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 4
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') cnt++;
	}

	printf("\nВ ней %d пробелов\n", cnt);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 5
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') s[i] = '#';
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 6.1
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i])) s[i] = '$';
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/

	//Задача 6.2
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isDigitMy(s[i])) s[i] = '$';
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 7.1
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toupper(s[i]);
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/


	//Задача 7.2
	/*char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toUpperAll(s[i]);
	}

	printf("\nСтрока после обработки = \"%s\"\n", s);

	{
		int x;
		scanf("%d", &x);
	}*/
}



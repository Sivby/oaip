#include<stdio.h>
#include<Windows.h>

void print1_10() {
	int a = 1;
	do {
		printf("%d ", a);
		a += 1;
	} while (a <= 10);
}

void print10_1() {
	int a = 10;
	do {
		printf("%d ", a);
		a -= 1;
	} while (a >= 1);
}

void print5Odds() {
	int a = 1;
	int i = 1;
	do {
		printf("%d ", a);
		a += 2;
		i += 1;
	} while (i <= 5);
}

void print100_10_while() {
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

void print1000_100_while() {
	int a = 1000;
	printf("%d ", a);
	while (a != 100) {
		a -= 100;
		printf("%d ", a);
	}
}

void print1000_0_24_while() {
	int a = 1000;
	printf("%d ", a);
	while (a > 16) {
		a -= 24;
		printf("%d ", a);
	}
}

void print_facts(int num) {
	int a = 1;
	int i = 1;
	printf("Введите N: ");
	scanf_s("%d", &num);
	while (i <= num) {
		a *= i;
		printf("%d ", a);
		i += 1;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	int num;
	do {
		printf("\n");
		printf("\n");
		printf("Выберете нужную вам операцию:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("2: Вывести числа от 10 до 1\n");
		printf("3: Вывести 5 первых нечетных чисел начиная с 1\n");
		printf("11: Вывести числа 100 90 80 ... 10 (через WHILE)\n");
		printf("12: Вывести числа 1000 900 800 ... 100 (через WHILE)\n");
		printf("20: Вывести числа от 1000 до 16 с шагом 24 (через WHILE)\n");
		printf("21: Вывести первые N факториалов\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			print10_1();
			break;
		case 2:
			print1_10();
			break;
		case 3:
			print5Odds();
			break;
		case 11:
			print100_10_while();
			break;
		case 12:
			print1000_100_while();
			break;
		case 20:
			print1000_0_24_while();
			break;
		case 21:
			

			print_facts(num);
			break;
		}
	} while (n != 0);
}
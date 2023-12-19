#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void rec1(int n) {
	printf(" %d", n);
	if (n > 2) {
		rec1(n - 2);
	}
}

void rec2(int n) {
	if (n > 2) {
		rec2(n - 2);
	}
	printf(" %d", n);
}

void rec3(int n) {
	printf(" %d", n);
	if (n > 2) {
		rec3(n - 2);
	}
	printf(" %d", n);
}

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void F2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		F2(n + 1);
		F2(n + 3);
	}
}

void G3(int n);

void F3(int n) {
	if (n > 0)
		G3(n - 1);
}

void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}


long fuct(int n) {
	long res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задание 1
	/*int n = 5;
	long f = fuct(n);
	printf("%d! = %ld", n, f);*/

	//Задача 2
	/*rec1(11);
	printf(" rec1 FINISH\n");
	rec2(11);
	printf(" rec2 FINISH\n");
	rec3(11);
	printf(" rec3 FINISH\n");*/
	

	//Задача 3
	/*rec1(7);
	printf(" rec1 FINISH\n");
	rec2(7);
	printf(" rec2 FINISH\n");
	rec3(7);
	printf(" rec3 FINISH\n");*/


	//Задача 4
	//recEGE1(3);

	//Задача 5
	//F1(10);

	//Задача 6
	//F2(1);

	//Задача 7
	//F3(11);
}

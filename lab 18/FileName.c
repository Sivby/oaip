#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Суслин Всеволод\n");
	/*printf("Задача 1\n");

	int a, b, c;
	int p;

	scanf_s("%d%d%d", &a, &b, &c);
	printf("ввели: %d, %d, %d\n", a, b, c);
	p = a * b * c;
	printf("p = %d\n", p);*/


	/*printf("Задача 2\n");

	int a, b, c;
	int p;

	FILE *fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf_s(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);

	printf("ввели: %d, %d, %d\n", a, b, c);

	p = a * b * c;

	printf("p = %d\n", p);

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	fprintf(fout, "%d", p);
	fclose(fout);*/


	/*printf("Задача 3\n");

	int a, b, c, d, e;
	int p;

	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("ввели: %d, %d, %d, %d, %d\n", a, b, c, d, e);
	p = a + b + c + d + e;
	printf("p = %d\n", p);*/


	/*printf("Задача 4\n");

	int a, b, c;
	int p;

	FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf_s(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);

	printf("ввели: %d, %d, %d\n", a, b, c);

	p = a * b * c;

	printf("p = %d\n", p);

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	fprintf(fout, "%d", p);
	fclose(fout);*/


	printf("Задача 5\n");

	int a[10];
	int n;
	int i;

	FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\in5.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf_s(fin, "%d", &n);

	for (i = 0; i < n; i++) {
		fscanf_s(fin, "%d", &a[i]);
	}
	fclose(fin);

	printf("ввели массив a[%d] = ", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	int s = 0;
	for (i = 0; i < n; i++) {
		s += a[i];
	}

	float sa = (float)s / n;
	printf("\nsa = %f\n", sa);
	for (i = 0; i < n; i++) {
		if (a[i] > sa) {
			a[i] *= 10;
		}
	}
	printf("ввели массив a[%d] = ", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 18\\out5.txt", "wt");
	if (fout == 0) {
		printf("Выходной файл не найден");
	}

	fprintf(fout, "%d\n", n);

	for (i = 0; i < n; i++) {
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);
}
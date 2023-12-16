#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int* pa;
int n;

void Load() {
	FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 19\\in3.txt", "rt");
	if (fopen == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf_s(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf_s(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void SaveResult() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) & (pa[i]>0)) {
			m++;
		}
	}

	FILE* fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 19\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if ((pa[i] < sa) & (pa[i] > 0)) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task3!\n");

	Load();
	SaveResult();

	free(pa);
}
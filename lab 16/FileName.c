#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}

void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}

int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

void more10() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			count++;
		}
	}
	printf("%d\n", count);
}

int findLastEven() {
	int eve = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			eve = i;
		}
	}
	return eve;
}

int findIndexMin() {
	int min = arr[0];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			cnt = i;
		}
	}
	return cnt;
}

int findIndexMax() {
	int max = arr[0];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			cnt = i;
		}
	}
	return cnt;
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("---------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечётных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: x2 для последнего чётного\n");
		printf("6: Сколько чётных левее минимального\n");
		printf("7: x10 для нечётных правее минимального\n");
		printf("8: Переставить местами min и max\n");
		printf("9: Все чётные элементы массива умножить на -1\n");
		printf("10: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("11: Все элементы стоящие между максимальным и минимальным увеличить в 10 раз\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;

		case 4:
			more10();
			break;

		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}

		}
		break;

		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d чётных элементов\n", cnt);
		}
		break;

		case 7:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);
			for (int i = index + 1; i < n; i++) {
				if (arr[i] % 2 != 0) {
					arr[i] *= 10;
				}
			}
		}
		break;

		case 8:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);
			int indexMax = findIndexMax();
			printf("Индекс максимального элемента = %d\n", indexMax);

			int tmp = arr[indexMin];
			arr[indexMin] = arr[indexMax];
			arr[indexMax] = tmp;
		}
		break;

		case 9:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 == 0) {
					arr[i] *= -1;
				}
			}
		}
		break;

		case 10:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] < 4) {
					arr[i] = 4;
				}
			}
		}
		break;

		case 11:
		{
			int mi = findIndexMin();
			int ma = findIndexMax();
			int max = max(mi, ma);
			int min = min(mi, ma);
			for (int i = min + 1; i < max; i++) {
				arr[i] *= 10;
			}
		}
		break;


		}


	} while (item != 0);
}

#include <stdio.h>
#include <Windows.h>
int arr[3][4] = { {10, 11, 12, 13}, {20, 21, 9, 23}, {30, 31, 32, 33} };
int n = 3;
int m = 4;


void print() {
	int i, j;
	printf("!!!! print() !!!!\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	
	do {
		print();
		printf("====================================\n");
		printf("\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: заполнить значениями i * 10 + j\n");
		printf("2: заполнить нулями\n");
		printf("3: заполнить случайными значениями\n");
		printf("4: все нечётные увеличить в 10 раз\n");
		printf("5: все кратные 10 уменьшить в 10 раз\n");
		printf("\n");
		printf("-1: Выйти из программы\n");
		printf("Выбранная операция >>>>>> \n");
		scanf_s("%d", &item);

		switch (item) {
		case 1:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = i * 10 + j;
				}
			}
			break;


		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = 0;
				}
			}
			break;

		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = rand() % 10;
				}
			}
			break;

		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] % 2 != 0) {
						arr[i][j] *= 10;
					}

				}
			}
			break;

		case 5:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] % 10 == 0) {
						arr[i][j] /= 10;
					}
				}
			}
			break;

		}
	} while (item != -1);
}
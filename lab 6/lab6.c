//Задача 1.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int i, n;
//	printf("n = ");
//	scanf_s("%d", &n);
//	i = 1;
//	do {
//		printf("%d\n", i);
//		i += 1;
//	} while (i <= n);
//}


//Задача 2.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int i, s;
//	i = 0;
//	s = 1;
//	do {
//		printf("2^%d = %d\n", i, s);
//		i += 1;
//		s *= 2;
//	} while (i <= 5);
//}

//Задача 3.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int s, p, y;
//	y = 0;
//	printf("summa = ");
//	scanf_s("%d", &s);
//	printf("procent = ");
//	scanf_s("%d", &p);
//	do {
//		printf("%d in %d year\n", s, y);
//		y += 1;
//		s = (s * (100 + p)) / 100;
//	} while (y <= 10);
//}

//Задача 4.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int n, i, c;
//	c = 1;
//	scanf_s("%d", &n);
//	i = 2;
//	do {
//		printf("%d ", i);
//		c += 1;
//		i += 2;
//	} while (c <= n);
//}

//Задача 5.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int n, i, c, a;
//	c = 1;
//	scanf_s("%d", &n);
//	scanf_s("%d", &a);
//	i = a;
//	do {
//		printf("%d ", i);
//		c += 1;
//		i += a;
//	} while (c <= n);
//}

//Задача 6. Вывод  всех степеней числа x от 0 до n.
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//void main() {
//	int n, i, s, x;
//	scanf_s("%d", &x);
//	scanf_s("%d", &n);
//	i = 0;
//	s = 1;
//	do {
//		printf("%d^%d = %d\n", x, i, s);
//		i += 1;
//		s *= x;
//	} while (i <= n);
//}
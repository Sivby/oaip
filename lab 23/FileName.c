#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
//Для задач 1, 2, 3, 6
#define MAX_LEN 80
char s[MAX_LEN];

//Для задачи 4
//#define MAX_LEN 40

int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 225)
		return 1;
	return 0;
}



int getNextDelim(FILE* fp, char token[]) {
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}
int getNextWord(FILE* fp, char token[], int maxLen) {
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
	if (i == 0)
		return 0;
	return 1;
}
char filename[] = "D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt";

char filenameIn[] = "D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt";
char filenameHTML[] = "D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1_out.html";


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Суслин Всеволод\n");


	/*printf("ЛР23 задача 1\n");

	FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной сигнал не создался");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t')
					s[i] = '%';
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");*/


	//Задача 2
	/*FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной сигнал не создался");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha_my(s[i]))
					s[i] = toupper(s[i]);
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 2 FINISH\n");*/


	//Задача 3
	/*FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной сигнал не создался");
		return;
	}

	int cnt;
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			cnt = 0;
			int i = 0;
			while (s[i] != '\0') {
				if (isalpha_my(s[i]))
					cnt++;
				i++;
			}
			if (cnt > 0 && s[i - 1] == '\n') {
				s[i - 1] = '#';
				s[i] = '\n';
				s[i + 1] = '\0';
			}
			else if (cnt > 0 && s[i - 1] != '\n') {
				s[i] = '#';
				s[i + 1] = '\0';
			}

			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");*/



	/*printf("Задача 4\n");
	printf("BEGIN!!!\n");

	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		printf("File %s doesn't opened!\n", filename);
		return;
	}

	char token[MAX_LEN];
	int res;
	while (!feof(fin)) {
		while (getNextDelim(fin, token)) {
			printf("<DELIM>%s</DELIM>\n", token);
		}
		if (getNextWord(fin, token, MAX_LEN)) {
			printf("<WORD>%s</WORD>\n", token);
		}
	}
	fclose(fin);
	printf("END!!!\n");*/


	
	//Задача 5
	/*printf("BEGIN!!!\n");

	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}

	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		fclose(fin);
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}

	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	int ch;
	while ((ch = getc(fin)) != EOF) {
		fprintf(fout, "%c", ch);
		if (ch == '\n')
			fprintf(fout, "<br>");
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	fclose(fin);
	fclose(fout);
	printf("END!!!\n");*/



	//Задача 6
	/*FILE* fin = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout;
	fout = fopen("D:\\VSEVOLOD\\Уроки\\oaip labs\\lab 23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной сигнал не создался");
		return;
	}

	int cnt;
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			cnt = 0;
			int i = 0;
			while (s[i] != '\0') {
				if (s[i] == ';')
					cnt++;
				i++;
			}
			char s2[MAX_LEN];
			strcpy(s2, s);
			s2[strlen(s)-1] = '\0';


			fprintf(fout, "%s%d\n\0", s2, cnt);
			printf(">>%s<<\n", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");*/

}

#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <time.h>

int N = 10;
int m1[10][10];
int m2[10][10];
int c[10][10];

void main() {
	srand(time(NULL)); // заполнение
	for (int i = 0; i < N; i++) {
		for (int j = (1 + i); j < N; j++) {
			m1[i][j] = rand() % 2;
			m1[j][i] = m1[i][j];
		}
	}

	for (int i = 0; i < N; i++) { // вывод массива
		for (int j = 0; j < N; j++) {
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
										// заполнение

	for (int i = 0; i < N; i++) {
		for (int j = (1 + i); j < N; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}

	for (int i = 0; i < N; i++) { // вывод массива
		for (int j = 0; j < N; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("Resltat ob'edinenia");
	printf("\n");
	printf("\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m1[i][j]||m2[i][j]) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) { // вывод массива
		for (int j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
//////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");
	printf("Resltat peresechenie");
	printf("\n");
	printf("\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m1[i][j] && m2[i][j]) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) { // вывод массива
		for (int j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
//////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");
	printf("Resltat kolcevaai summa");
	printf("\n");
	printf("\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((m1[i][j] && (!m2[i][j])) || ((!m1[i][j]) && m2[i][j])) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) { // вывод массива
		for (int j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	_getch();
}
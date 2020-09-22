#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include "lib.h"

void zadanie1() {
	int N1 = 5;
	int N2 = 10;
	int m1[5][5];
	int m2[11][11];

	srand(time(NULL)); // заполнение
	for (int i = 0; i < N1; i++) {
		for (int j = (1 + i); j < N1; j++) {
			m1[i][j] = rand() % 2;
			m1[j][i] = m1[i][j];
		}
	}

	for (int i = 0; i < N1; i++) { // вывод массива
		for (int j = 0; j < N1; j++) {
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	/*
	printf("\n");
	printf("\n");

	for (int i = 0; i < N1; i++) { // вывод списка
	printf("%d: ", i + 1);
	for (int j = 0; j < N1; j++) {
	if (m1[i][j]) {
	printf("V%d  ", j + 1);
	}
	}
	printf("\n");
	}*/

	printf("\n");
	///////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");

	srand(time(NULL)); // заполнение
	for (int i = 0; i < N2; i++) {
		for (int j = (1 + i); j < N2; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}

	for (int i = 0; i < N2; i++) { // вывод массива
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	/*
	printf("\n");
	printf("\n");

	for (int i = 0; i < N2; i++) { // вывод списка
	printf("%d: ", i + 1);
	for (int j = 0; j < N2; j++) {
	if (m2[i][j]) {
	printf("V%d  ", j + 1);
	}
	}
	printf("\n");
	}*/
	///////////////////////////////////////////////////////////////////////////////////////////
	/*printf("\n");
	printf("\n");

	int kol1, kol2;
	printf("Vvedite nomera vershin dla otojdectvlenia: ");
	scanf("%d%d", &kol1,&kol2);
	kol1--;
	kol2--;

	for (int i = 0; i < N2; i++) { // отождествление
	if (m2[kol2][i]) {
	m2[kol1][i] = 1;
	m2[i][kol1] = 1;
	}
	m2[kol2][i] = 0;
	m2[i][kol2] = 0;
	}
	for (int i = 0; i < N2; i++) { // обнуление главной диагонали
	m2[i][i] = 0;
	}
	////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");

	printf("Vvedite nomera vershin dla stagivania rebra: ");
	scanf("%d%d", &kol1, &kol2);

	if (m2[kol1][kol2]) {
	kol1--;
	kol2--;

	for (int i = 0; i < N2; i++) { // отождествление
	if (m2[kol2][i]) {
	m2[kol1][i] = 1;
	m2[i][kol1] = 1;
	}
	m2[kol2][i] = 0;
	m2[i][kol2] = 0;
	}
	for (int i = 0; i < N2; i++) { // обнуление главной диагонали
	m2[i][i] = 0;
	}
	}
	else {
	printf("Vershini ne smejnie");
	}*/
	///////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");

	int kol1, kol2;
	printf("Vvedite nomer vershini dla rassheplenia: ");
	scanf("%d", &kol1);

	kol1--;
	int sum = 0;

	for (int i = 0; i < N2; i++) { // счётчик смежных вершин
		if (m2[kol1][i]) {
			sum++;
			kol2 = i;		// просто узнать 1 смежную вершину
		}
	}

	if (!sum) {
		m2[kol1][10] = 1;
		m2[10][kol1] = 1;
		m2[10][10] = 0;
	}
	else {
		if (sum == 1) {
			for (int i = 0; i < N2; i++) { // копирование значений 1 вершины в другую
				m2[10][i] = m2[kol1][i];
				m2[i][10] = m2[i][kol1];
			}
			m2[10][kol1] = 1;		// коррекция
			m2[kol1][10] = 1;
			m2[10][10] = 0;
		}
		else {                 // создание новой вершины
			m2[10][kol2] = 1;  // в 10 строчку под номером kol2
			m2[10][kol1] = 1;  // создание связи с расщепляемой вершиной
			m2[kol2][10] = 1;  // в строчку kol2 под номером 10	
			m2[kol1][10] = 1;  // создание связи с расщепляемой вершиной
			m2[kol1][kol2] = 0;// вычёркивание связи с одной из вершин 
			m2[kol2][kol1] = 0;
			m2[10][10] = 0;
		}
	}
	N2++;
	///////////////////////////////////////////////////////////////

	for (int i = 0; i < N2; i++) { // вывод массива
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < N2; i++) { // вывод списка
		printf("%d: ", i + 1);
		for (int j = 0; j < N2; j++) {
			if (m2[i][j]) {
				printf("V%d  ", j + 1);
			}
		}
		printf("\n");
	}



	_getch();
}

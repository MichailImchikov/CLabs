﻿#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
	unsigned char num=0;
	unsigned char num2=0; // эта переменная для действий 
	unsigned char maskR=1;// маска права
	unsigned char maskL = 128;// маска лево
	char answer= 'o';
	int num1=300;// нужен для записи 
	int shift=0;// сдвиг
	int remains[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };// остаток при делении
	while (num1 > 255 || num1 < 0) 
	{
		printf("Enter a number from 0 to 255 ");
		scanf_s("%i", &num1);
	}
	num = (unsigned char)num1;
	while (answer != 'n') {
		num2 = num;                        
		if (answer != 'o')
		{
			printf("For how many positions?\n");
			scanf_s("%i", &shift);
		}
		for (int i = 0; i < shift; i++) {
			if (answer == 'r') {
				if (num2 & maskR) { num2 = num2 >> 1 ; num2 = num2 | 128; }
				else { num2 = num2 >> 1; }
			}
			if (answer == 'l') {
				if (num2 & maskL) { num2 = num2 << 1; num2 = num2 | 1; }
				else { num2 = num2 << 1; }
			}
		}
		printf("%i = ", num2);
		for (int i = 0; i < 8; i++) {
			remains[i] = num2 % 2;
			num2 = num2 / 2;
		}
		for (int i = 7; i > -1; i--) { printf("%i", remains[i]); }
		printf("\n");
		
		do {
			printf("where do you want to shift left(l) to right(r) or do you want to finish(n)?\n");
			scanf_s(" %c", &answer);
		} while (answer != 'r' && answer != 'l' && answer != 'n');
		
	}
}
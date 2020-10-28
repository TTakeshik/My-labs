#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#define M 100

int main()
{
	setlocale(LC_ALL, "Russian");
	int ms[M];
	int m, i, j, temp;
	printf("Введите кол-во элементов в массиве");
	scanf_s("%d", &m);
	printf("Заполните массив: ");
	for (i = 0; i < m; i++)
		scanf_s("%d", &ms[i]);
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < m - i - 1; j++)
		{
			if (ms[j] < ms[j + 1])
			{
				temp = ms[j];
				ms[j] = ms[j + 1];
				ms[j + 1] = temp;
			}
		}
	}
	for (j = 0; j < m; j++)
	{
		printf("%3d", ms[j]);
	}

}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define M 100

int main()
{
	int ms[M][M];
	int i, j, x, m, temp;
	printf("Enter of Array size:");
	scanf_s("%d", &m);
	printf("Enter elements of Array");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			scanf_s("%d", &ms[i][j]);
	}
	printf("\nArray:\n");
	for (i = 0; i < m; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%4d", ms[i][j]);
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			for (x = 0; x < m - i - 1; x++)
			{
				if (ms[j][x] < ms[j][x + 1])
				{
					temp = ms[j][x];
					ms[j][x] = ms[j][x + 1];
					ms[j][x + 1] = temp;

				}
			}
		}
	}
	printf("\nResult:\n");
	for (i = 0; i < m; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%4d", ms[i][j]);
	}



}
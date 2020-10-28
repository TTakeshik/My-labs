#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main()
{
	int ms[15];
	int sum, i;
	float raz;
	printf("Enter numbers of the Array");
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%d", &ms[i]);
		while (ms[i] < 0)
		{
			printf("Invalid data.");
			printf("Try again: ");
			scanf_s("%d", &ms[i]);
		}
	}
	int min = ms[0];
	int max = ms[0];
	for (int i = 0; i < 15; i++)
	{
		if (ms[i] > max)
			max = ms[i];
		if (ms[i] < min)
			min = ms[i];
		sum = min + max;
		raz = max - min;

	}
	printf("Sum = %d\n", sum);
	printf("Raz = %1.f", raz);

	return 0;
}

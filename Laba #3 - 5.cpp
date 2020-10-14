#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <locale.h>

int main()
{
	int n;
	const int a = 20, b = 10, c = 5, d = 1;
	setlocale(LC_ALL, "Russian");
	printf("¬ведите кол-во монет:");
	scanf_s("%d", &n);
	if (n <= 99)
	{
		for (int a = 0; a <= n; a += 20)
		{
			for (int b = 0; b <= n - a; b += 10)
			{
				if (a + b > n) break;
				for (int c = 0; c <= n - a - b; c += 5)
				{
					if (a + b + c > n) break;
					for (int d = 0; d <= n - a - b - c; ++d)
					{
						if (a + b + c + d == n)
						{
							printf("[20, 10, 5, 1]: %d %d %d %d\n", a / 20, b / 10, c / 5, d);
							break;
						}
					}
				}
			}
		}
	}
	else if (n > 99)
		printf("∆алкий смертный,не пытайс€ обмануть систему");
	return 0;
}


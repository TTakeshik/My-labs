#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	char** text;
	int s, b, max = 0, dl = -1, i1 = 0, i2 = 0, x = 0;
	bool f = false;
	printf("Введите количество строк: ");
	scanf_s("%d", &b);
	printf("Введите размер строки: ");
	scanf_s("%d", &s);
	++b;

	text = (char**)calloc(b, sizeof(char*));
	if (text == NULL)
	{
		printf("Недостаточно памяти!!! Попробуйте еще раз =)");
		free(text);
		return 0;
	}
	for (int i = 0; i < b; i++)
	{
		text[i] = (char*)calloc(s + 1, sizeof(char));
		if (text[i] == NULL)
		{
			printf("Недостаточно памяти!!! Попробуйте еще раз =)");
			free(text[i]);
			return 0;
		}
	}

	system("CLS");
	fflush(stdin);
	printf("Введите текст:\n");
	for (int i = 0; i < b; i++)
	{
		gets_s(text[i], s + 1);
	}	
	system("cls");
	printf("Ваш текст\n");
	for (int i = 1; i < b; i++)
	{
		puts(text[i]);
	}

	for (int i = 1; i < b; i++)
	{
		max = 0;
		for (int j = 0; text[i][j] != '\0'; j++)
		{
			if ((text[i][j] >= 'a' && text[i][j] <= 'z') || (text[i][j] >= 'A' && text[i][j] <= 'Z'))
			{
				x++;
			}
			else if (text[i][j] == ' ' || text[i][j] == '.' || text[i][j] == '!' || text[i][j] == '?')
			{
				
				
				dl = x;

				if (dl >= max)
				{
					i1 = j - x;
					i2 = j - 1;
					
					max = dl;
					x = 0;
					dl = 0;

					
						for (int t = i1; t <= i2; t++)
						{
							if (text[i][i1] >= 'a' && text[i][i1] <= 'z')
							{
								text[i][i1] -= 32;
							}
							i1++;
						}
					
					x = 0;
					i2 = 0;
					i1 = 0;
					f = false;
				}
				
				else if (dl < max && dl != -1)
				{
					x = 0;
					dl = -1;
				}
				if (text[i][j] == '.' && dl < max) {
					max = 0;
					continue;
				}
			}
			}
			
		
	
		
	}

	system("pause");
	system("cls");
	printf("Результат: \n");
	for (int i = 1; i < b; i++)
	{
		puts(text[i]);
	}

	free(text);
	system("pause");
	return 0;
}
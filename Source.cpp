
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
	int s, b, max = 0, dl = 0, i1 = 0, i2 = 0, x = 0;

	printf("������� ���������� �����: ");
	scanf_s("%d", &b);
	printf("������� ������ ������: ");
	scanf_s("%d", &s);
	++b;

	text = (char**)calloc(b, sizeof(char*));
	if (text == NULL)
	{
		printf("������������ ������!!! ���������� ��� ��� =)");
		free(text);
		return 0;
	}
	for (int i = 0; i < b; i++)
	{
		text[i] = (char*)calloc(s + 1, sizeof(char));
		if (text[i] == NULL)
		{
			printf("������������ ������!!! ���������� ��� ��� =)");
			free(text[i]);
			return 0;
		}
	}

	system("CLS");
	fflush(stdin);
	printf("������� �����:\n");
	for (int i = 0; i < b; i++)
	{
		gets_s(text[i], s + 1);
	}

	system("cls");
	printf("��� �����\n");
	for (int i = 1; i < b; i++)
	{
		puts(text[i]);
	}

	for (int i = 1; i < b; i++)
	{
		for (int j = 0; text[i][j] != '\0'; j++)
		{
			if ((text[i][j] >= 'a' && text[i][j] <= 'z') || (text[i][j] >= 'A' && text[i][j] <= 'Z'))
			{
				x++;
			}
			if (text[i][j] == ' ' || text[i][j] == '.' || text[i][j] == '!' || text[i][j] == '?')
			{
				dl = x;
			}
			if (dl > max)
			{
				i1 = j - x;
				i2 = j - 1;
				max = dl;
				x = 0;
				dl = 0;
			}
			if (dl < max && dl != 0)
			{
				x = 0;
				dl = 0;
			}
		}

		int j = i1;
		for (int t = i1; t <= i2; t++)
		{
			if (text[i][j] >= 'a' && text[i][j] <= 'z')
			{
				text[i][j] -= 32;
			}
			j++;
		}
		max = 0;
		dl = 0;
		x = 0;
		j = 0;
		i2 = 0;
		i1 = 0;
	}

	system("pause");
	system("cls");
	printf("���������: \n");
	for (int i = 1; i < b; i++)
	{
		puts(text[i]);
	}

	free(text);
	system("pause");
	return 0;
}
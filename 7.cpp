#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int zamena(int n, char* s, int m, char* str1, int l, char* str2, char*s1, int size)
{
    bool f = false;
    int k = 0, z = 0, koll = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            f = false;
        else
        {
            f = true;
            koll++;
        }
        if ((!f && koll != 0) || (f && i == n - 1))
        {
            z = 0;
            if (koll == m)
            {
                for (int j = i - koll; j < koll; j++)
                {
                    if (s[j] == str1[k])
                        z++;
                    k++;
                }
                if (z != m)
                    return 0;
                k = 0;
                y = koll;
                for (int x = 0; x < size; x++)
                {
                    if (x >= i - koll && x < l)
                    {
                        s1[x] = str2[k];
                        k++;
                    }
                    else
                    {
                        if (y < n)
                        {
                            s1[x] = s[y];
                            y++;
                        }
                    }
                }
                s1[size] = s[n];
                    
            }
            koll = 0;
        }

    }
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, l, koll = 0, slova = 0, size = 0;
    char* s, * str1, * str2, * s1;
    printf("Введите размер строки: ");
    scanf_s("%d", &n);
    s = (char*)malloc((n) * sizeof(char));
    rewind(stdin);
    gets_s(s, n + 1);
    printf("Строка: ");
    puts(s);
    bool f = false;
    printf("Введите размер слова которое вы хотите заменить: ");
    scanf_s("%d", &m);
    str1 = (char*)malloc((m) * sizeof(char));
    rewind(stdin);
    printf("Введите слово, которое хотите заменить: ");
    gets_s(str1, m + 1);
    printf("Введите размер слова на которое вы хотите заменить: ");
    scanf_s("%d", &l);
    str2 = (char*)malloc((l) * sizeof(char));
    rewind(stdin);
    printf("Введите слово на которое хотите заменить: ");
    gets_s(str2, l+1);
    size = n - m + l;
    s1 = (char*)calloc(size, sizeof(char));
    for (int i = 0; i<n; i++)
    {
        if (s[i] == ' ')
            f = false;
        else
        {
            f = true;
            koll++;
        }
        if ((!f && koll != 0) || (f && i==n-1))
        {
            slova++;
            koll = 0;
        }
        
    }
    zamena(n, s, m, str1, l, str2,s1, size);
    printf("\nКоличество слов: %d\n", slova);
    printf("Изменённая строка: ");
    puts(s1);
    return 0;
}
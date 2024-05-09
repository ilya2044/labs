#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool checkDuplicateDigits(int array[], int size, int digit) // проверка на повторяющиеся цифры
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == digit)
        {
            return true;
        }
    }
    return false;
}

bool isValidInput(int input) // проверка на цифру
{
    if (input < 0 || input > 9)
    {
        return false;
    }
    return true;
}

int main()
{
    bool igra = true;
    int cnt1 = 0;  // счетчик совпавшей цифры
    int cnt2 = 0;  // счетчик совпавшей цифры на своем месте
    int array1[4]; // загаданное число
    int array2[4]; // число от пользователя
    int i, j, input, hodi = 1;
    srand(time(NULL));

    for (i = 0; i < 4; i++) // формирование числа
    {
        int digit;
        do
        {
            digit = rand() % 10;
        } while (checkDuplicateDigits(array1, i, digit));

        array1[i] = digit;
    }

    bool igraem = true;

    while (igra)
    {
        if (igraem == true)
        {
            hodi++;
            printf("Введите 4 неповторяющиеся цифры:\n");
            for (i = 0; i < 4; i++) // цикл, который принимает число от пользователя, в цикле есть проверка на ошибки
            {
                bool validInput = false;
                do
                {
                    if (!validInput)
                    {
                        printf("Цифра %d: ", i + 1);
                        if (scanf("%d", &input) != 1)
                        {
                            printf("Ошибка: введите целое число.\n");
                            while (getchar() != '\n')
                                ;
                            continue;
                        }
                    }

                    if (!isValidInput(input))
                    {
                        printf("Ошибка: введите число от 0 до 9.\n");
                        while (getchar() != '\n')
                            ;
                        validInput = false;
                    }
                    else if (checkDuplicateDigits(array2, i, input))
                    {
                        printf("Ошибка: повторяющаяся цифра.\n");
                        validInput = false;
                    }
                    else
                    {
                        validInput = true;
                    }
                } while (!validInput);
                array2[i] = input;
            }
            printf("Вы ввели: "); // вывод числа от пользователя
            for (i = 0; i < 4; i++)
            {
                printf("%d", array2[i]);
            }
            printf("\n");
            igraem = false;
        }

        printf("\n");

        if ((array1[0] == array2[0]) && (array1[1] == array2[1]) && (array1[2] == array2[2]) && (array1[3] == array2[3]))
        {
            printf("Вы выиграли за %d ходов!!!\n", hodi);
            printf("Правильное число: ");
            for (i = 0; i < 4; i++)
            {
                printf("%d", array1[i]);
            }
            printf("\n");
            break;
            igraem = false;
        }
        else
        {
            for (int i = 0; i < 4; i++) // цикл, считающий cnt1 и cnt2
            {
                if (array1[0] == array2[i])
                {
                    cnt1++;
                }

                if (array1[1] == array2[i])
                {
                    cnt1++;
                }

                if (array1[2] == array2[i])
                {
                    cnt1++;
                }

                if (array1[3] == array2[i])
                {
                    cnt1++;
                }

                if (array1[i] == array2[i])
                {
                    cnt2++;
                }
            }
            printf("Количество совпавших цифр: %d, Количество цифр, стоящих на своем месте: %d\n", cnt1, cnt2);
            printf("\n");
            printf("Ход: %d", hodi);
            printf("\n");
            cnt1 = 0;
            cnt2 = 0;
            igraem = true;
        }
    }

    return 0;
}
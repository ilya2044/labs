#include <stdio.h>
#include <stdlib.h>

typedef struct school
{
    int num;
    float graduated;
    float enrolled;
    float percent;
} School;

void sort(School *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (array[j].percent < array[j + 1].percent)
            {
                School tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

float get_stat(School school)
{
    float percent = school.enrolled / (school.graduated / 100);
    return percent;
}

void print_array(School *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("Номер школы: %d, Кол-во выпускников: %d, Кол-во поступивших: %d, Процент поступивших: %.4f%% \n", array[i].num, (int)array[i].graduated, (int)array[i].enrolled, array[i].percent);
    }
}

int main()
{
    int n = 0;
    printf("Введите кол-во школ:\n");
    scanf("%d", &n);
    School *array = (School *)calloc(n, sizeof(School));
    for (int i = 0; i < n; ++i)
    {
        printf("Введите номер школы:\n");
        scanf("%d", &array[i].num);
        printf("Введите кол-во выпускников:\n");
        scanf("%f", &array[i].graduated);
        printf("Введите кол-во поступивших:\n");
        scanf("%f", &array[i].enrolled);
        array[i].percent = get_stat(array[i]);

        printf("Процент поступивших %f%%\n", array[i].percent);
    }
    sort(array, n);
    print_array(array, n);
    free(array);
    return 0;
}
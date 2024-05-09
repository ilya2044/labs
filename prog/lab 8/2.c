#include <stdio.h>
#include <stdlib.h>

typedef struct stat
{
    int department;
    int rooms;
    float people;
    float deltaS;
} Stat;

typedef struct dormitory
{
    int roomnumber;
    float S;
    int department;
    float people;
} Dormitory;

void get_stat(Dormitory *array, Stat *stat_array, int n)
{
    float deltaS = 0;
    for (int i = 0; i < n; ++i)
    {
        stat_array[i].rooms = 0;
        stat_array[i].people = 0;
        stat_array[i].deltaS = 0;
        deltaS = 0;
        for (int j = 0; j < n; ++j)
        {
            if (stat_array[i].department && stat_array[i].department == array[j].department)
            {
                stat_array[i].rooms++;
                stat_array[i].people += array[j].people;
                deltaS += array[j].S;
            }
        }
        stat_array[i].deltaS = deltaS / stat_array[i].people;
    }
}

void print_array(Stat *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (array[i].department)
        {
            printf("Факультет: %d, Кол-во проживающих: %d, Кол-во комнат: %d, Средняя площадь: %.3f \n", array[i].department, (int)array[i].people, array[i].rooms, array[i].deltaS);
        }
    }
}

int main()
{
    int n = 0, C = 0;
    printf("Введите кол-во комнат: \n");
    scanf("%d", &n);
    Stat *stat_array = (Stat *)calloc(n, sizeof(Stat));
    Dormitory *array = (Dormitory *)calloc(n, sizeof(Dormitory));
    for (int i = 0; i < n; ++i)
    {
        printf("Номер комнаты: \n");
        scanf("%d", &array[i].roomnumber);
        printf("Площадь комнаты: \n");
        scanf("%f", &array[i].S);
        printf("Факультет: \n");
        scanf("%d", &array[i].department);
        for (int j = 0; j < n; ++j)
        {
            if (array[i].department == stat_array[j].department)
            {
                break;
            }
            else
            {
                if (!stat_array[j].department)
                {
                    stat_array[j].department = array[i].department;
                    C++;
                    break;
                }
            }
        }
        printf("Кол-во проживающих: \n");
        scanf("%f", &array[i].people);
    }
    get_stat(array, stat_array, n);
    print_array(stat_array, n);
    printf("Кол-во различных факультетов: %i", C);
    free(array);
    free(stat_array);
    return 0;
}
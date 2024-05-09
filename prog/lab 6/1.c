#include <stdio.h>
#include <math.h>

int calc(float a, float b, float c, float *p, float *s)
{
    float per;
    if ((a < 0) || (b < 0) || (c < 0))
    {
        return 1;
    }
    if ((a + b == c) || (a + c == b) || (b + c == a))
    {
        *p = a + b + c;
        *s = 0;
        return 2;
    }
    if ((a + b < c) || (a + c < b) || (b + c < a))
    {
        return 3;
    }
    per = (a + b + c) / 2;
    *s = sqrt(per * (per - a) * (per - b) * (per - c));
    *p = a + b + c;
    return 0;
}

int main(void)
{
    float a, b, c, p, s;
    int t;
    printf("\nВведите стороны a , b , c   \n");
    scanf(" %f", &a);
    scanf(" %f", &b);
    scanf(" %f", &c);
    t = calc(a, b, c, &p, &s);

    if (t == 1)
    {
        printf("Ввели отрицательную сторону");
    }
    else if (t == 2)
    {
        printf("\nТреугольник вырожденный\n");
        printf("\nПериметр = %f, Площадь = %f", p, s);
    }
    else if (t == 3)
        printf("\nТреугольник не существует\n");
    else if (t == 0)
        printf("\nПериметр = %f, Площадь = %f", p, s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

double kv(double x, int n)
{
    double g;
    double l;
    if (n == 1)
    {
        l = x;
    }

    if (n > 0)
    {
        g = x;
        for (int i = 1; i < n; i++)
        {
            x *= g;
            l = x;
        }
    }

    if (n < 0)
    {
        int m = abs(n);
        g = x;
        double a = 1;
        for (int i = 1; i < m; i++)
        {
            x *= g;
            l = 1 / x;
        }
    }

    if (n == -1)
    {
        int m = abs(n);
        g = x;
        double a = 1;
        for (int i = 0; i < m; i++)
        {
            l = 1 / x;
        }
    }

    if (n == 0)
    {
        x = 1;
        l = x;
    }
    return l;
}

int main()
{
    double x;
    int n;
    double f;
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите степень числа x: ");
    scanf("%d", &n);
    f = kv(x, n);
    if (f < 0)
    {
        f = f * (-1);
    }
    printf("Результат: %f ", f);
    return 0;
}
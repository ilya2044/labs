#include <stdio.h>
#include <math.h>

int F(int x)
{
    int f = 1;
    for (int i = 1; i <= x; i++)
        f = f * i;
    return f;
}

float S(float x, int k)
{
    float m;
    m = x;
    while (k > 1)
    {
        m = m * x;
        k--;
    }
    return m;
}

void Chance(int n, int m, float *pd, float *pm)
{
    float p, q;
    int c;
    p = 0.45;
    q = 1 - p;
    c = (F(n)) / (F(m) * F(n - m));
    *pd = c * S(p, m) * S(q, n - m);
    *pm = c * S(q, m) * S(p, n - m);
}

int main()
{
    int n, m;
    float pd, pm;
    printf("введите общее кол-во детей \n");
    scanf("%i", &n);
    printf("введите число мальчиков или девочек \n");
    scanf("%i", &m);
    if (m > n)
    {
        printf("такого не может быть \n");
    }
    if ((m <= 0) || (n <= 0))
    {
        printf("такого не может быть \n");
    }
    if ((m <= n) && (n > 0) && (m > 0))
    {
        Chance(n, m, &pd, &pm);
        printf("вероятность, что будет столько девочек: %f\n", pd);
        printf("вероятность, что будет столько мальчиков: %f\n", pm);
    }
}
#include <stdio.h>
void pasha()
{
    int a, b, c, d, e, f;
    int n;
    printf("Введите год:");
    scanf("%d", &n);
    a = n % 19;
    b = n % 4;
    c = n % 7;
    d = (19 * a + 15) % 30;
    e = (2 * b + 4 * c + 6 * d + 6) % 7;
    f = d + e;
    if (f <= 26)
    {
        f += 4;
        printf("%d апреля", f);
    }
    else
    {
        printf("26 мая");
    }
}
int main()
{
    pasha();

    return 0;
}
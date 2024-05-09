#include <stdio.h>

int nums[100], i, j;

void print()
{
    if (nums[j] < 0)
    {
        printf("%d ", nums[j]);
        ++j;
        print();
        if (nums[j] > 0)
            printf("%d ", nums[j]);
        ++j;
    }
    else if (nums[j] > 0)
    {
        ++j;
        print();
        if (nums[j] > 0)
            printf("%d ", nums[j]);
        ++j;
    }
    else
    {
        j = 0;
    }
}

int main()
{
    while (scanf("%d", &nums[i]) && nums[i++])
        ;
    print();
    return 0;
}
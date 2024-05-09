#include <stdio.h>
int aaa(int x)
{
	if (x < 2)
	{
		return x;
	}
	return 10 * aaa(x / 2) + (x % 2);
}
main()
{
	int x;
	scanf("%d", &x);
	printf("%d", aaa(x));
}

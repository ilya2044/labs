#include <stdio.h>
long rec();

int main()
{

	rec();
	return 0;
}

long rec()
{
	int n;

	scanf("%d", &n);
	if (n != 0)
	{
		if (n > 0)
		{
			rec();
			printf("%4d", n);
		}
		else
		{
			if (n < 0)
			{
				rec();
				printf("\n");
			}
		}
	}
}

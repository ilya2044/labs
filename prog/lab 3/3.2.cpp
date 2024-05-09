#include <iostream>
using namespace std;

void FillRand(int x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		x[i] = rand() % 101;
	}
}

void PrintMas(int x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}

void Copy(int *a, int **b, int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a + i;
	}
}

void BubbleSort(int **x, int n)
{
	int i, j, *dp;
	for (i = (n - 1); i > 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (x[j - 1][0] > x[j][0])
			{
				dp = x[j - 1];
				x[j - 1] = x[j];
				x[j] = dp;
			}
		}
	}
}

int main()
{
	int *a, n, **b;
	cin >> n;
	a = new int[n];
	b = new int *[n];
	FillRand(a, n);
	PrintMas(a, n);
	Copy(a, b, n);
	BubbleSort(b, n);
	for (int i = 0; i < n; ++i)
	{
		cout << b[i][0] << " ";
	}
	cout << endl;
	PrintMas(a, n);
	delete (b);
	delete (a);
}

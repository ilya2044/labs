#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 100;
int A[100];
int prC, prM, k, prT, tT;

void FillRand()
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 10;
	}
}

void FillInc()
{
	for (int i = 0; i < N; i++)
	{
		A[i] = i + 1;
	}
}

void FillDec()
{
	int b = N;
	for (int i = 0; i < N; i++)
	{
		A[i] = b - 1;
		b = b - 1;
	}
}

void PrintMas()
{
	for (int i = 0; i < N; i++)
	{
		printf("%2d", A[i]);
	}
}

void BubSort(int *A, int n)
{
	prM = 0;
	prC = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			prC++;
			if (A[j] < A[j - 1])
			{
				k = A[j];
				A[j] = A[j - 1];
				A[j - 1] = k;
				prM += 3;
			}
		}
	}
	prT = prC + prM;
}

int CheckSum()
{
	int c = A[0];
	for (int i = 1; i < N; i++)
	{
		c = c + A[i];
	}
	return c;
}

int RunNum()
{
	int kol = 0;
	for (int i = 0; i < N; i++)
	{
		while (A[i] <= A[i + 1])
		{
			i++;
		}
		kol++;
	}
	return kol;
}

int main()
{
	int s, sum;
	prC = 0;
	prM = 0;
	printf("Unsorted array\n");
	FillRand();
	PrintMas();
	BubSort(A, N);
	printf("\nSorted array\n");
	PrintMas();
	printf("\nC = %d\nM = %d\nT = %d\n", prC, prM, prT);
	int tC = (N * N - N) / 2;
	int tM = (3 * tC) / 2;
	int tT = tC + tM;
	printf("\nTC = %d\nTM = %d\nTT = %d", tC, tM, tT);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N=100;
int A[100];
int C, M, T;

void FillRand () {
	srand(time(NULL));
	for (int i=0; i<N; i++) {
		A[i] = rand()%10;
	}
}

void FillInc () {
	for (int i=0; i<N; i++) {
		A[i] = i + 1;
	}
}

void FillDec () {
	int b = N;
	for (int i=0; i<N; i++) {
		A[i] = b - 1;
		b = b - 1;
	}
}

void PrintMas() {
	for (int i=0; i<N; i++) {
		printf ("%2d", A[i]);
	}
}

void ShakeSort(int *a, int n) {
	int left=0; int right=n-1; int i, k, temp;
	M=0; C=0;
	k=n-1;
	while (left<right) {
		for (i=right; i>left; i--) {
			C++;
			if (a[i-1] > a[i]) {
					temp = a[i];
					a[i]=a[i-1];
					a[i-1]=temp;
				M+=3;
				k=i;
			}
		}
	left = k;
			for (i=left; i<right; i++) {
				C++;
				if (a[i+1]<a[i]) {
						temp = a[i];
						a[i]=a[i+1];
						a[i+1]=temp;
					M+=3;
					k=i;
				}
			}
	right = k;
		}
}
    

int CheckSum () {
	int c = A[0];
	for (int i=1; i<N; i++) {
		c = c + A[i];
	}
	return c;
}

int RunNum () {
	int kol = 0;
	for (int i=0; i<N; i++) {
		while (A[i] <= A[i+1]) {
			i++;
		}
		kol++;
	}
	return kol;
} 

int main () {
	int s, sum;
	M=0, C=0;
	//printf("Unsorted array\n");
	FillDec();
	PrintMas();
	ShakeSort(A, N);
	printf("\nSorted array\n");
	PrintMas();
	T=C+M;
	printf ("\nPractical compares = %d\nPractical moves = %d\nPractical Laboriousness = %d\n", C, M, T);	
	int tC = ((N*N)-N)/2;
	int tM = (3*tC)/2;
	int tT = tC + tM;
	printf ("\nTheoretical compares = %d\nTheoretical moves = %d\nTheoretical Laboriousness = %d", tC, tM, tT);
	return 0;
}

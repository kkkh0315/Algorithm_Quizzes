#include <stdio.h>
#include <stdlib.h>

int Min(int a, int b);
int compare(const void* a, const void* b);

int A[100001];
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	int p = 1;
	int q = 0;
	int ans = 2000000000;
	while (p < N && q < N)
	{
		if (A[p] - A[q] < M)
		{
			++p;
			continue;
		}
		else if (A[p] - A[q] == M)
		{
			ans = M;
			break;
		}
		else
		{
			ans = Min(ans, A[p] - A[q]);
			++q;
		}
	}

	printf("%d", ans);

	return 0;
}

int Min(int a, int b)
{
	return a > b ? b : a;
}

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
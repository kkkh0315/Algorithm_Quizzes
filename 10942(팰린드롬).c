#include <stdio.h>
#include <string.h>

#define ARRAYSIZE 2001

void palindrome(int N);
void InitDP();

int dp[ARRAYSIZE][ARRAYSIZE];
int aArray[ARRAYSIZE];

int main(void)
{
	int N, M;

	InitDP();
	
	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++)
	{
		scanf("%d", &aArray[i]);
	}

	palindrome(N);

	scanf("%d", &M);
	int S, E;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &S, &E);
		printf("%d\n", dp[S][E]);
	}

	return 0;
}

void palindrome(int N)
{
	for (int i = 1; i < N + 1; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		if (aArray[i] == aArray[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int len = 2; len < N; len++)
	{
		for (int j = 1; j < N - len + 1; j++)
		{
			if ((aArray[j] == aArray[j + len]) && (dp[j + 1][j + len - 1]) == 1)
				dp[j][j + len] = 1;
		}
	}
	return;
}

void InitDP()
{
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		memset(dp[i], 0, sizeof(dp[i]));
	}
	return;
}
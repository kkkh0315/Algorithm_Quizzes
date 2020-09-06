#include <stdio.h>
#include <string.h>

#define MAXSIZE 1001

int map[MAXSIZE][MAXSIZE];
int dp[MAXSIZE][MAXSIZE];

int Min(int a, int b, int c);
int Max(int a, int b);
void InitDP();
void InitMap();

int main(void)
{
	int M, N;
	scanf("%d%d", &M, &N);

	InitMap();
	for (int i = 1; i < M + 1; ++i)
	{
		for (int j = 1; j < N + 1; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}

	InitDP();
	int maxlen = 0;
	for (int i = 1; i < M + 1; ++i)
	{
		for (int j = 1; j < N + 1; ++j)
		{
			if (map[i][j] == 0)
			{
				dp[i][j] = Min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
				maxlen = Max(maxlen, dp[i][j]);
			}
		}
	}

	printf("%d", maxlen);
	
	return 0;
}

int Min(int a, int b, int c)
{
	int m = a > b ? b : a;
	return m > c ? c : m;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

void InitDP()
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		memset(dp[i], 0, sizeof(dp[i]));
	}
	return;
}

void InitMap()
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		memset(map[i], 1, sizeof(map[i]));
	}
	return;
}
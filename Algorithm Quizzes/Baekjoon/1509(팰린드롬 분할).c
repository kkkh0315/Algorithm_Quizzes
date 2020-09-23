#include <stdio.h>
#include <string.h>

#define ARRAYSIZE 2501

void palindrome(int N);
void InitDP();

int dp[ARRAYSIZE][ARRAYSIZE];
char s[ARRAYSIZE];
int partdp[ARRAYSIZE]; //partdp[n] : 1~n까지 분할의 최소 방법 수

int main(void)
{
	InitDP();

	scanf("%s", s + 1);

	int slen = strlen(s + 1);
	palindrome(slen);
	
	partdp[0] = 0;
	for (int i = 1; i <= slen; ++i) {
		partdp[i] = 2500;
		for (int j = 1; j <= i; ++j) {
			if (dp[j][i]) {
				if (partdp[i] > partdp[j - 1] + 1) {
					partdp[i] = partdp[j - 1] + 1;
				}
			}
		}
	}

	printf("%d", partdp[slen]);
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
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int len = 2; len < N; len++)
	{
		for (int j = 1; j < N - len + 1; j++)
		{
			if ((s[j] == s[j + len]) && (dp[j + 1][j + len - 1]) == 1)
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int a, int b);
void InitDP(int (*dp)[1001]);
void CalLCS(int (*dp)[1001], char s1[], char s2[]);

char s1[1001];
char s2[1001];
int dp[1001][1001];

int main(void)
{
    scanf("%s", s1);
    scanf("%s", s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    InitDP(dp);
    CalLCS(dp, s1, s2);

    printf("%d", dp[len1][len2]);
    
    return 0;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

void InitDP(int (*dp)[1001])
{
    for (int i = 0; i < 1001; ++i)
    {
        memset(dp[i], 0, sizeof(int) * 1001);
    }
}

void CalLCS(int (*dp)[1001], char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
#include <stdio.h>
#include <string.h>

int dp[1001];

int CalTile(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    printf("%d", CalTile(n));

    return 0;
}

int CalTile(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (dp[n] != 0) return dp[n];
    return dp[n] = (CalTile(n - 1) + 2 * CalTile(n - 2)) % 10007;
}
#include <stdio.h>
#include <string.h>

#define MAXITEMS 101
#define MAXPOWER 100001


typedef struct T {
    int weight;
    int value;
}T;

int dp[MAXITEMS][MAXPOWER];


void InitDP(int(*dp)[100001]);
int Max(int a, int b);

int main(void)
{
    int N, K;
    T T[MAXITEMS];
    scanf("%d%d", &N, &K);
    for (int i = 1; i < N + 1; ++i)
    {
        scanf("%d%d", &T[i].weight, &T[i].value);
    }

    InitDP(dp);

    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 1; j < K + 1; ++j)
        {
            if (i == 1)
            {
                if (j >= T[i].weight)
                    dp[i][j] = T[i].value;
            }
            else
            {
                if (j >= T[i].weight)
                    dp[i][j] = Max(T[i].value + dp[i - 1][j - T[i].weight], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%d", dp[N][K]);
    
    return 0;
}

void InitDP(int(*dp)[100001])
{
    for (int i = 0; i < MAXITEMS; ++i)
    {
        memset(dp[i], 0, sizeof(dp));
    }
    return;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}
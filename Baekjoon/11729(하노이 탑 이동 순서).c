#include <stdio.h>

int dp[21];

void MoveHanoi(int n, int depart, int stopby, int dest);
int CalHanoi(int n);

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d\n", CalHanoi(N));
    MoveHanoi(N, 1, 2, 3);
    
    return 0;
}

void MoveHanoi(int n, int depart, int stopby, int dest)
{
    if (n == 1) printf("%d %d\n", depart, dest);
    else
    {
        MoveHanoi(n - 1, depart, dest, stopby);
        printf("%d %d\n", depart, dest);
        MoveHanoi(n - 1, stopby, depart, dest);
    }
}

int CalHanoi(int n)
{
    if (n == 1) return 1;
    if (dp[n]) return dp[n];
    return dp[n] = 2 * CalHanoi(n - 1) + 1;
}
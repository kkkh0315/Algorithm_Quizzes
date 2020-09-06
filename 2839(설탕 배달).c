#include <stdio.h>

#define TRUE 1

int main(void)
{
    int N, nCount = 0;
    scanf("%d", &N);
    while (TRUE)
    {
        if (N % 5 == 0) 
        {
            nCount += N / 5;
            printf("%d", nCount);
            break;
        }
        N -= 3;
        ++nCount;
        if (N < 0)
        {
            nCount = -1;
            printf("%d", nCount);
            break;
        }
    }

    return 0;
}
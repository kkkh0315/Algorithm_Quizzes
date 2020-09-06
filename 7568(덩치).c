#include <stdio.h>

typedef struct body {   //몸무게, 키, 덩치 순위를 담은 구조체
    int weight;
    int height;
    int rank;
}Body;

void InitRank(int N, Body* aBody);
void CalRank(int N, Body* aBody);


int main(void)
{
    int N;
    Body aBody[50];

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", &aBody[i].weight, &aBody[i].height);
    }

    InitRank(N, aBody); //rank 1로 초기화
    CalRank(N, aBody); //rank(덩치 순위) 계산

    //출력
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", aBody[i].rank);
    }

    return 0;
}

void InitRank(int N, Body* aBody) 
{
    for (int i = 0; i < N; ++i)
    {
        aBody[i].rank = 1;
    }
    return;
}

void CalRank(int N, Body* aBody) 
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i != j)
            {
                if ((aBody[i].weight < aBody[j].weight) && (aBody[i].height < aBody[j].height))
                    ++aBody[i].rank;
            }
        }
    }
    return;
}
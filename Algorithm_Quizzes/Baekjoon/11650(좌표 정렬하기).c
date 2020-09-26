#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x;
	int y;
}C;

int compare(const void* a, const void* b)
{
	C* pa = (C*)a;
	C* pb = (C*)b;
	if (pa->x == pb->x)
	{
		return pa->y - pb->y;
	}
	else
	return pa->x - pb->x;
}



C coor[100001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &coor[i].x, &coor[i].y);
	}

	qsort(coor, N, sizeof(coor[0]), compare);


	for (int i = 0; i < N; ++i)
	{
		printf("%d %d\n", coor[i].x, coor[i].y);
	}
	
	return 0;
}
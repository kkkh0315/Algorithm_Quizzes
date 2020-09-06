#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

long long aArray[100001];
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &aArray[i]);
	}
	std::sort(aArray, aArray + N);

	long long answer = aArray[0];
	int nCount = 0;
	int nOldCount = 0;
	for (int i = 1; i < N; i++)
	{
		if (aArray[i] == aArray[i - 1])
			++nCount;
		else nCount = 0;
		if (nCount > nOldCount)
		{
			nOldCount = nCount;
			answer = aArray[i];
		}
	}

	printf("%lld", answer);
	return 0;
}
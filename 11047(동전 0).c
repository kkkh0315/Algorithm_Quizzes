#include <stdio.h>


int main(void)
{
	int N;
	int K;
	int count = 0;
	int coin[11];
	scanf("%d%d", &N, &K);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &coin[i]);
	}


	for (int i = N - 1; i >= 0; --i)
	{
		if (K >= coin[i])
		{
			while (K >= coin[i])
			{
				K -= coin[i];
				++count;
			}
		}
		else if (K == 0)
			break;
	}

	printf("%d", count);
	

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	return *(char*)b - *(char*)a;
}

int ctoi(char a)
{
	return a - '0';
}

int main(void)
{
	char aArray[11];
	scanf("%s", aArray);
	int len = strlen(aArray);
	qsort(aArray, len, sizeof(char), compare);
	
	for (int i = 0; i < len; ++i)
	{
		aArray[i] = ctoi(aArray[i]);
	}

	for (int i = 0; i < len; ++i)
	{
		printf("%d", aArray[i]);
	}
	
	return 0;
}
#include <stdio.h>
#include <string.h>

int pelcheck(int s, int e);

char aArray[6];
int pel[5][5];

int main(void)
{
	while (aArray[0] != '0')
	{
		scanf("%s", aArray);
		int s = 0;
		int e = strlen(aArray) - 1;
		
		if (aArray[0] == '0') break;
		if (pelcheck(s, e) == 1)
			printf("yes\n");
		if (pelcheck(s, e) == -1)
			printf("no\n");
	}
	return 0;
}

int pelcheck(int s, int e)
{
	if (s == e) return 1;
	else if (s + 1 == e)
	{
		if (aArray[s] == aArray[e]) return 1;
		else return -1;
	}
	else
	{
		if (aArray[s] == aArray[e])
		{
			if (pelcheck(s + 1, e - 1) == 1) return 1;
		}
		else return -1;
	}
}
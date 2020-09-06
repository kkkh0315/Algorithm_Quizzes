#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);

	int width = 1 + 4 * (num - 1);
	int height = 1 + 4 * (num - 1);
	char** aArray = (char**)calloc(height, sizeof(char*)); //2차원배열 동적할당
	for (int i = 0; i < height; ++i)
	{
		aArray[i] = (char*)calloc(width, sizeof(char));
	}

	//2차원 배열 전체 공백으로 초기화(콘솔에선 같지만 ' '이랑 '\0'을 채점 시스템이 구별하네요)
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			aArray[i][j] = ' ';
		}
	}

	//위아래 피라미드 만들기
	for (int j = 0; j < height; ++j)
	{
		if (j % 2 == 0)
		{
			if (j <= height / 2)
			{
				for (int k = j; k < width - j; ++k)
				{
					aArray[j][k] = '*';
				}
			}
			else if (j > height / 2)
			{
				for (int k = height - j - 1; k < j + 1; ++k)
				{
					aArray[j][k] = '*';
				}
			}
		}
	}

	//양 옆 날개 만들기
	for (int j = 0; j < width; ++j)
	{
		if (j % 2 == 0)
		{
			if (j < width / 2)
			{
				for (int k = 1 + j; k < height - j; ++k)
				{
					aArray[k][j] = '*';
				}
			}
			else if (j > width / 2)
			{
				for (int k = height - j; k < 1 + j; ++k)
				{
					aArray[k][j] = '*';
				}
			}
		}
	}

	//출력
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			printf("%c", aArray[i][j]);
		}
		if (i < height - 1) //마지막엔 개행하지 않기 위해
		{
			putchar('\n');
		}
	}



	for (int i = 0; i < height; ++i) //2차원배열 동적할당 해제
	{
		free(aArray[i]);
	}
	free(aArray);


	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);

	if (num == 1) printf("*");
	else
	{
		int width = 4 * num - 3;
		int height = 4 * num - 1;

		char** aArray = (char**)calloc(height, sizeof(char*)); //2차원배열 동적할당
		if (aArray)
		{
			for (int i = 0; i < height; ++i)
			{
				aArray[i] = (char*)calloc(width, sizeof(char));
			}


			//2차원 배열 3번째 줄부터 공백으로 초기화
			for (int i = 2; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
				{
					aArray[i][j] = ' ';
				}
			}


			//달팽이 배열을 응용했습니다.
			int x = width, y = 0;
			int nDirection = -1;

			for (int nLength = width + height; nLength > 3; nLength -= 4)
			{
				if (nLength == width + height) //첫번째만 nLength를 1 줄여야 함.
					--nLength;

				for (int i = 0; i < nLength; ++i)
				{
					if (i < nLength / 2)
						x += nDirection;
					else
						y -= nDirection;

					aArray[y][x] = '*';
				}
				
				if (nLength == width + height - 1) //nLength 원상 복귀.
					++nLength;

				nDirection = -nDirection;
			}

			//출력
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width; ++j)
				{
					if(aArray[i][j]) //두번째줄 공백으로 두지 않기 위해. 여기서 해멤.
					printf("%c", aArray[i][j]);
				}
				if (i < height - 1)
					putchar('\n');
			}
		}


		for (int i = 0; i < height; ++i) //2차원배열 동적할당 해제
		{
			free(aArray[i]);
		}
		free(aArray);
	}

	return 0;
}
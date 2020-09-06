#include <stdio.h>
#include <stdlib.h>

//C만 사용해서 작성한 코드입니다. C++을 최대한 사용하지 않으면서 코딩하는 연습 중.
//참고해서 봐주세요!


#define QUEUESIZE 101

typedef struct queue {
	int aArray[QUEUESIZE];
	int topindex;
	int maxindex;
}Queue;

typedef struct test {
	int N;
	int M;
	Queue queue;
}Test;

//사용할 사용자 정의 함수 선언
void InitQueue(Queue* pqueue);
int CalSize(Queue* pqueue);
void Push(Queue* pqueue, int j, int data);
int FindMax(Queue* pqueue, int maxindex);

int main(void)
{
	int nTestcase, nImportance;

	scanf("%d", &nTestcase);
	getchar(); //버퍼 비우기. scanf로 입력 받을 시 마지막 개행 문자가 버퍼에 남아 있는다.
	
	Test* pTest = NULL;
	pTest = (Test*)malloc(sizeof(Test) * nTestcase);

	for (int i = 0; i < nTestcase; ++i)
	{
		InitQueue(&(pTest[i].queue)); //topindex, maxindex를 초기화
		scanf("%d%d", &pTest[i].N, &pTest[i].M);
		getchar();
		for (int j = 0; j < pTest[i].N; ++j)
		{
			scanf("%d", &nImportance);
			getchar();
			Push(&(pTest[i].queue), j, nImportance);
		}
	}


	//정답 출력
	for (int i = 0; i < nTestcase; ++i)
	{
		int nCount = 0;
		for (int j = 0; pTest[i].queue.aArray[pTest[i].M] != 0; ++j)
		{
			pTest[i].queue.aArray[FindMax(&(pTest[i].queue), pTest[i].queue.maxindex)] = 0;

			++nCount;
		}
		printf("%d\n", nCount);
	}

	free(pTest);

	return 0;

}

//사용 할 사용자 정의 함수 정의
void InitQueue(Queue* pqueue)
{
	pqueue->topindex = -1;
	pqueue->maxindex = 0;
	return;
}

int CalSize(Queue* pqueue)
{
	return pqueue->topindex + 1;
}

void Push(Queue* pqueue, int j, int data)
{
	pqueue->aArray[j] = data;
	++(pqueue->topindex);
}

int FindMax(Queue* pqueue, int maxindex)
{
	if (CalSize(pqueue) == 1)
		return 0;
	else
	{
		for (int i = maxindex + 1; i < CalSize(pqueue); ++i)
		{
			if (pqueue->aArray[pqueue->maxindex] < pqueue->aArray[i])
				pqueue->maxindex = i;
		}
		for (int i = 0; i < maxindex; ++i)
		{
			if (pqueue->aArray[pqueue->maxindex] < pqueue->aArray[i])
				pqueue->maxindex = i;
		}

		return pqueue->maxindex;
	}
}

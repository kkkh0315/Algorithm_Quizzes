#include <stdio.h>
#include <string.h>

#define QUEUESIZE 10001

typedef struct queue {
	int aArray[QUEUESIZE];
	int topindex; //가장 마지막으로 push된 값의 인덱스(zero-base)
}Queue;

//사용할 사용자 정의 함수 선언
void InitQueue(Queue* pqueue);
int IsEmpty(Queue* pqueue);
int CalSize(Queue* pqueue);
int IsFull(Queue* pqueue);
void Push(Queue* pqueue, int data);
int Pop(Queue* pqueue);
int Front(Queue* pqueue);
int Back(Queue* pqueue);

int main(void)
{
	char command[6];
	Queue queue;
	int data; //push할 때 쓸 data
	int n;
	
	scanf("%d", &n);
	getchar(); //버퍼 비우기. scanf로 입력 받을 시 마지막 개행 문자가 버퍼에 남아 있는다.
	InitQueue(&queue);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", command); //push, pop, size, empty, front, back 중 명령을 받는다.
		getchar(); 
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &data);
			getchar();
			Push(&queue, data);
		}

		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", Pop(&queue));
		}

		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", CalSize(&queue));
		}

		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", IsEmpty(&queue));
		}

		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", Front(&queue));
		}

		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", Back(&queue));
		}
	}

	return 0;

}

//사용할 사용자 정의 함수 정의
void InitQueue(Queue* pqueue)
{
	pqueue->topindex = -1; //첫번째 Push부터 ++queue->topindex를 실행하고 그 결과가 0이어야 하기 때문
}

int IsEmpty(Queue* pqueue)
{
	if (pqueue->topindex == -1) return 1;
	else return 0;
}

int CalSize(Queue* pqueue)
{
	return pqueue->topindex + 1;
}

int IsFull(Queue* pqueue)
{
	if (CalSize(pqueue) >= QUEUESIZE) return 1;
	else return 0;
}

void Push(Queue* pqueue, int data)
{
	if (IsFull(pqueue) == 1) return;
	else
	{
		pqueue->aArray[++(pqueue->topindex)] = data;
		//topindex를 1 늘리고 data 저장
	}
}

int Pop(Queue* pqueue)
{
	if (IsEmpty(pqueue) == 1) return -1;
	else
	{
		int pop = pqueue->aArray[0];
		for (int i = 0; i < CalSize(pqueue) - 1; ++i)
		{
			pqueue->aArray[i] = pqueue->aArray[i + 1];
		}
		--(pqueue->topindex);
		//aArray[0]은 임시 저장해 두고, 요소들의 인덱스를 1씩 줄인다.

		return pop;
	}
}

int Front(Queue* pqueue)
{
	if (IsEmpty(pqueue) == 1) return -1;
	else
	{
		return pqueue->aArray[0];
	}
}

int Back(Queue* pqueue)
{
	if (IsEmpty(pqueue) == 1) return -1;
	else
	{
		return pqueue->aArray[pqueue->topindex];
	}
}
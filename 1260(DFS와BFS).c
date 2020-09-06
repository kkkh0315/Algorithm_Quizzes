#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUESIZE 1001
#define TRUE 1
#define FALSE 0

//C언어만 사용하려고 최대한 노력했습니다.
//C++은 사용하지 않기 위해 큐를 직접 구현했습니다.
//그로 인해 C++ STL을 사용했다면 하지 않아도 될 작업들을 손수 해야했던 부분들이 있습니다.

typedef struct queue {
	int aArray[QUEUESIZE];
	int topindex;
}Queue;

//C언어로 큐(Queue) 구현
void InitQueue(Queue* pqueue);
int IsEmpty(Queue* pqueue);
int CalSize(Queue* pqueue);
int IsFull(Queue* pqueue);
void Push(Queue* pqueue, int data);
int Pop(Queue* pqueue);

//DFS BFS 구현
void DFS(int V);
void BFS(int V);

//qsort용 compare 함수
int compare(const void* a, const void* b);

int checked[QUEUESIZE];
int connection[QUEUESIZE][10000]; //connection[a노드의][x번째] = 인접 노드 번호
int N, M, V;


int main(void)
{
	scanf("%d%d%d", &N, &M, &V);


	//그래프 설정
	for (int i = 0; i < N + 1; ++i) //모든 노드의 모든 인접 노드를 9999로 초기화
	{                               //후에 오름차순 정리로 9999를 뒤로 뺄 예정
		for (int j = 0; j < 10000; ++j)
		{
			connection[i][j] = 9999; 
		}
	}

	int a, b;

	for (int i = 0; i < M; ++i) //인접 노드들 저장
	{
		scanf("%d%d", &a, &b);
		connection[a][i] = b;
		connection[b][i] = a;
	}

	for (int i = 0; i < N + 1; ++i) //각 노드들의 인접 노드들 오름차순으로 정리
	{
		qsort(connection[i], sizeof(connection[i]) / sizeof(int), sizeof(int), compare);
	}

	DFS(V);
	for (int i = 0; i < QUEUESIZE; ++i) //BFS()에서 다시 쓸 수 있게 checked 배열 원상 복귀
	{
		checked[i] = FALSE;
	}
	putchar('\n');
	BFS(V);


	return 0;
}


//사용할 사용자 정의 함수 정의
void InitQueue(Queue* pqueue)
{
	pqueue->topindex = -1;
}

int IsEmpty(Queue* pqueue)
{
	if (pqueue->topindex == -1) return TRUE;
	else return FALSE;
}

int CalSize(Queue* pqueue)
{
	return pqueue->topindex + 1;
}

int IsFull(Queue* pqueue)
{
	if (CalSize(pqueue) >= QUEUESIZE) return TRUE;
	else return FALSE;
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
	int pop = pqueue->aArray[0];
	for (int i = 0; i < CalSize(pqueue) - 1; ++i)
	{
		pqueue->aArray[i] = pqueue->aArray[i + 1];
	}
	--(pqueue->topindex);
	//aArray[0]은 임시 저장해 두고, 요소들의 인덱스를 1씩 줄인다.

	return pop;
}

void DFS(int V) //깊이 우선 탐색 구현
{
	if (checked[V]) return;
	checked[V] = TRUE;
	printf("%d ", V);
	for (int i = 0; i < 10000; ++i)
	{
		int y = connection[V][i];
		if (y == 9999) return; //인접 노드 배열의 9999는 무시
		DFS(y);
	}
}

void BFS(int V)
{
	Queue q;
	InitQueue(&q);
	Push(&q, V);
	checked[V] = TRUE;
	while (!IsEmpty(&q))
	{
		int x = Pop(&q);
		printf("%d ", x);
		for (int i = 0; i < 10000; ++i)
		{
			int y = connection[x][i];
			if (y == 9999) continue; //인접 노드 배열의 9999는 무시
			if (!checked[y])
			{
				Push(&q, y);
				checked[y] = TRUE;
			}
		}
	}
}

int compare(const void* a, const void* b)    //qsort를 위한 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

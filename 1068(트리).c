#include <stdio.h>
#include <stdlib.h>

//C언어만 사용한 코딩입니다. C++은 최대한 사용하지 않았습니다.
//지워진 노드는 DELETED, 리프 노드가 아닌 노드는 NOTLEAF로
//치환하고 전체에서 두 경우를 제외한 노드들만 리프 노드로 카운트하는
//방식으로 코딩했습니다.

#define DELETED -100
#define NOTLEAF -200

typedef struct node* pnode; //node 포인터
typedef struct node {
	int name;
	int parentname;
	pnode parent;
}node;

node aNode[51];

void Deletenode(pnode aNode, int deletenum, int N);
void Notleaf(pnode aNode, int N);
int Countleaf(pnode aNode, int N);

int main(void)
{
	//노드 설정

	int N;
	scanf("%d", &N);
	fgetc(stdin);

	for (int i = 0; i < N; ++i) //노드 이름은 0부터 시작
	{
		aNode[i].name = i;
	}

	int num;

	//트리 구조 형성

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &(aNode[i].parentname)); //부모 노드 이름 입력
		fgetc(stdin); //버퍼 지우기
		if (aNode[i].parentname == -1)
			aNode[i].parent = NULL;
		else
		{
			num = aNode[i].parentname;
			aNode[i].parent = &aNode[num]; //부모 관계 형성
		}
	}

	//문제 조건에 맞는 리프 노드 구별
	int deletenum;
	scanf("%d", &deletenum);
	
	Deletenode(aNode, deletenum, N); //지운 노드는 DELETED으로 치환하여 구별
	Notleaf(aNode, N); //리프 노드가 아닌 노드는 NOTLEAF로 치환하여 구별

	int nCount = Countleaf(aNode, N); //DELETED도 NOTLEAF도 아닌 노드 갯수 도출
	
	//출력
	printf("%d", nCount);

	return 0;
}


//사용자 정의 함수 정의
void Deletenode(pnode aNode, int deletenum, int N)
{
	aNode[deletenum].name = DELETED;
	for (int i = 0; i < N; ++i)
	{
		if (&aNode[deletenum] == aNode[i].parent)
			Deletenode(aNode, i, N);
	}

	return;
}

void Notleaf(pnode aNode, int N)
{
	for (int i = 0; i < N; ++i)
	{
		if (aNode[i].name != DELETED) //지운 노드가 아니라면
		{
			for (int j = 0; j < N; ++j)
			{
				if ((aNode[j].parent == &(aNode[i])) && (aNode[j].name != DELETED))
					aNode[i].name = NOTLEAF; //그 노드가 어떤 지워지지 않은 노드의 부모 노드라면
											 //(즉, 유효한 자식 노드가 있다면) NOTLEAF로 치환
			}
		}
	}
	return;
}

int Countleaf(pnode aNode, int N)
{
	int nCount = 0; //리프 노드의 갯수

	for (int i = 0; i < N; ++i)
	{
		if ((aNode[i].name != DELETED) && (aNode[i].name != NOTLEAF))
			++nCount;
	} //지워지지도 않았고 유효한 자식 노드도 없다면 리프 노드

	return nCount;
}

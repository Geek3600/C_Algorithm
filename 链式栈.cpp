#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//�������� ��㶨��
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *PNODE;

//ջ�������ݵĶ���
typedef struct Stack
{
	struct Node* pTop;
	struct Node* pBottom;
}STACK, *PSTACK;

void initStack(PSTACK pS);
void pushStack(PSTACK pS, int val);
void traverse(PSTACK pS);
bool pop(PSTACK pS);
void clear(PSTACK pS);

int main()
{
	STACK S;
	initStack(&S);
	pushStack(&S, 1);
	pushStack(&S, 2);
	pushStack(&S, 3);
	pushStack(&S, 4);
	pushStack(&S, 5);
	pushStack(&S, 6);
	pushStack(&S, 7);
	pushStack(&S, 5);
	pushStack(&S, 4);
	traverse(&S);
	pop(&S);
	printf("\n");
	traverse(&S);
	clear(&S);
	printf("\n");
	traverse(&S);
	return 0;
}


//��ʼ��ջ����������ջ����ջ��
void initStack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}

// ѹջ������ͷ�巨��ӽ�㡣
// ע�⣺ջ�����������ͷ������ջ��ָ���Ѿ�
//       �����������ͷ��㣬�������������ٸ�������һ��ͷ���
//       ÿ���¼�����ʱ��ջ��ָ���ֵ��Ҫ���и���
void pushStack(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

// ����ջ�����������
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d", p->data);
		p = p->pNext;
	}
}

// ��ջ������ջ�����ԣ�ÿ�ζ�ֻ�ܵ���ͷ��㣬�����ܵ�������Ľ��
bool pop(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)// �ж�ջ�Ƿ�Ϊ��
	{
		return false;
	}
	else
	{
		PNODE p = pS->pTop;
		pS->pTop = p->pNext;
		free(p);
		return true;
	}
}

// ��������߱������ͷ��ڴ�
void clear(PSTACK pS)
{
	
	if (pS->pBottom == pS->pTop)
	{
		return;
	}
	else
	{
		
		PNODE p = pS->pTop;
		while (pS->pTop != pS->pBottom)
		{
			pS->pTop = p->pNext;
			free(p);
			p = pS->pTop;
		}
	}
}
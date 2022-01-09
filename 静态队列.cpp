#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Queue 
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

void init(QUEUE * pQ);
bool en_queue(QUEUE* pQ, int val);
void traverse_queue(QUEUE* pQ);

int main()
{
	QUEUE Q;
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	traverse_queue(&Q);
	return 0;

}

void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->rear = pQ->front = 0;
}

bool en_queue(QUEUE* pQ, int val)
{
	if ((pQ->rear + 1) % 6 == pQ->front)// ÅÐ¶ÏÊÇ·ñÒÑÂú
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
	}
}

void traverse_queue(QUEUE* pQ)
{
	int i;
	i = pQ->front;
	while (i != pQ->rear)
	{
		printf("%d", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
}
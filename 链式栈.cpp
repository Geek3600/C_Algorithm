#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//链表类型 结点定义
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE, *PNODE;

//栈类型数据的定义
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


//初始化栈，即：创建栈顶和栈底
void initStack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败！");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}

// 压栈操作，头插法添加结点。
// 注意：栈顶处是链表的头，由于栈顶指针已经
//       储存了链表的头结点，所以我们无需再给链表创建一个头结点
//       每次新加入结点时，栈顶指针的值都要进行更新
void pushStack(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

// 遍历栈（链表）并输出
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d", p->data);
		p = p->pNext;
	}
}

// 出栈，由于栈的特性，每次都只能弹出头结点，而不能弹出任意的结点
bool pop(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)// 判断栈是否为空
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

// 清空链表，边遍历边释放内存
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
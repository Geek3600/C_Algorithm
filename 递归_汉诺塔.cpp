#include<stdio.h>

void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("%c -> %c\n", A, C);
	}
	else
	{
		hanoi(n - 1,A, C, B);
		printf("%c -> %c\n", A, C);
		hanoi(n - 1, B, A, C);
	}

}
int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入要移动的盘子数: ");
	scanf_s("%d", &n);

	hanoi(n, 'A', 'B', 'C');

}


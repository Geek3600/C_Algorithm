#include<stdio.h>
/* �׳˵�ѭ������
int main() 
{
	int val;
	int i, mult = 1;
	printf("������һ������");
	printf("val = ");
	scanf_s("%d", &val);

	for (i = 1; i <= val; i++)
	{
		mult = mult * i;
	}
	printf("%d", mult);
	return 0;

}
*/

long f(long n)
{ 
	if (n == 1)
	{	
		return 1;
	}
	else
	{
		return f(n - 1) + n;
	}

}

int main()
{
	printf("%d", f(4));
}


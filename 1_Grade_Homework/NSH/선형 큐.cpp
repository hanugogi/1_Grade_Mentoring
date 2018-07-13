#include <stdio.h>
#define SIZE 10

int Q[SIZE];
int front = -1, rear = -1;
int OUT[SIZE*SIZE];
int last = 0; 

void get()
{
	if(front==rear)
	{
		printf("UNDER FLOW!\n");
	}
	else
		OUT[last++] = Q[++front];
}

void put(int num)
{
	if(rear-front == SIZE)
	{
		printf("OVER FOLW!\n");
	}
	else
	{
		rear++;
		Q[rear] = num;
	}
}

int main()
{
	printf("=============================================\n");
	printf("put�� �����Է�, get�� 9999�Է�, ����� 00�Է�\n");
	printf("=============================================\n");
	int num = 1;
	while(num!=00)
	{
		printf("�Է�: ");
		scanf("%d", &num);
		if(num==9999)
			get();
		else
			put(num);	
	
	printf("ť: ");
	for(int i = front + 1; i<=rear; i++)
	{
		printf("%d ", Q[i]);
	}
	putchar('\n'); 
	printf("������ ��: ");
	for(int i=0;i<last;i++)
	{
		printf("%d ", OUT[i]);
	}
	putchar('\n');
	}
}

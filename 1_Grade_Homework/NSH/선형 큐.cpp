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
	printf("put은 숫자입력, get은 9999입력, 종료는 00입력\n");
	printf("=============================================\n");
	int num = 1;
	while(num!=00)
	{
		printf("입력: ");
		scanf("%d", &num);
		if(num==9999)
			get();
		else
			put(num);	
	
	printf("큐: ");
	for(int i = front + 1; i<=rear; i++)
	{
		printf("%d ", Q[i]);
	}
	putchar('\n'); 
	printf("나오는 수: ");
	for(int i=0;i<last;i++)
	{
		printf("%d ", OUT[i]);
	}
	putchar('\n');
	}
}

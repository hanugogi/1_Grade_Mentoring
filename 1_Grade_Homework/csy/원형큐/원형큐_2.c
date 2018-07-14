#include<stdio.h>
#define SIZE 16 // 원형큐의 실제 칸 개수 (사용자가 실제로 쓸 수 있는 데이터 공간은 SIZE-1)  

int data[SIZE];
int front=SIZE-1; //front:출구 
int rear=SIZE-1; //rear: 입구 
int output[SIZE*SIZE];
int i,cnt;

void push(int n)
{
	if((rear+1)%SIZE==front)
	{
		printf("overflow\n\n");
	}
	else
	{
		rear=(rear+1)%SIZE;
		data[rear]=n;
	}
}

void pop()
{
	if(rear==front)
	{
		printf("underflow\n\n");
	}
	else
	{
		front=(front+1)%SIZE;
		output[i++] = data[front];
		cnt++;
		//return data[front];
	}	
}

void screen()
{	
	printf("Q:");
	for(i=rear;i<front;i++)
	{
		printf("%-3d",data[i]);
	}
	printf("\n");
	
	printf("Get:");
	for(i=0;i<cnt;i++)
	{
		printf("%-3d",output[i]);
	}
}

main()
{
	int n;
	
	while(1)
	{
		printf("pop은 99999 종료는 44444\n");
		scanf("%d",&n); 
	
		if(n==99999)
		{
			pop();
			screen();
		}
		else if(n==44444)
		{
			break;
		}
		else
		{
			push(n);
			screen();
		}
	}
}

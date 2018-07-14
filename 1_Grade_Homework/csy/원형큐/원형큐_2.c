#include<stdio.h>
#define SIZE 16 // ����ť�� ���� ĭ ���� (����ڰ� ������ �� �� �ִ� ������ ������ SIZE-1)  

int data[SIZE];
int front=SIZE-1; //front:�ⱸ 
int rear=SIZE-1; //rear: �Ա� 
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
		printf("pop�� 99999 ����� 44444\n");
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

#include<stdio.h>
#define SIZE 15 //SIZE�� 15�� �ʱ�ȭ 

int input[SIZE];
int output[SIZE*SIZE];
int front =0;
int rear=0;

void put(int n) // ť�� ������ ���� 
{
	if(input[rear]!='\0')
	{
		printf("overflow~~!!\n");	
	}
	else
	{
		input[rear]=n;
		rear++;
		if(rear>=SIZE)
		{
			rear=0;
		}
	}

} 

void get() //ť�� ������ ��� ��� 
{
	if(input[front]=='\0')
	{
		printf("underflow~~!!\n");
	}
	else
	{
		output[front]=input[front];
		input[front]='\0';
		front++;
		if(front==SIZE)
		{
			front=0;
		}
	}
}

void screen()
{
	int i;
	
	printf("Q:");
	for(i=front;i<SIZE;i++)
	{
		if(input[i]!='\0')
		printf("%-2d",input[i]);
	}
	if(front>=rear)
	{
		for(i=0;i<rear;i++)
		{
			printf("%-3d",input[i]);
		}
	}
	printf("\n");
	
	printf("get:");
	for(i=0;i<front;i++)
	{
		printf("%-2d",output[i]);
	}
	printf("\n\n\n");
}

main() //put&get ť�� ������ ���� �� �̿� 
{
	int n;
	
	while(1)
	{
		printf("--------------------------------------------------\n");
		printf("\t\tget�� 99999�Դϴ�\n");
		printf("\t\t����� 44444�Դϴ�\n");
		printf("--------------------------------------------------\n");
	
		scanf("%d",&n);
	
		if(n==99999)
		{
			get();
			screen();
			
		}
		else if(n==44444)
		{
			break;
		}
		else
		{
			put(n);
			screen();
		}
	}
}

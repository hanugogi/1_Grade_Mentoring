#include<stdio.h>
#define SIZE 10 //SIZE�� 10���� �����Ѵ�.

int stack[SIZE];//stack�迭 ����(ũ�� 10) 
int top = -1;//stack�� ���κ� 
int output[SIZE*SIZE];//pop�Ǵ� ���ڸ� ������ �迭 
int out = -1;//output�迭�� ���κ� 
void pop()
{
	if(top==SIZE-SIZE-1)//�� �̻� pop�� ���� ���� ��� 
	{
		printf("UNDER FLOW!\n");//under flow��� 
	}
	else
	{
		output[++out]=stack[top--];/*output�� ���κ��� 1���� ��Ű�� �� ���� stack�� ���κ��� �����Ѵ�. 
		stack�� ���� 1���� ��Ų��.	*/
	}
}

void push(int num)//�Է�(����)  ���� ���ڸ� num�� ���� 
{
	if(top>=SIZE - 1)//stack�� ������ �Ѿ ��� 
		printf("OVERFLOW!\n");//over flow ��� 
	else//stack�� ������ ���� ��� 
		stack[++top] = num;//top(stack�� ��)�� 1���� ��Ű�� ���ڸ� �����Ѵ�. 
}

void print()
{
	printf("stack: ");	
	for(int i=0;i<=top;i++)
	{
		printf("%d ", stack[i]); //stack�迭�� ����ִ� ���� ������� ��� 
	}
	putchar('\n');
	printf("output is: ");
	for(int i=0;i<=out;i++)
	{
		printf("%d ", output[i]);//���ݱ��� pop�� ���ڵ��� ���ʴ�� ��� 
	}
	putchar('\n');
	putchar('\n'); 
}

void explain()//stack ��� ����� �����ϴ� �Լ� 
{
	printf("==========================\n");
	printf("push�� ���� �Է�\n");
	printf("pop�� 9999\n");
	printf("����� 8888�Դϴ�.\n");
	printf("==========================\n"); 
}
int main()
{
	int input;//���ڸ� �Է¹��� ���� ���� 
	explain();//stack ���� ����
	while(1)
	{ 
		printf("�Է�: ");
		scanf("%d", &input);//���ڸ� �Է� ����  
		if(input!=9999&&input!=8888)//�Է��� ���ڸ� push�� ��� 
		{
			push(input);//�Է¹��� ���ڸ� push 
			print();//���� stack�� ���¸� ��� 
		}
		else if(input==9999)//pop�� ��� 
		{
			pop();//���� ������(top)�� ���� ���� pop 
			print();//���� stack�� ���¸� ��� 
		}
		else//���α׷� ���� 
			break;
	}	
}

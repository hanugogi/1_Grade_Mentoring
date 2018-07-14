#include<stdio.h> //���α׷��� ���� ������� ���� 
#define SIZE 10 //SIZE�� 10���� ���� 

int output[SIZE*SIZE]; //����� �ִ������ SIZE*SIZE�� ����  
int input[SIZE]; //�Է� & stack�� ������ SIZE�� ����  
int top=-1; //stack�� ���� ũ��(=��ġ)�� -1�� �ʱ�ȭ 
int bottom=0; //stack�� ��°����� 0���� �ʱ�ȭ 

void push(int n) //n�� �޾Ƽ� stack���ٰ� push�ϴ� �Լ� 
{
	if(top==SIZE-1) // ���� top�� SIZE-1(=9)��� ���̻� �Է��� ���� �� ���� 
	{
		printf("overflow~!!\n"); //overflow~~!!��� ����� �Ͽ� overflow���� �˸� 
	}
	else //top�� SIZE-1(=9)�� �ƴ϶�� 
	{
		top++; //top�� 1�������Ѽ� stack�� ���� ũ��(=��ġ)�� ��ĭ ������Ŵ 
		input[top]= n;//top��ġ�� n�� �Է¹��� 
	}
}

void pop() //stack���ٰ� pop�� �ϴ� �Լ� 
{
	if(top==-1) //���� top�� -1�̶�� ���̻� ����� �� �� ���� 
	{
		printf("underflow~!!\n"); //underflow~~!!��� ��� �Ͽ� underflow���� �˸� 
	}
	else //top�� -1�� �ƴ϶�� 
	{
		output[bottom]=input[top]; //bottom��ġ�� ��¿� ���� top��ġ�� �Է��� ���� 
		top--; //top�� 1���ҽ��Ѽ� stack�� ���� ũ��(=��ġ)�� �� ĭ ���ҽ�Ŵ   
		bottom++; //bottom���� 1�������Ѽ� ���� �迭�� ���� �� �ְ� �� 
	}
}

void screen()
{
	int i; //�ݺ����� 
	
	printf("stack["); //stack�̶�� ��� 
	for(i=0;i<=top;i++) //i�� 0���� �ʱ�ȭ�ϰ� top���� i�� 1�� �����ϸ鼭 �ݺ�  
	{
		printf("%-3d",input[i]); //����� i�迭�� ��� 
	}
	printf("]\n"); //]�� ����ϰ� �� �� ���� 
	
	printf("output"); //output�� ��� 
	for(i=0;i<bottom;i++) //i�� 0���� �ʱ�ȭ�ϰ� bottom������ i�� 1�� �����ϸ鼭 �ݺ� 
	{
		printf("%-3d",output[i]); //����� i�迭�� ��� 
	}
	printf("\n\n\n");//3�� ��� 
}

main()
{
	int n; //������� �� 

	while(1) //���ѹݺ� 
	{	
		printf("--------------------------------------------------\n");
		printf("\t\tpop�� 99999�Դϴ�\n");
		printf("\t\t����� 44444�Դϴ�\n");
		printf("--------------------------------------------------\n");
		scanf("%d",&n); //������� ��(=n)�� �Է� ���� 
	
		if(n==99999) //���� n�� 99999�̶�� 
		{
			pop(); //pop�Լ� ���� 
			screen(); //screen�Լ� ���� 
		}
		else if(n==44444) //���� n�� 44444�̶�� 
		{
			break; //break�������� ���α׷� ����(=���ѹݺ��� ��������) 
		}
		else //�ƴ϶�� 
		{
			push(n); //push�Լ��� ���� 
			screen(); //screen�Լ� ���� 
		}
	}
}

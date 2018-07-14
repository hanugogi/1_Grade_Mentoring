#include<stdio.h>
#define SIZE 10 //SIZE를 10으로 선언한다.

int stack[SIZE];//stack배열 선언(크기 10) 
int top = -1;//stack의 끝부분 
int output[SIZE*SIZE];//pop되는 숫자를 저장할 배열 
int out = -1;//output배열의 끝부분 
void pop()
{
	if(top==SIZE-SIZE-1)//더 이상 pop할 값이 없을 경우 
	{
		printf("UNDER FLOW!\n");//under flow출력 
	}
	else
	{
		output[++out]=stack[top--];/*output의 끝부분을 1증가 시키고 그 곳에 stack의 끝부분을 대입한다. 
		stack의 끝을 1감소 시킨다.	*/
	}
}

void push(int num)//입력(전달)  받은 숫자를 num에 저장 
{
	if(top>=SIZE - 1)//stack의 범위를 넘어갈 경우 
		printf("OVERFLOW!\n");//over flow 출력 
	else//stack의 공간이 있을 경우 
		stack[++top] = num;//top(stack의 끝)을 1증가 시키고 숫자를 저장한다. 
}

void print()
{
	printf("stack: ");	
	for(int i=0;i<=top;i++)
	{
		printf("%d ", stack[i]); //stack배열에 들어있는 값을 순서대로 출력 
	}
	putchar('\n');
	printf("output is: ");
	for(int i=0;i<=out;i++)
	{
		printf("%d ", output[i]);//지금까지 pop된 숫자들을 차례대로 출력 
	}
	putchar('\n');
	putchar('\n'); 
}

void explain()//stack 사용 방법을 설명하는 함수 
{
	printf("==========================\n");
	printf("push는 숫자 입력\n");
	printf("pop은 9999\n");
	printf("종료는 8888입니다.\n");
	printf("==========================\n"); 
}
int main()
{
	int input;//숫자를 입력받을 변수 선언 
	explain();//stack 사용법 설명
	while(1)
	{ 
		printf("입력: ");
		scanf("%d", &input);//숫자를 입력 받음  
		if(input!=9999&&input!=8888)//입력한 숫자를 push할 경우 
		{
			push(input);//입력받은 숫자를 push 
			print();//현재 stack의 상태를 출력 
		}
		else if(input==9999)//pop할 경우 
		{
			pop();//가장 마지막(top)에 들어온 값을 pop 
			print();//현재 stack의 상태를 출력 
		}
		else//프로그램 종료 
			break;
	}	
}

#include<stdio.h> //프로그램에 쓰인 헤더파일 선언 
#define SIZE 10 //SIZE를 10오로 선언 

int output[SIZE*SIZE]; //출력의 최대범위를 SIZE*SIZE로 선언  
int input[SIZE]; //입력 & stack의 범위를 SIZE로 선언  
int top=-1; //stack의 값의 크기(=위치)를 -1로 초기화 
int bottom=0; //stack의 출력갯수를 0으로 초기화 

void push(int n) //n을 받아서 stack에다가 push하는 함수 
{
	if(top==SIZE-1) // 만약 top이 SIZE-1(=9)라면 더이상 입력을 받을 수 없음 
	{
		printf("overflow~!!\n"); //overflow~~!!라고 출력을 하여 overflow임을 알림 
	}
	else //top이 SIZE-1(=9)이 아니라면 
	{
		top++; //top을 1증가시켜서 stack의 값의 크기(=위치)를 한칸 증가시킴 
		input[top]= n;//top위치에 n을 입력받음 
	}
}

void pop() //stack에다가 pop을 하는 함수 
{
	if(top==-1) //만약 top이 -1이라면 더이상 출력을 할 수 없음 
	{
		printf("underflow~!!\n"); //underflow~~!!라고 출력읋 하여 underflow임을 알림 
	}
	else //top이 -1이 아니라면 
	{
		output[bottom]=input[top]; //bottom위치에 출력에 현재 top위치에 입력을 넣음 
		top--; //top을 1감소시켜서 stack의 값의 크기(=위치)를 한 칸 감소시킴   
		bottom++; //bottom값을 1증가시켜서 다음 배열에 넣을 수 있게 함 
	}
}

void screen()
{
	int i; //반복변수 
	
	printf("stack["); //stack이라고 출력 
	for(i=0;i<=top;i++) //i를 0으로 초기화하고 top까지 i를 1씩 증가하면서 반복  
	{
		printf("%-3d",input[i]); //출력의 i배열을 출력 
	}
	printf("]\n"); //]을 출력하고 한 줄 내림 
	
	printf("output"); //output를 출력 
	for(i=0;i<bottom;i++) //i를 0으로 초기화하고 bottom전까지 i를 1씩 증가하면서 반복 
	{
		printf("%-3d",output[i]); //출력의 i배열을 출력 
	}
	printf("\n\n\n");//3줄 띄움 
}

main()
{
	int n; //사용자의 값 

	while(1) //무한반복 
	{	
		printf("--------------------------------------------------\n");
		printf("\t\tpop는 99999입니다\n");
		printf("\t\t종료는 44444입니다\n");
		printf("--------------------------------------------------\n");
		scanf("%d",&n); //사용자의 값(=n)을 입력 받음 
	
		if(n==99999) //만약 n이 99999이라면 
		{
			pop(); //pop함수 실행 
			screen(); //screen함수 실행 
		}
		else if(n==44444) //만약 n이 44444이라면 
		{
			break; //break실행으로 프로그램 종료(=무한반복을 빠져나옴) 
		}
		else //아니라면 
		{
			push(n); //push함수를 실행 
			screen(); //screen함수 실행 
		}
	}
}

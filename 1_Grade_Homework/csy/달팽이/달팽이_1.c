#include<stdio.h>

int main()
{
	int ary[100][100]; //ary이라는 배열을 100x100의 크기로 설정 
	int y=0,x=-1,direction=1,p,q,size,num=1,limit; //arrow=방향,p와q는 반복변수,size은 크기,limit은 남은 반복숫자,num은 숫자,x는 y보다 하나씩 많으므로 x를 -1으로 설정  
	
	do //do while문으로 입력을 먼저받고 숫자가 100초과일경우 반복한다. 
	{ 
		printf("100이하의 숫자를 입력하세요: "); //배열의 크기가 100x100이므로 100이하의 숫자를 입력해야한다. 
		scanf("%d",&size); //사용자가 원하는 크기의 숫자를 입력한다. 
	}while(size>100); //萱微� 100을 초과할 경우 다시 입력을 받는다.  
	
	limit=size; //사용자가 받은 숫자(size)을 limit에 대입한다. 
	
	while(limit!=0) //limit가 0일때까지 반복을 한다. 
	{
		for(p=0;p<limit;p++) //반복변수(p)가 limit만큼 증가할때까지(1씩증가) 반복한다. 
		{
			x+=direction; //[direction가 1일때] 1씩 증가하면서 오른쪽으로 배열을 이동 [direction가 -1일때] -1씩 감소하면서 왼쪽으로 배열을 이동 
			ary[y][x]=num; //이동한 배열에 숫자를 입력 
			num++; //숫자는 1씩 증가한다. 
		}
		limit--; //x로 배열이동한두 ㅣ숫자를 입력하고나면 limit를 1씩 감소한다. 
		for(p=0;p<limit;p++) //limit가 0일때까지 반복한다. 
		{
			y+=direction; //[direction가 1일때] 1씩 증가하면서 아래쪽으으로 배열을 이동 [direction가 -1일때] -1씩 감소하면서 위쪽으로 배열을 이동
			ary[y][x]=num; //이동한 배열에 숫자를 입력 
			num++;//숫자는 1씩 증가한다. 
		}
		direction*=-1; //두개의 반복문이 끝나면 -1을 곱하여 방향을 바꾸어 준다.(1은 -1로 -1은 1로) 
	}
	for(p=0;p<size;p++)//size만큼 반복 
	{
		for(q=0;q<size;q++) //size만큼 반복 
		{
			printf("%-5d",ary[p][q]); //출력
		}
		printf("\n");//한줄이 끝나면 줄 바꿈 
	}
	}

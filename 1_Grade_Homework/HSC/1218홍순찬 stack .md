#include <stdio.h>
#define Max_Size 10

	int stack[Max_Size]; //값 10개가 들어갈 수 있는 스택 크기 선언 
	int out_Put [Max_Size*Max_Size]; // pop의 범위 선언 
	int top = -1; 
	int out = 0;
	 
	
int Push(int PUT){	//입력받은 put값을 stack에 넣어주는 함수 
	
	if(top>=Max_Size-1){
		printf("----------Over_Flow---------\n");//top가 스택에 최대값이랑 같거나 클경우 오버플로우를 출력 
	}
	
	else{//top을 ++해주고 스택에 put값을 넣어준다. 
		top++;
		stack[top] = PUT ;
	}
}

int Pop(){ //stack에 쌓여있던 값을 빼주고 out_Put에 넣어준다. 
	
	if(top==-1){
		printf("----------Under_Flow----------\n");//top이 -1일 될경우 언더 플로우 출력  
	}
	else{
		out++;
		top--;
		out_Put[out]=stack[top+1];
	}
}

int print(){
	int i;	//for문에 쓰일 i 선언  
	printf("Stack");	//push를 해주었을 때 담기는 부분  
	for(i=0; i<=top; i++)	//top보다 작거나 같으면 스택을 출력 
	{	
		printf("\t%d .|\t%d\t|\n", i, stack[i]);
	}
	printf("out_put  :");
	
	for(i = 0; i <= out; i++){
		if(out_Put[i]!=0)
			printf("%d ", out_Put[i]); //out보다력 작으면 output된 값들을 출 
	}
}

int main(void)  //프로그램을 실행 시키는 부분  
{    
    printf("---------------------------------------------------\n");  //49~53까지는 시작전 설명 
    printf("|                 STACK START                     |\n");
    printf("|                pop은 1입니다                    |\n");                                                
    printf("|     프로그램을 종료하고 싶은면 0을 입력하세요   |\n");
    printf("---------------------------------------------------\n");    
    
    print();
    int put;    //넣을 값은 선언 해주는 부분  
    
    while(1)
    {
        printf("\n들어온 값은:");
        scanf("%d", &put);        //넣을 값을 받는 부분 
        if(put != 0 && put != 1)    //pop(1)이나 프로그램 종료(0)이 아닐경우 stack에 값을 넣는다. 
        {
            Push(put);
            print();
        }
        
        if(put == 0)    //0이 들어올 경우 프로그램 종료   
        {
            break;
        }
            
        if(put == 1)    //1이 들어올 경우 pop 
        {
            Pop();
            print();
        }
   } 
    
    return 0;
}
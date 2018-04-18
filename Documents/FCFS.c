#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Work_Q 10  //작업큐의 크기
#define Redy_Q 10  //준비큐의 크기
#define Result_Q 10  //결과 작성을위한 리스트

typedef struct pcb{    //PCB 구조체 원형
 struct pcb *next;   //다음 구조체를 가르키는 포인터
 char p_state[10];   //상태를 저장할 공간
 int p_count;    //프로세서 ID
 int arrive_time;   //존비큐로 도착할 시간
 int bust_time;    //실행될 시간
 int excute_time;   //실행되는 시간을 보여줄 값
 int wait_time;    //실행되기까지 대기할 시간
}PCB;

int All_time=0;      //전체 시스템이 작업하는 시간
int total_wait_time=0;    //대기시간이 누적되는 값
int total_exe_time=0;    //전체 실행시간이 누적되는 값
int response_time=0;    //반응시간
PCB *Work_head;      //각각 리스트의 헤드와 테일들
PCB *Work_tail;
PCB *Ready_head;
PCB *Ready_tail;
PCB *Result_head;
PCB *Result_tail;

/*도스명령어로 화면을 지움.*/
void clrscr(void)  
{

   system("cls");  

}

void init_Work_Q()     //작업큐의 초기화
{
 Work_head = (PCB *) malloc (sizeof (PCB));
 Work_tail = (PCB *) malloc (sizeof (PCB));
 Work_head->next=Work_tail;
 Work_tail->next=Work_tail;
}

void insert_Ready_Q(PCB *t);
void insert_result_Q(PCB *s);

/*작업큐에있는 프로세서들의 리스트를 만들고 초기화*/
void insert_Work_Q(int procount,int time,int burst) 
{
 PCB *s; 

 s=(PCB*)malloc(sizeof(PCB));

 s->p_count=procount;
 s->arrive_time=time;
 s->bust_time=burst;
 s->excute_time=0;
 s->wait_time=0;
 
 strcpy(s->p_state,"대기");


 s->next=Work_head->next;
 Work_head->next=s; 
}

/*프로세스들 시간에 따라 잡업큐에서 레디큐로 이동 */
void delete_Work_Q(int time) 
{

 PCB *s;
 PCB *p;
 p=Work_head;
 s=p->next;

 while(s!=Work_tail)
 {
  if(s->arrive_time==time)
  {
   
   p->next=s->next;
   
   insert_Ready_Q(s);
   clrscr();
   printf("\n\n\n\n\n\n\n------------------프로세스 PID %d Ready-Queue 도착  arrived time : %d-------------\n\n ",s->p_count,s->arrive_time);
   printf("\n                          다음 페이지.......<Enter>\n");
   getchar();
  }
  p=p->next;
  s=p->next;
 } 

}

/*작업큐에있는 내용들을 프린트 한다
(디버깅용으로 사용했음, 프로그램에서 안쓰임)*/
void print_Work_Q()     
{
 PCB *s;
 s=Work_head->next;
 printf("작업큐에있는 프로세스들 :\n");
 while(s!=Work_tail)
 {
  printf("PID= %d   ",s->p_count);
  s=s->next;
 }
 printf("\n");
}

/*준비큐의 초기화*/
void init_Ready_Q()   
{
 Ready_head = (PCB *) malloc (sizeof (PCB));
 Ready_tail = (PCB *) malloc (sizeof (PCB));
 Ready_head->next=Ready_tail;
 Ready_tail->next=Ready_tail;
}

/*준비큐에 들어온 순서에 따라 큐의 뒤에 배치
(큐의 앞부분이 처리되고 새로들어온 순서에따라
큐의 뒤로가서 연결된다 ,처리는 앞부터한다) */
void insert_Ready_Q(PCB *r) 
{       
 PCB *s;     
 PCB *p;
 p=Ready_head;
 s=p->next;
 while(s!=Ready_tail)
 {
  p=p->next;
  s=p->next;
 }
 r->next=s;
 p->next=r;
}

/*준비큐를 돌면서 버스트와 실행시간이 같아진것을 링크에서 삭제한다.*/
int delete_Ready_Q()
{
 PCB *s;
 PCB *p;
 p=Ready_head;
 s=p->next;
 
 while(s->bust_time!=s->excute_time&&s!=Ready_tail)
 {
  p=p->next;          
  s=p->next;
 }
 
 p->next=s->next; //s를 링크에서 뺀다
 
 /*링크에서 삭제된 PCB는 출력을 위한정보를 할당받고 
 출력을 위한 링크로 삽입된다. */
 if(s!=Ready_tail)     
 {         
  
  strcpy(s->next->p_state,"실행");
  clrscr();
  printf("\n\n\n\n\n\n\n********************************* PID %d 종료 됨*********************************\n\n\n",s->p_count);
  printf("\n                          다음 페이지.......<Enter>\n");
  getchar();
  strcpy(s->p_state,"종료");
  total_wait_time=total_wait_time+s->wait_time; //대기 시간을 축척한다
  total_exe_time=total_exe_time+s->excute_time;   //실행 시간을 축척한다.
  response_time=response_time+ s->wait_time + s->bust_time;    //반응 시간의 합 
  insert_result_Q(s);

  /*모든 프로세서들이 종료되었을 경우 0을 리턴하여 main()에서 결과를 출력하게 한다.*/
  if(Ready_head->next==Ready_tail)  
  {
   return 0;
  }
 }
 return 1;
}

/*레디큐의 PCB들을  프린트 한다. */
void print_Ready_Q()             
{
 PCB *s;
 PCB *p;
 s=Ready_head->next;
 p=Result_head->next;

 clrscr();
 printf("===============================================================================\n");
 printf("===========================시스템 진행 시간  <<%d>>============================\n",All_time-1);
 printf("===============================================================================\n\n");
 printf("PID\t  arrived time\t burst time\t wait time\t excute time\t state\n");
 while(s!=Ready_tail)
 {
  printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %s\n",s->p_count,s->arrive_time,s->bust_time,s->wait_time,s->excute_time,s->p_state);
  s=s->next;
 }
 while(p!=Result_tail)  //종료된 PCB 까지 프린트하여 한눈에 알아볼수있도록한다.  
 {
  printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %s\n",p->p_count,p->arrive_time,p->bust_time,p->wait_time,p->excute_time,p->p_state);   
  p=p->next;
 }
 printf("\n\n");
}

/*결과값을 출력할 리스트의 초기화 */
void init_Result_Q()   
{
 Result_head = (PCB *) malloc (sizeof (PCB));
 Result_tail = (PCB *) malloc (sizeof (PCB));
 Result_head->next=Result_tail;
 Result_tail->next=Result_tail;
}

/*결과값을 출력할 리스트의 삽입*/
void insert_result_Q(PCB *s) 
{ 
 s->next=Result_head->next;
 Result_head->next=s;    
}


/*문맥이 내용이 바뀔때마다 데이터를 업데이트 함(교수님의 강의의 dispatcher를
조금 다르게 구현했음..문맥교환이 아닌 PCB구조체의 업데이트중심)*/
void dispatcher() 
{     
 PCB *s;   
 s=Ready_head->next;
 
 s->excute_time=s->excute_time+1;
 strcpy(s->p_state,"실행");
 
 s=s->next;
 while(s!=Ready_tail)
 {

  s->wait_time=s->wait_time+1;
  s=s->next;
 }
}

/*결과 값리스트를 출력하기위한 함수(종료된 프로세스를 출력한다)*/
void printresult() 
{     

 PCB *p;
 int a=0; 
 int b=0;
 p=Result_head->next;

 clrscr();
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<모든 프로세스 종료>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
 while(p!=Result_tail)
 {
  printf("PID=%d\t  arrived=%d\t  burst=%d\t  wait=%d\t  excute=%d  state=%s\n",p->p_count,p->arrive_time,p->bust_time,p->wait_time,p->excute_time,p->p_state);  
  p=p->next;
 }
 printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

 
 printf("\n\n\t\t프로스세 갯수 : %d\t 시스템 진행 시간 :%d\t \n\t\t평균 대기 시간 :%.3f\t반응 시간 :%.3f \n\n",Work_Q,All_time-1,(float)total_wait_time/Work_Q,(float)response_time/Work_Q);

}

 


void main()
{
 int i=0;        //메인함수에서 필요한 각종 데이터 초기화
 int time=0;
 int Resultprint=1;
 init_Work_Q();
 init_Ready_Q();
 init_Result_Q();
 int timeData[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ;  //arrived time data 
 int executionTime[10] = {10, 4, 3, 6, 10, 4, 2, 5, 2, 10} ; //burst time data

 /*작업큐에 arrived time 과 burst time을 초기화 하고  작업큐를 만든다*/
 for(i=0;i<Work_Q;i++)      
 {           
  insert_Work_Q(i,timeData[i],executionTime[i]);
 }


 while(1)  //while문 하나가 시간 1에 해당한다.
 {
  All_time++;     //전체 시스템이 돌아 가는 시간
  delete_Work_Q(time++);  //arrived_tinme이 되면 작업큐에서 레디큐로 옮기는 함수
  dispatcher();    //시간에 따른 업데이트를 하는 함수
 
  Resultprint=delete_Ready_Q(); //프로세스가 종료되면 준비큐에서 삭제 하는 함수  
          // 리턴값이 0이면 모든프로세스가 종료된것임 
 
  print_Ready_Q(); //준비큐에있는 내용을 프린트 한다.
 
  if(Resultprint==0)  //준비큐가 비어있으면  순환문을끝내고 ,
  {      //결과 값을 프린트 하도록 한다.
   break;
  }

  printf("\n                          다음 페이지.......<Enter>\n");
  getchar();  //한페이지씩 보여주기 위해 캐릭터 하나를 받는다.
  clrscr();  //화면을 지우고 업데이트 할수있도록 한다.
 }
 printresult();  //스케쥴러가 종료되기전 모든 정보를 표시한다.
 scanf("%d",&i);  //엔터를 막치다가 그냥 끝내버리는 것을  방지하기위해..사용
}

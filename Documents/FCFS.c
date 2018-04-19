#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Work_Q 10  //�۾�ť�� ũ��
#define Redy_Q 10  //�غ�ť�� ũ��
#define Result_Q 10  //��� �ۼ������� ����Ʈ

typedef struct pcb{    //PCB ����ü ����
 struct pcb *next;   //���� ����ü�� ����Ű�� ������
 char p_state[10];   //���¸� ������ ����
 int p_count;    //���μ��� ID
 int arrive_time;   //����ť�� ������ �ð�
 int bust_time;    //����� �ð�
 int excute_time;   //����Ǵ� �ð��� ������ ��
 int wait_time;    //����Ǳ���� ����� �ð�
}PCB;

int All_time=0;      //��ü �ý����� �۾��ϴ� �ð�
int total_wait_time=0;    //���ð��� �����Ǵ� ��
int total_exe_time=0;    //��ü ����ð��� �����Ǵ� ��
int response_time=0;    //�����ð�
PCB *Work_head;      //���� ����Ʈ�� ���� ���ϵ�
PCB *Work_tail;
PCB *Ready_head;
PCB *Ready_tail;
PCB *Result_head;
PCB *Result_tail;

/*������ɾ�� ȭ���� ����.*/
void clrscr(void)  
{

   system("cls");  

}

void init_Work_Q()     //�۾�ť�� �ʱ�ȭ
{
 Work_head = (PCB *) malloc (sizeof (PCB));
 Work_tail = (PCB *) malloc (sizeof (PCB));
 Work_head->next=Work_tail;
 Work_tail->next=Work_tail;
}

void insert_Ready_Q(PCB *t);
void insert_result_Q(PCB *s);

/*�۾�ť���ִ� ���μ������� ����Ʈ�� ����� �ʱ�ȭ*/
void insert_Work_Q(int procount,int time,int burst) 
{
 PCB *s; 

 s=(PCB*)malloc(sizeof(PCB));

 s->p_count=procount;
 s->arrive_time=time;
 s->bust_time=burst;
 s->excute_time=0;
 s->wait_time=0;
 
 strcpy(s->p_state,"���");


 s->next=Work_head->next;
 Work_head->next=s; 
}

/*���μ����� �ð��� ���� ���ť���� ����ť�� �̵� */
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
   printf("\n\n\n\n\n\n\n------------------���μ��� PID %d Ready-Queue ����  arrived time : %d-------------\n\n ",s->p_count,s->arrive_time);
   printf("\n                          ���� ������.......<Enter>\n");
   getchar();
  }
  p=p->next;
  s=p->next;
 } 

}

/*�۾�ť���ִ� ������� ����Ʈ �Ѵ�
(���������� �������, ���α׷����� �Ⱦ���)*/
void print_Work_Q()     
{
 PCB *s;
 s=Work_head->next;
 printf("�۾�ť���ִ� ���μ����� :\n");
 while(s!=Work_tail)
 {
  printf("PID= %d   ",s->p_count);
  s=s->next;
 }
 printf("\n");
}

/*�غ�ť�� �ʱ�ȭ*/
void init_Ready_Q()   
{
 Ready_head = (PCB *) malloc (sizeof (PCB));
 Ready_tail = (PCB *) malloc (sizeof (PCB));
 Ready_head->next=Ready_tail;
 Ready_tail->next=Ready_tail;
}

/*�غ�ť�� ���� ������ ���� ť�� �ڿ� ��ġ
(ť�� �պκ��� ó���ǰ� ���ε��� ����������
ť�� �ڷΰ��� ����ȴ� ,ó���� �պ����Ѵ�) */
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

/*�غ�ť�� ���鼭 ����Ʈ�� ����ð��� ���������� ��ũ���� �����Ѵ�.*/
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
 
 p->next=s->next; //s�� ��ũ���� ����
 
 /*��ũ���� ������ PCB�� ����� ���������� �Ҵ�ް� 
 ����� ���� ��ũ�� ���Եȴ�. */
 if(s!=Ready_tail)     
 {         
  
  strcpy(s->next->p_state,"����");
  clrscr();
  printf("\n\n\n\n\n\n\n********************************* PID %d ���� ��*********************************\n\n\n",s->p_count);
  printf("\n                          ���� ������.......<Enter>\n");
  getchar();
  strcpy(s->p_state,"����");
  total_wait_time=total_wait_time+s->wait_time; //��� �ð��� ��ô�Ѵ�
  total_exe_time=total_exe_time+s->excute_time;   //���� �ð��� ��ô�Ѵ�.
  response_time=response_time+ s->wait_time + s->bust_time;    //���� �ð��� �� 
  insert_result_Q(s);

  /*��� ���μ������� ����Ǿ��� ��� 0�� �����Ͽ� main()���� ����� ����ϰ� �Ѵ�.*/
  if(Ready_head->next==Ready_tail)  
  {
   return 0;
  }
 }
 return 1;
}

/*����ť�� PCB����  ����Ʈ �Ѵ�. */
void print_Ready_Q()             
{
 PCB *s;
 PCB *p;
 s=Ready_head->next;
 p=Result_head->next;

 clrscr();
 printf("===============================================================================\n");
 printf("===========================�ý��� ���� �ð�  <<%d>>============================\n",All_time-1);
 printf("===============================================================================\n\n");
 printf("PID\t  arrived time\t burst time\t wait time\t excute time\t state\n");
 while(s!=Ready_tail)
 {
  printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %s\n",s->p_count,s->arrive_time,s->bust_time,s->wait_time,s->excute_time,s->p_state);
  s=s->next;
 }
 while(p!=Result_tail)  //����� PCB ���� ����Ʈ�Ͽ� �Ѵ��� �˾ƺ����ֵ����Ѵ�.  
 {
  printf("%d\t %d\t\t %d\t\t %d\t\t %d\t\t %s\n",p->p_count,p->arrive_time,p->bust_time,p->wait_time,p->excute_time,p->p_state);   
  p=p->next;
 }
 printf("\n\n");
}

/*������� ����� ����Ʈ�� �ʱ�ȭ */
void init_Result_Q()   
{
 Result_head = (PCB *) malloc (sizeof (PCB));
 Result_tail = (PCB *) malloc (sizeof (PCB));
 Result_head->next=Result_tail;
 Result_tail->next=Result_tail;
}

/*������� ����� ����Ʈ�� ����*/
void insert_result_Q(PCB *s) 
{ 
 s->next=Result_head->next;
 Result_head->next=s;    
}


/*������ ������ �ٲ𶧸��� �����͸� ������Ʈ ��(�������� ������ dispatcher��
���� �ٸ��� ��������..���Ʊ�ȯ�� �ƴ� PCB����ü�� ������Ʈ�߽�)*/
void dispatcher() 
{     
 PCB *s;   
 s=Ready_head->next;
 
 s->excute_time=s->excute_time+1;
 strcpy(s->p_state,"����");
 
 s=s->next;
 while(s!=Ready_tail)
 {

  s->wait_time=s->wait_time+1;
  s=s->next;
 }
}

/*��� ������Ʈ�� ����ϱ����� �Լ�(����� ���μ����� ����Ѵ�)*/
void printresult() 
{     

 PCB *p;
 int a=0; 
 int b=0;
 p=Result_head->next;

 clrscr();
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<��� ���μ��� ����>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
 printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
 while(p!=Result_tail)
 {
  printf("PID=%d\t  arrived=%d\t  burst=%d\t  wait=%d\t  excute=%d  state=%s\n",p->p_count,p->arrive_time,p->bust_time,p->wait_time,p->excute_time,p->p_state);  
  p=p->next;
 }
 printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

 
 printf("\n\n\t\t���ν��� ���� : %d\t �ý��� ���� �ð� :%d\t \n\t\t��� ��� �ð� :%.3f\t���� �ð� :%.3f \n\n",Work_Q,All_time-1,(float)total_wait_time/Work_Q,(float)response_time/Work_Q);

}

 


void main()
{
 int i=0;        //�����Լ����� �ʿ��� ���� ������ �ʱ�ȭ
 int time=0;
 int Resultprint=1;
 init_Work_Q();
 init_Ready_Q();
 init_Result_Q();
 int timeData[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ;  //arrived time data 
 int executionTime[10] = {10, 4, 3, 6, 10, 4, 2, 5, 2, 10} ; //burst time data

 /*�۾�ť�� arrived time �� burst time�� �ʱ�ȭ �ϰ�  �۾�ť�� �����*/
 for(i=0;i<Work_Q;i++)      
 {           
  insert_Work_Q(i,timeData[i],executionTime[i]);
 }


 while(1)  //while�� �ϳ��� �ð� 1�� �ش��Ѵ�.
 {
  All_time++;     //��ü �ý����� ���� ���� �ð�
  delete_Work_Q(time++);  //arrived_tinme�� �Ǹ� �۾�ť���� ����ť�� �ű�� �Լ�
  dispatcher();    //�ð��� ���� ������Ʈ�� �ϴ� �Լ�
 
  Resultprint=delete_Ready_Q(); //���μ����� ����Ǹ� �غ�ť���� ���� �ϴ� �Լ�  
          // ���ϰ��� 0�̸� ������μ����� ����Ȱ��� 
 
  print_Ready_Q(); //�غ�ť���ִ� ������ ����Ʈ �Ѵ�.
 
  if(Resultprint==0)  //�غ�ť�� ���������  ��ȯ���������� ,
  {      //��� ���� ����Ʈ �ϵ��� �Ѵ�.
   break;
  }

  printf("\n                          ���� ������.......<Enter>\n");
  getchar();  //���������� �����ֱ� ���� ĳ���� �ϳ��� �޴´�.
  clrscr();  //ȭ���� ����� ������Ʈ �Ҽ��ֵ��� �Ѵ�.
 }
 printresult();  //�����췯�� ����Ǳ��� ��� ������ ǥ���Ѵ�.
 scanf("%d",&i);  //���͸� ��ġ�ٰ� �׳� ���������� ����  �����ϱ�����..���
}

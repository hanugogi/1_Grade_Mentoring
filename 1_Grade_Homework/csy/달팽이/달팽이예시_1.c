#include <stdio.h>

 

int main()
{

int ary[50][50];
int n, z, i, j, x=0, y=-1, turn=1;

int num=1;

 

printf("숫자입력 : ");
scanf("%d",&n);

z=n;

while(z!=0)
{

for(i=0; i<z; i++)

{

y+=turn;
ary[x][y]=num;
num++;

}

 

z--;

 

for(i=0; i<z; i++)
{

x+=turn;
ary[x][y]=num;
num++;

}

 

turn*=-1;


}

 

for(i=0; i<n; i++)
{

for(j=0; j<n;j++)
{

printf("%5d",ary[i][j]);

}

printf("\n");

}

 

return 0;

}

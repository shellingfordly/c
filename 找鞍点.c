#include <stdio.h>
#include<stdlib.h>
#define N 5
#define M 5
int main(void)
{
	int i,j,b=1,k,flag=0,jmax,sp,a[N][M]={0};
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			//a[i][j]=rand()%100+1;
			a[i][j]=b;
			printf("%-3d",a[i][j]);
			b++;
		}
		printf("\n");
	}	
	
	for(i=0;i<N;i++)
	{
		for(j=1;j<M;j++)
		{
			sp=a[i][0];
			if(sp<a[i][j])
			{
				sp=a[i][j];
				jmax=j;
				flag=1;
			}
		}
		for(k=0;k<N;k++)
		{
			if(sp>a[k][jmax])
			{
				flag=0;
			}
		}
		if(flag)
		{
			//输出便退出
			printf("%d行%d列的数%d\n",i,jmax,sp);
			break;
		}
	}	
	//如果最后一个数不是鞍点，也就是满足上面的sp>a[k][jmax]，此时flag会被赋予=0
	//因此当i==N时，也就是全部循环都已经跑完，依然没有退出循环，则输出没有
	//if(flag==0)
	if(i==N)
	{
		printf("没有");
	}
}

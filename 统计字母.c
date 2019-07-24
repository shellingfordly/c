#include<stdio.h>
#include<string.h> 
#define N 5
int main(void)
{
	有问题的！ 
	int a[N]={0},*p;
	int i,j,flag=0;
	int b[N][2]={0};
	
	for(i=0;i<5;i++)
	{	//一开始写成了：scanf("%d",a); 只有第一个a[0]有数据，并且是输入的最后一个数据 
		scanf("%d",&a[i]);
		printf("%d",a[i]);
	} 
	/*
	for(p=a;p-a<5;p++)
	{	
		scanf("%d",p);
		printf("%d",*p);
	}*/
	
	b[0][0]=a[0];
	printf("\n未写入的数组b：\n");
	for(i=0;b[i][0]!=0;i++)
	{
		for(j=0;j<2;j++)
			printf("%-2d",b[i][j]);
		printf("\n");	
	}
	
	
	for(i=0;a[i]!=0;i++)
	{
		//printf("\n进入了循环");
		flag=0;	
		for(j=0;j<N;j++)
		{
			if(a[i]==b[j][0])
			{
				//printf("%d",a[i]);
				b[j][1]++;
				break;
			}
		}	
		if(j==N)
		{
			for(j=0;j<N;j++)
				if(b[j][0]==0)
				{
					b[j][0]=a[i];
					b[j][1]++;
					break;
				}	
		}
	}  
	
	printf("\n打印数组b：\n");
	for(i=0;b[i][0]!=0;i++)
	{
		for(j=0;j<2;j++)
			printf("%-2d",b[i][j]);
		printf("\n");	
	}	
	return 0; 
}


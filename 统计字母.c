#include<stdio.h>
#include<string.h> 
#define N 5
int main(void)
{
	������ģ� 
	int a[N]={0},*p;
	int i,j,flag=0;
	int b[N][2]={0};
	
	for(i=0;i<5;i++)
	{	//һ��ʼд���ˣ�scanf("%d",a); ֻ�е�һ��a[0]�����ݣ���������������һ������ 
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
	printf("\nδд�������b��\n");
	for(i=0;b[i][0]!=0;i++)
	{
		for(j=0;j<2;j++)
			printf("%-2d",b[i][j]);
		printf("\n");	
	}
	
	
	for(i=0;a[i]!=0;i++)
	{
		//printf("\n������ѭ��");
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
	
	printf("\n��ӡ����b��\n");
	for(i=0;b[i][0]!=0;i++)
	{
		for(j=0;j<2;j++)
			printf("%-2d",b[i][j]);
		printf("\n");	
	}	
	return 0; 
}


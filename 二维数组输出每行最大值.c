#include<stdio.h>
#include<stdlib.h>
#define N 5
#define M 6 
int main(void)
{
	int a[N][M]={0};
	int i=0,j=0; 
	int b[N]={0};
	printf("数组a的值\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			a[i][j]=rand()%20+1;
			printf("%-4d",a[i][j]);
			if(a[i][j]>b[i])
				b[i]=a[i][j];
		}
		printf("\n");
	}
	printf("每行最大值：\n");
	for(i=0;i<N;i++)
		printf("%d\n",b[i]);

	return 0;
} 

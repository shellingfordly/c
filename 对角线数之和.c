#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(void)
{
	int a[N][N],i,j,p_sum=0,n_sum=0;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=rand()%20+1;
			printf("%-5d",a[i][j]);
			if(i==j)
			{
				p_sum+=a[i][j];
			}
			if(i+j==N-1)
			{
				n_sum+=a[i][j];
			}
		}
		printf("\n");
	}
	printf("正对角线数之和为:%3d\n负对角线数之和为:%3d",p_sum,n_sum);
}
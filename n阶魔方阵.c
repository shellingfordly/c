#include <stdio.h>
#include <string.h>
#define N 7
int main(void)
{
	int i=0,j=0,k=0,a[N][N]={0};
	
	j=N/2;
	a[i][j]=1;
	
	for(k=2;k<=N*N;k++)
	{
		i=i-1;
		j=j+1;
		if(i<0&&j==N)
		{
			i=i+2;
			j=j-1;
		}
		else
		{
			if(i<0)i=N-1;
			if(j==N)j=0;
		}
		if(a[i][j]==0)a[i][j]=k;
		else
		{
			i=i+2;
			j=j-1;
			a[i][j]=k;
		}
	}
	
	//打印
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}

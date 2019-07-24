#include <stdio.h>
#define N 17
int main(void)
{
	/*
		m --圈数
		n --数组a的阶
		k --每一圈显示的数
		a --存放数据的数组，最多到9圈
	*/
	int m,n,k,i,j,a[N][N]={0};
	
	printf("输入回形矩阵的圈数(1-9)：");
	scanf("%d",&m);
	k=m;
	n=m*2-1;
	for(i=0;i<m;i++)
	{
		//每一圈上层的元素
		for(j=i;j<n-i;j++)
			a[i][j]=k;
		//每一圈右层的元素
		for(j=i+1;j<n-i;j++)
			a[j][n-i-1]=k;
		//下层元素
		for(j=n-i-2;j>=i;j--)
			a[n-i-1][j]=k;
		//左层元素
		for(j=n-i-2;j>i;j--)
			a[j][i]=k;
		k--;
	}
	
	//打印数组
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%-2d",a[i][j]);
		}
		printf("\n");
	}
}
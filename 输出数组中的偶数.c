#include<stdio.h>
#define N 20 
int main(void)
{
	int a[N]={0},b[N]={0};
	int i=0,j=0,n=0;
	
	printf("输入要输入的值的个数：");
	scanf("%d",&n);
	printf("a的值：");
	while(i<n)
	{
		scanf("%d", a+i);	
		i++;
	} 
	//一开始这里给的判断条件是 a!=0;然而a输入了值之后就没有等于0的值，因此做了一些奇怪的循环 
	for(i=0;i<n;i++)
	{	
		if(a[i]%2==0)
		{
			b[j]=a[i];
			j++;
		}	
	}
	
 	
 	printf("b中的值：");
	for(i=0;i<n;i++)
	{
		if(b[i]==0) break;
		printf("%-4d",b[i]); 
	}	
	printf("\n");

	return 0;
}

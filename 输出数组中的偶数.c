#include<stdio.h>
#define N 20 
int main(void)
{
	int a[N]={0},b[N]={0};
	int i=0,j=0,n=0;
	
	printf("����Ҫ�����ֵ�ĸ�����");
	scanf("%d",&n);
	printf("a��ֵ��");
	while(i<n)
	{
		scanf("%d", a+i);	
		i++;
	} 
	//һ��ʼ��������ж������� a!=0;Ȼ��a������ֵ֮���û�е���0��ֵ���������һЩ��ֵ�ѭ�� 
	for(i=0;i<n;i++)
	{	
		if(a[i]%2==0)
		{
			b[j]=a[i];
			j++;
		}	
	}
	
 	
 	printf("b�е�ֵ��");
	for(i=0;i<n;i++)
	{
		if(b[i]==0) break;
		printf("%-4d",b[i]); 
	}	
	printf("\n");

	return 0;
}

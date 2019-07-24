#include <stdio.h>
int main(void)
{
	int i,max=0,a;
	
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a);
		//不打印a就只能输出五次，i却打印为10，奇怪
		printf("%d\n",a);
		if(max<a) max=a;
	}
	printf("%d",i);
	//printf("%d",max);
	
	return 0;
}

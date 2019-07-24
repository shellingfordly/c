#include <stdio.h>
int main(void)
{
	int i,min=0,a;
	scanf("%d",&a);
	min=a;
	for(i=0;i<9;i++)
	{
		scanf("%d",&a);
		//不打印a就只能输出五次，i却打印为10，奇怪,最小值输出这边也是一样
		printf("%d\n",a);
		if(min>a) min=a;
	}
	//printf("%d",i);
	printf("%d",min);
	
	return 0;
}
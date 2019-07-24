#include <stdio.h>
int main(void)
{
	double a;
	//a=getchar();
	scanf("%lf",&a);
	switch(a)
	{
		case "8.5":printf("1\n");
		//为什么这里的default语句也打印出来了
		//没有break.....
		default:printf("%d",a);
	}
}

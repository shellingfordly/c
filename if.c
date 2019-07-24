#include <stdio.h>
int main(void)
{
	int a=3,b=4,c=5,t=0;
	if(a>b)
	  if(b>c)
	    printf("1");
	else printf("2");
	//此时else属于最近的一个if，并不会因为缩进看上去属于第一个
}

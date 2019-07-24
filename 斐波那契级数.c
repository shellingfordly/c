#include <stdio.h>
int main(void)
{
	int i,a,b,c,temp;
	a=b=1;
	printf("%7d%7d",a,b);
	temp=2;
	for(i=0;i<28;i++)
	{
		c=a+b;
		printf("%7d",c);
		temp++;
		if(temp%6==0)printf("\n");
		a=b;
		b=c;
	}
}

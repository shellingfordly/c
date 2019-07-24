#include <stdio.h>
int main(void)
{
	int i=1,n=1,fac=1,sum=0;
	
	for(;n<=20;)
	{
		do
		{
			fac=fac*i;
			i++;
		}while(i<=n);
		sum=sum+fac;
		n++;
	}
	printf("sum=%d",sum);
}

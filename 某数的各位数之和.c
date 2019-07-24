#include <stdio.h>
int main(void)
{
	int a,sum=0,n;
	scanf("%d",&a);
	while(a>0)
	{
		n=a%10;
		sum+=n;
		a/=10;
	}
	printf("%d",sum);
}

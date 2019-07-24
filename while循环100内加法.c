#include <stdio.h>
int main(void)
{
	int i,j,one=0,sum=0;
	
	i=1;
	while(i<=100)
	{
		j=1;
		while(j<=i)
		{
			one=one+j;
			j++;
		}
		i++;
		sum = sum + one;
	}
	printf("%d",sum);
}
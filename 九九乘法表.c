#include <stdio.h>
int main(void)
{
	int i=1;
	for(;i<10;i++)
	{
		int j=1;
		for(;j<=i;j++)
		{
			printf("%d*%d=%d\t",j,i,j*i);
		}
		printf("\n");
	}
	
	
}
#include <stdio.h>
int main(void)
{
	int i,sign;
	double sum=0;
	sign=1;
	
	/*
	//1-1/2+1/3-...-1/100
	for(i=1;i<=100;i++)
	{
		sum=sum+sign*1.0/i;
		sign=-sign;
		//printf("%lf\n",sum);
	}
	
	*/
	
	//1/2-1/4+1/6-...-1/100
	for(i=2;i<=100;i=i+2)
	{
		sum=sum+sign*1.0/i;
		sign=-sign;
		//printf("%lf\n",sum);
	}
	
	
	printf("%lf",sum);
}
#include <stdio.h>
#include <math.h>
int main(void)
{
	double pai=1,sign=-1;
	int i=3;
	
	//fabs(a); a的绝对值
	//1e-4  10的-4次方
	//while(fabs(sign/i)>=1e-4)
	while(fabs(sign/i)>=1e-7)
	{
		pai=pai+(double)sign/i;
		i=i+2;
		sign=-sign;
	}
	printf("%lf",pai*4);
	
}
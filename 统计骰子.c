#include <stdio.h>
#include <math.h>
#include <time.h>
int main(void)
{
	int b[6][2]={0},a,i,j;

	printf("a的值\n");
	srand(time(0));
	for(i=0;i<100;i++)
	{
		//书中说需要加入此条语句，保证产生的随机数独立，然后我加入之后a的每个值都一样，不知道是不是手机允许的原因
		//原因：此句不应该放在这里
		//srand(time(0));
		a=rand()%6+1;
		printf("%-2d",a);
		
		/*
		//用if判断
		if(i==0)
		{
			b[i][i]=a;
			b[i][i+1]++;
			continue;
		}
		for(j=0;j<6;j++)
		{
			if(a==b[j][0])
			{
				b[j][1]++;
				break;
			}
		}
		if(j==6)
		{
			for(j=0;j<6;j++)
			{
				if(b[j][0]==0)
				{
					b[j][0]=a;
					b[j][1]++;
					break;
				}
			}
		}*/
		
		
		//用switch判断
		switch(a)
		{
			case 1: b[0][1]++;break;
			case 2: b[1][1]++;break;
			case 3: b[2][1]++;break;
			case 4: b[3][1]++;break;
			case 5: b[4][1]++;break;
			case 6: b[5][1]++;break;
			default:printf("a值异常");break;
		}
	}
	
	printf("\n出现的次数\n");
	for(i=0;i<6;i++)
	{
		//用switch判断时要写入1-6的值
		//用if时不需要此句，要注释掉
		b[i][0]=i+1;
		for(j=0;j<2;j++)
		{
			printf("%-2d",b[i][j]);
		}
		printf("\n");
	}
}

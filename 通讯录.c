#include <stdio.h>
#define N 2
int main(void)
{
	int i;
	char num[N][5]={0};
	char name[N][5]={0};
	char tel[N][5]={0};
	
	for(i=0;i<N;i++)
	{
		printf("第%d条记录\n",i+1);
		printf("学号");
		gets(num[i]);
		printf("姓名");
		gets(name[i]);
		printf("电话");
		gets(tel[i]);
	}
	printf("\n学号   姓名   电话\n");
	for(i=0;i<N;i++)
	{
		
		printf("%-7s%-7s%-7s",num[i],name[i],tel[i]);
		printf("\n");
	}
	
}

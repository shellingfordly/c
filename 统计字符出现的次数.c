#include<stdio.h>
#define N 10
int main(void)
{
	char a[N]={'\0'},*p=a;
	char b[N]={0};
	int c[N]={0};
	int i=0,j=0,k=0; 
	printf("输入字符串：\n");
	gets(a);
	//puts(a);
	
	/*
	//检查c的初始值是不是全为0 
	printf("c的初始值"); 
	for(i=0;i<N;i++)
		printf("%d",c[i]);
	*/
	
	//开始循环，检查a中字符
	for(i=0;a[i]!='\0';i++)
	{
		//进入b字符数组的循环，检查a中输入的值是否出现过 
		for(j=0;j<N;j++)
		{
			if(b[j]==a[i])
			{
				//出现过，次数加一	
				c[j]++;
				//查看c值的变化 
				//printf("再次出现值%d\n",c[j]);
				break;
			}	
		}	
		//跑完循环，说明没有出现过，在b中添加字符 
		if(j==N)
		{	
			for(j=0;j<N;j++)
			{
				//检查b中没有写入的位置，添加新字符，并且次数加一 
				if(b[j]==0)
				{
					b[j]=a[i];
					c[j]++; 
					//查看b和c的值的变化 
					//printf("b值为：%c\t c的值%d\n",b[j],c[j]);	
					break;	
				}	
			}
		}
	}
	
	//puts(b);
	
	printf("每个字符出现的次数"); 
	for(i=0;i<N;i++)
		if(b[i]!=0)
			printf("%c%3d\n",b[i],c[i]);

	return 0;
} 

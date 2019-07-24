#include<stdio.h> 
#define N 26 
int main(void)
{
	//N给的10，但是我输入14个字母却记录下来了 
	//即使我给a[3]也一样，不管输入多少个字符，a依然记录下来了 
	char a[]={'\0'},*p=a;
	//N决定了b数值能存入多少个不同字符，N取26使每个字母都可以被统计 
	char b[N][2]={0};
	int i=0,j=0; 
	printf("输入字符串：\n");
	gets(a);
	puts(a);
	
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
			if(b[j][0]==a[i])
			{
				//出现过，次数加一	
				b[j][1]++;
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
				if(b[j][0]==0)
				{
					b[j][0]=a[i];
					b[j][1]++; 
					//查看b和c的值的变化 
					//printf("b值为：%c\t c的值%d\n",b[j],c[j]);	
					break;	
				}	
			}
		}
	}
	
	//puts(b);
	
	printf("每个字符出现的次数：\n"); 
	for(i=0;i<N;i++)
		if(b[i][0]!=0)
			printf("%c%3d\n",b[i][0],b[i][1]);

	return 0;
} 

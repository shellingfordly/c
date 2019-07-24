#include<stdio.h>
int main(void)
{
	char a[]={'\0'},b[]={0};
	int i=0,j=0;
	
	gets(a);
	printf("a的值：");
	puts(a);
	 
	for(i=0;a[i]!='\0';i++)
	{
		//判断a中的字符是否在a-z之间，是才赋给b啊
		//但是输出的b却有大写字母，奇怪 
		if(a[i]>='a' && a[i]<='z')
		{
			//printf("%c\n",a[i]);
			b[j]=a[i];
			printf("%c\n",b[j]);
			j++;
		}	
	}
	
 	
 	printf("b中的值：");
	puts(b);
	/*for(i=0;b[i]!='\0';i++)
		printf("%c",b[i]); 
	printf("\n");
	*/
	return 0;
}

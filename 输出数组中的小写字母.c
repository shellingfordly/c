#include<stdio.h>
int main(void)
{
	char a[]={'\0'},b[]={0};
	int i=0,j=0;
	
	gets(a);
	printf("a��ֵ��");
	puts(a);
	 
	for(i=0;a[i]!='\0';i++)
	{
		//�ж�a�е��ַ��Ƿ���a-z֮�䣬�ǲŸ���b��
		//���������bȴ�д�д��ĸ����� 
		if(a[i]>='a' && a[i]<='z')
		{
			//printf("%c\n",a[i]);
			b[j]=a[i];
			printf("%c\n",b[j]);
			j++;
		}	
	}
	
 	
 	printf("b�е�ֵ��");
	puts(b);
	/*for(i=0;b[i]!='\0';i++)
		printf("%c",b[i]); 
	printf("\n");
	*/
	return 0;
}

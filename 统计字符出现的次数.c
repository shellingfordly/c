#include<stdio.h>
#define N 10
int main(void)
{
	char a[N]={'\0'},*p=a;
	char b[N]={0};
	int c[N]={0};
	int i=0,j=0,k=0; 
	printf("�����ַ�����\n");
	gets(a);
	//puts(a);
	
	/*
	//���c�ĳ�ʼֵ�ǲ���ȫΪ0 
	printf("c�ĳ�ʼֵ"); 
	for(i=0;i<N;i++)
		printf("%d",c[i]);
	*/
	
	//��ʼѭ�������a���ַ�
	for(i=0;a[i]!='\0';i++)
	{
		//����b�ַ������ѭ�������a�������ֵ�Ƿ���ֹ� 
		for(j=0;j<N;j++)
		{
			if(b[j]==a[i])
			{
				//���ֹ���������һ	
				c[j]++;
				//�鿴cֵ�ı仯 
				//printf("�ٴγ���ֵ%d\n",c[j]);
				break;
			}	
		}	
		//����ѭ����˵��û�г��ֹ�����b������ַ� 
		if(j==N)
		{	
			for(j=0;j<N;j++)
			{
				//���b��û��д���λ�ã�������ַ������Ҵ�����һ 
				if(b[j]==0)
				{
					b[j]=a[i];
					c[j]++; 
					//�鿴b��c��ֵ�ı仯 
					//printf("bֵΪ��%c\t c��ֵ%d\n",b[j],c[j]);	
					break;	
				}	
			}
		}
	}
	
	//puts(b);
	
	printf("ÿ���ַ����ֵĴ���"); 
	for(i=0;i<N;i++)
		if(b[i]!=0)
			printf("%c%3d\n",b[i],c[i]);

	return 0;
} 

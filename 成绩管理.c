#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#define N 10 
void myPrint();
void myCreate(int a[]);
void myDisplay(int *p);
void mySearch(int *p);
void myMax(int a[]);
void myAdd(int *p);
void mydelete(int *p);
void mySort(int *p);
int myLength(int *p);

int main(void)
{
	char choose='\0',yes_no='\0';
	int a[N+1]={100,99,88,77,66,55,44,33,22,11},goCount=1;
	
	do
	{
		if(goCount)
			myPrint(); //�˵�
		goCount=0;
		printf("\n����ѡ��(0-7)��"); 
		choose=getche();
		switch(choose)
		{
			case '1': myCreate(a); break; //���� 
			case '2': myDisplay(a); break; //��ʾ 
			case '3': mySearch(a); break; //��ѯ 
			case '4': myMax(a); break; //��ֵ 
			case '5': myAdd(a); break; //���� 
			case '6': mydelete(a); break; //ɾ�� 
			case '7': mySort(a); break; //���� 
			case '0': exit(0);
			default : printf("%cΪ�Ƿ�ѡ�\n",choose); 
		}
		printf("�Ƿ����ѡ��(Y/N)?");
		do
		{
			//printf("1");
			yes_no=getche();
		}while(yes_no!='y' && yes_no!='Y' && yes_no!='n' && yes_no!='N');
	}while(yes_no=='Y'||yes_no=='y'); 
	return 0;
} 

void myPrint()
{
	
	printf("\n     |------------------------|\n");
	printf("     |-----������ѡ����-----|\n");
	printf("     |------------------------|\n");
	printf("     |-----1������------------|\n");
	printf("     |-----2����ʾ------------|\n");
	printf("     |-----3������------------|\n");
	printf("     |-----4����ֵ------------|\n");
	printf("     |-----5������------------|\n");
	printf("     |-----6��ɾ��------------|\n");
	printf("     |-----7������------------|\n");
	printf("     |-----0���˳�------------|\n");
	printf("     |------------------------|\n");
	
}

void myCreate(int a[])
{
	int i=0,*p=NULL;
	printf("\n����ɼ���");
	for(p=a;p-a<N;p++)
		scanf("%d",p);
} 

void myDisplay(int *p)
{
	int i=0,length;
	length=myLength(p);
	printf("\n���гɼ���");
	for(;i<length;i++)
		//if(*(p+i)!=0)
			printf("%-4d",*(p+i));
	printf("\n");
}

void mySearch(int *p)
{
	int i=0,s;
	printf("\n����Ҫ���ҵĳɼ���");
	scanf("%d",&s);
	for(;i<N+1;i++)
	{
		if(s==*(p+i))
		{
			printf("���ҵĳɼ�Ϊ��%d\n",s);
			break;
	
		}	
	}
	if(i==N+1)
		printf("û���ҵ��˳ɼ�\n");
} 

void myMax(int a[])
{
	int i=1,k=0,max=a[0];
	for(;i<N+1;i++)
		if(max<a[i])
		{
			max=a[i];
			k=i;	
		}
					
	printf("\n��߳ɼ���%d��λ�ã�%d\n",max,k);
}

void myAdd(int a[])
{
	int i=0,x,k;
	printf("\n������Ҫ����ĳɼ���λ��(0-10):");
	scanf("%d%d",&x,&k);
	for(i=N;i>k;i--)
		a[i]=a[i-1];
	a[k]=x;
	printf("���³ɼ��ɹ�!\n");		
}

void mydelete(int *p)
{
	int i=0,d=0,flag=i,length;
	length=myLength(p);
	printf("%d",*(p+N));
	printf("\n����Ҫɾ���ĳɼ���");
	scanf("%d",&d);
	for(;i<length;i++)
		if(*(p+i)==d)
			flag=i;
	for(i=flag;i<length;i++)
		*(p+i)=*(p+i+1);	
	printf("ɾ���ɹ�\n");
}

void mySort(int *p)
{ 
	int i=0,j=0,temp=0,length,sx;
	length=myLength(p);
	printf("\n����(1)/����(0)��");
	scanf("%d",&sx);
	for(i=0;i<length;i++)
		for(j=i+1;j<length;j++)
			if(sx){
				//���� 
				if(*(p+i)>*(p+j)){	
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
				}
			}	
			else{
				//���� 
				if(*(p+i)<*(p+j)){	
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
				}
		
			}		
	/*
	//����ʾ�� 
	//��Ҫ�ı������е�����λ�ã���������k 
	for(i=0;i<length;i++)
	{	
		k=*(p+i);
		for(j=i+1;j<length;j++)
		{
			if(k>*(p+j))
			{	
				temp=k;
				k=*(p+j);
				*(p+j)=temp;
			}	
		}
	}*/
	printf("���������\n");
}

//�з���ֵ�����Ͳ�����void 
int myLength(int *p)
{
	int i=0;
	for(;i<N+1;i++)
		if(*(p+i)==0)
			return i;
	return i; 
}
 
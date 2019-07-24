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
			myPrint(); //菜单
		goCount=0;
		printf("\n输入选择(0-7)："); 
		choose=getche();
		switch(choose)
		{
			case '1': myCreate(a); break; //创建 
			case '2': myDisplay(a); break; //显示 
			case '3': mySearch(a); break; //查询 
			case '4': myMax(a); break; //最值 
			case '5': myAdd(a); break; //插入 
			case '6': mydelete(a); break; //删除 
			case '7': mySort(a); break; //排序 
			case '0': exit(0);
			default : printf("%c为非法选项！\n",choose); 
		}
		printf("是否继续选择(Y/N)?");
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
	printf("     |-----请输入选项编号-----|\n");
	printf("     |------------------------|\n");
	printf("     |-----1：输入------------|\n");
	printf("     |-----2：显示------------|\n");
	printf("     |-----3：查找------------|\n");
	printf("     |-----4：最值------------|\n");
	printf("     |-----5：插入------------|\n");
	printf("     |-----6：删除------------|\n");
	printf("     |-----7：排序------------|\n");
	printf("     |-----0：退出------------|\n");
	printf("     |------------------------|\n");
	
}

void myCreate(int a[])
{
	int i=0,*p=NULL;
	printf("\n输入成绩：");
	for(p=a;p-a<N;p++)
		scanf("%d",p);
} 

void myDisplay(int *p)
{
	int i=0,length;
	length=myLength(p);
	printf("\n所有成绩：");
	for(;i<length;i++)
		//if(*(p+i)!=0)
			printf("%-4d",*(p+i));
	printf("\n");
}

void mySearch(int *p)
{
	int i=0,s;
	printf("\n输入要查找的成绩：");
	scanf("%d",&s);
	for(;i<N+1;i++)
	{
		if(s==*(p+i))
		{
			printf("查找的成绩为：%d\n",s);
			break;
	
		}	
	}
	if(i==N+1)
		printf("没有找到此成绩\n");
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
					
	printf("\n最高成绩：%d；位置：%d\n",max,k);
}

void myAdd(int a[])
{
	int i=0,x,k;
	printf("\n请输入要插入的成绩和位置(0-10):");
	scanf("%d%d",&x,&k);
	for(i=N;i>k;i--)
		a[i]=a[i-1];
	a[k]=x;
	printf("更新成绩成功!\n");		
}

void mydelete(int *p)
{
	int i=0,d=0,flag=i,length;
	length=myLength(p);
	printf("%d",*(p+N));
	printf("\n输入要删除的成绩：");
	scanf("%d",&d);
	for(;i<length;i++)
		if(*(p+i)==d)
			flag=i;
	for(i=flag;i<length;i++)
		*(p+i)=*(p+i+1);	
	printf("删除成功\n");
}

void mySort(int *p)
{ 
	int i=0,j=0,temp=0,length,sx;
	length=myLength(p);
	printf("\n正序(1)/倒序(0)：");
	scanf("%d",&sx);
	for(i=0;i<length;i++)
		for(j=i+1;j<length;j++)
			if(sx){
				//正序 
				if(*(p+i)>*(p+j)){	
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
				}
			}	
			else{
				//倒序 
				if(*(p+i)<*(p+j)){	
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
				}
		
			}		
	/*
	//错误示范 
	//是要改变数组中的数据位置，不能另起k 
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
	printf("排序结束！\n");
}

//有返回值，类型不能是void 
int myLength(int *p)
{
	int i=0;
	for(;i<N+1;i++)
		if(*(p+i)==0)
			return i;
	return i; 
}
 
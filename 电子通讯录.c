#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//为5时添加数据会乱 
#define N 6 
#define M 10
void myPrint();
void myCreate(char num[N][M],char name[N][M],char tel[N][M]);
void myDisplay(char num[N][M],char name[N][M],char tel[N][M]);
void mySearch(char num[N][M],char name[N][M],char tel[N][M]);
void schNum(char num[N][M],char name[N][M],char tel[N][M]);
void schName(char num[N][M],char name[N][M],char tel[N][M]);
void numNull(char num[M]); 
void myModify(char num[N][M],char name[N][M],char tel[N][M]);
void myAdd(char num[N][M],char name[N][M],char tel[N][M]);
void myDelete(char num[N][M],char name[N][M],char tel[N][M]);
void delNum(char num[N][M],char name[N][M],char tel[N][M]);
void delName(char num[N][M],char name[N][M],char tel[N][M]);
void mySort(char num[N][M],char name[N][M],char tel[N][M]);
int myLength(char num[N][M]);


int main(void)
{
	char choose='\0',yes_no='\0';
	char num[N][M]={"004","002","001","005","003"},
		 name[N][M]={"111","222","333","444","555"},
		 tel[N][M]={"1111","2222","3333","4444","5555"};
	//char num[N][M]={'\0'};

	do
	{
		myPrint();
		printf("\n输入选择(0-7):");
		choose=getche();
		switch(choose)
		{
			case '1': myCreate(num,name,tel); break; //创建 
			case '2': myDisplay(num,name,tel); break; //显示 
			case '3': mySearch(num,name,tel); break; //查询 
			case '4': myModify(num,name,tel); break; //修改 
			case '5': myAdd(num,name,tel); break; //添加 
			case '6': myDelete(num,name,tel); break; //删除 
			case '7': mySort(num,name,tel); break; //排序 
			case '0': exit(0);
			default : printf("%c为非法选项！\n",choose); 	
		}
		printf("\n是否继续选择(Y/N)：");
		do{
			yes_no=getche();
		}while(yes_no!='Y'&&yes_no!='y'&&yes_no!='n'&&yes_no!='N');
	}while(yes_no=='y'||yes_no=='Y'); 
	return 0;		
} 

void myPrint()
{
	system("cls");
	printf("   ________________________________\n");
	printf("  |           电子通讯录           |\n");
	printf("  |________________________________|\n");
	printf("  |           1：创建              |\n");
	printf("  |           2：显示              |\n");
	printf("  |           3：查询              |\n");
	printf("  |           4：修改              |\n");
	printf("  |           5：添加              |\n");
	printf("  |           6：删除              |\n");
	printf("  |           7：排序              |\n");
	printf("  |           0：退出              |\n");		
	printf("  |________________________________|\n");
}

void myCreate(char num[N][M],char name[N][M],char tel[N][M])
{
	//system("cls");
	int i=0;
	printf("\n输入通讯录的记录：\n");
	do
	{
		printf("输入第%d条记录：\n",i+1);
		printf("学号："); 
		do
		{
			gets(num[i]);
			numNull(num[i]);
		//一开始我用num[i]==""无法判断，没有进入循环
		//必须使用strcmp方法 
		}while(strcmp(num[i],"")==0); 
		printf("姓名：");
		gets(name[i]);
		printf("电话：");
		gets(tel[i]); 
 		i++;
	}while(i!=N-1);
} 

void myDisplay(char num[N][M],char name[N][M],char tel[N][M])
{
	//system("cls");
	int i=0;
	printf("\n学号  姓名  电话\n");
	//for(i=0;i<N;i++)
	while(strcmp(num[i],"")!=0)
	{
		//第一次的时候数据用的''单引号、怎么输出都不对
		//字符串要用双引号 
		printf("%s   %s   %s\n",num[i],name[i],tel[i]);
		i++; 
	}			
}

void myAdd(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=1;
	char addNum[M]="",addName[M]="",addTel[M]="";
	printf("\n输入要添加的数据：\n");
	printf("学号：");
	do{
		gets(addNum);
		numNull(addNum);
	}while(strcmp(addNum,"")==0);
	printf("姓名：");
	gets(addName);
	printf("电话：");
	gets(addTel);
	
	//一开始我用for(;i<N;)但是N我已经给成了6，所以循环跑完i=6，即第七个数据 
	do
	{
		if(strcmp(addNum,num[i])==0 || strcmp(addTel,tel[i])==0)
			//记录存在，flag为0 
			flag=0;
		i++;
	}while(strcmp(num[i],"")!=0);
	if(flag){
		//记录不存在，添加 
		strcpy(num[i],addNum);
		strcpy(name[i],addName);
		strcpy(tel[i],addTel);
		//printf("%d-----%s----%s----%s",i,num[i],name[i],tel[i]);
		printf("添加成功！");
	}
	else{
		printf("已有此记录！\n");
		//重置flag为1，表示没有记录，可以添加
		//否则flag=0不管输入什么，循环一直导向这里 
		flag=1;
	}
}

void mySearch(char num[N][M],char name[N][M],char tel[N][M])
{
	//判断学号h或者姓名m是用h/m是字符判断
	//所以'\0'，否则"" 
	char sMeans='\0';
		
	printf("\n按学号(h)/姓名(m)查询：");
	sMeans=getche();
	if(sMeans=='h'||sMeans=='H')
		schNum(num,name,tel);
	else if(sMeans=='m'||sMeans=='M')
		schName(num,name,tel);
	else printf("非法字符！");

}

void schNum(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=0;
	//一开始写成char sNum=""; 
	char sNum[M]="";
	
	printf("\n输入要查询的学号：");
	gets(sNum);
	//printf("%s",sNum);
	for(i=0;i<N;i++)
	{
		//printf("查询第%d次\n",i);
		if(strcmp(sNum,num[i])==0)
		{
			printf("\n学号  姓名  电话\n");
			printf("%s   %s   %s\n",num[i],name[i],tel[i]);
			flag=1;
		}	
	}
	if(flag==0)
		printf("没有此记录！"); 
}

void schName(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=0;
	char sName[M]="";
	
	printf("\n输入要查询的姓名：");
	gets(sName);
	for(i=0;i<N;i++)
	{
		if(strcmp(sName,name[i])==0)
		{
			printf("\n学号  姓名  电话\n");
			printf("%s    %s   %s\n",num[i],name[i],tel[i]);
			flag=1;
		}	
	}
	if(!flag)
		printf("没有此记录！"); 
	
}

void mySort(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,j=0,length;
	char temp[M]="";
	length=myLength(num);	
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(strcmp(num[i],num[j])>0)
			{	
			
				strcpy(temp,num[i]);
				strcpy(num[i],num[j]);
				strcpy(num[j],temp);
			}			
	
		}
	}
/*	while(strcmp(num[i],"")!=0)
	{
		j=i+1;
		printf("进入%d循环--%s\n",i,num[i]);
		while(strcmp(num[j],"")!=0)
		{
			printf("进入二层循环%d-----\n",j,num[j]);
			//num[i]>num[j]老是忘记，字符串不能直接比较 
			if(strcmp(num[i],num[j])>0)
			{	
				
				strcpy(temp,num[i]);
				printf("%s",temp);
				strcpy(num[i],num[j]);
				strcpy(num[j],temp);
			}			
			j++;
		}
		i++;
	}
*/					
}

void myModify(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0;
	char mName[M]="";
	
	printf("\n输入要修改记录的姓名：");
	//gets写成get 
	gets(mName);
	for(i=0;i<N;i++)
		if(strcmp(mName,name[i])==0)
			break; 
	if(i<N)
	{
		printf("修改后的学号：");
		do{
			gets(num[i]); 
			numNull(num[i]);
		}while(strcmp(num[i],"")==0);
		printf("修改后的姓名：");
		gets(name[i]);
		printf("修改后的电话：");
		gets(tel[i]);
		printf("修改成功！");
	}
	else printf("没有此人！"); 
			
} 

void numNull(char num[M])
{
	//字符串的定义
	//char num[M];为数组形式
	//使用的时候直接num就行 
	if(strcmp(num,"")==0)
		printf("学号不可为空！请重新输入：");			
}

void myDelete(char num[N][M],char name[N][M],char tel[N][M])
{ 
	char dMeans='\0';
	printf("\n按学号(h)/姓名(m)删除：");
	dMeans=getche();
	if(dMeans=='h'||dMeans=='H')
		delNum(num,name,tel);		
	else if(dMeans=='m'||dMeans=='M')
		delName(num,name,tel);
	else printf("非法字符！\n");
}

void delNum(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,k=0; 
	char dNum[M]="";
	
	printf("\n输入需要删除的学号：");
	gets(dNum);
	for(i=0;i<N;i++)
	{
		if(strcmp(dNum,num[i])==0)
		{
			for(k=i;k<N-1;k++)
			{
				//字符串的复制不能直接 =
				//要用字符串方法strcpy 
				strcpy(num[k],num[k+1]);
				strcpy(name[k],name[k+1]);
				strcpy(tel[k],tel[k+1]);
			}
			//字符串只能在定义的时候赋值
			//赋空值也报错 
			//num[k]="";name[k]="";tel[k]="";
			//并且在显示函数中也不用进行判断，不输出空值
			//字符串不会输出空值'\0',"",NULL
			strcpy(num[k],"");
			strcpy(name[k],"");
			strcpy(tel[k],"");
			printf("删除成功！");
			break;
		}		
	}
	if(k==0)
		printf("查无此人!");	
}

void delName(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,k=0; 
	char dName[M]="";
	
	printf("\n输入需要删除的姓名：");
	gets(dName);
	for(i=0;i<N;i++)
	{
		if(strcmp(dName,name[i])==0)
		{
			for(k=i;k<N-1;k++)
			{
				strcpy(num[k],num[k+1]);
				strcpy(name[k],name[k+1]);
				strcpy(tel[k],tel[k+1]);
			}
			strcpy(num[k],"");
			strcpy(name[k],"");
			strcpy(tel[k],"");
			printf("删除成功！");
			break;

		}		
	}
	if(k==0)
		printf("查无此人!");	
		
}

int myLength(char num[N][M])
{
	int i=0;
	while(strcmp(num[i],"")!=0)
		i++;
	return i;
}
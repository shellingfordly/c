#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Ϊ5ʱ������ݻ��� 
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
		printf("\n����ѡ��(0-7):");
		choose=getche();
		switch(choose)
		{
			case '1': myCreate(num,name,tel); break; //���� 
			case '2': myDisplay(num,name,tel); break; //��ʾ 
			case '3': mySearch(num,name,tel); break; //��ѯ 
			case '4': myModify(num,name,tel); break; //�޸� 
			case '5': myAdd(num,name,tel); break; //��� 
			case '6': myDelete(num,name,tel); break; //ɾ�� 
			case '7': mySort(num,name,tel); break; //���� 
			case '0': exit(0);
			default : printf("%cΪ�Ƿ�ѡ�\n",choose); 	
		}
		printf("\n�Ƿ����ѡ��(Y/N)��");
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
	printf("  |           ����ͨѶ¼           |\n");
	printf("  |________________________________|\n");
	printf("  |           1������              |\n");
	printf("  |           2����ʾ              |\n");
	printf("  |           3����ѯ              |\n");
	printf("  |           4���޸�              |\n");
	printf("  |           5�����              |\n");
	printf("  |           6��ɾ��              |\n");
	printf("  |           7������              |\n");
	printf("  |           0���˳�              |\n");		
	printf("  |________________________________|\n");
}

void myCreate(char num[N][M],char name[N][M],char tel[N][M])
{
	//system("cls");
	int i=0;
	printf("\n����ͨѶ¼�ļ�¼��\n");
	do
	{
		printf("�����%d����¼��\n",i+1);
		printf("ѧ�ţ�"); 
		do
		{
			gets(num[i]);
			numNull(num[i]);
		//һ��ʼ����num[i]==""�޷��жϣ�û�н���ѭ��
		//����ʹ��strcmp���� 
		}while(strcmp(num[i],"")==0); 
		printf("������");
		gets(name[i]);
		printf("�绰��");
		gets(tel[i]); 
 		i++;
	}while(i!=N-1);
} 

void myDisplay(char num[N][M],char name[N][M],char tel[N][M])
{
	//system("cls");
	int i=0;
	printf("\nѧ��  ����  �绰\n");
	//for(i=0;i<N;i++)
	while(strcmp(num[i],"")!=0)
	{
		//��һ�ε�ʱ�������õ�''�����š���ô���������
		//�ַ���Ҫ��˫���� 
		printf("%s   %s   %s\n",num[i],name[i],tel[i]);
		i++; 
	}			
}

void myAdd(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=1;
	char addNum[M]="",addName[M]="",addTel[M]="";
	printf("\n����Ҫ��ӵ����ݣ�\n");
	printf("ѧ�ţ�");
	do{
		gets(addNum);
		numNull(addNum);
	}while(strcmp(addNum,"")==0);
	printf("������");
	gets(addName);
	printf("�绰��");
	gets(addTel);
	
	//һ��ʼ����for(;i<N;)����N���Ѿ�������6������ѭ������i=6�������߸����� 
	do
	{
		if(strcmp(addNum,num[i])==0 || strcmp(addTel,tel[i])==0)
			//��¼���ڣ�flagΪ0 
			flag=0;
		i++;
	}while(strcmp(num[i],"")!=0);
	if(flag){
		//��¼�����ڣ���� 
		strcpy(num[i],addNum);
		strcpy(name[i],addName);
		strcpy(tel[i],addTel);
		//printf("%d-----%s----%s----%s",i,num[i],name[i],tel[i]);
		printf("��ӳɹ���");
	}
	else{
		printf("���д˼�¼��\n");
		//����flagΪ1����ʾû�м�¼���������
		//����flag=0��������ʲô��ѭ��һֱ�������� 
		flag=1;
	}
}

void mySearch(char num[N][M],char name[N][M],char tel[N][M])
{
	//�ж�ѧ��h��������m����h/m���ַ��ж�
	//����'\0'������"" 
	char sMeans='\0';
		
	printf("\n��ѧ��(h)/����(m)��ѯ��");
	sMeans=getche();
	if(sMeans=='h'||sMeans=='H')
		schNum(num,name,tel);
	else if(sMeans=='m'||sMeans=='M')
		schName(num,name,tel);
	else printf("�Ƿ��ַ���");

}

void schNum(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=0;
	//һ��ʼд��char sNum=""; 
	char sNum[M]="";
	
	printf("\n����Ҫ��ѯ��ѧ�ţ�");
	gets(sNum);
	//printf("%s",sNum);
	for(i=0;i<N;i++)
	{
		//printf("��ѯ��%d��\n",i);
		if(strcmp(sNum,num[i])==0)
		{
			printf("\nѧ��  ����  �绰\n");
			printf("%s   %s   %s\n",num[i],name[i],tel[i]);
			flag=1;
		}	
	}
	if(flag==0)
		printf("û�д˼�¼��"); 
}

void schName(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,flag=0;
	char sName[M]="";
	
	printf("\n����Ҫ��ѯ��������");
	gets(sName);
	for(i=0;i<N;i++)
	{
		if(strcmp(sName,name[i])==0)
		{
			printf("\nѧ��  ����  �绰\n");
			printf("%s    %s   %s\n",num[i],name[i],tel[i]);
			flag=1;
		}	
	}
	if(!flag)
		printf("û�д˼�¼��"); 
	
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
		printf("����%dѭ��--%s\n",i,num[i]);
		while(strcmp(num[j],"")!=0)
		{
			printf("�������ѭ��%d-----\n",j,num[j]);
			//num[i]>num[j]�������ǣ��ַ�������ֱ�ӱȽ� 
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
	
	printf("\n����Ҫ�޸ļ�¼��������");
	//getsд��get 
	gets(mName);
	for(i=0;i<N;i++)
		if(strcmp(mName,name[i])==0)
			break; 
	if(i<N)
	{
		printf("�޸ĺ��ѧ�ţ�");
		do{
			gets(num[i]); 
			numNull(num[i]);
		}while(strcmp(num[i],"")==0);
		printf("�޸ĺ��������");
		gets(name[i]);
		printf("�޸ĺ�ĵ绰��");
		gets(tel[i]);
		printf("�޸ĳɹ���");
	}
	else printf("û�д��ˣ�"); 
			
} 

void numNull(char num[M])
{
	//�ַ����Ķ���
	//char num[M];Ϊ������ʽ
	//ʹ�õ�ʱ��ֱ��num���� 
	if(strcmp(num,"")==0)
		printf("ѧ�Ų���Ϊ�գ����������룺");			
}

void myDelete(char num[N][M],char name[N][M],char tel[N][M])
{ 
	char dMeans='\0';
	printf("\n��ѧ��(h)/����(m)ɾ����");
	dMeans=getche();
	if(dMeans=='h'||dMeans=='H')
		delNum(num,name,tel);		
	else if(dMeans=='m'||dMeans=='M')
		delName(num,name,tel);
	else printf("�Ƿ��ַ���\n");
}

void delNum(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,k=0; 
	char dNum[M]="";
	
	printf("\n������Ҫɾ����ѧ�ţ�");
	gets(dNum);
	for(i=0;i<N;i++)
	{
		if(strcmp(dNum,num[i])==0)
		{
			for(k=i;k<N-1;k++)
			{
				//�ַ����ĸ��Ʋ���ֱ�� =
				//Ҫ���ַ�������strcpy 
				strcpy(num[k],num[k+1]);
				strcpy(name[k],name[k+1]);
				strcpy(tel[k],tel[k+1]);
			}
			//�ַ���ֻ���ڶ����ʱ��ֵ
			//����ֵҲ���� 
			//num[k]="";name[k]="";tel[k]="";
			//��������ʾ������Ҳ���ý����жϣ��������ֵ
			//�ַ������������ֵ'\0',"",NULL
			strcpy(num[k],"");
			strcpy(name[k],"");
			strcpy(tel[k],"");
			printf("ɾ���ɹ���");
			break;
		}		
	}
	if(k==0)
		printf("���޴���!");	
}

void delName(char num[N][M],char name[N][M],char tel[N][M])
{
	int i=0,k=0; 
	char dName[M]="";
	
	printf("\n������Ҫɾ����������");
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
			printf("ɾ���ɹ���");
			break;

		}		
	}
	if(k==0)
		printf("���޴���!");	
		
}

int myLength(char num[N][M])
{
	int i=0;
	while(strcmp(num[i],"")!=0)
		i++;
	return i;
}
#include<stdio.h>
#include<string.h>
int main(void)
{
	int i=0,j=0,k=0;
	char *temp=NULL,*p[4];
	
	p[0]="ddd";
	p[1]="ccc";
	p[2]="bbb";
	p[3]="aaa";
	
	for(i=0;i<4;i++)
		puts(p[i]);
	for(i=0;i<4;i++)
	{
		k=i;
		for(j=i+1;j<4;j++)
		{
			if(strcmp(p[i],p[j])>0)
				k=j;		
		}
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	}
	printf("½»»»ºó\n");	
	for(i=0;i<4;i++)
		puts(p[i]);
		//printf("")
	
}
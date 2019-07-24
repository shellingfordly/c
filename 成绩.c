#include <stdio.h>
int main(void)
{
	int a,b,c;
	scanf("%d",&c);
	a=c/10;
	b=c%10;
	switch(a)
	{
		case 10:
		case 9:printf("A");break;
		case 8:
		  if(b>=5)printf("A");
		  else printf("B");
		  break;
		case 7:printf("B");break;
		case 6:printf("C");break;
		case 5:
		  if(b>=5)printf("C");
		  else printf("D");
		  break;
		case 4:printf("D");break;
		default:printf("E");break;
	}
}

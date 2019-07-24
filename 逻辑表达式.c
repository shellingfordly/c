#include <stdio.h>
int main(void)
{
	int y;
	y='1';
	if(y) printf("%d\n",y);
	else printf("error\n");
	
	int a=0,b=0;
	switch(a==b)
	{
		case 0:printf("aaa");
		case 1:printf("bbb");
		case 2:printf("ccc");
	}
	
}
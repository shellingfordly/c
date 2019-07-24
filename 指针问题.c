#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[20]="abcdefg",*p="ABC";
	int i=0;
	strcpy(s+2,p);
	printf("%s\n",s);
	for(;i<7;i++)
	  printf("%c",s[i]);
	
}

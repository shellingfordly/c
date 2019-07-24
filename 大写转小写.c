#include <stdio.h>
int main(void)
{
	char word="\0";
	word=(int)getchar();
	if(word>=65&&word<=90)printf("%c",32+word);
	else printf("%c",word);	
}

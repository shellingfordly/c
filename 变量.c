#include <stdio.h>
//变量可以定义在全局
int i =1;
//全局也可以打印输出
printf("%d",i);
void x(){
printf("xxxx");}
//全局可以调用函数
x();


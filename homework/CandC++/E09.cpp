#include<stdio.h>
int main()
{
	int month;
	printf("请输入月份.\n");							//提示用户输入
	scanf("%d",&month);							//输入月份
	switch(month)										//按月份输出天数
	{
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):printf("31days.\n");break;
		case(2):printf("28days.\n");break;
		default:printf("30days.\n");
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int month,day;
	printf("ÇëÊäÈëÔÂÈÕ.\n");
	scanf("%d%d",&month,&day);
	switch(month)
	{
	case 1:day=day;break;
	case 2:day=day+31;break;
	case 3:day=day+31+28;break;
	case 4:day=day+31+28+31;break;
	case 5:day=day+31+28+31+30;break;
	case 6:day=day+31+28+31+30+31;break;
	case 7:day=day+31+28+31+30+31+30;break;
	case 8:day=day+31+28+31+30+31+30+31;break;
	case 9:day=day+31+28+31+30+31+30+31+31;break;
	case 10:day=day+31+28+31+30+31+30+31+31+30;break;
	case 11:day=day+31+28+31+30+31+30+31+31+30+31;break;
	case 12:day=day+31+28+31+30+31+30+31+31+30+31+30;break;
	default:printf("error.\n");
	}
	if(month>=1&&month<=12)
	{
	switch(day%7)
		{
		case 1:printf("TUESDAY.\n");break;
		case 2:printf("WEDNESDAY.\n");break;
		case 3:printf("THUSDAY.\n");break;
		case 4:printf("FRIDAY.\n");break;
		case 5:printf("SATURDAY.\n");break;
		case 6:printf("SUNDAY.\n");break;
		case 7:printf("MONDAY.\n");break;
		}
	}
	return 0;
}
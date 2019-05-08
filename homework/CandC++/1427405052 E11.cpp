#include<stdio.h>
#include<math.h>
int main()
{
	float x1,y1,r,x2,y2,d;
	printf("请输入圆心坐标x1 y1及圆半径r.\n");
	scanf("%f%f%f",&x1,&y1,&r);
	printf("请输入点坐标x2 y2.\n");
	scanf("%f%f",&x2,&y2);
	d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(d<=r)printf("点在圆上.\n");
	else printf("点在园外.\n");
	return 0;
}
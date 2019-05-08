#include<stdio.h>
#include<math.h>
int main()
{
	float x1,x2,x3,y1,y2,y3,c,s,a,b,c,d;
	printf("请输入三个顶点的横纵坐标.\n");
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
	if((y1-y2)*(x2-x3)==(x1-x2)(y2-y3))
		printf("不能构成三角形.\n");
	else
	{
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	s=a+b+c;
	d=s/2;

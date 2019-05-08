#include<stdio.h>
#include<math.h>
int main()
{
	double x1,y1,x2,y2,x3,y3,s,t,l1,l2,l3,c;
	printf("请输入三个点的横纵坐标.\n");
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	if ((x2-x1)*(y3-y2)==(x3-x2)*(y2-y1)) printf("error!");
	else 
	{
		l1=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		l2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		l3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		t=(l1+l2+l3)/2;
		s=sqrt(t*(t-l1)*(t-l2)*(t-l3));
		c=l1+l2+l3;
		printf("面积为：%.2lf\n周长为：%.2lf\n",s,c);
	}
	return 0;
}
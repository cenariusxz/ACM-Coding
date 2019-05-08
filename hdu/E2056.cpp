#include<stdio.h>
int main()
{
	double x1,x2,x3,x4,y1,y2,y3,y4;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		double t,s,a,b,c,d;
		if (x1>x2)
		{
			t=x1;
			x1=x2;
			x2=t;
		}
		if (y1>y2)
		{
			t=y1;
			y1=y2;
			y2=t;
		}
		if (x3>x4)
		{
			t=x3;
			x3=x4;
			x4=t;
		}
		if (y3>y4)
		{
			t=y3;
			y3=y4;
			y4=t;
		}
		if (y2<=y3||y4<=y1||x2<=x3||x4<=x1) s=0;
		else 
		{
			a=(x1>x3)?x1:x3;
			b=(x4>x2)?x2:x4;
			c=(y1>y3)?y1:y3;
			d=(y4>y2)?y2:y4;
			s=(b-a)*(d-c);
		}
		printf("%.2lf\n",s);
	}
	return 0;
}
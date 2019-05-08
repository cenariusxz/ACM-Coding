#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,dics,p,q,x1,x2;
	printf("请输入a,b,c.\n");
	scanf("%f,%f,%f",&a,&b,&c);
	dics=b*b-4*a*c;
	if(dics<0)printf("无实根");
	else
	{p=-b/(2*a);
	q=sqrt(dics)/(2*a);
	x1=p+q;
	x2=p-q;
	printf("方程的根为：\nx1=%7.2f\tx2=%7.2f\n",x1,x2);
	}
}

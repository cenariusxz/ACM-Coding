#include <stdio.h>
#include<math.h>
void main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,C,S,cosC,sinC;
	printf("����������������ĺ�����������\n");				//��ʾ�û�����
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);	
	a=sqrt(fabs((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));			//�������߳���
	b=sqrt(fabs((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
	c=sqrt(fabs((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
	if((a+b>c)&&(a+c>b)&&(b+c>a))							//�ж��Ƿ��ܹ���������
	{														//�����ܳ���������
		C=a+b+c;
		cosC=(a*a+b*b-c*c)/(2.0*a*b);
		sinC=sqrt(1-cosC*cosC);
		S=0.5*a*b*sinC;
		printf("�ܳ�=%lf\t���=%lf\n",C,S);
	}
	else
	{
		printf("error\n");
	}
}
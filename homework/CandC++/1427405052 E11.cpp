#include<stdio.h>
#include<math.h>
int main()
{
	float x1,y1,r,x2,y2,d;
	printf("������Բ������x1 y1��Բ�뾶r.\n");
	scanf("%f%f%f",&x1,&y1,&r);
	printf("�����������x2 y2.\n");
	scanf("%f%f",&x2,&y2);
	d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(d<=r)printf("����Բ��.\n");
	else printf("����԰��.\n");
	return 0;
}
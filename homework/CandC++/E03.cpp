#include<stdio.h>

int main()
{
	float r,c,s,V,S,pi=3.14159;
	printf("������뾶\n");										//��ʾ�û�����뾶
	scanf("%f",&r);
	c=2*pi*r;													//�����ֵ
	s=pi*r*r;
	V=(4/3)*pi*r*r*r;
	S=2*pi*r*r;
	printf("c=%7.2f\ts=%7.2f\nV=%7.2f\tS=%7.2f\n",c,s,V,S);		//������
	return 0;
}
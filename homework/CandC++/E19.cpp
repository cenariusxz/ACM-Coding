#include<stdio.h>
int main()
{
	int s1,s2,s3,count=0;
	for (s1=0;s1<=100/5;s1++)
	{
		for (s2=0;s2<=(100-5*s1)/3;s2++)
		{
			s3=(100-5*s1-3*s2)*3;
			if (s1+s2+s3==100)
			{
				count++;
				printf("%d��\n���̹�%dֻ\nĸ��%dֻ\n����%dֻ.\n",count,s1,s2,s3);
			}
		}
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int num,x1,x2,x3,x4,x5;
	printf("������һ����������λ��������.\n");
	scanf("%d",&num);
	x1=num/10000;
	x2=num/1000-10*x1;
	x3=num/100-100*x1-10*x2;
	x4=num/10-1000*x1-100*x2-10*x3;
	x5=num-10000*x1-1000*x2-100*x3-10*x4;
	if (num>99999||num<1) printf("error.\n");
	else
		if (x1) 
		{printf("������λ��.\n");
		printf("%d\t%d\t%d\t%d\t%d\n",x1,x2,x3,x4,x5);
		printf("%d%d%d%d%d\n",x5,x4,x3,x2,x1);
		}
		else 
			if (x2) 
			{printf("������λ��.\n");
			printf("%d\t%d\t%d\t%d\n",x2,x3,x4,x5);
			printf("%d%d%d%d\n",x5,x4,x3,x2);
			}
			else 
				if (x3) 
				{printf("������λ��.\n");
				printf("%d\t%d\t%d\n",x3,x4,x5);
				printf("%d%d%d\n",x5,x4,x3);
				}
				else
					if (x4) 
					{printf("������λ��.\n");
					printf("%d\t%d\n",x4,x5);
					printf("%d%d\n",x5,x4);
					}
					else 
					{
					printf("����һλ��.\n");
					printf("%d\n",x5);
					printf("%d\n",x5);
					}
	return 0;
}

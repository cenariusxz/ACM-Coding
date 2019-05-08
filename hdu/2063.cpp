#include<stdio.h>
#include<string.h>
char b[2000][100];
int main()
{
	char a[2000];
	while (gets(a))
	{
		if (strcmp(a,"#")==0) break;
		else 
		{
			int count=0,i,len,j,k;
			bool f=0;
			len=strlen(a);
			for (i=0;i<len;i++)
			{
				if(a[i]!=' '&&f==0)
				{
					f=1;
					count++;
				}
				if (a[i]==' ') f=0;
			}
			printf("%d\n",count);
		}
	}
	return 0;
}
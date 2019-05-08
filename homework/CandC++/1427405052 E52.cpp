#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp1,*fp2;
	int a[21],i,j,k,t;
	fp1=fopen("E52.dat","rb");				//打开文件，若无法打开则提示并关闭程序
	if(fp1==NULL)
	{
		printf("文件无法打开.\n");
		exit(0);
	}
	i=fread(a,sizeof(int),20,fp1);			//将文件中的数据读入数组中
	if(i==0)
	{
		printf("读文件失败.\n");
		exit(0);
	}
	for(i=0;i<20;i++)						//选择法对数组中数据排序
	{
		k=i;
		for(j=i+1;j<20;j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			t=a[k];
			a[k]=a[i];
			a[i]=t;
		}
	}
	for(i=0;i<20;i++) printf("%d\t",a[i]);
	printf("\n");
	fp2=fopen("1.dat","wb");				//创建一个新文件
	if(fp2==NULL)                  
	{
		printf("文件无法打开.\n");
		exit(0);
	}
	fwrite(a,sizeof(int),20,fp2);			//将数组的数据读入新文件中
	fclose(fp1);
	fclose(fp2);
}
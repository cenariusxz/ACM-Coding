#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *fp1,*fp2;
	int a[21],i,j,k,t;
	fp1=fopen("E52.dat","rb");				//���ļ������޷�������ʾ���رճ���
	if(fp1==NULL)
	{
		printf("�ļ��޷���.\n");
		exit(0);
	}
	i=fread(a,sizeof(int),20,fp1);			//���ļ��е����ݶ���������
	if(i==0)
	{
		printf("���ļ�ʧ��.\n");
		exit(0);
	}
	for(i=0;i<20;i++)						//ѡ�񷨶���������������
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
	fp2=fopen("1.dat","wb");				//����һ�����ļ�
	if(fp2==NULL)                  
	{
		printf("�ļ��޷���.\n");
		exit(0);
	}
	fwrite(a,sizeof(int),20,fp2);			//����������ݶ������ļ���
	fclose(fp1);
	fclose(fp2);
}
#include<stdio.h>
#include<string.h>
struct Data																//�����ṹ��
{
	char name[20];
	char tel[12];
	char mob[20];
	char pos[8];
	char add[50];
}data[51];

void display(Data data[],int n)											//���ͨѶ¼����
{
	int i;
	for (i=1;i<=n;i++) printf("%s %s %s %s %s\n",data[i].name,data[i].tel,data[i].mob,data[i].pos,data[i].add);
}
int mcreat(Data data[])													//����ͨѶ¼����
{
	int n,i;
	printf("��������Ҫ¼�����ϵ�˵ĸ���.\n");
	scanf("%d",&n);
	printf("������������Ҫ¼�����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
	for (i=1;i<=n;i++) scanf("%s%s%s%s%s",&data[i].name,&data[i].tel,&data[i].mob,&data[i].pos,&data[i].add);
	return n;
}

int msearch(Data data[],int n)											//��ͨѶ¼��Ѱ����ϵ�˺���
{
	int i;
	char name[20];
	printf("��������Ҫ��������ϵ��������\n");
	scanf("%s",&name);
	for (i=1;i<=n;i++) if (strcmp(name,data[i].name)==0) return i;		//���ҵ����򷵻ظ���ϵ�˵ı�ţ����򷵻�0
	return 0;
}

void delete1(Data data[],int n,int f)									//ɾ����ϵ�˺���
{
	int i;
	for (i=f;i<n;i++) data[i]=data[i+1];
	n--;
	printf("ɾ���������ͨѶ¼��\n");
	display(data,n);
	printf("\n");
	return;
}

void change2(Data data[],int n,int f)									//�޸���ϵ�˺���
{
	Data data1;
	printf("�������޸ĺ����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
	scanf("%s%s%s%s%s",&data1.name,&data1.tel,&data1.mob,&data1.pos,&data1.add);
	strcpy(data[f].name,data1.name);
	strcpy(data[f].tel,data1.tel);
	strcpy(data[f].mob,data1.mob);
	strcpy(data[f].pos,data1.pos);
	strcpy(data[f].add,data1.add);
	printf("�޸Ľ������ͨѶ¼��\n");
	display(data,n);
	printf("\n");
	return;
}

void search3(Data data[],int i)											//��ѯ��ϵ�˺���
{
	printf("%s  %s  %s  %s  %s\n",data[i].name,data[i].tel,data[i].mob,data[i].pos,data[i].add);
	printf("\n");
	return;
}

void add4(Data data[],int n)											//�����ϵ�˺���
{
	printf("��������Ҫ¼�����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
	scanf("%s%s%s%s%s",&data[n+1].name,&data[n+1].tel,&data[n+1].mob,&data[n+1].pos,&data[n+1].add);
	n++;
	printf("��ӽ������ͨѶ¼��\n");
	display(data,n);
	printf("\n");
	return;
}

int main()
{
	int n=mcreat(data);													//���ȴ���ͨѶ¼
	printf("\n");
	while(1)															//����ѭ������ֱ���û�ֹͣ
	{
		int m;
		printf("����ɾ�������롰1���������޸������롰2���������ѯ�����롰3����������������롰4�����˳����������롰0��\n");
		scanf("%d",&m);
		if (m==0) break;												//���롰0��������ѭ����ֹ����
		else if (m==1)													//�Ȳ�����ϵ�ˣ��ٽ���ɾ������
		{
			int f=msearch(data,n);
			if (f==0) printf("�޴���ϵ�ˡ�\n\n");
			else
			{
				delete1(data,n,f);
				n--;
			}
		}
		else if (m==2)													//�Ȳ�����ϵ�ˣ��ٽ����޸Ĳ���
		{
			int f=msearch(data,n);
			if (f==0) printf("�޴���ϵ�ˡ�\n\n");
			else change2(data,n,f);
		}
		else if (m==3)													//������ϵ�ˣ������
		{
			int f=msearch(data,n);
			if (f==0) printf("�޴���ϵ�ˡ�\n\n");
			else search3(data,f);
		}
		else if (m==4)													//�����ϵ��
		{
			add4(data,n);
			n++;
		}
		else printf("�����������������롣\n\n");
	}
	return 0;
}
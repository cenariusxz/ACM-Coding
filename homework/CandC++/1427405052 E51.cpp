#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contactor
{
	char name[20];
	int age;
	int sex;
    char phone[20];
	char postcode[10];
	char address[100];
};

struct Tontactor
{
	char name[20];
	int age;
	int sex;
    char phone[20];
	char postcode[10];
	char address[100];
	struct Tontactor *next;
};


struct Tontactor *mcreat(char a[])								//����������
{
	struct Tontactor *p,*q,*head,temp;
	FILE *fp1;
	char name[20],phone[20],postcode[10],address[100];
	int age,sex,b;
	fp1=fopen(a,"rb");											//���ļ������ļ�����������ʾ���رճ���
	if(fp1==NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	head=(struct Tontactor*)malloc(sizeof(struct Tontactor));
	q=head;                                                                                 
	while(!feof(fp1))											//��������
	{
		b=fread(&temp,sizeof(struct Contactor),1,fp1);
		if(b==0)
		{
			break;
		}
		p=(struct Tontactor*)malloc(sizeof(struct Tontactor));
		strcpy(p->name,temp.name);
		strcpy(p->phone,temp.phone);
		strcpy(p->postcode,temp.postcode);
		strcpy(p->address,temp.address);
		p->age=temp.age;
		p->sex=temp.sex;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	fclose (fp1);												//�رճ���
	return head;
}

void display(struct Tontactor *head)							//��ʾ������
{
	struct Tontactor *p;
	char sex;
	p=head->next;
	while(p!=NULL)
	{
		if (p->sex==1) sex='M';
		else sex='F';
		printf("%-10s%-3d%-2c%-12s%8s%-20s\n", p->name, p->age, sex,p->phone,p->postcode,p->address);
		p=p->next;
	}
	printf("\n");
	return;
}

void minsert(struct Tontactor *head,struct Tontactor temp)		//�����㺯��
{
	struct Tontactor *p,*q,*k;
	q=head;
	k=head->next;
	p=(struct Tontactor*)malloc(sizeof(struct Tontactor));
	strcpy(p->name,temp.name);
	strcpy(p->phone,temp.phone);
	strcpy(p->postcode,temp.postcode);
	strcpy(p->address,temp.address);
	p->age=temp.age;
	p->sex=temp.sex;
	p->next=k;
	q->next=p;
	return;
}

void mdelete(struct Tontactor *head)							//ɾ����㺯��
{
	struct Tontactor *p,*q;
	q=head;
	p=head->next;
	while(p!=NULL)												//�����������25�Ľ���ɾ��
	{
		if(p->age>=25)
		{
			q->next=p->next;
			free(p);
		}
		else
		{
			q=q->next;
			p=q->next;
			continue;
		}
		p=q->next;
	}
	return;
}

void Num(double a[],struct Tontactor *head)							//����Ů�����ֵ��ƽ��ֵ����
{
	struct Tontactor *p;
	int count=0;
	double sum=0,ave,max=0; 
	p=head->next;
	while(p!=NULL)
	{
		if(p->sex==0)
		{
			sum=sum+p->age;
			max=max>p->age?max:p->age;
			count++;
		}
		p=p->next;
	}
	if (count==0) ave=0;
	else ave=sum/count;
	a[0]=max;
	a[1]=ave;
	return;
}

int minsearch(struct Tontactor *head)								//��ѯ�����޸ĺ���
{
	struct Tontactor *p,*q;
	char name[100];
	q=head;
	p=head->next;
	printf("����Ҫ��ѯ����ϵ�˵�����: ");
	gets(name);
	while(p!=NULL)													//��������Ѱ����ϵ�ˣ����ҵ�������޸Ĳ��������������򷵻�0
	{
		if(strcmp(p->name,name)==0)
		{
			char name[20],phone[20],postcode[10],address[100];
			int age,sex;
			printf("�����������޸ĺ����ϵ�˵����������䡢�Ա�0ΪŮ��1Ϊ�У����绰���ʱࡢ��ַ.\n");
			scanf("%s%d%d%s%s%s",name,&age,&sex,phone,postcode,address);
			strcpy(p->name,name);
			p->sex=sex;
			p->age=age;
			strcpy(p->postcode,postcode);
			strcpy(p->address,address);
			strcpy(p->phone,phone);
			return 1;
		}
		else
		{
			q=p;
			p=p->next;
		}
	}
	return 0;
}

void mfree(struct Tontactor *head)											//�ͷ�����
{
	while (head!=NULL)
	{
		struct Tontactor *p=head->next;
		free(head);
		head=p;
	}
	return;
}

int main()
{
	FILE *fp1;
	struct Tontactor *head,*p,temp;
	char c[100]="contact.dat";
	double a[2];
	int n;
	head=mcreat(c);
	printf("ԭͨѶ¼��Ϣ:\n");
	display(head);
	printf("����������Ҫ��������ϵ�˵����������䡢�Ա�0ΪŮ��1Ϊ�У����绰���ʱࡢ��ַ.\n");
	scanf("%s%d%d%s%s%s",temp.name,&temp.age,&temp.sex,temp.phone,temp.postcode,temp.address);
	getchar();
	minsert(head,temp);
	printf("�����ϵ�˺��ͨѶ¼��Ϣ:\n");
	display(head);
	mdelete(head);
	printf("ɾ�����ڵ���25�����ϵ�˺��ͨѶ¼��Ϣ:\n");
	display(head);
	Num(a,head);
	printf("Ů���������:%lf\nŮ��ƽ������:%lf\n",a[0],a[1]);
	n=minsearch(head);
	if(!n) printf("����������.\n");
	printf("�޸ĺ��ͨѶ¼��Ϣ:\n");
	display(head);
	fp1=fopen("D:\\res.txt","wb");
	p=head->next;
	while(p!=NULL)
	{
		fprintf(fp1,"%-10s%-3d%-2c%-12s%8s%-20s\n",p->name,p->age,p->sex,p->phone,p->postcode,p->address);
		p=p->next;
	}
	mfree(head);
	return 0;
}
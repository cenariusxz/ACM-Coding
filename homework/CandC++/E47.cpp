#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Data																//�����ṹ��
{
	char name[20];
	char tel[10];
	char mob[15];
	char pos[7];
	char add[50];
	Data *next;
}data;

void display(struct Data *head)											//���ͨѶ¼����
{
	Data *p=head->next;
	while(p!=NULL)
	{
		printf("%s %s %s %s %s\n",p->name,p->tel,p->mob,p->pos,p->add);
		p=p->next;
	}
	return;
}

struct Data *mcreat()													//����ͨѶ¼����
{
	int n,i;
	printf("��������Ҫ¼�����ϵ�˵ĸ���.\n");
	scanf("%d",&n);
	Data *head,*p1,*p2;
	p2=head=p1=(Data*)malloc(sizeof(Data));
	head->next=p1;
	printf("������������Ҫ¼�����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
	for (i=1;i<=n;i++)
	{
		p2=p1;
		p1=(Data*)malloc(sizeof(Data));
		scanf("%s%s%s%s%s",&p1->name,&p1->tel,&p1->mob,&p1->pos,&p1->add);
		p2->next=p1;
	}
	p1->next=NULL;
	return head;
}

void delete1(Data *head)												//ɾ����ϵ�˺���
{
	Data *s=head,*p;
	char name[20];
	bool f=0;
	printf("��������Ҫ��������ϵ��������\n");
	scanf("%s",&name);
	while (s->next!=NULL)
	{
		if (strcmp(name,s->next->name)==0)
		{
			p=s->next;
			s->next=p->next;
			free(p);
			f=1;
			break;
		}
		s=s->next;
	}
	if (f)
	{
		printf("ɾ���������ͨѶ¼��\n");
		display(head);
	}
	else printf("�޴���ϵ�ˡ�\n");
	printf("\n");
	return;
}

void change2(Data *head)												//�޸���ϵ�˺���
{
	Data *s=head;
	char name[20];
	bool f=0;
	printf("��������Ҫ��������ϵ��������\n");
	scanf("%s",&name);
	while (s->next!=NULL)
	{
		if (strcmp(name,s->next->name)==0)
		{
			char name[20],tel[10],mob[15],pos[7],add[50];
			printf("�������޸ĺ����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
			scanf("%s%s%s%s%s",&name,&tel,&mob,&pos,&add);
			strcpy(s->next->name,name);
			strcpy(s->next->tel,tel);
			strcpy(s->next->mob,mob);
			strcpy(s->next->pos,pos);
			strcpy(s->next->add,add);
			f=1;
			break;
		}
		s=s->next;
	}
	if (f)
	{
		printf("�޸Ľ������ͨѶ¼��\n");
		display(head);
	}
	else printf("�޴���ϵ�ˡ�\n");
	printf("\n");
	return;
}

void search3(Data *head)												//��ѯ��ϵ�˺���
{
	Data *s=head;
	char name[20];
	bool f=0;
	printf("��������Ҫ��������ϵ��������\n");
	scanf("%s",&name);
	while (s->next!=NULL)
	{
		if (strcmp(name,s->next->name)==0)
		{
			printf("%s  %s  %s  %s  %s\n",s->next->name,s->next->tel,s->next->mob,s->next->pos,s->next->add);
			f=1;
			break;
		}
		s=s->next;
	}
	if (!f) printf("�޴���ϵ�ˡ�\n");
	printf("\n");
	return;
}

void add4(Data *head)													//�����ϵ�˺���
{
	Data *s=head->next,*p=(Data*)malloc(sizeof(Data));
	printf("��������Ҫ¼�����ϵ���������绰���ƶ��绰���ʱࡢͨѶ��ַ\n");
	scanf("%s%s%s%s%s",&p->name,&p->tel,&p->mob,&p->pos,&p->add);
	p->next=s;
	head->next=p;
	printf("��ӽ������ͨѶ¼��\n");
	display(head);
	printf("\n");
	return;
}

int main()
{
	Data *head=mcreat();												//���ȴ���ͨѶ¼
	printf("\n");
	while(1)															//����ѭ������ֱ���û�ֹͣ
	{
		int m;
		printf("����ɾ�������롰1���������޸������롰2���������ѯ�����롰3����������������롰4�����˳����������롰0��\n");
		scanf("%d",&m);
		if (m==0) break;												//���롰0��������ѭ����ֹ����
		else if (m==1) delete1(head);									//����ɾ������
		else if (m==2) change2(head);									//�����޸Ĳ���
		else if (m==3) search3(head);									//���в��Ҳ���
		else if (m==4) add4(head);										//������Ӳ���
		else printf("�����������������롣\n\n");
	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Data																//创建结构体
{
	char name[20];
	char tel[10];
	char mob[15];
	char pos[7];
	char add[50];
	Data *next;
}data;

void display(struct Data *head)											//输出通讯录函数
{
	Data *p=head->next;
	while(p!=NULL)
	{
		printf("%s %s %s %s %s\n",p->name,p->tel,p->mob,p->pos,p->add);
		p=p->next;
	}
	return;
}

struct Data *mcreat()													//创建通讯录函数
{
	int n,i;
	printf("请输入需要录入的联系人的个数.\n");
	scanf("%d",&n);
	Data *head,*p1,*p2;
	p2=head=p1=(Data*)malloc(sizeof(Data));
	head->next=p1;
	printf("请依次输入需要录入的联系人姓名、电话、移动电话、邮编、通讯地址\n");
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

void delete1(Data *head)												//删除联系人函数
{
	Data *s=head,*p;
	char name[20];
	bool f=0;
	printf("请输入需要操作的联系人姓名。\n");
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
		printf("删除结束后的通讯录：\n");
		display(head);
	}
	else printf("无此联系人。\n");
	printf("\n");
	return;
}

void change2(Data *head)												//修改联系人函数
{
	Data *s=head;
	char name[20];
	bool f=0;
	printf("请输入需要操作的联系人姓名。\n");
	scanf("%s",&name);
	while (s->next!=NULL)
	{
		if (strcmp(name,s->next->name)==0)
		{
			char name[20],tel[10],mob[15],pos[7],add[50];
			printf("请输入修改后的联系人姓名、电话、移动电话、邮编、通讯地址\n");
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
		printf("修改结束后的通讯录：\n");
		display(head);
	}
	else printf("无此联系人。\n");
	printf("\n");
	return;
}

void search3(Data *head)												//查询联系人函数
{
	Data *s=head;
	char name[20];
	bool f=0;
	printf("请输入需要操作的联系人姓名。\n");
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
	if (!f) printf("无此联系人。\n");
	printf("\n");
	return;
}

void add4(Data *head)													//添加联系人函数
{
	Data *s=head->next,*p=(Data*)malloc(sizeof(Data));
	printf("请输入需要录入的联系人姓名、电话、移动电话、邮编、通讯地址\n");
	scanf("%s%s%s%s%s",&p->name,&p->tel,&p->mob,&p->pos,&p->add);
	p->next=s;
	head->next=p;
	printf("添加结束后的通讯录：\n");
	display(head);
	printf("\n");
	return;
}

int main()
{
	Data *head=mcreat();												//首先创建通讯录
	printf("\n");
	while(1)															//不断循环操作直到用户停止
	{
		int m;
		printf("如需删除请输入“1”，如需修改请输入“2”，如需查询请输入“3”，如需添加请输入“4”，退出操作请输入“0”\n");
		scanf("%d",&m);
		if (m==0) break;												//输入“0”则跳出循环终止操作
		else if (m==1) delete1(head);									//进行删除操作
		else if (m==2) change2(head);									//进行修改操作
		else if (m==3) search3(head);									//进行查找操作
		else if (m==4) add4(head);										//进行添加操作
		else printf("输入有误，请重新输入。\n\n");
	}
	return 0;
}
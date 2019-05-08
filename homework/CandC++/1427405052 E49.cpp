#include<stdio.h>
#include<stdlib.h>
typedef struct Data
{
	int num;
	Data *next;
}NumNode;

NumNode* mcreat(char *name)								//����������
{
	FILE *fp=fopen(name,"r");
	if (fp==NULL)
	{
		printf("�ļ������ڣ�\n");
		exit(0);
	}
	NumNode* head=(NumNode*)malloc(sizeof(NumNode));
	NumNode* tail=head;
	int n;
	while (!feof(fp))
	{
		fscanf(fp,"%d",&n);
		NumNode* p=(NumNode*)malloc(sizeof(NumNode));
		p->num=n;
		tail->next=p;
		tail=p;
	}
	tail->next=NULL;
	fclose(fp);
	return head;
}

void display(NumNode* head)								//��ʾ������
{
	NumNode* p=head->next;
	while(p!=NULL)
	{
		printf("%-6d",p->num);
		p=p->next;
	}
	printf("\n");
	return;
}

void msort(NumNode* head)								//������
{
	NumNode *p,*q;
	int t;
	p=head->next;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if (q->num<p->num)
			{
				t=q->num;
				q->num=p->num;
				p->num=t;
			}
			q=q->next;
		}
		p=p->next;
	}
	return;
}

void mout(NumNode* head)								//������ļ�
{
	FILE *fp=fopen("out.txt","w");
	NumNode *s=head->next;
	while (s!=NULL)
	{
		fprintf(fp,"%d\n",s->num);
		s=s->next;
	}
	return;
}

void mfree(NumNode *head)								//�ͷ�����
{
	while (head!=NULL)
	{
		NumNode *p=head->next;
		free(head);
		head=p;
	}
	return;
}

int main()
{
	NumNode* head;
	head=mcreat("in.txt");
	printf("Դ�ļ�����\n");
	display(head);
	msort(head);
	printf("���������\n");
	display(head);
	mout(head);
	mfree(head);
	return 0;
}
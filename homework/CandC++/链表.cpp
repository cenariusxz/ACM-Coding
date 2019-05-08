#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char name[10];
	int num;
	struct Node *next;
}NumNode;

NumNode* mcreat(NumNode* head)
{
	int i;
	NumNode *tail;
	head=tail=(NumNode*)malloc(sizeof(NumNode));
	for (i=1;i<=5;i++)
	{
		NumNode *p=(NumNode*)malloc(sizeof(NumNode));
		scanf("%s%d",p->name,&p->num);
		tail->next=p;
		tail=p;
	}
	tail->next=NULL;
	return head;
}

void display(NumNode *head)
{
	NumNode *p=head->next;
	while(p!=NULL)
	{
		printf("%s\t%d\n",p->name,p->num);
		p=p->next;
	}
	return;
}
/*
int main()
{
	NumNode *head;
	head=mcreat(head);
	display(head);
	int n;
	scanf("%d",&n);
	mdelete(n);

	return 0;
}*/

int main()
{
	NumNode *head=(NumNode*)malloc(sizeof(NumNode));
	head=mcreat(head);
	display(head);
	return 0;
}
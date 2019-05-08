#include<stdio.h>
#include<stdlib.h>
struct WareHouse
{
	int ID;				//货物编码
	int  num;			//货物数量
};
typedef struct WareHouseNode
{
	int ID;				//货物编码
	int  num;			//货物数量
	struct WareHouseNode *next;
}Node;

Node *mcreat(char file[])
{
	FILE *fp=fopen(file,"rb");
	if(fp==NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	struct WareHouse t;
	Node *head,*tail;
	head=tail=(Node*)malloc(sizeof(Node));
	while(!feof(fp))
	{
		Node *p=(Node*)malloc(sizeof(Node));
		fread(&t,sizeof(struct WareHouse),1,fp);
		p->ID=t.ID;
		p->num=t.num;
		tail->next=p;
		tail=p;
	}
	tail->next=NULL;
	fclose(fp);
	return(head);
}

void display(Node *head)
{
	Node *s=head->next;
	while(s!=NULL)
	{
		printf("%5d%5d\n",s->ID,s->num);
		s=s->next;
	}
	printf("\n");
	return;
}

void mfree(Node *head)
{
	Node *p,*s;
	p=head;
	while(p!=NULL)
	{
		s=p->next;
		free(p);
		p=s;
	}
	return;
}

void madd(Node *head)
{
	Node *p=head->next,*s;
	while(p!=NULL)
	{
		if (p->ID==10)
		{
			s=p;
			while(s->next!=NULL)
			{
				if (s->next->ID==10)
				{
					p->num+=s->next->num;
					Node *q=s->next;
					s->next=q->next;
					free(q);
				}
				else s=s->next;
			}
			break;
		}
		else p=p->next;
	}
	return;
}

void mout(Node *head)
{
	FILE *fp;
	fp=fopen("d:\\res.txt","w");
	Node *p=head->next;
	if(fp==NULL)
	{
		printf("文件打开错误！\n");
		exit(0);
	}
	while(p!=NULL)
	{
		fprintf(fp,"%5d%5d\n",p->ID,p->num);
		p=p->next;
	}
	return;
}

int main()
{
	Node *head=(Node*)malloc(sizeof(Node));
	head=mcreat("D:\\input.dat");
	display(head);
	madd(head);
	display(head);
	mout(head);
	mfree(head);
	return 0;
}
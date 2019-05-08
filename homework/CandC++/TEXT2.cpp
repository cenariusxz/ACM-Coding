#include <stdio.h>
#include <stdlib.h>



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
}NODE;

NODE * CreateList(char *FName);
void DisplayList(NODE *Head);
void WriteFile(char *FName, NODE *Head);
void FreeList(NODE *Head);
void GroupList(NODE *Head);

void main()
{
	NODE *head;

	head=CreateList("d:\\input.dat");
	DisplayList(head);

	GroupList(head);
	DisplayList(head);

	WriteFile("d:\\res.txt", head);

	FreeList(head);
}

NODE * CreateList(char *FName)
{
	FILE *fp;
	NODE *head, *q, *p;
	struct WareHouse temp;
	int flag;

	fp=fopen(FName,"rb");
	if (fp==NULL)
	{
		printf("读文件打开异常\n");
		exit(0);
	}

	head=(NODE *)malloc(sizeof(NODE));
	q=head;
	while(!feof(fp))
	{
		flag=fread(&temp, sizeof(struct WareHouse), 1, fp);
		if (flag != 0)
		{
			p=(NODE *)malloc(sizeof(NODE));

			p->ID=temp.ID;
			p->num=temp.num;

			q->next=p;
			q=p;
		}
	}

	q->next=NULL;

	fclose(fp);

	return head;
}

void DisplayList(NODE *Head)
{
	NODE *p;

	p=Head->next;
	while (p!=NULL)
	{
		printf("%5d%5d\n",p->ID,p->num);
		p=p->next;
	}
	printf("\n");
}

void WriteFile(char *FName, NODE *Head)
{
	NODE *p;
	FILE *fp;

	fp=fopen(FName,"w");
	if (fp==NULL)
	{
		printf("写文件打开异常\n");
		exit(0);
	}

	p=Head->next;
	while (p!=NULL)
	{
		fprintf(fp,"%5d%5d\n",p->ID,p->num);
		p=p->next;
	}
	fprintf(fp,"\n");

	fclose(fp);
}

void FreeList(NODE *Head)
{
	NODE *q,*p;

	q=Head;
	while (q!=NULL)
	{
		p=q->next;
		free(q);
		q=p;
	}
}

void GroupList(NODE *Head)
{
	NODE *aim, *q, *p;

	aim=Head->next;
	while(aim->next != NULL)
	{
		q=aim;
		p=aim->next;

		if (aim->ID != 10)
		{
			aim=aim->next;
			continue;
		}

		while (p!=NULL)
		{
			if (aim->ID == p->ID)
			{
				aim->num += p->num;

				q->next=p->next;
				free(p);

				p=q->next;
			}
			else
			{
				q=p;
				p=p->next;
			}
		}

		aim=aim->next;
	}
}

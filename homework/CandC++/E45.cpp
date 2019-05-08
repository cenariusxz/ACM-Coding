#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN sizeof(struct Num)

struct Num											//�����ṹ��
{
	int num;
	struct Num *next;
};

int n;

struct Num *creat(int sum)							//����������
{
	struct Num *head,*p1,*p2;
	head=p1=p2=(struct Num *)malloc(LEN);
	p1->num=1;
	head->next=NULL;
	for (n=1;n<=sum;n++) 
	{
		if (n==1)head->next=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Num*)malloc(LEN);
		p1->num=n;
	}
	p2->next=NULL;
	return head;
}

void display (struct Num *pt,int count)				//���������
{
	do 
	{
		printf("%d\t",pt->num);
		pt=pt->next;
		count++;
		if (count%5==0&&pt!=NULL) printf("\n");
	}while (pt!=NULL);
	printf("\n");
}

void del(struct Num *stx)							//ɾ����㺯��
{
	struct Num *s=stx->next;
	stx->next=s->next;
	free(s);
	return;
}

int main()
{
	int sum;
	struct Num *head,*p;
	srand((unsigned)time(NULL));
	sum=(rand()%20)+20;								//��������Ϊ20��40��������
	head=creat(sum);								//��������
	printf("ɾȥż�����ǰ��\n");
	display(head->next,5);							//�������
	printf("ɾȥż������\n");
	p=head->next;
	while (p!=NULL&&p->next!=NULL)					//ɾ��ÿ�����������һ�����
	{
		del(p);
		p=p->next;
	}
	display(head->next,5);							//�������
	return 0;
}
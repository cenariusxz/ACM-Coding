#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN sizeof(struct Num)

struct Num											//创建结构体
{
	int num;
	struct Num *next;
};

int n;

struct Num *creat(int sum)							//创建链表函数
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

void display (struct Num *pt,int count)				//输出链表函数
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

void del(struct Num *stx)							//删除结点函数
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
	sum=(rand()%20)+20;								//定链表长度为20到40间的随机数
	head=creat(sum);								//创建链表
	printf("删去偶数结点前：\n");
	display(head->next,5);							//输出链表
	printf("删去偶数结点后：\n");
	p=head->next;
	while (p!=NULL&&p->next!=NULL)					//删除每个奇数后面的一个结点
	{
		del(p);
		p=p->next;
	}
	display(head->next,5);							//输出链表
	return 0;
}
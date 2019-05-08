#include<stdio.h>
#include<string.h>
struct Data																//创建结构体
{
	char name[20];
	char tel[12];
	char mob[20];
	char pos[8];
	char add[50];
}data[51];

void display(Data data[],int n)											//输出通讯录函数
{
	int i;
	for (i=1;i<=n;i++) printf("%s %s %s %s %s\n",data[i].name,data[i].tel,data[i].mob,data[i].pos,data[i].add);
}
int mcreat(Data data[])													//创建通讯录函数
{
	int n,i;
	printf("请输入需要录入的联系人的个数.\n");
	scanf("%d",&n);
	printf("请依次输入需要录入的联系人姓名、电话、移动电话、邮编、通讯地址\n");
	for (i=1;i<=n;i++) scanf("%s%s%s%s%s",&data[i].name,&data[i].tel,&data[i].mob,&data[i].pos,&data[i].add);
	return n;
}

int msearch(Data data[],int n)											//在通讯录中寻找联系人函数
{
	int i;
	char name[20];
	printf("请输入需要操作的联系人姓名。\n");
	scanf("%s",&name);
	for (i=1;i<=n;i++) if (strcmp(name,data[i].name)==0) return i;		//如找到，则返回该联系人的编号，否则返回0
	return 0;
}

void delete1(Data data[],int n,int f)									//删除联系人函数
{
	int i;
	for (i=f;i<n;i++) data[i]=data[i+1];
	n--;
	printf("删除结束后的通讯录：\n");
	display(data,n);
	printf("\n");
	return;
}

void change2(Data data[],int n,int f)									//修改联系人函数
{
	Data data1;
	printf("请输入修改后的联系人姓名、电话、移动电话、邮编、通讯地址\n");
	scanf("%s%s%s%s%s",&data1.name,&data1.tel,&data1.mob,&data1.pos,&data1.add);
	strcpy(data[f].name,data1.name);
	strcpy(data[f].tel,data1.tel);
	strcpy(data[f].mob,data1.mob);
	strcpy(data[f].pos,data1.pos);
	strcpy(data[f].add,data1.add);
	printf("修改结束后的通讯录：\n");
	display(data,n);
	printf("\n");
	return;
}

void search3(Data data[],int i)											//查询联系人函数
{
	printf("%s  %s  %s  %s  %s\n",data[i].name,data[i].tel,data[i].mob,data[i].pos,data[i].add);
	printf("\n");
	return;
}

void add4(Data data[],int n)											//添加联系人函数
{
	printf("请输入需要录入的联系人姓名、电话、移动电话、邮编、通讯地址\n");
	scanf("%s%s%s%s%s",&data[n+1].name,&data[n+1].tel,&data[n+1].mob,&data[n+1].pos,&data[n+1].add);
	n++;
	printf("添加结束后的通讯录：\n");
	display(data,n);
	printf("\n");
	return;
}

int main()
{
	int n=mcreat(data);													//首先创建通讯录
	printf("\n");
	while(1)															//不断循环操作直到用户停止
	{
		int m;
		printf("如需删除请输入“1”，如需修改请输入“2”，如需查询请输入“3”，如需添加请输入“4”，退出操作请输入“0”\n");
		scanf("%d",&m);
		if (m==0) break;												//输入“0”则跳出循环终止操作
		else if (m==1)													//先查找联系人，再进行删除操作
		{
			int f=msearch(data,n);
			if (f==0) printf("无此联系人。\n\n");
			else
			{
				delete1(data,n,f);
				n--;
			}
		}
		else if (m==2)													//先查找联系人，再进行修改操作
		{
			int f=msearch(data,n);
			if (f==0) printf("无此联系人。\n\n");
			else change2(data,n,f);
		}
		else if (m==3)													//查找联系人，并输出
		{
			int f=msearch(data,n);
			if (f==0) printf("无此联系人。\n\n");
			else search3(data,f);
		}
		else if (m==4)													//添加联系人
		{
			add4(data,n);
			n++;
		}
		else printf("输入有误，请重新输入。\n\n");
	}
	return 0;
}
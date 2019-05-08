#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<queue>

using namespace std;

struct Treap
{
    int size;
    int key,fix;
    Treap *ch[2];
    Treap(int key)
    {
        size=1;
        fix=rand();
        this->key=key;
        ch[0]=ch[1]=NULL;
    }
    int compare(int x) const
    {
        if(x==key) return -1;
        return x<key? 0:1;
    }
    void Maintain()
    {
        size=1;
        if(ch[0]!=NULL) size+=ch[0]->size;
        if(ch[1]!=NULL) size+=ch[1]->size;
    }
};

void Rotate(Treap* &t,int d)
{
    Treap *k=t->ch[d^1];
    t->ch[d^1]=k->ch[d];
    k->ch[d]=t;
    t->Maintain();  //必须先维护t，再维护k，因为此时t是k的子节点
    k->Maintain();
    t=k;
}

void Insert(Treap* &t,int x)
{
    if(t==NULL) t=new Treap(x);
    else
    {
        //int d=t->compare(x);   //如果值相等的元素只插入一个
        int d=x < t->key ? 0:1;  //如果值相等的元素都插入
        Insert(t->ch[d],x);
        if(t->ch[d]->fix > t->fix)
            Rotate(t,d^1);
    }
    t->Maintain();
}

//一般来说，在调用删除函数之前要先用Find()函数判断该元素是否存在
void Delete(Treap* &t,int x)
{
    int d=t->compare(x);
    if(d==-1)
    {
        Treap *tmp=t;
        if(t->ch[0]==NULL)
        {
            t=t->ch[1];
            delete tmp;
            tmp=NULL;
        }
        else if(t->ch[1]==NULL)
        {
            t=t->ch[0];
            delete tmp;
            tmp=NULL;
        }
        else
        {
            int k=t->ch[0]->fix > t->ch[1]->fix ? 1:0;
            Rotate(t,k);
            Delete(t->ch[k],x);
        }
    }
    else Delete(t->ch[d],x);
    if(t!=NULL) t->Maintain();
}

bool Find(Treap *t,int x)
{
    while(t!=NULL)
    {
        int d=t->compare(x);
        if(d==-1) return true;
        t=t->ch[d];
    }
    return false;
}

int Kth(Treap *t,int k)
{
    if(t==NULL||k<=0||k>t->size)
        return -1;
    if(t->ch[0]==NULL&&k==1)
        return t->key;
    if(t->ch[0]==NULL)
        return Kth(t->ch[1],k-1);
    if(t->ch[0]->size>=k)
        return Kth(t->ch[0],k);
    if(t->ch[0]->size+1==k)
        return t->key;
    return Kth(t->ch[1],k-1-t->ch[0]->size);
}

int Rank(Treap *t,int x)
{
    int r;
    if(t->ch[0]==NULL) r=0;
    else  r=t->ch[0]->size;
    if(x==t->key) return r+1;
    if(x<t->key)
        return Rank(t->ch[0],x);
    return r+1+Rank(t->ch[1],x);
}

void DeleteTreap(Treap* &t)
{
    if(t==NULL) return;
    if(t->ch[0]!=NULL) DeleteTreap(t->ch[0]);
    if(t->ch[1]!=NULL) DeleteTreap(t->ch[1]);
    delete t;
    t=NULL;
}

void Print(Treap *t)
{
    if(t==NULL) return;
    Print(t->ch[0]);
    cout<<t->key<<endl;
    Print(t->ch[1]);
}

int val[10005];

int main()
{
	int n,cnt=0;
	while(scanf("%d",&n)!=EOF){
		int i,size=0,pos=0;
		Treap *root=NULL;
		printf("Case #%d:\n",++cnt);
		for(i=1;i<=n;i++){
			char s[10];
			scanf("%s",s);
			if(s[0]=='q'){
				printf("%d\n",Kth(root,((size-pos)/2)+1));
			}
			if(s[0]=='i'){
				int a;
				scanf("%d",&a);
				Insert(root,a);
				val[++size]=a;
			}
			if(s[0]=='o'){
				Delete(root,val[++pos]);
			}
		}
		DeleteTreap(root);
	}
	return 0;
	/*
    int n,x,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&val[i]);
        int index=1;
        Treap *root=NULL;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&x);
            for(int j=index; j<=x; j++)
                Insert(root,val[j]);
            index=x+1;
            printf("%d\n",Kth(root,i));
        }
        DeleteTreap(root);
    }
    return 0;*/
}

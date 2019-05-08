#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int pre=0;

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

int Rank1(Treap *t,int x)
{
    if(x==t->key) return t->key;
    if(x>t->key){
		pre=t->key;
		if(t->ch[1]==NULL)return t->key;
		return Rank1(t->ch[1],x);
	}
	if(t->ch[0]==NULL)return t->key;
	return Rank1(t->ch[0],x);
}

int Rank2(Treap *t,int x)
{
    if(x==t->key)return t->key;
    if(x<t->key){
		pre=t->key;
		if(t->ch[0]==NULL)return t->key;
		return Rank2(t->ch[0],x);
	}
	if(t->ch[1]==NULL)return t->key;
	return Rank2(t->ch[1],x);
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

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

int main()
{
	int n=read();int k=read();int a=read();int m=read();
	int index=1;
	Treap *root=NULL;
	int num=(n+1)/(a+1);
	int ans=-1,i;
	Insert(root,0);
	Insert(root,n+1);
	for(i=1;i<=m;i++){
		int p=read();
		if(ans==-1){
			if(Find(root,p))continue;
			pre=p;
			int tmp=Rank1(root,p);
			int minn=min(tmp,pre);
			pre=p;
			tmp=Rank2(root,p);
			int maxx=max(tmp,pre);
			num-=(maxx-minn)/(a+1);
			num+=(p-minn)/(a+1);
			num+=(maxx-p)/(a+1);
			if(num<k)ans=i;
			Insert(root,p);
		}
	}
	printf("%d\n",ans);
    return 0;
}

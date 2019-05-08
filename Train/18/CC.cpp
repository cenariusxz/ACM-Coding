#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=5e5+5;

struct node{
	node *nxt,*pre;
	int num;
	node(){nxt=NULL;pre=NULL;num=-1;};
	node(int x):num(x){nxt=NULL;pre=NULL;}
}*pos[maxn],*root;

int cnt=1;

void learn(int id,int num){
	node *s=new node(num);
	s->pre=pos[id];
	pos[id]=s;
}

void rollback(int id){
	node *tmp=pos[id]->pre;
	node *s=new node(tmp->num);
	s->nxt=pos[id];
	s->pre=tmp->pre;
	pos[id]=s;
}

void relearn(int id){
	node *tmp=pos[id]->nxt;
	node *s=new node(tmp->num);
	s->pre=pos[id];
	s->nxt=tmp->nxt;
	pos[id]=s;
}

void clone(int pid){
	int id=++cnt;
	node *s=new node(pos[pid]->num);
	s->nxt=pos[pid]->nxt;
	s->pre=pos[pid]->pre;
	pos[id]=s;
}

int check(int id){
	if(pos[id]->num==-1)printf("basic\n");
	else printf("%d\n",pos[id]->num);
}

int main(){
	int m,k;
	root=new node();
	node *s=new node(-1);
	s->pre=root;
	pos[1]=s;
	scanf("%d%d",&m,&k);
	while(m--){
		char s[10];
		scanf("%s",s);
		if(s[0]=='l'){
			int a,b;
			scanf("%d%d",&a,&b);
			learn(a,b);
		}
		else if(s[0]=='r'&&s[1]=='o'){
			int a;
			scanf("%d",&a);
			rollback(a);
		}
		else if(s[0]=='c'&&s[1]=='h'){
			int a;
			scanf("%d",&a);
			check(a);
		}
		else if(s[0]=='c'&&s[1]=='l'){
			int a;
			scanf("%d",&a);
			clone(a);
		}
		else if(s[0]=='r'&&s[1]=='e'){
			int a;
			scanf("%d",&a);
			relearn(a);
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=5e6+5;

struct Node{
	int nxt,pre;
	int num,id;
	node(){nxt=-1;pre=-1;num=-1;id=-1;};
	node(int x,int Id):num(x),id(Id){nxt=-1;pre=-1;}
}node[maxn];

int pos[maxn],root,size;

int cnt=1;

void learn(int id,int num){
	int index=pos[id];
	node[size].pre=index;
	node[size].num=num;
	node[size].id=id;
	node[index].nxt=size;
	pos[id]=size++;
}

void rollback(int id){
	int index=pos[id];
	int p=node[index].pre;
	if(node[index].id==node[p].id)node[index]=p;
	else{
		node[size].pre=node[p].pre;
		node[size].num=node[p].num;
		node[size].id=id;
		node[size]=nxt=index;
		node[index]
	}
	node *tmp=pos[id]->pre;
	if(tmp->id==id)pos[id]=pos[id]->pre;
	else{
		node *s=new node(tmp->num,id);
		s->nxt=pos[id];
		s->pre=tmp->pre;
		pos[id]=s;
	}
}

void relearn(int id){
	node *tmp=pos[id]->nxt;
	if(tmp->id==id)pos[id]=pos[id]->nxt;
	else{
//	printf("%d %d %d %d\n",pos[id]->id,pos[id]->num,tmp->id,tmp->num);
		node *s=new node(tmp->num,id);
		s->pre=pos[id];
		s->nxt=tmp->nxt;
		pos[id]=s;
	}
}

void clone(int pid){
	int id=++cnt;
	node *s=new node(pos[pid]->num,id);
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
	root=0;
	size=1;
	memset(node,-1,sizeof(node));
	pos[1]=size++;
	node[pos[1]].pre=root;
	node[pos[1]].num=-1;
	node[pos[1]].id=1;
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

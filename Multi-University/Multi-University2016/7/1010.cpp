#include<stdio.h>
#include<string.h>
using namespace std;

char s[10];

struct Node{
	Node* pre;		//tong zhan shang ge
	Node* last;		//shang ge cha ru
	Node* nxt;		//xia ge cha ru
	int change;
	int num;
};

// A 0 B 1

Node* top;
Node* tail;
Node* Atop;
Node* Btop;

void pushA(int num){
	Node* tmp=new Node();
	tmp->pre=Atop->pre;
	tmp->last=top->last;
	tmp->nxt=top;
	tmp->change=-1;
	tmp->num=num;
	top->last->nxt=tmp;
	Atop->pre=tmp;
	top->last=tmp;
}

void pushB(int num){
	Node* tmp=new Node();
	tmp->pre=Btop->pre;
	tmp->last=top->last;
	tmp->nxt=top;
	tmp->change=-1;
	tmp->num=num;
	top->last->nxt=tmp;
	Btop->pre=tmp;
	top->last=tmp;
}

void popA(){
	Node* tmp=Atop->pre;
	printf("%d\n",tmp->num);
	if(tmp->change!=-1){
		tmp->last->change=tmp->change;
		Atop->pre=tmp->last;
	}
	else Atop->pre=tmp->pre;
	tmp->last->nxt=tmp->nxt;
	tmp->nxt->last=tmp->last;
	delete tmp;
}

void popB(){
	Node* tmp=Btop->pre;
	printf("%d\n",tmp->num);
	if(tmp->change!=-1){
		tmp->last->change=tmp->change;
		Btop->pre=tmp->last;
	}
	else Btop->pre=tmp->pre;
	tmp->last->nxt=tmp->nxt;
	tmp->nxt->last=tmp->last;
	delete tmp;
}

void mergeAB(){
	top->last->change=0;
	Atop->pre=top->last;
	Btop=new Node();
}

void mergeBA(){
	top->last->change=1;
	Btop->pre=top->last;
	Atop=new Node();
}

int main(){
	int n;
	int T=0;
	while(scanf("%d",&n)!=EOF&&n){
		top=new Node();
		Atop=new Node();
		Btop=new Node();
		tail=new Node();
		top->last=tail;
		tail->nxt=top;
		printf("Case #%d:\n",++T);
		while(n--){
			scanf("%s",s);
			if(s[1]=='u'){
				char t[5];
				int num;
				scanf("%s%d",t,&num);
				if(t[0]=='A')pushA(num);
				else pushB(num);
			}
			else if(s[1]=='o'){
				char t[5];
				scanf("%s",t);
				if(t[0]=='A')popA();
				else popB();
			}
			else if(s[1]=='e'){
				char t1[5],t2[5];
				scanf("%s%s",t1,t2);
				if(t1[0]=='A')mergeAB();
				else mergeBA();
			}
		}

	}
	return 0;
}

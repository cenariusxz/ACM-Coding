#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int r;
	int num;
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn],t[maxn];

void addSAM(int w){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->ma=p->ma+1;np->r=1;
	while(p&&!p->go[w])p->go[w]=np,p=p->par;
	if(!p)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=&sam[tot++];
			nq->ma=p->ma+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int ans[maxn];

int main(){
	tot=0;
	last=root=&sam[tot++];
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;s[i];++i)addSAM(s[i]-'a');
	for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
	for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
	for(int i=0;i<tot;++i){
		B[--Cnt[sam[i].ma]]=&sam[i];
		sam[i].num=Cnt[sam[i].ma];
	}
	SAM *p;
	for(int i=tot-1;i>=0;--i){
		p=B[i];
		if(p->par)p->par->r+=p->r;
	}
	for(int i=0;i<tot;++i){
		ans[B[i]->ma]=max(ans[B[i]->ma],B[i]->r);
	}
	for(int i=len-1;i>=1;--i){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1;i<=len;++i)printf("%d\n",ans[i]);
	return 0;
}

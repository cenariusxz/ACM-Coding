#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int l,r;
	void clear(){l=0x3f3f3f3f;r=-1;par=0;ma=0;memset(go,0,sizeof(go));}	//多组样例可能需要清空，否则会MLE
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn];

void addSAM(int w,int pos){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->clear();
	np->ma=p->ma+1;
	np->l=min(np->l,pos);
	np->r=max(np->r,pos);
	while(p&&!p->go[w])p->go[w]=np,p=p->par;
	if(!p)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=&sam[tot++];
			nq->clear();
			nq->ma=p->ma+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int main(){
	while(scanf("%s",s)&&s[0]!='#'){
		tot=0;
		last=root=&sam[tot++];
		root->clear();
		int len=strlen(s);
		for(int i=0;s[i];++i)addSAM(s[i]-'a',i);
		memset(Cnt,0,sizeof(Cnt));
		for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
		for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
		for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];
		SAM *p=root;
		int ans=0;
		for(int i=tot-1;i>=0;--i){
			p=B[i];
			if(p->par){
				p->par->l=min(p->par->l,p->l);
				p->par->r=max(p->par->r,p->r);
				int l=p->r-p->l;
				int ma=p->ma,mi=p->par->ma+1;
				if(l>=ma)ans+=ma-mi+1;
				else if(l>=mi)ans+=l-mi+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

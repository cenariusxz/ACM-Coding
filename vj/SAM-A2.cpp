#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn],t[maxn];

void addSAM(int w){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->ma=p->ma+1;
	while(p&&!p->go[w])p->go[w]=np,p=p->par;
	if(!p)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=&sam[tot++];
			*nq=*q;nq->ma=p->ma+1;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int main(){
	tot=0;
	last=root=&sam[tot++];
	scanf("%s%s",s,t);
	int len=strlen(s);
	for(int i=0;i<len;++i)addSAM(s[i]-'a');
	SAM *p=root;
	int res=0,ans=0;
	len=strlen(t);
	for(int i=0;i<len;++i){
		int w=t[i]-'a';
		if(p->go[w])res++,p=p->go[w];
		else{
			while(p&&!p->go[w])p=p->par;
			if(!p)res=0,p=root;
			else res=p->ma+1,p=p->go[w];
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}

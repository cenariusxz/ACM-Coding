#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=26e4;

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	SAM(int _ma):par(0),ma(_ma){memset(go,0,sizeof(go));}
}*root,*last;

void addSAM(int w){
	SAM *p=last;
	SAM *np=new SAM(p->ma+1);
	while(p&&!p->go[w])p->go[w]=np,p=p->par;
	if(!p)np->par=root;
	else{
		SAM *q=p->go[w];
		if(p->ma+1==q->ma)np->par=q;
		else{
			SAM *nq=new SAM(p->ma+1);
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			q->par=nq;
			np->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

char s[maxn],t[maxn];

int main(){
	scanf("%s%s",s,t);
	int l1=strlen(s);
	int l2=strlen(t);
	last=root=new SAM(0);
	for(int i=0;i<l1;++i)addSAM(s[i]-'a');
	for(int i=0;i<l2;++i)t[i]-='a';
	SAM *p=root;
	int ans=0,res=0;
	for(int i=0;i<l2;++i){
		if(p->go[t[i]])p=p->go[t[i]],res++;
		else{
			for(;p&&!p->go[t[i]];p=p->par);
			if(!p)p=root,res=0;
			else res=p->ma+1,p=p->go[t[i]];
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}

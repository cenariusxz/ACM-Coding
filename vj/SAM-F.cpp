#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)
typedef long long ll;

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int x;
	void clear(){par=0;ma=x=0;memset(go,0,sizeof(go));}
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn];

void addSAM(int w){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->clear();
	np->ma=p->ma+1;
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
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		tot=0;
		last=root=&sam[tot++];
		root->clear();
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;s[i];++i)addSAM(s[i]-'a');

		memset(Cnt,0,sizeof(Cnt));
		for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
		for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
		for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];

		while(n--){
			scanf("%s",s);
			SAM *p=root;
			int res=0;
			for(int i=0;s[i];++i){
				int w=s[i]-'a';
				if(p->go[w])res++,p=p->go[w];
				else{
					while(p&&!p->go[w])p=p->par;
					if(!p)res=0,p=root;
					else res=p->ma+1,p=p->go[w];
				}
				p->x=max(p->x,res); 
			}
		}
		ll ans=0;
		SAM *p;
		for(int i=tot-1;i>=0;--i){
			p=B[i];
			if(p->par){
				if(p->x){
					p->par->x=p->par->ma;
				}
				else p->x=p->par->ma;
			}
			ans+=p->ma-p->x;
		}
		printf("Case %d: %lld\n",q,ans);
	}
	return 0;
}

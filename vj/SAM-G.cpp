#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)
typedef long long ll;

struct SAM{
	SAM *par,*go[60];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int r;
	int num;
	void clear(){par=0;num=r=ma=0;memset(go,0,sizeof(go));}	//多组样例可能需要清空，否则会MLE
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn],t[maxn];

void addSAM(int w){
	SAM *p=last;
	SAM *np=&sam[tot++];
	np->clear();
	np->r=1;
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
	int k;
	while(scanf("%d",&k)&&k){
		tot=0;
		last=root=&sam[tot++];
		root->clear();
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;s[i];++i)addSAM(s[i]-'A');
		memset(Cnt,0,sizeof(Cnt));
		for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
		for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
		for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];

		SAM *p;
		for(int i=tot-1;i>=0;--i){
			p=B[i];
			if(p->par)p->par->r+=p->r;
		}

		scanf("%s",t);
		int res=0;		//res是对于后面的每个i位置能匹配的最长长度
		ll ans=0;
		p=root;
		for(int i=0;t[i];++i){
			int w=t[i]-'A';
			if(p->go[w])res++,p=p->go[w];
			else{
				while(p&&!p->go[w])p=p->par;
				if(!p)res=0,p=root;
				else res=p->ma+1,p=p->go[w];
			}
			if(p->par){
				p->par->num++;
				if(res>=k){
					ans+=(res-max(k,p->par->ma+1)+1)*(ll)p->r;
			//		printf("%d %d %d %d\n",res,p->par->ma+1,p->ma,p->r);
				}
			}
		}
//		printf("%lld\n",ans);
		for(int i=tot-1;i>=0;--i){
			p=B[i];
			if(p->par){
				p->par->num+=p->num;
				if(p->ma>=k)ans+=(p->num)*(ll)(p->ma-max(k,p->par->ma+1)+1)*(ll)p->r;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

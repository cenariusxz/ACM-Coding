#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
const int maxn=5e5+5;	//后缀自动机节点数(串长的2倍)
const int mod=2012;

struct SAM{
	SAM *par,*go[11];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int dp,num;
	void clear(){par=0;num=dp=ma=0;memset(go,0,sizeof(go));}	//多组样例可能需要清空，否则会MLE
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn],t[maxn];

queue<SAM*>q;

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
	int n;
	while(scanf("%d",&n)!=EOF){
		tot=0;
		last=root=&sam[tot++];
		root->clear();
		s[0]=0;
		for(int i=1;i<=n;++i){
			scanf("%s",t);
			strcat(s,t);
			int len=strlen(s);
			s[len]='0'+10;
			s[len+1]=0;
		}
		int len=strlen(s);
		for(int i=0;s[i];++i)addSAM(s[i]-'0');
		memset(Cnt,0,sizeof(Cnt));
		for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
		for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
		for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];

		SAM *p;
		root->num=1;
		root->dp=0;
		int ans=0;
		for(int i=0;i<tot;++i){
			p=B[i];
			ans=(ans+p->dp)%mod;
			for(int j=0;j<10;++j){
				if(i==0&&j==0)continue;
				if(p->go[j]){
					p->go[j]->num=(p->go[j]->num+p->num)%mod;
					p->go[j]->dp=(p->go[j]->dp+p->dp*10%mod+p->num*j%mod)%mod;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

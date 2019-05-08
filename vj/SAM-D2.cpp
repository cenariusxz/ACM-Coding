#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=2e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
	int dp;
}*root,*last,sam[maxn];
int tot;

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
			nq->ma=p->ma+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

int dfs1(SAM *s){
	if(s->dp)return s->dp;
	s->dp=1;
	for(int i=0;i<26;++i){
		if(s->go[i])s->dp+=dfs1(s->go[i]);
	}
	return s->dp;
}

int q,k,c;
char ans[maxn];

void dfs(SAM *s,int k){
	if(k==1){
		ans[c]=0;
		printf("%s\n",ans);
		return;
	}
	k-=1;
	for(int i=0;i<26;++i){
		if(s->go[i]){
			if(k<=s->go[i]->dp){
				ans[c++]='a'+i;
				dfs(s->go[i],k);
				return;
			}
			k-=s->go[i]->dp;
		}
	}
}

int main(){
	tot=0;
	last=root=&sam[tot++];
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;s[i];++i)addSAM(s[i]-'a');
	dfs1(root);
	scanf("%d",&q);
	while(q--){
		c=0;
		scanf("%d",&k);
		k++;
		dfs(root,k);
	}
	return 0;
}

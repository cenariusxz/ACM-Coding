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
			nq->ma=p->ma+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->par=q->par;
			np->par=q->par=nq;
			while(p&&p->go[w]==q)p->go[w]=nq,p=p->par;
		}
	}
	last=np;
}

char ans[maxn];
int q,k,c;

void dfs(SAM *s,int k){
	if(k==1){
		ans[c]=0;
		printf("%s\n",ans);
		return;
	}
	k--;
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

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	tot=0;
	last=root=&sam[tot++];
	scanf("%s",s);
	q=read();
	int len=strlen(s);
	for(int i=0;s[i];++i)addSAM(s[i]-'a');
	for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
	for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
	for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];
	for(int i=tot-1;i>=0;--i){
		B[i]->dp++;
		if(B[i]->par)B[i]->par->dp+=B[i]->dp;
	}
	while(q--){
		c=0;
		k=read()+1;
		dfs(root,k);
	}
	return 0;
}

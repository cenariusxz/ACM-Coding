#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=2e5+5;	//后缀自动机节点数(串长的2倍)

struct SAM{
	SAM *par,*go[26];
	int ans[15];
	int ma;				//子串可行长度区间[min,max]，此为max，min是par的ma+1
}*root,*last,sam[maxn],*B[maxn];
int tot,Cnt[maxn];

char s[maxn];

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
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;s[i];++i)addSAM(s[i]-'a');
	for(int i=0;i<tot;++i)Cnt[sam[i].ma]++;
	for(int i=1;i<=len;++i)Cnt[i]+=Cnt[i-1];
	for(int i=0;i<tot;++i)B[--Cnt[sam[i].ma]]=&sam[i];
	int cnt=0;
	while(scanf("%s",s)!=EOF){
		cnt++;
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
			p->ans[cnt]=max(p->ans[cnt],res);
		}
		for(int i=tot-1;i>=0;--i){
			p=B[i];
			if(p->par)p->par->ans[cnt]=max(p->par->ans[cnt],p->ans[cnt]);
		}
	}
	int ans=0;
	for(int i=0;i<tot;++i){
		int tmp=B[i]->ma;
		for(int j=1;j<=cnt;++j){
			tmp=min(tmp,B[i]->ans[j]);
		}
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}

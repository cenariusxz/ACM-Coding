#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int maxl=20;

int ma[maxn][maxl];
int st[maxn][maxl];
char s[maxn];
int a[maxn],prelog[maxn];

void initRMQ(int n){
	for(int i=2;i<=n;++i){
		prelog[i]=prelog[i-1];
		if((i&(-i))==i)prelog[i]++;
	}
	for(int i=1;i<=n;++i)ma[i][0]=a[i];
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			ma[i][j]=min(ma[i][j-1],ma[i+(1<<j-1)][j-1]);
		}
	}
}

int askRMQ(int l,int r){
	if(l>r)swap(l,r);
	int k=prelog[r-l+1];
	return min(ma[l][k],ma[r-(1<<k)+1][k]);
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		scanf("%s",s+1);
		memset(a,0,sizeof(a));
		if(s[1]=='(')a[1]=1;
		else a[1]=-1;
		for(int i=2;i<=n;++i){
			if(s[i]=='(')a[i]=a[i-1]+1;
			else a[i]=a[i-1]-1;
		}
		initRMQ(n);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(l>r)swap(l,r);
			if(s[l]==s[r]||s[l]==')')printf("Yes\n");
			else if(askRMQ(l,r-1)>=2)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

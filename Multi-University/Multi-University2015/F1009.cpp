#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int maxm=200005;

ll dis[maxm];
int val[maxm],l[maxm],r[maxm];
int n;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

int st[maxm<<2];
priority_queue<pii,vector<pii>,cmp>q;

void update(int o,int l,int r,int ql,int qr,ll c){
	if(st[o]==1)return;
	if(ql<=l&&qr>=r&&st[o]==-1){
		st[o]=1;
		for(int i=l;i<=r;++i){
			dis[i]=c+val[i];
			q.push(make_pair(dis[i],i));
		}
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	if(st[o<<1]==st[o<<1|1])st[o]=st[o<<1];
	else st[o]=0;
}

void dij(){
	int i;
	memset(st,-1,sizeof(st));
	memset(dis,-1,sizeof(dis));
	update(1,1,n,1,1,0);
	while(!q.empty()){
		pii u=q.top();q.pop();
		int pos=u.second;
		int ql=pos+l[pos];
		int qr=pos+r[pos];
		if(ql<=n){
			if(qr>n)qr=n;
			update(1,1,n,ql,qr,u.first);
		}
		ql=pos-r[pos];
		qr=pos-l[pos];
		if(qr>=1){
			if(ql<1)ql=1;
			update(1,1,n,ql,qr,u.first);
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
	int T=read();
	while(T--){
		n=read();
		int i;
		for(i=1;i<=n;i++)l[i]=read();
		for(i=1;i<=n;i++)r[i]=read();
		for(i=1;i<=n;i++)val[i]=read();
		dij();
		for(i=1;i<=n;i++){
			if(dis[i]==-1)printf("-1");
			else printf("%lld",dis[i]-val[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}

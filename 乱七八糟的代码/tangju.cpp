#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int type[maxn];
int from[maxn],to[maxn];
int id[maxn];

int head[maxn],point[maxn<<1],nxt[maxn<<1],size;

int dep[maxn],stx[maxn],edx[maxn];

int st[maxn<<2],st1[maxn<<2],cha[maxn<<2];
int minn[maxn<<2];
int t;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	t=0;
	memset(cha,0,sizeof(cha));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void build(int o,int l,int r){
	if(l==r){
		st[o]=-1;
		st1[o]=id[l];
		minn[o]=id[l];
		return;
	}
	int m=(l+r)>>1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	st[o]=-1;
	if(st1[o<<1]<=st1[o<<1|1])st1[o]=st1[o<<1];
	else st1[o]=st1[o<<1|1];
	minn[o]=min(minn[o<<1],minn[o<<1|1]);
}

void dfs(int s,int fa,int d){
	dep[s]=d;
	stx[s]=++t;
	id[t]=s;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==fa)continue;
		dfs(j,s,d+1);
	}
	edx[s]=t;
}

void pushdown(int o,int l,int r){
	if(cha[o]){
		int m=(l+r)>>1;
		cha[o<<1]=cha[o];
		cha[o<<1|1]=cha[o];
		st[o<<1]=cha[o];
		st[o<<1|1]=cha[o];
		st1[o<<1]=minn[o<<1];
		st1[o<<1|1]=minn[o<<1|1];
		cha[o]=0;
	}
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		st[o]=c;
		st1[o]=minn[o];
		cha[o]=c;
		return;
	}
	pushdown(o,l,r);
	int m=(l+r)>>1;
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	if(st[o<<1]>st[o<<1|1]){
		st[o]=st[o<<1];
		st1[o]=st1[o<<1];
	}
	else if(st[o<<1]<st[o<<1|1]){
		st[o]=st[o<<1|1];
		st1[o]=st1[o<<1|1];
	}
	else{
		st[o]=st[o<<1];
		st1[o]=min(st1[o<<1],st1[o<<1|1]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		init();
		scanf("%d",&n);
		int cnt=1;
		for(int i=1;i<=n;++i){
			char s[100];
			scanf("%s",s);
			if(s[0]=='+'){
				type[i]=1;
				int num=0;
				for(int j=1;s[j];++j){
					num=num*10+s[j]-'0';
				}
				from[i]=++cnt;
				to[i]=num;
				add(from[i],to[i]);
			}
			else{
				type[i]=0;
				int num=0;
				for(int j=1;s[j];++j){
					num=num*10+s[j]-'0';
				}
				from[i]=num;
			}
		}
		memset(dep,-1,sizeof(dep));
		dfs(1,-1,0);
		build(1,1,cnt);
		update(1,1,cnt,stx[1],stx[1],dep[1]);
		for(int i=1;i<=n;++i){
			if(type[i]==1)update(1,1,cnt,stx[from[i]],stx[from[i]],dep[from[i]]);
			else{
				update(1,1,cnt,stx[from[i]],edx[from[i]],-1);
			}
			printf("%d\n",st1[1]);
		}
	}
	return 0;
}

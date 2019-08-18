#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int head[maxn],point[maxn<<1],nxt[maxn<<1],size;
int stmax[maxn<<2], stsum[maxn<<2];
int root, fa[maxn], dep[maxn], sz[maxn], son[maxn], rk[maxn], top[maxn], id[maxn], dn;
int n,m,num[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size = 0;
	memset(sz,0,sizeof(sz));
	memset(son,0,sizeof(son));
	dn = 0;
}

void add(int a, int b){
	point[size] = b;
	nxt[size] = head[a];
	head[a] = size++;
}

void dfs1(int s,int f,int d){
	fa[s] = f;
	dep[s] = d;
	sz[s] = 1;
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int j = point[i];
		if(j == f)continue;
		dfs1(j,s,d+1);
		sz[s] += sz[j];
		if(sz[j] > sz[son[s]])son[s] = j;
	}
}

void dfs2(int s,int t){
	top[s] = t;
	id[s] = ++dn;
	rk[dn] = s;
	if(!son[s])return;
	dfs2(son[s],t);
	for(int i = head[s] ; ~i ; i = nxt[i]){
		int j = point[i];
		if(j == fa[s] || j == son[s])continue;
		dfs2(j,j);	
	}
}

void build(int o,int l,int r){
	if(l == r){
		stmax[o] = stsum[o] = num[rk[l]];
		return;
	}
	int m = (l + r) >> 1;
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	stmax[o] = max(stmax[o<<1], stmax[o<<1|1]);
	stsum[o] = stsum[o<<1] + stsum[o<<1|1];
}

void update(int o,int l,int r,int ind,int c){
	if(l == r){
		stmax[o] = stsum[o] = c;
		return;	
	}
	int m = (l + r) >> 1;
	if(ind <= m)update(o<<1,l,m,ind,c);
	else update(o<<1|1,m+1,r,ind,c);
	stmax[o] = max(stmax[o<<1], stmax[o<<1|1]);
	stsum[o] = stsum[o<<1] + stsum[o<<1|1];
}

int querymax(int o,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r)return stmax[o];
	int m = (l + r) >> 1;
	int ans = -INF;
	if(ql <= m)ans = max(ans, querymax(o<<1,l,m,ql,qr));
	if(qr >= m+1)ans = max(ans, querymax(o<<1|1,m+1,r,ql,qr));
	return ans;
}

int querysum(int o,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r)return stsum[o];
	int m = (l + r) >> 1;
	int ans = 0;
	if(ql <= m)ans += querysum(o<<1,l,m,ql,qr);
	if(qr >= m+1)ans += querysum(o<<1|1,m+1,r,ql,qr);
	return ans;
}

int Qsum(int u,int v){
	int ans = 0;
	while(top[u] != top[v]){
		if(dep[top[u]] > dep[top[v]])swap(u,v);	// top[u]靠近根，v爬
		ans += querysum(1,1,n,id[top[v]], id[v]);
		v = fa[top[v]];
	}
	if(id[u] > id[v])swap(u,v);
	ans += querysum(1,1,n,id[u],id[v]);
	return ans;
}

int Qmax(int u,int v){
	int ans = -INF;
	while(top[u] != top[v]){
		if(dep[top[u]] > dep[top[v]])swap(u,v);	// top[u]靠近根，v爬
		ans = max(ans, querymax(1,1,n,id[top[v]], id[v]));
		v = fa[top[v]];
	}
	if(id[u] > id[v])swap(u,v);
	ans = max(ans, querymax(1,1,n,id[u],id[v]));
	return ans;
}

int main(){
	init();
	scanf("%d", &n);
	for(int i = 1 ; i < n ; ++ i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &num[i]);
	root = 1;
	dfs1(root, 0, 1);
	dfs2(root, root);
	build(1,1,n);
	scanf("%d", &m);
	while(m --){
		char s[5];
		int a,b;
		scanf("%s%d%d",s,&a,&b);
		if(s[0] == 'C')update(1,1,n,id[a],b);
		if(s[1] == 'S')printf("%d\n",Qsum(a,b));
		if(s[1] == 'M')printf("%d\n",Qmax(a,b));
	}
	return 0;
}


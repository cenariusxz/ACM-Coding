#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
#define PB push_back
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int maxn = 100010;

int N,M;
int first[maxn],nxt[maxn << 1],ver[maxn << 1],ecnt;
int dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],w[maxn],aw[maxn],tsz;
int val[maxn];
int prea[maxn << 2],pred[maxn << 2],sufa[maxn << 2],sufd[maxn << 2];

inline int Read(){
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x;
}

void Init(){
    memset(first,-1,sizeof(first));
    ecnt = 0;
    tsz = 0;
}

void Add_edge(int u,int v){
    nxt[++ecnt] = first[u];
    ver[ecnt] = v;
    first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
    sz[p] = 1;
    dep[p] = d;
    son[p] = -1;
    fa[p] = pre;
    int tmp = 0,v;
    for(int i = first[p]; i != -1; i = nxt[i]) if((v = ver[i]) != pre){
        Dfs(v,p,d + 1);
        if(sz[v] > tmp){
            tmp = sz[v];
            son[p] = v;
        }
        sz[p] += sz[v];
    }
}

void Dfs_pos(int p,int tp){
    w[p] = ++tsz;
	aw[tsz] = p;
    top[p] = tp;
    if(son[p] != -1) Dfs_pos(son[p],tp);
    for(int i = first[p]; i != -1; i = nxt[i]){
        int v = ver[i];
        if(v != son[p] && v != fa[p])
            Dfs_pos(v,v);
    }
}

void Build(int p,int l,int r){
	if(l == r){
		
	}
}

int Find(int a,int b){
    v1 = v2 = 0;
    int f1 = top[a],f2 = top[b];
    int res = 0;
    while(f1 != f2){
        if(dep[f1] > dep[f2]){
            query = 0;
            VV[++v1] = (Query_sum(w[f1],w[a],1,1,tsz));
            res += query;
            a = fa[f1];
            f2 = top[a];
        }
        else{
            query = 0;
            V2[++v2] = (Query_sum(w[f2],w[b],1,1,tsz));
            res += query;
            b = fa[f2];
            f2 = top[b];
        }
    }
    if(a == b) return res;
    if(dep[a] > dep[b]){
        query = 0;
        VV[++v1] = (Query_sum(w[son[b]],w[a],1,1,tsz));
        res += query;
    }
    else{
        query = 0;
        V2[++v2] = (Query_sum(w[son[a]],w[b],1,1,tsz));
        res += query;
    }
    for(int i = v2; i >= 1; --i) VV[++v1] = (V2[i]);
    for(int i = 1; i <= v1; ++i)
        if(VV[i].second == VV[i + 1].first) res--;
    return res;
}

void Update_tree(int a,int c,int p,int l,int r){
    if(l == r){
        Ls[p] = Rs[p] = c;
        Ns[p] = 1;
        return;
    }
    Push_down(p);
    int mid = getmid(l,r);
    if(a <= mid) Update_tree(a,c,lp,l,mid);
    else Update_tree(a,c,rp,mid + 1,r);
    Push_up(p);
}

void Update2(int a,int b,int c,int p,int l,int r){
    if(a <= l && r <= b){
        Ls[p] = Rs[p] = Tag[p] = c;
        Ns[p] = 1;
        return;
    }
    Push_down(p);
    int mid = getmid(l,r);
    if(a <= mid) Update2(a,b,c,lp,l,mid);
    if(b > mid)  Update2(a,b,c,rp,mid + 1,r);
    Push_up(p);
}

void Change(int a,int b,int c){
    int f1 = top[a],f2 = top[b];
    while(f1 != f2){
        if(dep[f1] > dep[f2]){
            swap(a,b);
            swap(f1,f2);
        }
        Update2(w[f2],w[b],c,1,1,tsz);
        b = fa[f2];
        f2 = top[b];
    }
    if(a == b) return;
    if(dep[a] > dep[b]) swap(a,b);
    Update2(w[son[a]],w[b],c,1,1,tsz);
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
        scanf("%d",&N);
		Init();
		for(int i = 1; i <= N; ++i){
			scanf("%d",&val[i]);
		}
        for(int i = 2; i <= N; ++i){
            int a;
			scanf("%d",&a);
			Add_edge(a,i);
            Add_edge(i,a);
        }
        Dfs(1,0,0);
        Dfs_pos(1,1);
		Build(1,1,tsz);
    	scanf("%d",&M);
		for(int i = 1; i <= M; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",Find(a,b));
		}
	}
    return 0;
}

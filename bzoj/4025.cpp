#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
const int maxn = 1e5 + 5;

struct node{
    int a,b;
    bool f;
    node(int _a, int _b, bool _f):a(_a),b(_b),f(_f){}
};
int n,m,T,ans[maxn],fa[maxn],dep[maxn],col[maxn];
vector<pair<int,int> >V[maxn << 2];
vector<node>st[maxn << 2];

int find(int &x){
    int res = 0;
    while(x != fa[x]){
		res ^= col[x];
		x = fa[x];
	}
    return res;
}

void init(){
    for(int i = 0 ; i <= n ; ++ i)fa[i] = i, ans[i] = dep[i] = 1;
    memset(col, 0, sizeof(col));
}
void update(int o,int l,int r,int ql,int qr,int a,int b){
    if(ql <= l && qr >= r){
        V[o].PB(MP(a,b));
        return;
    }
    int mid = (l+r) >> 1;
    if(ql <= mid)update(o<<1, l, mid, ql, qr, a, b);
    if(qr >= mid+1)update(o<<1|1, mid+1, r, ql, qr, a, b);
}

void query(int o,int l,int r){
    bool f = 0;
    for(int i = 0 ; i < V[o].size() ; ++ i){
        int a = V[o][i].first, b = V[o][i].second;
		int col1 = find(a), col2 = find(b);
        if(a == b){
            if(col1 == col2){
                f = 1;
                break;
            }
            continue;
        }
        if(dep[a] < dep[b])swap(a,b);
        fa[b] = a;
		col[b] = col1 ^ col2 ^ 1;
        if(dep[a] == dep[b])dep[a] ++;
		st[o].PB(node(a,b,dep[a] == dep[b]));
    }
    int mid = (l+r) >> 1;
    if(f){
    	for(int i = l ; i <= r ; ++ i)ans[i] = 0;
    }
    else if(l < r){
        query(o<<1,l,mid);
        query(o<<1|1,mid+1,r);
    }
    for(int i = st[o].size() - 1 ; i >= 0 ; -- i){
    	node u = st[o][i];
        int a = u.a, b = u.b;
        fa[b] = b;
		col[b] = 0;
		dep[a] -= u.f;
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&T);
    init();
    for(int i = 1 ; i <= m ; ++ i){
        int a,b,l,r;
        scanf("%d%d%d%d",&a,&b,&l,&r);
        l ++;
        if(l > r)continue;
        update(1,1,T,l,r,a,b);
    }
    query(1,1,T);
    for(int i = 1 ; i <= T ; ++ i){
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

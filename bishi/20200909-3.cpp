#include <bits/stdc++.h>
using namespace std;
#define PB push_back
const int maxn = 1e6 + 6;

int n, a[maxn], num[maxn], Nxt[maxn][2], Cnt[maxn], size = 1, ans;
int lft[maxn], rht[maxn], fa[maxn];

void insertword(int s){
    int p=0;
    for(int i = 30 ; i >= 0 ; -- i){
		int bit = (s & (1 << i)) ? 1 : 0;
        int &x=Nxt[p][bit];
        if(!x){
            memset(Nxt[size],0,sizeof(Nxt[size]));
            x=size++;
        }
        Cnt[x]++;
        p=x;
    }
}

void deleteword(int s){
    int p=0;
	for(int i = 30 ; i >= 0 ; -- i){
		int bit = (s & (1 << i)) ? 1 : 0;
        int x=Nxt[p][bit];
        Cnt[x]--;
        p=x;
    }
}

int findword(int s){
	int p=0;
    for(int i = 30 ; i >= 0 ; -- i){
		int bit = (s & (1 << i)) ? 0 : 1;
		int x=Nxt[p][bit];
        if(!x || !Cnt[x]){
			x = Nxt[p][bit^1];
			if(s & (1 << i))s ^= (1 << i);
		}
        else if(! (s & (1 << i)))s ^= (1 << i);
        p=x;
    }
    return s;
}

void dfs(int s, int sum){
	num[s] = sum ^ a[s];
	ans = max(ans, findword(num[s]));
	insertword(num[s]);
	if(lft[s])dfs(lft[s], num[s]);
	if(rht[s])dfs(rht[s], num[s]);
	deleteword(num[s]);
}

int main(){
	memset(fa, -1, sizeof(fa));
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i){
		int id, w, l, r;
		scanf("%d%d%d%d", &id, &w, &l, &r);
		a[id] = w;
		lft[id] = l; fa[l] = id;
		rht[id] = r; fa[r] = id;
	}
	int root = -1;
	for(int i = 1 ; i <= n ; ++ i)if(fa[i] == -1)root = i;
	insertword(0);
	dfs(root, 0);
	printf("%d\n", ans);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 200010;

int T,n,m;
int A[MAXN];
int PT[MAXN],lson[30 * MAXN],rson[30 * MAXN],c[30 * MAXN];
int mp[MAXN];
int tot;

int Build(int l,int r){
	int root = ++tot;
	c[root] = 0;
	if(l != r){
		int mid = getmid(l,r);
		lson[root] = Build(l,mid);
		rson[root] = Build(mid + 1,r);
	}
	return root;
}

int Update(int root,int pos,int val){
	int nxt = ++tot,tmp = nxt;
	c[nxt] = c[root] + val;
	int l = 1,r = n;
	while(l < r){
		int mid = getmid(l,r);
		if(pos <= mid){
			lson[nxt] = ++tot;
			rson[nxt] = rson[root];
			nxt = lson[nxt];
			root = lson[root];
			r = mid;
		}
		else{
			rson[nxt] = ++tot;
			lson[nxt] = lson[root];
			nxt = rson[nxt];
			root = rson[root];
			l = mid + 1;
		}
		c[nxt] = c[root] + val;
	}
	return tmp;
}

int Query(int root,int pos){
	int res = 0;
	int l = 1,r = n;
	while(pos < r){
		int mid = getmid(l,r);
		if(pos <= mid){
			r = mid;
			root = lson[root];
		}
		else{
			res += c[lson[root]];
			root = rson[root];
			l = mid + 1;
		}
	}	
	return res + c[root];
}

int Query2(int root,int k,int l,int r){
	int mid = getmid(l,r);
	if(l == r) return l;
	if(k <= c[lson[root]]) return Query2(lson[root],k,l,mid);
	else return Query2(rson[root],k - c[lson[root]],mid + 1,r);
}

inline int Read(){
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9')ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x;
}

int main(){
	T = Read();
	for(int tt = 1; tt <= T; ++tt){
		n = Read();
		m = Read();
		memset(mp,0,sizeof(mp));
		for(int i = 1; i <= n; ++i){
			A[i] = Read();
		}
		tot = 0;
		PT[n + 1] = Build(1,n);
		for(int i = n; i >= 1; --i){
			if(mp[A[i]] == 0){
				PT[i] = Update(PT[i + 1],i,1);
			}
			else{
				int tmp = Update(PT[i + 1],mp[A[i]],-1);
				PT[i] = Update(tmp,i,1);
			}
			mp[A[i]] = i;
		}
		printf("Case #%d:",tt);
		int ans = 0;
		for(int i = 1; i <= m; ++i){
			int a,b;
			a = Read();
			b = Read();
			int ta = a,tb = b;
			a = min((ta + ans) % n + 1,(tb + ans) % n + 1);
			b = max((ta + ans) % n + 1,(tb + ans) % n + 1);
			int num = Query(PT[a],b);
			int k = (num + 1) / 2;
			ans = Query2(PT[a],k,1,n);
			printf(" %d",ans);
		}
		puts("");
	}
	return 0;
}

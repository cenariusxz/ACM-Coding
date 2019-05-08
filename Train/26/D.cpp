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
typedef pair<ll,ll> pll;
const double eps = 1e-8;
const ll INF = 1LL << 60;
const int MAXN = 100010;

int T,N,L;
int A[MAXN];
pll B[MAXN];
ll tmax[MAXN << 2],dp[MAXN];

void Update(int a,ll c,int p,int l,int r){
	if(l == r){
		tmax[p] = c;
		return;
	}
	int mid = getmid(l,r);
	if(a <= mid) Update(a,c,p << 1,l,mid);
	else Update(a,c,p << 1|1,mid + 1,r);
	tmax[p] = max(tmax[p << 1],tmax[p << 1|1]);
}

ll Query(int a,int b,int p,int l,int r){
	if(a > b) return -INF;
	if(a <= l && r <= b){
		return tmax[p];
	}
	int mid = getmid(l,r);
	ll res = -INF;
	if(a <= mid) res = max(res,Query(a,b,p << 1,l,mid));
	if(b > mid)  res = max(res,Query(a,b,p << 1|1,mid + 1,r));
	return res;
}

void Build(int p,int l,int r){
	tmax[p] = -INF;
	if(l == r) return;
	int mid = getmid(l,r);
	Build(p << 1,l,mid);
	Build(p << 1|1,mid + 1,r);
}

bool cmp(pll a,pll b){
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%d",&N,&L);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&A[i]);
			B[i].first = 1ll * A[i] * A[i] - A[i];
			B[i].second = i;
		}
		Build(1,1,N);
		for(int i = 1; i <= N; ++i) dp[i] = -INF;
		sort(B + 1,B + N + 1,cmp);
		for(int i = 1; i <= N; ++i){
			int se = B[i].second;
			ll res = Query(max(1LL,B[i].second - L),B[i].second - 1,1,1,N);
			if(B[i].second <= L) res = max(res,0LL);
			if(res != -INF) dp[se] = res + B[i].first;
			if(dp[se] != -INF) Update(B[i].second,dp[se],1,1,N);
		}
		printf("Case #%d: ",tt);
		if(dp[N] == -INF){
			printf("No solution\n");
		}
		else{
			printf("%lld\n",dp[N] + A[N]);
		}
	}
	return 0;
}

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
const int MAXN = 100010;

int T,n,Q;
int A[MAXN];
int que[MAXN],qcnt;
map<int,ll> mp,tmp[2];
map<int,ll>::iterator it;
int tgcd[MAXN << 2];

void Build(int p,int l,int r){
	if(l == r){
		tgcd[p] = A[l];
		return;
	}
	int mid = getmid(l,r);
	Build(p << 1,l,mid);
	Build(p << 1|1,mid + 1,r);
	tgcd[p] = __gcd(tgcd[p << 1],tgcd[p << 1|1]);
}

int c = 0;

int Query(int a,int b,int p,int l,int r){
	if(a <= l && r <= b){
		return tgcd[p];
	}
	int mid = getmid(l,r);
	int res = -1;
	if(a <= mid){
		if(res == -1) res = Query(a,b,p << 1,l,mid);
		else res = __gcd(res,Query(a,b,p << 1,l,mid));
	}
	if(b > mid){
		if(res == -1) res = Query(a,b,p << 1|1,mid + 1,r);
		else res = __gcd(res,Query(a,b,p << 1|1,mid + 1,r));
	}
	return res;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		mp.clear();
		scanf("%d",&n);
		for(int i = 1; i <= n;++i){
			scanf("%d",&A[i]);
		}
		Build(1,1,n);
		qcnt = 0;
		tmp[0].clear();
		tmp[1].clear();
		int id,pre;
		for(int i = 1; i <= n; ++i){
			id = i & 1;
			pre = id ^ 1;
			tmp[id].clear();
			for(it = tmp[pre].begin(); it != tmp[pre].end(); ++it){
				tmp[id][__gcd((*it).first,A[i])] += (*it).second;
			}
			tmp[id][A[i]]++;
			for(it = tmp[id].begin(); it != tmp[id].end(); ++it){
				mp[(*it).first] += (*it).second;
			}
		}
		scanf("%d",&Q);
		printf("Case #%d:\n",tt);
		for(int i = 1; i <= Q; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			int g = Query(a,b,1,1,n);
			printf("%d %lld\n",g,mp[g]);
		}
	}
	return 0;
}


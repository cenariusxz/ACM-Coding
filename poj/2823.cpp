#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

deque<int> qmax, qmin;

int n, k, a[maxm], amax[maxm], amin[maxm];

void solve(){
	for(int i = 1 ; i <= n ; ++ i){
		while(!qmax.empty() && a[qmax.back()] >= a[i])qmax.pop_back();
		qmax.PB(i);
		while(!qmin.empty() && a[qmin.back()] <= a[i])qmin.pop_back();
		qmin.PB(i);
		if(i < k)continue;
		if(!qmax.empty() && qmax.front() < i-k+1)qmax.pop_front();
		amin[i] = a[qmax.front()];
		if(!qmin.empty() && qmin.front() < i-k+1)qmin.pop_front();
		amax[i] = a[qmin.front()];
	}
	for(int i = k ; i <= n ; ++ i){
		printf("%d%c", amin[i], i == n ? '\n' : ' ');
	}
	for(int i = k ; i <= n ; ++ i){
		printf("%d%c", amax[i], i == n ? '\n' : ' ');
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d", &a[i]);
	solve();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

int n,m,k;
int x,y,z;
int r1,p1,p2;
int A,B;

void solve(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		if(r1)r1 = max(r1, x);
		else r1 = x;
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d", &y);
		if(p1)p1 = max(p1, y);
		else p1 = y;
	}
	scanf("%d", &k);
	while(k--){
		scanf("%d", &z);
		if(p2)p2 = min(p2, z);
		else p2 = z;
	}
	scanf("%d%d", &A, &B);
	printf("%.12lf\n", sqrt(B*0.1*p1*r1*r1 / (B*0.1*p1 + A*0.1*p2)));
}

int main(){
	solve();
	return 0;
}


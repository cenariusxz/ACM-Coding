#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

struct node{
	string name;
	ll v;
	bool operator < (const node a)const{
		return v < a.v;
	}
}nd[maxn];

int n;
ll L;
char s[55];

int main(){
	scanf("%d%lld", &n, &L);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s%lld", s, &nd[i].v);
		nd[i].name = string(s);
	}
	sort(nd + 1 , nd + 1 + n);
	for(int i = 1 ; i < n ; ++ i){
		ll len = i * nd[i].v;
		ll res2 = len % L;
		if(res2 != 0)res2 = L - res2;
		printf("%s %lld %lld\n", nd[i].name.c_str(), len / L, res2);
	}
	printf("%s\n", nd[n].name.c_str());
	return 0;
}


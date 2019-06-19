#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int cnt[maxn];
int n,a;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i = 0 ; i <= 1000 ; ++ i){
		if(cnt[i])printf("%d %d\n",i,cnt[i]);
	}
	return 0;
}



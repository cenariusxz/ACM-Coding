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

bitset<1000>bs[1005], tmp;
int n, st;
char s[1005];
int V[1005][1005];

void init(){
	for(int i = 1 ; i <= 1000 ; ++ i){
		for(int j = 1 ; j <= 1000 ; ++ j){
			V[i][j] = V[i][j-1];
			if(i % j == 0 || j % i == 0)V[i][j] ++;
		}
	}
}

int main(){
	init();
	scanf("%d", &n);
	// 0~n-1  0~n-1;
	for(int i = 0 ; i < n ; ++ i){
		scanf("%s", s);
		bs[i] = bitset<1000>(string(s));
	}
	ll ans = 0;
	for(int st = 0 ; st < n ; ++ st){
		tmp.set();
		int len = 0, cnt = 0;
		for(int ed = st ; ed < n ; ++ ed){
			tmp &= bs[ed];
			if(!tmp.count())break;
			len ++;
			cnt = 0;
			for(int i = 0 ; i < n ; ++ i){
				if(tmp.test(i))cnt++;
				else cnt = 0;
				ans += V[len][cnt];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

